from Crypto.Util.number import *
from sympy import prime
import random


def primorial(num):
    result = 1
    for i in range(1, num + 1):
        result *= prime(i)
    return result


def bit_length(n):
    return len(bin(n)) - 2


n = 787190064146025392337631797277972559696758830083248285626115725258876808514690830730702705056550628756290183000265129340257928314614351263713241
enc = 365164788284364079752299551355267634718233656769290285760796137651769990253028664857272749598268110892426683253579840758552222893644373690398408
# print(bit_length(n))
# M = primorial(39)
# print(M)
# print(bit_length(M))
# M = primorial(71)
# print(bit_length(M))
# M = primorial(126)
# print(bit_length(M))

e = 0x10001
M = 2**130
p = 796688410951167236263039235508020180383351898113
q = 839777194079410698093279448382785381699926556673
k1 = p // M
k2 = q // M
n1 = p % M
n2 = q % M

print(p // M)
print(q // M)
print(p % M)
print(q % M)

print(bit_length(p))
print(bit_length(q))
print(bit_length(p // M))
print(bit_length(q // M))
print(bit_length(p % M))
print(bit_length(q % M))

n = p * q
print(n // (M**2))
print(n % (M**2))
print(n // M)
print(n % M)

print(k1 * k2)
print(k1 * n2 + k2 * n1)
print(n1 * n2 % M)
