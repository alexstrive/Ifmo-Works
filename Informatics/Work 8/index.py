from math import log

from collections import Counter

from utils import get_fano_dictionary, rgb_to_value, quantum, get_mid_sequence_length, get_haffman_dictionary
from ImageReader import ImageReader
from TaskManager import TaskManager

task_manager = TaskManager()
image_reader = ImageReader()

# Task 1
task_manager.show_title()

pixels = image_reader.read_image()
width, height = image_reader.get_size()

print("Изображение прочтено")

# Task 2
task_manager.show_title()

quantumed_pixels = []
middle_row = height / 2

for current_column in range(width):
    pixel_value = rgb_to_value(pixels[middle_row, current_column])
    quantumed_pixel_value = quantum(pixel_value)
    quantumed_pixels.append(quantumed_pixel_value)

print("Квантование пикселей выполнено")

# Task 3
task_manager.show_title()

counted_quantumed_pixels = Counter(quantumed_pixels)

print(counted_quantumed_pixels)

probabilities = dict.fromkeys(counted_quantumed_pixels.keys(), 0)
for pixel, count in counted_quantumed_pixels.items():
    probabilities[pixel] = count / len(quantumed_pixels)

print(f"Вычислена частота появления каждого символа: {sorted(probabilities.items(), key=lambda probability: probability[1])}")

# Task 4
task_manager.show_title()

entropy_value = 0
alphabet_count = len(counted_quantumed_pixels.keys())

for pixel, probability in probabilities.items():
    entropy_value -= probability * log(probability, 2)

print(f"Текущее число символов: {alphabet_count}")
print(f"Значение энтропии {entropy_value}")

# Task 5
task_manager.show_title()

common_binary_sequence = []
rank = len(bin(max(quantumed_pixels))) - 2

for pixel in quantumed_pixels:
    common_binary_sequence.append("{:0{positions}b}".format(pixel, positions=rank))

print(f"Сформирована равномерный двоичный код: {common_binary_sequence}")

# Task 6
task_manager.show_title()

fano_binary_sequence = []
fano_dictionary = get_fano_dictionary(counted_quantumed_pixels.keys())

for pixel in quantumed_pixels:
    fano_binary_sequence.append(fano_dictionary[pixel])

print(f"Словарь Фано применён к последовательности. Полученная последовательность: {fano_binary_sequence}")

# Task 7
task_manager.show_title()

haffman_binary_sequence = []
haffman_dictionary = get_haffman_dictionary()

for pixel in quantumed_pixels:
    haffman_binary_sequence.append(haffman_dictionary[pixel])

print(f"Словарь Хаффмана применён к последовательности. Полученная последовательность: {haffman_binary_sequence}")

# Task 8
task_manager.show_title()

common_binary_sequence_length = get_mid_sequence_length(common_binary_sequence)
fano_binary_sequence_length = get_mid_sequence_length(fano_binary_sequence)
haffman_binary_sequence_length = get_mid_sequence_length(haffman_binary_sequence)

print(f"Длина двоичной последовательности: {common_binary_sequence_length} символов")
print(f"Длина двоичной последовательности Фано: {fano_binary_sequence_length} символов")
print(f"Длина двоичной последовательности Хаффмана: {haffman_binary_sequence_length} символов")

# Task 9
task_manager.show_title()

fano_compress_rate = (common_binary_sequence_length - fano_binary_sequence_length) / common_binary_sequence_length * 100
haffman_compress_rate = (common_binary_sequence_length - haffman_binary_sequence_length) / common_binary_sequence_length * 100

print(f"Сжатие алгоритмом Фано: {fano_compress_rate}%")
print(f"Сжатие алгоритмом Хаффмана: {haffman_compress_rate}%")

# Task 10
task_manager.show_title()

fano_redundancy = 1 - entropy_value / fano_binary_sequence_length
haffman_redundancy = 1 - entropy_value / haffman_binary_sequence_length

print(f"Избыточность кода Фано: {fano_redundancy}")
print(f"Избыточность кода Хаффмана: {haffman_redundancy}")
