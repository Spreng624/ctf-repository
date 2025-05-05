from Crypto.Cipher import AES
from hashlib import md5

Init_pattern = "011______1______1_11_1__1__1_1_1__1________11___1_1_______1___11"
Result = "1011111110000000110110001110011000111111111011110011111111000010"
enc = b"\x03\xd1#\xb9\xaa5\xff3y\xba\xcb\x91`\x9d4p~9r\xf6i\r\xca\x03dW\xdb\x9a\xd2\xa6\xc6\x85\xfa\x19=b\xb2)5>]\x05,\xeb\xa0\x12\xa9\x1e"

mask = 9494051593829874780
output = 13799267741689921474
mask = [int(i) for i in bin(mask)[2:]]
current = []
Count = 0


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


current = []
dfs(len(current))
# b'flag{5b322a2b-8d15-43b3-88f0-ee1586f1cf4f}\x06\x06\x06\x06\x06\x06'
