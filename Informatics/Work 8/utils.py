import math

'''Fano Generation'''

fano_dictionary = {
    40: "100",
    60: "111",
    80: "110",
    100: "101",
    120: "011",
    140: "010",
    160: "0000",
    200: "0011",
    220: "0010",
    260: "0001",
}

haffman_dictionary = {
    160: "0000",
    260: "0001",
    220: "0010",
    200: "0011",
    140: "0100",
    120: "0101",
    40: "0110",
    100: "0111",
    80: "10",
    60: "11",
}


def gen_fano_codes(alphabet_count):
    code_length = int(math.ceil(math.log2(alphabet_count)))
    codes = ["{:0{positions}b}".format(symbol, positions=code_length) for symbol in range(2 ** code_length)]
    print("Коды Фано сгенерированы")

    return codes


def get_fano_dictionary(alphabet):
    # fano_codes = gen_fano_codes(len(alphabet))
    # fano_dictionary = dict(zip(alphabet, fano_codes))
    print("Словарь Фано сгенерирован")

    return fano_dictionary


'''Haffman Generation'''

prob = [(160, 9.45179584120983e-05), (260, 9.45179584120983e-05), (220, 0.0001890359168241966),
        (200, 0.0001890359168241966), (140, 0.0001890359168241966), (120, 0.0001890359168241966),
        (40, 0.0001890359168241966), (100, 0.0023629489603024575), (80, 0.0035916824196597355),
        (60, 0.00500945179584121)]


def get_haffman_dictionary():
    return haffman_dictionary


# for pr in prob:

'''Pixel Functions'''


def quantum(value):
    return round(value / 20) * 20


def rgb_to_value(rgb):
    r, g, b = rgb
    return (r >> 8) + (g >> 8) + b


'''Sequence Functions'''


def get_mid_sequence_length(sequence):
    # total_length = 0
    #
    # for element in sequence:
    #     print(element)
    #     total_length += len(element)

    return math.trunc(sum(map(len, sequence)) / len(sequence))
