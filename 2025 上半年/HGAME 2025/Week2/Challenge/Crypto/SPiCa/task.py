from Crypto.Util.number import getPrime, long_to_bytes,bytes_to_long
from secrets import flag
from sage.all import *

def derive_M(n):
    iota=0.035
    Mbits=int(2 * iota * n^2 + n * log(n,2))
    M = random_prime(2^Mbits, proof = False, lbound = 2^(Mbits - 1))
    return Integer(M)

m = bytes_to_long(flag).bit_length()
n = 70
p = derive_M(n)


F = GF(p)
x = random_matrix(F, 1, n)
A = random_matrix(ZZ, n, m, x=0, y=2)
A[randint(0, n-1)] = vector(ZZ, list(bin(bytes_to_long(flag))[2:]))
h = x*A

with open("data.txt", "w") as file:
    file.write(str(m) + "\n")
    file.write(str(p) + "\n")
    for item in h:
        file.write(str(item) + "\n")