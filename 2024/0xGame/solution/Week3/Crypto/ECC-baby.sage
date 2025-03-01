from Crypto.Cipher import AES
from hashlib import md5


def MD5(m):
    return md5(str(m).encode()).digest()


p = 4559252311
a = 1750153947
b = 3464736227
E = EllipticCurve(GF(p), [a, b])
G = E(2909007728, 1842489211)
P = E(1923527223, 2181389961)
G_ = E(1349689070, 1217312018)
C = E(662346568, 2640798701)

n = E.order()


def Pohlig_Hellman(n, P, Q):
    factors, exponents = zip(*factor(n))
    primes = [factors[i] ^ exponents[i] for i in range(len(factors))]
    print(primes)
    dlogs = []
    for fac in primes:
        t = int(int(P.order()) // int(fac))
        dlog = discrete_log(t * Q, t * P, operation="+")
        dlogs += [dlog]
        print(
            "factor: " + str(fac) + ", Discrete Log: " + str(dlog)
        )  # calculates discrete logarithm for each prime order
    num2 = crt(dlogs, primes)
    return num2


# key = Pohlig_Hellman(n,G,P)
key = 1670419487
print(f"key={key}")
M = C - G_ * key
print(M[0])


enc = "29bb47e013bd91760b9750f90630d8ef82130596d56121dc101c631dd5d88201a41eb3baa5aa958a6cd082298fc18418"
Cipher = AES.new(MD5(M[0]), AES.MODE_ECB)
flag = Cipher.decrypt(bytes.fromhex(enc))
print(flag.decode())  # 0xGame{0b0e28c2-b36d-d745-c0be-fcf0986f316a}
