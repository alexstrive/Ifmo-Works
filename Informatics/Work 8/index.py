# WARNING! UGLY CODE!

from math import log
from PIL import Image
from collections import Counter

IMAGE_PATH = "./"
IMAGE_NAME = "image"
IMAGE_TYPE = "jpg"


def quantum(pixel_value):
    return round(pixel_value / 20) * 20


def rgb_to_pixel(rgb):
    r, g, b = rgb
    return (r >> 8) + (g >> 8) + b


# Task 1
original_image = Image.open(IMAGE_PATH + IMAGE_NAME + "." + IMAGE_TYPE)
width, height = original_image.size
pixels = original_image.load()

# Task 2
quanted_pixels = []
middle_row = height / 2

for current_column in range(width):
    pixel_value = rgb_to_pixel(pixels[middle_row, current_column])
    quanted_pixel_value = quantum(pixel_value)
    quanted_pixels.append(quanted_pixel_value)

# Task 3
counted_quantumed_pixels = Counter(quanted_pixels)

probabilities = dict.fromkeys(counted_quantumed_pixels.keys(), 0)
for pixel, count in counted_quantumed_pixels.items():
    probabilities[pixel] = count / sum(quanted_pixels)

# Task 4
entropy = 0
alphabet_symbol_count = len(counted_quantumed_pixels.keys())

for pixel, probability in probabilities.items():
    entropy -= probability * log(probability, 2)

# Task 5
# Task 6
fanoCode = []

print(sorted(set(counted_quantumed_pixels.keys())))

for pixel in quanted_pixels:
    if pixel == 40:
        fanoCode.append('0000')
    elif pixel == 60:
        fanoCode.append('0001')
    elif pixel == 80:
        fanoCode.append('0010')
    elif pixel == 100:
        fanoCode.append('0011')
    elif pixel == 120:
        fanoCode.append('010')
    elif pixel == 140:
        fanoCode.append('011')
    elif pixel == 160:
        fanoCode.append('100')
    elif pixel == 200:
        fanoCode.append('101')
    elif pixel == 220:
        fanoCode.append('110')
    elif pixel == 260:
        fanoCode.append('111')

print(fanoCode)
# Task 9
# Task 10