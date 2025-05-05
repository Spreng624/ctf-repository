from Crypto.Util.number import *
from Crypto.Cipher import AES
import hashlib

p = 55099055368053948610276786301
G = (19663446762962927633037926740, 35074412430915656071777015320)
Q = (26805137673536635825884330180, 26376833112609309475951186883)
x1, y1 = G
x2, y2 = Q

a = (
    (y1 * y2 * (y2**2 * x1 - y1**2 * x2) + (x1 * y1 - x2 * y2))
    * inverse(x1 * x2 * (x1**2 * y2 - y1 * x2**2), p)
    % p
)
d = (a * G[0] ** 3 + G[1] ** 3 + 1) % p * inverse(G[0] * G[1], p) % p

ciphertext = b"k\xe8\xbe\x94\x9e\xfc\xe2\x9e\x97\xe5\xf3\x04'\x8f\xb2\x01T\x06\x88\x04\xeb3Jl\xdd Pk$\x00:\xf5"

R.<x,y,z> = Zmod(p)[]
cubic = a * x^3 + y^3 + z^3 - d*x*y*z
E = EllipticCurve_from_cubic(cubic,morphism=True)
G = E(G)
Q = E(Q)
E_ord = G.order()

def Pohlig_Hellman(n,P,Q):
    factors, exponents = zip(*factor(n))
    primes = [factors[i] ^ exponents[i] for i in range(len(factors))]
    print(primes)
    dlogs = []
    for fac in primes:
        t = int(int(P.order()) // int(fac))
        dlog = discrete_log(t*Q,t*P,operation="+")
        dlogs += [dlog]
        print("factor: "+str(fac)+", Discrete Log: "+str(dlog)) #calculates discrete logarithm for each prime order
    num2 = crt(dlogs,primes)
    return num2

x = Pohlig_Hellman(E_ord,G,Q)
print(f"x={x}")
# x=2633177798829352921583206736

key = hashlib.sha256(str(x).encode()).digest()
cipher = AES.new(key, AES.MODE_ECB)
flag = cipher.decrypt(ciphertext)
print(f"flag={flag}")
# flag=b'hgame{N0th1ng_bu7_up_Up_UP!}\x04\x04\x04\x04'