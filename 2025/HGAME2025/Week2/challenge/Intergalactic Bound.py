from Crypto.Util.number import *
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from random import randint
import hashlib


def add_THCurve(P, Q):
    if P == (0, 0):
        return Q
    if Q == (0, 0):
        return P
    x1, y1 = P
    x2, y2 = Q
    x3 = (x1 - y1**2 * x2 * y2) * pow(a * x1 * y1 * x2**2 - y2, -1, p) % p
    y3 = (y1 * y2**2 - a * x1**2 * x2) * pow(a * x1 * y1 * x2**2 - y2, -1, p) % p
    return x3, y3


def mul_THCurve(n, P):
    R = (0, 0)
    while n > 0:
        if n % 2 == 1:
            R = add_THCurve(R, P)
        P = add_THCurve(P, P)
        n = n // 2
    return R


flag = b"hgame{SPiCa_is_a_good_name_for_a_crypto_algorithm}"
p = getPrime(96)
a = randint(1, p)
G = (randint(1, p), randint(1, p))
d = (a * G[0] ** 3 + G[1] ** 3 + 1) % p * inverse(G[0] * G[1], p) % p
x = randint(1, p)
Q = mul_THCurve(x, G)
print(f"p = {p}")
print(f"G = {G}")
print(f"Q = {Q}")

key = hashlib.sha256(str(x).encode()).digest()
cipher = AES.new(key, AES.MODE_ECB)
flag = pad(flag, 16)
ciphertext = cipher.encrypt(flag)
print(f"ciphertext={ciphertext}")
print(f"x = {x}, a = {a}, d = {d}")

"""
p = 55099055368053948610276786301
G = (19663446762962927633037926740, 35074412430915656071777015320)
Q = (26805137673536635825884330180, 26376833112609309475951186883)
ciphertext=b"k\xe8\xbe\x94\x9e\xfc\xe2\x9e\x97\xe5\xf3\x04'\x8f\xb2\x01T\x06\x88\x04\xeb3Jl\xdd Pk$\x00:\xf5"
"""
