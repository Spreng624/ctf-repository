import base64
import random
import numpy as np


def init_sbox(key):
    s_box = list(range(256))
    j = 0
    for i in range(256):
        j = (j + s_box[i] + ord(key[i % len(key)])) % 256
        s_box[i], s_box[j] = s_box[j], s_box[i]
    return s_box


def decrypt(cipher, box):
    res = []
    i = j = 0
    cipher_bytes = base64.b64decode(cipher)
    for s in cipher_bytes:
        i = (i + 1) % 256
        j = (j + box[i]) % 256
        box[i], box[j] = box[j], box[i]
        t = (box[i] + box[j]) % 256
        k = box[t]
        res.append(chr(s ^ k))
    return "".join(res)


def random_num(seed_num):
    random.seed(seed_num)
    for i in range(36):
        print(chr(int(str(random.random() * 10000)[0:2]) ^ (data[i])), end="")


data = [
    1,
    11,
    116,
    33,
    68,
    32,
    111,
    45,
    19,
    98,
    52,
    32,
    38,
    58,
    113,
    38,
    119,
    7,
    110,
    39,
    60,
    57,
    56,
    26,
    95,
    84,
    91,
    10,
    43,
    41,
    44,
    1,
    118,
    29,
    125,
    41,
]

ciphertext = "MjM184anvdA="
key = "XR4"
box = init_sbox(key)
a = decrypt(ciphertext, box)

print("flag{", end="")
random_num(int(a))
print("}")
