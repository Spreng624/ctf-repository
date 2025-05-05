from Crypto.Util.number import *
from hashlib import md5
import itertools


def MD5(m):
    return md5(str(m).encode()).hexdigest()

def small_roots(f, bounds, m=1, d=None):
    if not d:
        d = f.degree()
    R = f.base_ring()
    N = R.cardinality()
    f /= f.coefficients().pop(0)
    f = f.change_ring(ZZ)
    G = Sequence([], f.parent())
    for i in range(m+1):
        base = N^(m-i) * f^i
        for shifts in itertools.product(range(d), repeat=f.nvariables()):
            g = base * prod(map(power, f.variables(), shifts))
            G.append(g)
    B, monomials = G.coefficient_matrix()
    monomials = vector(monomials)
    factors = [monomial(*bounds) for monomial in monomials]
    for i, factor in enumerate(factors):
        B.rescale_col(i, factor)
    B = B.dense_matrix().LLL()
    B = B.change_ring(QQ)
    for i, factor in enumerate(factors):
        B.rescale_col(i, 1/factor)
    H = Sequence([], f.parent().change_ring(QQ))
    for h in filter(None, B*monomials):
        H.append(h)
        I = H.ideal()
        if I.dimension() == -1:
            H.pop()
        elif I.dimension() == 0:
            roots = []
            for root in I.variety(ring=ZZ):
                root = tuple(R(root[var]) for var in f.variables())
                roots.append(root)
            return roots
    return []

n = 181261975027495237253637490821967974838107429001673555664278471721008386281743
a = 80470362380817459255864867107210711412685230469402969278321951982944620399953
b = 108319759370236783814626433000766721111334570586873607708322790512240104190351
h = [
    2466192191260213775762623965067957944241015,
    1889892785439654571742121335995798632991977,
    1996504406563642240453971359031130059982231,
    1368301121255830077201589128570528735229741,
    3999315855035985269059282518365581428161659,
    3490328920889554119780944952082309497051942,
    2702734706305439681672702336041879391921064,
    2326204581109089646336478471073693577206507,
    3428994964289708222751294105726231092393919,
    1323508022833004639996954642684521266184999,
    2208533770063829989401955757064784165178629,
    1477750588164311737782430929424416735436445,
    973459098712495505430270020597437829126313,
    1849038140302190287389664531813595944725351,
    1172797063262026799163573955315738964605214,
    1754102136634863587048191504998276360927339,
    113488301052880487370840486361933702579704,
    2862768938858887304461616362462448055940670,
    3625957906056311712594439963134739423933712,
    3922085695888226389856345959634471608310638,
]

h = [i<<115 for i in h]
length = len(h) - 1

M = Matrix(ZZ, length+2, length+2)

for i in range(length):
    M[i, i] = n
    M[-2, i] = pow(a, i+1, n)
    M[-1, i] = ((pow(a, i+1, n) - 1) * inverse_mod(a-1, n) * b + pow(a, i+1, n)*h[0] - h[i+1]) % n
M[-2, -2] = 1
M[-1, -1] = 2^115

for line in M.LLL():
    if abs(line[-1]) == K:
        seed = inverse_mod(a, n) * (h[0] + abs(line[-2]) - b) % n
        print(f"seed = {seed}")  # 101639613050544872292192629515273562035022699788445344858455157668840828973361
        print(f"0xGame{{{MD5(seed)}}}")  # 0xGame{459049e068d93f6d70f1ea0da705264a}
        

PR.<x,y> = PolynomialRing(Zmod(n))
f = (h[0] + x) * a + b - (h[1] + y)
roots = small_roots(f,(2^115, 2^115), m=4, d=4)
print(roots)
s1 = (h[0]<<115) + roots[0][0]
seed = (s1 - b) * inverse_mod(a, n) % n
print(f"seed = {seed}")  # 101639613050544872292192629515273562035022699788445344858455157668840828973361
print(f"0xGame{{{MD5(seed)}}}")  # 0xGame{459049e068d93f6d70f1ea0da705264a}