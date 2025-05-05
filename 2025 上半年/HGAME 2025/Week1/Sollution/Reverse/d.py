from test import get_patch_info
from delta_patch import apply_patch_to_buffer

patch = bytes(
    [
        0x50,
        0x41,
        0x33,
        0x30,
        0xC0,
        0x08,
        0x97,
        0xFC,
        0xFD,
        0x3C,
        0xDA,
        0x01,
        0x18,
        0x23,
        0x68,
        0x83,
        0x04,
        0x80,
        0x52,
        0x00,
        0x6C,
        0x61,
        0x72,
        0x72,
        0x79,
        0x2D,
        0x6B,
        0x69,
        0x6C,
        0x6C,
        0x65,
        0x64,
        0x2D,
        0x74,
        0x68,
        0x69,
        0x73,
        0x21,
        0x21,
        0x21,
        0x01,
        0xCA,
        0x00,
        0xB7,
        0x03,
        0x88,
        0x69,
        0xB3,
        0xFA,
        0xF4,
        0x89,
        0x36,
        0xA5,
        0xDD,
        0x8C,
        0x01,
        0xD1,
        0xDA,
        0x4D,
        0x88,
        0x11,
        0x69,
        0x4C,
        0xBB,
        0x71,
        0x7D,
        0xDA,
        0x75,
        0x6A,
        0x37,
        0x2A,
        0xD2,
        0x88,
        0x11,
        0x91,
        0x22,
        0x4E,
        0x66,
        0xDE,
        0xA0,
        0x31,
        0x3D,
        0x22,
        0xCC,
        0x9B,
        0xD6,
        0xAE,
        0x47,
        0xB4,
        0x39,
        0xB1,
        0x56,
        0x01,
    ]
)

buf = b"amateursCTF{" + b"_" * 41 + b"}"

try:
    out = apply_patch_to_buffer(patch, buf)
    print(out)
except Exception as e:
    print(e)

info = get_patch_info(patch)
hexinfo = []
for x in info:
    try:
        hexinfo.append(hex(x))
    except:
        hexinfo.append(x)

newheader = patch[:14] + b"h\x13\x02" + patch[16 + 4 + 0x14 :]
try:
    out = apply_patch_to_buffer(buf, newheader)
    print(out)
except Exception as e:
    print(e)
# Patch file is invalid
# b'amateursCTF{suff3r_th3_p41n_of_a_m1ll10n_wind0ws_d3v5}'
