import sys, random, copy, math
from PIL import Image  # Подключим необходимые библиотеки.

IMAGE_PATH = "./"  # Путь до картинки, с которой будем работать, пустой если находится в той же директоррии, что и программа.
IMAGE_NAME = "pic"  # Имя картинки.
IMAGE_TYPE = "jpg"  # Тип картинки, крайне рекомендуется jpg.

original_image = Image.open(IMAGE_PATH + IMAGE_NAME + "." + IMAGE_TYPE)  # Открываем изображение.

height_modifier = 0


# draw = ImageDraw.Draw(image) #Создаем инструмент для рисования.

def update_light(component, modifier):
    return component + modifier


# ЛИНЕЙНЫЕ ФИЛЬТРЫ

# Константное преобразование
def constant(pixel):
    r, g, b = pixel
    return r, g, b


# Выделение красной компоненты
def only_red(pixel):
    r, g, b = pixel
    return r, 0, 0


# Выделение зеленой компоненты
def only_green(pixel):
    r, g, b = pixel
    return 0, g, 0


# Выделение синей компоненты
def only_blue(pixel):
    r, g, b = pixel
    return 0, 0, b


# Оттенки серого
def grey_shadows(pixel):
    r, g, b = pixel
    return r, r, r


# Сепия
def sepia(pixel):
    k = 20
    r, g, b = pixel
    middle = (r + g + b) / 3
    r, g, b = middle + 2 * k, middle + k, middle
    return int(r), int(g), int(b)


# Сепия с зеленым оттенком
def custom_sepia(pixel):
    k = 20
    r, g, b = pixel
    middle = (r + g + b) / 3
    r, g, b = middle + 2 * k, middle + k, middle
    return int(r), int(g) + 50, int(b)


# Негатив
def negative(pixel):
    r, g, b = pixel
    return 255 - r, 255 - g, 255 - b


# Добавление шума в диапазоне [-factor; factor]
def noise(pixel, factor=80):
    r, g, b = pixel
    random_value = random.randint(-factor, factor)
    return r + random_value, g + random_value, b + random_value


# Увеличение яркости на modifier
def high_light(pixel, modifier=50):
    return tuple(map(lambda component: update_light(component, modifier), pixel))


# Уменьшение яркости на modifier
def low_light(pixel, modifier=50):
    return tuple(map(lambda component: update_light(component, -modifier), pixel))


# Черно-белый
def black_and_white(pixel):
    middle_value = sum(pixel)

    if middle_value <= (256 // 2) * 3:
        return 0, 0, 0
    else:
        return 256, 256, 256


# Свой линейный фильтр
# Повышен зеленый канал
def custom_linear_filter(pixel):
    r, g, b = pixel
    return r, g + 50, b


# Список преобразований
linear_transformations = [constant,
                          only_red, only_green, only_blue,
                          grey_shadows, sepia, negative, custom_sepia, noise, high_light, low_light, black_and_white,
                          custom_linear_filter]

# Последовательное применение всех преобразований с сохранением результата.
for transformation in linear_transformations:
    image = original_image.copy()  # Создаем новое изображение, чтобы не испортить оригинальное.
    width = image.size[0]  # Определяем ширину.
    height = image.size[1]  # Определяем высоту.
    pixels = image.load()  # Выгружаем значения пикселей.

    # Перебираем каждый пиксель
    for i in range(width):
        for j in range(height):
            pixels[i, j] = transformation(pixels[i, j])  # Применяем текущее преобразование.

    image.save(IMAGE_PATH + IMAGE_NAME + "_" + transformation.__name__ + "." + IMAGE_TYPE)  # Сохранение картинки.


# МАТРИЧНЫЕ ФИЛЬТРЫ

# Константная матрица 3x3.
def const():
    return [[0, 0, 0], [0, 1, 0], [0, 0, 0]]


# Размытие по Гауссу
def blur():
    return [
        [0.00000067, 0.00002292, 0.00019117, 0.00038771, 0.00019117, 0.00002292, 0.00000067],
        [0.00002292, 0.00078634, 0.00655965, 0.01330373, 0.00655965, 0.00078633, 0.00002292],
        [0.00019117, 0.00655965, 0.05472157, 0.11098164, 0.05472157, 0.00655965, 0.00019117],
        [0.00038771, 0.01330373, 0.11098164, 0.22508352, 0.11098164, 0.01330373, 0.00038771],
        [0.00019117, 0.00655965, 0.05472157, 0.11098164, 0.05472157, 0.00655965, 0.00019117],
        [0.00002292, 0.00078634, 0.00655965, 0.01330373, 0.00655965, 0.00078633, 0.00002292],
        [0.00000067, 0.00002292, 0.00019117, 0.00038771, 0.00019117, 0.00002292, 0.00000067],
    ]


# Резкость
def sharpen():
    return [
        [-1, -1, -1],
        [-1, 9, -1],
        [-1, -1, -1]
    ]


# Свой матричный фильтр
# Матричное размытие
def custom_matrix_filter():
    return [
        [-27, -18, -9, -18, -27],
        [-18, -9, 1, -9, -18],
        [-9, 1, -9, 1, -9],
        [-18, -9, 1, -9, -18],
        [-27, -18, -9, -18, -27]
    ]


matrix_filters = [const, blur, sharpen, custom_matrix_filter]


def matrix_transformation(old_pixels, width, height, x, y, get_matrix):
    matrix = get_matrix()
    n = len(matrix)  # Узнаем размерность матрицы.
    new_color = [0, 0, 0]
    matrix_sum = 0  # Посчитаем сумму в матрице преобразования для того, чтобы потом поделить на это значение.
    # Таким образом интенсивность изображения не измениться.
    # Перебираем соседей
    for i in range(n):
        for j in range(n):
            new_x = x - n // 2 + i  # Вычисляем координату соседа, с учетом того, что "мы" в центре матрицы.
            new_y = y - n // 2 + j

            # Проверяем соседа на существование.
            if 0 <= new_x < width and 0 <= new_y < height:
                matrix_sum += matrix[i][j]
                # Перебираем цветовую компоненту.
                for c in range(3):
                    new_color[c] += old_pixels[new_x, new_y][c] * matrix[i][
                        j]  # Добавляем цвет соседа умноженный на коэффициент из матрицы.

    for c in range(3):
        if matrix_sum != 0:
            new_color[c] /= matrix_sum  # Нормируем цвет.
        else:
            new_color[c] = 0
    return int(new_color[0]), int(new_color[1]), int(new_color[2])


for matrix in matrix_filters:
    image = original_image.copy()  # Создаем новое изображение, чтобы не испортить оригинальное.
    width, height = image.size  # Определяем ширину и высоту
    pixels = image.load()  # Выгружаем значения пикселей.
    old_pixels = original_image.load()  # Выгружаем значения пикселей оригинального изображения.

    # Перебираем каждый пиксель
    for i in range(width):
        for j in range(height):
            pixels[i, j] = matrix_transformation(old_pixels, width, height, i, j,
                                                 matrix)  # Применяем текущее преобразование.

    image.save(IMAGE_PATH + IMAGE_NAME + "_matrix_" + matrix.__name__ + "." + IMAGE_TYPE)  # Сохранение картинки.
