class Round:
    def __init__(self):
        super().__init__()

    def shl(self, p0, p1):
        p0 = (p0 >> 3) % 1024
        return Round.Result(p0, ((p1 + p0) % 1024))

    def shr(self, p0, p1):
        p0 = (p0 << 3) % 1024
        return Round.Result(p0, ((p1 + p0) % 1024))

    def add(self, p0, p1, p2):
        p1 = (p1 + p0[p2]) % 1024
        return Round.Result(p1, (p2 + p1) % 1024)

    def sub(self, p0, p1, p2):
        p1 = (((p1 - p0[p2]) % 1024) + 1024) % 1024
        return Round.Result(p1, (p2 + p1) % 1024)

    def xor(self, p0, p1, p2):
        i = (p0[p2] ^ p1) % 1024
        return Round.Result(i, (p2 + i) % 1024)

    def round(self, p0, p1):
        assert len(p1) == 12
        result = None
        ointArray = [0] * 12
        i2 = 33
        for i in range(12):
            c = ord(p1[i])
            for _ in range(32):
                match (p0[i2] ^ c) % 5:
                    case 0:
                        result = self.add(p0, c, i2)
                    case 1:
                        result = self.sub(p0, c, i2)
                    case 2:
                        result = self.xor(p0, c, i2)
                    case 3:
                        result = self.shl(c, i2)
                    case 4:
                        result = self.shr(c, i2)
                    case _:
                        Round.Result(c, i2)
                c = result.getNum()
                i2 = result.getRip()
            ointArray[i] = c
        return ointArray

    class Result:
        def __init__(self, num, rip):
            self.num = num
            self.rip = rip

        def getNum(self):
            return self.num

        def getRip(self):
            return self.rip


def Makebox(p0):
    ointArray = [0] * 1024
    for i in range(1024):
        i2 = 1023 - i
        ointArray[i2] = i
    for i in range(1024):
        ointArray[i] ^= ord(p0[i % len(p0)])
    return ointArray


passwords = []
encoded_box = Makebox("c9m1bRmfY5Wk")


def dfs(password, i):
    ointArray1 = [352, 646, 752, 882, ord("A"), 0, ord("z"), 0, 0, 7, 350, 360]
    if i == 12:
        passwords.append(password)
        return

    for p in "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_":
        password += p
        result = Round().round(encoded_box, password + "0" * (11 - i))
        if result[i] == ointArray1[i]:
            dfs(password, i + 1)
        password = password[:-1]
    return False


dfs("", 0)
print(passwords)
for password in passwords:
    print(f"D0g3xGC{{round_and{password}}}")
# ['_rounD_we_go']
# D0g3xGC{round_and_rounD_we_go}
