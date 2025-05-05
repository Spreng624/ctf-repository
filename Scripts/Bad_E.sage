from Crypto.Util.number import *
import time


def AMM(delta: int, r: int, q:int, all: bool = False):
    """
    使用AMM算法，在有限域F_q上求解r次根。

    参数:
        delta (int): 待开根数
        r (int): 开根的次数，要满足r能整除q
        q (int): 模数，为质数
        all (int): 是否返回所有解，默认为False，返回一个根。
    """
    if pow(delta, (q - 1) // gcd(q - 1, r), q) != 1:
        raise Exception(f"{delta}不是{r}次剩余")
        
    if (q - 1) % r != 0:
        raise Exception("使用AMM算法需要满足r整除(q-1)")

    # Step 1: Choose ρ uniformly at random from F_q^*
    F = GF(q)
    delta = F(delta)
    rho = F.random_element()

    # Step 2: Check if ρ^((q-1)/r) ≠ 1
    while rho ** ((q-1) // r) == F(1):
        rho = F.random_element()

    # Step 3: Compute t and s such that q-1 = r^t * s
    t = 0
    s = q - 1
    while s % r == 0:
        s = s // r
        t += 1

    # Compute α such that s | rα - 1
    print(r, s)
    alpha = inverse_mod(r, s)

    # Compute a, b, c, h
    a = rho ** (r ** (t-1) * s)
    b = delta ** (r*alpha - 1)
    c = rho ** s
    h = F(1)

    # Step 4: For i = 1 to t-1
    for i in range(1, t):
        # Compute d = b^r^(t-1-i)
        d = b**(r**(t-1 - i))

        if d == F(1):
            j = 0
        else:
            # Compute j = -log_a(d)
            j = -discrete_log(d, a)

        # Update b and h
        b = b * (c**r)**j
        h = h * c**j
        c = c**r

    # Step 5: Return δ^α * h
    root = int((delta ** alpha) * h)
    
    if not all:
        return root
    
    roots = [int(root)]
    while len(roots) < r:
        a = randint(2, q - 1)
        res = pow(a, (q - 1) // r, q) * root % q
        if res not in roots:
            roots.append(int(res))
    return roots

def quick_rooting(n: int, r: int, p: int, all: bool = False):
    """
    在特定条件下，快速求解有限域下的n次方根
    
    参数:
        delta (int): 待开根数
        r (int): 开根的次数，要满足r能整除q
        q (int): 模数，为质数
        all (int): 是否返回所有解，默认为False，返回一个根。
    """
    if pow(n, (p - 1) // gcd(p - 1, r), p) != 1:
        raise Exception(f"{n}不是{r}次剩余")
        
    if (p + r - 1) % (r ** 2) != 0:
        raise Exception("快速开根需要满足r^2整除p+r-1")
    
    root = pow(n, (p+r-1)//(r**2), p)
    
    if not all:
        return root
    
    roots = [int(root)]
    while len(roots) < r:
        a = randint(2, p - 1)
        res = pow(a, (p - 1) // r, p) * root % p
        if res not in roots:
            roots.append(int(res))
    return roots
    

def rooting(c, e, p):
    # 将e约简到可逆，e_为余下的因数。
    e_ = 1
    while GCD(e, (p - 1)) != 1:
        e_ *= GCD(e, (p - 1))
        e //= GCD(e, (p - 1))
    
    d = inverse(e, p-1)
    c = pow(c, d, p)
    
    # 分解e_，简化计算
    expanded_factors = []
    for prime, exponent in factor(e_):
        expanded_factors.extend([prime] * exponent)
    
    cs = [c]
    ms = []
    for r in expanded_factors:
        ms = []
        for c in cs:
            # 检查c是否为r次剩余
            if pow(c, (p - 1) // gcd(p - 1, r), p) == 1:
                if (p+r-1)%(r**2) == 0:
                    ms += quick_rooting(c, r, p, True)
                else:
                    ms += AMM(c, r, p, True)
        cs = ms
            
    return sorted(ms)

p = 
q = 
n = 
c = 
e = 

res1 = rooting(c, e, p)
res2 = rooting(c, e, q)
for i in res1:
    for j in res2:
        m = crt([i, j], [p, q])
        try:
            print(long_to_bytes(m).decode())
        except:
            pass

