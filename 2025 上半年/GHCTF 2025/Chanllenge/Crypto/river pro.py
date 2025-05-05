from Crypto.Util.number import getRandomNBitInteger
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from hashlib import md5
from secret import flag


class 踩踩背:
    def __init__(self, n, seed, mask, lfsr=None):
        self.state = [int(b) for b in f"{seed:0{n}b}"]
        self.mask_bits = [int(b) for b in f"{mask:0{n}b}"]
        self.n = n
        self.lfsr = lfsr

    def update(self):
        s = sum([self.state[i] * self.mask_bits[i] for i in range(self.n)]) & 1
        self.state = self.state[1:] + [s]

    def __call__(self):
        if self.lfsr:
            if self.lfsr():
                self.update()
            return self.state[-1]
        else:
            self.update()
            return self.state[-1]


class 奶龙(踩踩背):
    def __init__(self, n, seed, mask):
        super().__init__(n, seed, mask, lfsr=None)


n = 64
seed, mask1, mask2 = [getRandomNBitInteger(64) for _ in "___"]
lfsr1 = 奶龙(n, seed, mask1)
lfsr2 = 踩踩背(n, seed, mask2, lfsr1)
print(f"mask = {mask1, mask2}")
print(f"output = {sum(lfsr2() << (n - 1 - i) for i in range(n))}")
print(
    f"enc = {AES.new(key=md5(str(seed).encode()).digest(), mode=AES.MODE_ECB).encrypt(pad(flag, 16))}"
)
# mask = (17021818741783351666, 12005190714466672542)
# output = 17293857204223553536
# enc = b'\xc4\xc0\xf2\xe6\x15\x0c\xaf\xd1\x0f\xab\x1abF\x16W\xbcA/&2\x10M\xdc\x1c2\x83b\xf7K\x97\xf9\xc5\xe6ku\xc8\xb0\x8d\xbcT:@xN\x1d=\x13)'
