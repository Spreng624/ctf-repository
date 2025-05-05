from Crypto.Util.number import *
from hashlib import md5
from random import randint


def MD5(m):
    return md5(str(m).encode()).hexdigest()


def CRT(a, n):
    N = 1
    for i in range(len(a)):
        N *= n[i]
    x = 0
    for i in range(len(a)):
        m = N // n[i]
        x += a[i] * m * inverse(m, n[i])
    return x % N


def brute_force(M, N):
    M = M % N
    for m in range(2, N):
        if pow(m, 2, N) == M:
            return m


def tonelli_shanks(n, p):
    if pow(n, (p - 1) // 2, p) != 1:
        raise ValueError(f"{n} 不是模 {p} 的平方剩余")

    s = 0
    q = p - 1
    while q % 2 == 0:
        q //= 2
        s += 1

    z = 2
    while pow(z, (p - 1) // 2, p) == 1:
        z += 1

    R = pow(n, (q + 1) // 2, p)
    c = pow(z, q, p)
    t = pow(n, q, p)
    M = s

    while t != 1:
        i = 0
        temp = t
        while temp != 1:
            temp = (temp * temp) % p
            i += 1

        b = pow(c, 1 << (M - i - 1), p)
        R = (R * b) % p
        c = (b * b) % p
        t = (t * c) % p
        M = i

    return R


N = 1022053332886345327
p, q = 970868179, 1052721013
e = 294200073186305890
c = 107033510346108389
phi = (p - 1) * (q - 1)

print(f"gcd(e, phi) = {GCD(e, phi)}")
# gcd(e, phi) = 2

D = inverse(e // 2, phi)
M = pow(c, D, N)
print(f"M = {M}")
# M = 919254629320741497

# m1 = brute_force(M, p)
# m2 = brute_force(M, q)

m1 = tonelli_shanks(M, p)
m2 = tonelli_shanks(M, q)
m = CRT([m1, m2], [p, q])
assert pow(m, e, N) == c
print(f"0xGame{{{MD5(m)}}}")
# 0xGame{3932f6728585abbf751a212f69276d3e}
