from Crypto.Cipher import AES
from hashlib import md5
import numpy as np

mask = (17021818741783351666, 12005190714466672542)
mask1, mask2 = mask
output = 17293857204223553536
print("output:", bin(output)[2:])
print("mask1:", bin(mask1)[2:])
print("mask2:", bin(mask2)[2:])
enc = b"\xc4\xc0\xf2\xe6\x15\x0c\xaf\xd1\x0f\xab\x1abF\x16W\xbcA/&2\x10M\xdc\x1c2\x83b\xf7K\x97\xf9\xc5\xe6ku\xc8\xb0\x8d\xbcT:@xN\x1d=\x13)"

mask1 = [int(i) for i in bin(mask1)[2:]]
mask2 = [int(i) for i in bin(mask2)[2:]]
output = [int(i) for i in bin(output)[2:]]
# print(mask1, mask2)


def reState(current: list[64]):
    l = current[-1]
    for i in range(63):
        l ^= mask[i + 1] & current[i]
    current = [l] + current[:-1]
    return current


def cut(s: list):
    s_out = []
    p = -1
    for i in range(len(s)):
        if i == 0:
            s_out = [1]
        else:
            if s[i] == 1:
                p += 1
                s_out.append(s[p])
            elif s[i] == 0:
                s_out.append(s[p])
    s_out = "".join(str(i) for i in s_out)
    if s_out == Result[0 : len(s)]:
        return True
    else:
        return False


def check(current: list[64]):
    global Count
    Count += 1
    seed = current.copy()
    for _ in range(64):
        seed = reState(seed)
    seed = int("".join(str(i) for i in seed), 2)

    m = AES.new(key=md5(str(seed).encode()).digest(), mode=AES.MODE_ECB).decrypt(enc)
    if m.isascii():
        print(m)
        exit()


def dfs(position):
    if position == 64:
        if cut(current):
            check(current)
        return

    current.append(0)
    if cut(current):
        dfs(position + 1)
    current.pop()

    current.append(1)
    if cut(current):
        dfs(position + 1)
    current.pop()


# current = []
# dfs(len(current))
M = np.zeros((64, 64), dtype=np.uint8)
for i in range(64):
    for j in range(i, 64):
        M[i][j] = mask1[j - i]

M0 = np.zeros((64, 64), dtype=np.uint8)
for i in range(64):
    M0[i][i] = 1
    for j in range(i):
        M0[i][j] = mask2[j - i + 64]

np.set_printoptions(linewidth=100, precision=1, suppress=True, edgeitems=10)
print(M)
print(M0)
print(np.linalg.inv(M))
M1 = np.linalg.inv(M)
print(M1)
for i in range(64):
    for j in range(64):
        M1[i][j] = int(M1[i][j]) % 2
print(M1 * M0 == np.eye(64))
# print(M1 == np.eye(64))

# M = np.zeros((64, 64), dtype=np.uint8)
# for i in range(64):
#     for j in range(i, 64):
#         M[i][j] = mask1[j - i]

# M0 = np.zeros((64, 64), dtype=np.uint8)
# for i in range(64):
#     M0[i][i] = 1
#     for j in range(i):
#         M0[i][j] = mask2[j - i]

# print(M)
# print(M0)
# M1 = np.linalg.inv(M) * M0
# for i in range(64):
#     for j in range(64):
#         M1[i][j] = int(M1[i][j]) % 2
# # np.set_printoptions(threshold=np.inf)
# print(M1 == np.eye(64))
