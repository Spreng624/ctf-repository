from Crypto.Util.number import *


p = 839252355769732556552066312852886325703283133710701931092148932185749211043
a = 166868889451291853349533652847942310373752202024350091562181659031084638450
b = 168504858955716283284333002385667234985259576554000582655928538041193311381
E = EllipticCurve(GF(p), [a, b])
P = E(
    547842233959736088159936218561804098153493246314301816190854370687622130932,
    259351987899983557442340376413545600148150183183773375317113786808135411950,
    1,
)
Q = E(
    52509027983019069214323702207915994504051708473855890224511139305828303028,
    520507172059483331872189759719244369795616990414416040196069632909579234481,
    1,
)


def SmartAttack(P, Q, p):
    E = P.curve()
    Eqp = EllipticCurve(Qp(p, 2), [ZZ(t) + randint(0, p) * p for t in E.a_invariants()])

    P_Qps = Eqp.lift_x(ZZ(P.xy()[0]), all=True)
    for P_Qp in P_Qps:
        if GF(p)(P_Qp.xy()[1]) == P.xy()[1]:
            break

    Q_Qps = Eqp.lift_x(ZZ(Q.xy()[0]), all=True)
    for Q_Qp in Q_Qps:
        if GF(p)(Q_Qp.xy()[1]) == Q.xy()[1]:
            break

    p_times_P = p * P_Qp
    p_times_Q = p * Q_Qp

    x_P, y_P = p_times_P.xy()
    x_Q, y_Q = p_times_Q.xy()

    phi_P = -(x_P / y_P)
    phi_Q = -(x_Q / y_Q)
    k = phi_Q / phi_P
    return ZZ(k)


k = SmartAttack(P, Q, p)
print(k)  # 7895892011
print(k * P == Q)

n = [1008061, 651602, 943532]
part1 = "".join([hex(i)[2:] for i in n])
part2 = 7895892011
flag = "flag{" + str(part1) + "-" + str(part2) + "}"
print(flag)
# flag{f61bd9f152e65ac-7895892011}
