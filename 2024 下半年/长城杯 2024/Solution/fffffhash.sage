TARGET = 201431453607244229943761366749810895688
h0 = 0x6c62272e07bb014262b821756295c58d
p = 0x0000000001000000000000000000013b
MOD = 2^128

def solve_good(n):
    goods = []
    M = Matrix.column([p^(n - i - 1) for i in range(n)] + [h0 * p^n - TARGET, MOD])
    M = M.augment(identity_matrix(n+1).stack(vector([0] * (n+1))))
    Q = Matrix.diagonal([2^128] + [1] * (n + 1))
    M *= Q
    M = M.LLL()
    M /= Q
    # 筛选符合要求的解
    for r in M:
        if r[0] == 0 and abs(r[-1]) == 1 and all(abs(x) < 256 for x in r):
            r *= r[-1]
            goods.append(r[1:-1])
    return goods

def check_good(n, good):
    inp = []
    h = int(h0)
    for i in range(n):
        h = (h * p + good[i]) % MOD
        x = int(h) ^^ int(h - good[i])
        if x >= 256:
            return
        inp.append(x)
    print(bytes(inp).hex())
    
for n in range(30):
    goods = solve_good(n)
    for good in goods:
        check_good(n, good)
