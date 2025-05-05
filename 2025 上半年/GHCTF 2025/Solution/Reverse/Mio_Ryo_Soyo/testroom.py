def SSSooooyyooo(Src, key):
    result = []
    for c in Src:
        if "a" <= c and c <= "z":
            temp = ((ord(c) - ord("a")) + key) % 26
            result.append(chr(ord("a") + temp))
            continue
        if "0" <= c and c <= "9":
            temp = (ord(c) - ord("0") - key) % 10
            result.append(chr(ord("0") + temp))
            continue
        result.append(c)
        continue
    return "".join(result)


def de_S(Src, key):
    result = []
    for c in Src:
        if "a" <= c and c <= "z":
            temp = ((ord(c) - ord("a")) - key) % 26
            result.append(chr(ord("a") + temp))
            continue
        if "0" <= c and c <= "9":
            temp = (ord(c) - ord("0") + key) % 10
            result.append(chr(ord("0") + temp))
            continue
        result.append(c)
        continue
    return "".join(result)


s = '9v!rD8us"44_N(1;_U?z6!Mn16"mjz<\\l[=3*>#&4C>zt0L2C3;)z--3Z'
print(s)
s = de_S(s, 9)
print(s)
# 8m!iD7lj"33_N(0;_U?q5!Me05"daq<\c[=2*>#&3C>qk9L1C2;)q--2Z
s = "JX2NG:CM:KJ?S0=:>?NC>K5<V29Z5<Y:9C=;LA1RQ9G:7"
print(s)
s = de_S(s, 7)
print(s)
# JX9NG:CM:KJ?S7=:>?NC>K2<V96Z2<Y:6C=;LA8RQ6G:4
s = "NSSCTF{Th3y'r3_a11_p1aY_Ba5e!}"

# en = SSSooooyyooo("V69TO=D2>O4404>LO=Q0", 9)
# print(en)
# print(de_S(en, 9))
