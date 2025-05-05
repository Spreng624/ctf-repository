from Crypto.Util.number import *
from random import randint
from hashlib import md5

R = [10, 29, 83, 227, 506, 1372, 3042, 6163]
A = 1253412688290469788410859162653
B = 16036
M = [10294, 12213, 10071, 4359, 1310, 4376, 7622, 14783]
S_list = [
    13523,
    32682,
    38977,
    44663,
    43353,
    31372,
    17899,
    17899,
    44663,
    16589,
    40304,
    25521,
    31372,
]


def decrypt(c):
    byte = 0
    bit_array = []
    for r in reversed(R):
        if c >= r:
            bit_array.append(1)
            c -= r
        else:
            bit_array.append(0)
    bit_array = bit_array[::-1]
    num = int("".join(str(bit) for bit in bit_array), 2)

    return bytes([num])


A_ = inverse(A, B)
m = b""
for s in S_list:
    m += decrypt((A_ * s) % B)

print(m)

# CRYPTO_ALGORIT
# HMS_WELL_DONE
flag1 = b"CRYPTO_ALGORIT"
flag2 = b"HMS_WELL_DONE"

flag = "flag{" + md5(flag1 + flag2).hexdigest()[::-1] + "}"
print(flag)
# flag{64f67374264b7621650b1de4dbc5f924}
