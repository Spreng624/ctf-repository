# hgame2025 WriteUp

## Crypto

### Ancient Recall

一个模拟塔罗牌占卜的程序，VALUE经过了250次Fortune_wheel得到final_Value，把Fortune_wheel逆向就好了。

```python
def Reverse_wheel(FATE):
    FATEd = [
        (FATE[0] - FATE[1] + FATE[2] - FATE[3] + FATE[4]) // 2,
        (FATE[0] + FATE[1] - FATE[2] + FATE[3] - FATE[4]) // 2,
        (-FATE[0] + FATE[1] + FATE[2] - FATE[3] + FATE[4]) // 2,
        (FATE[0] - FATE[1] + FATE[2] + FATE[3] - FATE[4]) // 2,
        (-FATE[0] + FATE[1] - FATE[2] + FATE[3] + FATE[4]) // 2,
    ]
    return FATEd


final_Value = [
    2532951952066291774890498369114195917240794704918210520571067085311474675019,
    2532951952066291774890327666074100357898023013105443178881294700381509795270,
    2532951952066291774890554459287276604903130315859258544173068376967072335730,
    2532951952066291774890865328241532885391510162611534514014409174284299139015,
    2532951952066291774890830662608134156017946376309989934175833913921142609334,
]

Value = final_Value
for i in range(250):
    Value = Reverse_wheel(Value)

initial_FATE = []
for i in Value:
    if i < 0:
        initial_FATE.append("re-" + tarot[(i ^ -1) % 78])
    else:
        initial_FATE.append(tarot[i % 78])

FLAG = ("hgame{" + "&".join(initial_FATE) + "}").replace(" ", "_")
print(FLAG)
# hgame{re-The_Moon&re-The_Sun&Judgement&re-Temperance&Six_of_Cups}

```

### Intergalactic Bound

首先这是Twisted Hessian curves 

```
a*x^3+y^3+1=dxy
```

方程代入P，Q两点联立消去d可以计算出a，再计算出d，这样参数就齐了。

然后用Pohlig_Hellman方法计算x即可

```python
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
```



## Reverse

### SignUp

如图，程序将flag去掉hgame{后复制到Destination后用sub_140014D3检查

![img](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250215174643680.png)

用sub_1400016EF加密后与byte_1400BB880比较，相关参数有unk_1409BB2A0 unk_1499BB889。

![img](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250215174643675.png)

加密函数如图，已逆向（验证过了）

```C
void encrypt(_DWORD *a1, __int64 a2, __int64 a3)
{
    unsigned int v4, v5, v6, v8;
    int v9, i;

    v6 = 0;
    for (v8 = 11; v8 > 0; v8--)
    {
        v6 += *(_DWORD *)(a3 + 4LL * (v8 % 4));
        v9 = (v6 >> 2) & 3;
        for (i = 0; i < 9; ++i)
        {
            v4 = a1[(i + 1) % 9];
            v5 = a1[(i + 8) % 9];
            a1[i] += ((v5 ^ *(_DWORD *)(a2 + 4LL * (v9 ^ i & 3))) + (v4 ^ v6)) ^ (((16 * v5) ^ (v4 >> 3)) + ((4 * v4) ^ (v5 >> 5)));
        }
    }
}

void decrypt(_DWORD *a1, __int64 a2, __int64 a3)
{
    unsigned int v4, v5, v6, v8;
    int v9, i;

    v6 = 0;
    for (v8 = 1; v8 < 12; v8++)
    {
        v6 -= *(_DWORD *)(a3 + 4LL * (v8 % 4));
        v9 = (v6 >> 2) & 3;
        for (i = 8; i >= 0; --i)
        {
            v4 = a1[(i + 1) % 9];
            v5 = a1[(i + 8) % 9];
            a1[i] -= ((v5 ^ *(_DWORD *)(a2 + 4LL * (v9 ^ i & 3))) + (v4 ^ v6)) ^ (((16 * v5) ^ (v4 >> 3)) + ((4 * v4) ^ (v5 >> 5)));
        }
    }
}
```

接下来就是unk_1409BB2A0 unk_1499BB889怎么找

追踪前者找到这个函数，居然用整个main的代码段作为数据加密，太疯狂了。

于是我把整个main代码段拿过来计算:

得到a2[4] = {2544000949, 3782569402, 2705540682, 1519331407}

![img](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250215174643654.png)

追踪后者找到这个函数，是个反调试程序，正常运行下Dr0~Dr3应该都是0，推定a3[4] = {0, 0, 0, 0}

![img](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250215174643713.png)

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define _BYTE unsigned char
#define _DWORD unsigned int

void encrypt(_DWORD *a1, __int64 a2, __int64 a3)
{
    unsigned int v4, v5, v6, v8;
    int v9, i;

    v6 = 0;
    for (v8 = 11; v8 > 0; v8--)
    {
        v6 += *(_DWORD *)(a3 + 4LL * (v8 % 4));
        v9 = (v6 >> 2) & 3;
        for (i = 0; i < 9; ++i)
        {
            v4 = a1[(i + 1) % 9];
            v5 = a1[(i + 8) % 9];
            a1[i] += ((v5 ^ *(_DWORD *)(a2 + 4LL * (v9 ^ i & 3))) + (v4 ^ v6)) ^ (((16 * v5) ^ (v4 >> 3)) + ((4 * v4) ^ (v5 >> 5)));
        }
    }
}

void decrypt(_DWORD *a1, __int64 a2, __int64 a3)
{
    unsigned int v4, v5, v6, v8;
    int v9, i;

    v6 = 0;
    for (v8 = 1; v8 < 12; v8++)
    {
        v6 -= *(_DWORD *)(a3 + 4LL * (v8 % 4));
        v9 = (v6 >> 2) & 3;
        for (i = 8; i >= 0; --i)
        {
            v4 = a1[(i + 1) % 9];
            v5 = a1[(i + 8) % 9];
            a1[i] -= ((v5 ^ *(_DWORD *)(a2 + 4LL * (v9 ^ i & 3))) + (v4 ^ v6)) ^ (((16 * v5) ^ (v4 >> 3)) + ((4 * v4) ^ (v5 >> 5)));
        }
    }
}

int main()
{
    char s[] = {
        0x23, 0xEA, 0x50, 0x30, 0x00, 0x4C, 0x51, 0x47,
        0xEE, 0x9C, 0x76, 0x2B, 0xD5, 0xE6, 0x94, 0x17,
        0xED, 0x2B, 0xE4, 0xB3, 0xCB, 0x36, 0xD5, 0x61,
        0xC0, 0xC2, 0xA0, 0x7C, 0xFE, 0x67, 0xD7, 0x5E,
        0xAF, 0xE0, 0x79, 0xC5};

    _DWORD a2[4] = {2544000949, 3782569402, 2705540682, 1519331407};
    _DWORD a3[4] = {0, 0, 0, 0};

    decrypt((_DWORD *)s, a2, a3);
    // 3fe4722c-1dbf-43b7-8659-c1c4a0e42e4d
    // hgame{3fe4722c-1dbf-43b7-8659-c1c4a0e42e4d}
    for (int i = 0; i < 36; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}
```