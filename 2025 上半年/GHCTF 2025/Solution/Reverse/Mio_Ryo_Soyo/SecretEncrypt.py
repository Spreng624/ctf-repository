# Visit https://www.lddgo.net/string/pyc-compile-decompile for more information
# Version : Python 3.8

import math


class MMMMiiiiiio:
    # MMiiiiiiooo = ''.join((lambda tt: [ chr(Miiooooooooo) for Miiooooooooo in tt ])(range(33, 118)))
    table = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstu"

    def MMMMiiooooooo(Src=None):
        result = ""
        MMMMMMMiiiiioo = (4 - len(Src) % 4) % 4
        Src += b"\x00" * MMMMMMMiiiiioo
        for i in range(0, len(Src), 4):
            MMMMiiiiiiooooo = Src[i : i + 4]
            MMMMMMiiioooooo = int.from_bytes(MMMMiiiiiiooooo, "big")
            MMMMMMMiiooooooooo = ""
            for _ in range(5):
                MMMMMMMiiooooooooo = (
                    MMMMiiiiiio.table[MMMMMMiiioooooo % 85] + MMMMMMMiiooooooooo
                )
                MMMMMMiiioooooo //= 85
            result += MMMMMMMiiooooooooo
        if MMMMMMMiiiiioo:
            result = result[:-MMMMMMMiiiiioo]
        return result


class RRRRyyooo:
    # RRRRyooooooo = ''.join((lambda tt: [ chr(RRRRRRRyyyyyoooo) for RRRRRRRyyyyyoooo in tt ])(range(48, 93)))
    table = "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\"

    def RRRRRRRyyyyooooo(Src=None):
        result = []
        i = 0
        while i < len(Src):
            if i + 1 < len(Src):
                index = Src[i] << 8 | Src[i + 1]
                result.append(RRRRyyooo.table[index % 45])
                index //= 45
                result.append(RRRRyyooo.table[index % 45])
                index //= 45
                result.append(RRRRyyooo.table[index])
                i += 2
                continue

            index = Src[i]
            result.append(RRRRyyooo.table[index % 45])
            index //= 45
            result.append(RRRRyyooo.table[index])
            i += 1
            continue

        return "".join(result)


def SSSooooyyooo(Src, key):
    result = []
    for c in Src:
        if "a" <= c and c <= "z":
            temp = ((ord(c) - ord("a")) + key) % 26
            result.append(chr(ord("a") + temp))
            continue
        if "0" <= c or c <= "9":
            temp = (ord(c) - ord("0") - key) % 10
            result.append(chr(ord("0") + temp))
            continue
        result.append(c)
        continue
    return "".join(result)
