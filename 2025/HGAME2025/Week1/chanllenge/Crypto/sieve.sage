# sage
from Crypto.Util.number import bytes_to_long
from sympy import nextprime

FLAG = b"hgame{xxxxxxxxxxxxxxxxxxxxxx}"
m = bytes_to_long(FLAG)


def trick(k):
    if k > 1:
        mul = prod(range(1, k))
        if k - mul % k - 1 == 0:
            return euler_phi(k) + trick(k - 1) + 1
        else:
            return euler_phi(k) + trick(k - 1)
    else:
        return 1


e = 65537
p = q = nextprime(trick(e ^ 2 // 6) << 128)
n = p * q
enc = pow(m, e, n)
print(f"{enc=}")
# enc=2449294097474714136530140099784592732766444481665278038069484466665506153967851063209402336025065476172617376546
