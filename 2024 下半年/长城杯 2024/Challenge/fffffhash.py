import os
from Crypto.Util.number import *


def giaogiao(hex_string):
    base_num = 0x6C62272E07BB014262B821756295C58D
    x = 0x0000000001000000000000000000013B
    MOD = 2**128
    for i in hex_string:
        base_num = (base_num * x) & (MOD - 1)
        base_num ^= i
    return base_num


giao = 201431453607244229943761366749810895688

print("1geiwoligiaogiao")
hex_string = int(input(), 16)
s = long_to_bytes(hex_string)

if giaogiao(s) == giao:
    # print(os.getenv('FLAG'))
    print("flag{2e8fea93-5434-49e0-bb74-853d2049b724}")
else:
    print("error")
