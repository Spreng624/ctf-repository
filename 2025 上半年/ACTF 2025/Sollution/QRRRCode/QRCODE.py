from pyzbar.pyzbar import decode
from PIL import Image

import string
import random
from hashlib import sha256
import numpy as np

import qrcode


def decode_qr(image):
    decoded = decode(image)
    return decoded[0].data.decode("utf-8") if decoded else ""


def create_image(matrix, module_size=10):
    size = len(matrix) * module_size
    img = Image.new("1", (size, size), 1)
    pixels = img.load()

    for x in range(len(matrix)):
        for y in range(len(matrix[0])):
            if matrix[x][y]:
                for dx in range(module_size):
                    for dy in range(module_size):
                        px = x * module_size + dx
                        py = y * module_size + dy
                        if px < size and py < size:
                            pixels[px, py] = 0
    return img


def generate_qr(word):
    qrs = []
    qr = qrcode.QRCode(
        version=1,
        error_correction=qrcode.constants.ERROR_CORRECT_L,
        box_size=10,
        border=4,
    )
    qr.add_data(word)
    qr.make(fit=True)

    matrix = qr.get_matrix()
    matrix = [[i for i in row[4:25]] for row in matrix[4:25]]
    # print(matrix)
    qrs.append(matrix)

    matrix = [list(row) for row in zip(*matrix[::-1])]
    qrs.append(matrix)

    matrix = [list(row) for row in zip(*matrix[::-1])]
    qrs.append(matrix)

    matrix = [list(row) for row in zip(*matrix[::-1])]
    qrs.append(matrix)

    return qrs


def make_data(front, left, top):
    data = [[[True for _ in range(21)] for _ in range(21)] for _ in range(21)]
    for x in range(21):
        for y in range(21):
            if not front[x][y]:
                for z in range(21):
                    data[x][y][z] = False

    for y in range(21):
        for z in range(21):
            if not left[y][z]:
                for x in range(21):
                    data[x][y][z] = False

    for x in range(21):
        for z in range(21):
            if not top[x][z]:
                for y in range(21):
                    data[x][y][z] = False

    if not check_data(data):
        return None

    for x in range(21):
        for y in range(21):
            for z in range(21):
                if data[x][y][z]:
                    data[x][y][z] = False
                    if not check_data(data):
                        data[x][y][z] = True
        print(x, check_data(data), end="\r")
    print()
    return data


def display(matrix):
    for row in matrix:
        for cell in row:
            print("X" if cell else " ", end="")
        print()


def check_data(data):
    front = [
        [any(data[x][y][z] for z in range(21)) for y in range(21)] for x in range(21)
    ]
    left = [
        [any(data[x][y][z] for x in range(21)) for z in range(21)] for y in range(21)
    ]
    top = [
        [any(data[x][y][z] for y in range(21)) for z in range(21)] for x in range(21)
    ]
    projections = [front, left, top]
    validation = ["Azure", "Assassin", "Alliance"]
    for projection, word in zip(projections, validation):
        content = decode_qr(create_image(projection))
        if content != word:
            return False
    return True


def main():
    for front in generate_qr("Azure"):
        for left in generate_qr("Assassin"):
            for top in generate_qr("Alliance"):
                data = make_data(front, left, top)
                if data is not None:
                    result = ""
                    for z in range(21):
                        for y in range(21):
                            for x in range(21):
                                result += str(int(data[x][y][z]))
                    # print(len(result))
                    print(result)
                    # return result


if __name__ == "__main__":
    main()
