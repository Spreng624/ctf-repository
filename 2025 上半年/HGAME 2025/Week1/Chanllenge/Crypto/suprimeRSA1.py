from Crypto.Util.number import *
import random

FLAG = b"hgame{xxxxxxxxxxxxxxxxx}"
e = 0x10001


# trick
def factorial(num):
    result = 1
    for i in range(1, num + 1):
        result *= i
    return result


a = 2
b = 2
assert factorial(a) + factorial(b) == a**b
M = (a + b) << 128


def gen_key():
    while True:
        k = getPrime(29)
        a = getPrime(random.randint(20, 62))
        p = k * M + pow(e, a, M)
        if isPrime(p):
            return p


p, q = gen_key(), gen_key()
n = p * q
m = bytes_to_long(FLAG)
enc = pow(m, e, n)

print(f"{n=}")
print(f"{enc=}")

"""
n=669040758304155675570167824759691921106935750270765997139446851830489844731373721233290816258049
enc=487207283176018824965268172307888245763817583875071008869370172565777230514379236733742846575849
"""
