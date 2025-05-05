from z3 import *

x1, x5 = 3846448765, 0xD085A85201A4
x, y, z = BitVecs("x y z", 32)

solver = Solver()
solver.add(14 * x + 11 * y - z == 0x48FB41DDD)
solver.add(9 * x - 3 * y + 4 * z == 0x2BA692AD7)
solver.add(((z - y) >> 1) + (x ^ 0x87654321) == 3451779756)

if solver.check() == sat:
    model = solver.model()
    x2, x3, x4 = model[x].as_long(), model[y].as_long(), model[z].as_long()
    print(
        "0xGame{%8x-%4s-%4s-%4s-%12x}"
        % (
            x1,
            x2.to_bytes(4, byteorder="little").decode(),
            x3.to_bytes(4, byteorder="little").decode(),
            x4.to_bytes(4, byteorder="little").decode(),
            x5,
        )
    )
