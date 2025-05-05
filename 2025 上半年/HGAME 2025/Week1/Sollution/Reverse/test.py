from ctypes import windll, wintypes, c_uint64, cast, POINTER, byref, c_size_t
import zlib

# 定义类型
DELTA_FLAG_TYPE = c_uint64
DELTA_FLAG_NONE = 0x00000000
DELTA_APPLY_FLAG_ALLOW_PA19 = 0x00000001


# 定义 DELTA_INPUT 结构
class DELTA_INPUT(wintypes.Structure):
    class U1(wintypes.Union):
        _fields_ = [("lpcStart", wintypes.LPVOID), ("lpStart", wintypes.LPVOID)]

    _anonymous_ = ("u1",)
    _fields_ = [("u1", U1), ("uSize", c_size_t), ("Editable", wintypes.BOOL)]


# 定义 DELTA_OUTPUT 结构
class DELTA_OUTPUT(wintypes.Structure):
    _fields_ = [("lpStart", wintypes.LPVOID), ("uSize", c_size_t)]


# 加载 msdelta.dll
msdelta = windll.msdelta
ApplyDeltaB = msdelta.ApplyDeltaB
ApplyDeltaB.argtypes = [
    DELTA_FLAG_TYPE,
    DELTA_INPUT,
    DELTA_INPUT,
    POINTER(DELTA_OUTPUT),
]
ApplyDeltaB.restype = wintypes.BOOL


# 示例调用
def apply_patch(source_data, delta_data, legacy=False):
    # 初始化结构
    source = DELTA_INPUT()
    delta = DELTA_INPUT()
    output = DELTA_OUTPUT()

    # 设置源数据
    source.lpStart = cast(source_data, wintypes.LPVOID)
    source.uSize = len(source_data)
    source.Editable = False

    # 设置增量数据
    delta.lpStart = cast(delta_data, wintypes.LPVOID)
    delta.uSize = len(delta_data)
    delta.Editable = False

    # 设置标志
    apply_flags = DELTA_APPLY_FLAG_ALLOW_PA19 if legacy else DELTA_FLAG_NONE

    # 调用 ApplyDeltaB
    result = ApplyDeltaB(apply_flags, source, delta, byref(output))
    if not result:
        raise Exception(
            f"ApplyDeltaB failed with error {windll.kernel32.GetLastError()}"
        )

    return output.lpStart, output.uSize
