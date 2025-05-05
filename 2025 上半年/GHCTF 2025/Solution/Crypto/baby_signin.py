from Crypto.Util.number import *
from sympy.ntheory.residue_ntheory import sqrt_mod
from sympy.ntheory.modular import crt

p = 182756071972245688517047475576147877841
q = 305364532854935080710443995362714630091
c = 14745090428909283741632702934793176175157287000845660394920203837824364163635
n = 55807222544207698804941555841826949089076269327839468775219849408812970713531
e = 4
n = p * q
phi = (p - 1) * (q - 1)
M4 = c

for M2_p in sqrt_mod(M4, p, all_roots=True):
    for m1 in sqrt_mod(M2_p, p, all_roots=True):
        for M2_q in sqrt_mod(M4, q, all_roots=True):
            for m2 in sqrt_mod(M2_q, q, all_roots=True):
                m = crt([p, q], [m1, m2])[0]
                m = long_to_bytes(m)
                if m.startswith(b"NSSCTF{"):
                    print(m)
# b'NSSCTF{4MM_1s_so_e4s7!}'
