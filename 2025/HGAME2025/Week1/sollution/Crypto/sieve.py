from Crypto.Util.number import *
from sympy import nextprime

p = q = nextprime(155763335447735055 << 128)
n = p * q
e = 65537
phi = (p - 1) * q
d = inverse(e, phi)
enc = 2449294097474714136530140099784592732766444481665278038069484466665506153967851063209402336025065476172617376546
m = pow(enc, d, n)
print(long_to_bytes(m))  # b'hgame{sieve_is_n0t_that_HArd}'
