from Crypto.Util.number import *

p = 64141017538026690847507665744072764126523219720088055136531450296140542176327
a = 362
d = 7
e = 0x10001


def add(P, Q):
    (x1, y1) = P
    (x2, y2) = Q

    x3 = (x1 * y2 + y1 * x2) * inverse(1 + d * x1 * x2 * y1 * y2, p) % p
    y3 = (y1 * y2 - a * x1 * x2) * inverse(1 - d * x1 * x2 * y1 * y2, p) % p
    return (x3, y3)


def mul(x, P):
    Q = (0, 1)
    while x > 0:
        if x % 2 == 1:
            Q = add(Q, P)
        P = add(P, P)
        x = x >> 1
    return Q


eG = (
    34120664973166619886120801966861368419497948422807175421202190709822232354059,
    11301243831592615312624457443883283529467532390028216735072818875052648928463,
)

# T -> M
J = 2 * (a + d) / (a - d)
K = 4 / (a - d)

# M -> W
A = (3 - J**2) / (3 * K**2)
B = (2 * J**3 - 9 * J) / (27 * K**3)

E = EllipticCurve(Zmod(p), [0, 0, 0, A, B])
od = E.order()
e_inv = int(pow(e, -1, od))
G = mul(e_inv, eG)

print(long_to_bytes(G[0]))  # b'D0g3xGC{SOlvE_The_Edcurv3}'
