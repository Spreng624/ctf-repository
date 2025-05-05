# Misc

## sign in | FINISHED

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211034.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211036.png)

https://toolgg.com/image-decoder.html

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211037.png)

## 简简单单 | FINISHED

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211038.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211039.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211040.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211041.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211042.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211043.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211044.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211045.png)

## 夜观天象 | FINISHED

先在key.html中将所有的rgb抄下来，转换16进制就得到了key

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211046.png)

用slienteye破解下，我们得到了flag.txt

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211047.png)

```plain&#x20;text
我夜观天象，算出你将会得到flag

天象='角木蛟 觜火猴 箕水豹 毕月乌 氐土貉 毕月乌 轸水蚓 女土蝠 尾火虎 昴日鸡 壁水貐 箕水豹 尾火虎 奎木狼 心月狐 张月鹿 尾火虎 井木犴 昴日鸡 柳土獐 角木蛟 女土蝠 室火猪 觜火猴 氐土貉 奎木狼 牛金牛 箕水豹 亢金龙 胃土雉 房日兔 翼火蛇 尾火虎 轸水蚓 箕水豹 尾火虎 尾火虎 壁水貐 牛金牛 亢金龙 氐土貉 箕水豹 翼火蛇 翼火蛇 亢金龙 女土蝠 星日马 角木蛟 壁水貐 井木犴 角木蛟 牛金牛 箕水豹 柳土獐 室火猪 张月鹿 心月狐 星日马 角木蛟 虚日鼠 亢金龙 参水猿 箕水豹 箕水豹 尾火虎 翼火蛇 斗木獬 参水猿 心月狐 尾火虎 张月鹿 张月鹿 虚日鼠 星日马 斗木獬 室火猪 氐土貉 鬼金羊 角木蛟 娄金狗 斗木獬 井木犴 壁水貐 斗木獬 氐土貉 星日马 轸水蚓 氐土貉'

```

```python
star_to_direction = {
    "斗木獬": 0, "牛金牛": 0, "女土蝠": 0, "虚日鼠": 0, "危月燕": 0, "室火猪": 0, "壁水貐": 0,
    "角木蛟": 1, "亢金龙": 1, "氐土貉": 1, "房日兔": 1, "心月狐": 1, "尾火虎": 1, "箕水豹": 1,
    "奎木狼": 2, "娄金狗": 2, "胃土雉": 2, "昴日鸡": 2, "毕月乌": 2, "觜火猴": 2, "参水猿": 2,
    "井木犴": 3, "鬼金羊": 3, "柳土獐": 3, "星日马": 3, "张月鹿": 3, "翼火蛇": 3, "轸水蚓": 3
}
stars_list = [
    "角木蛟", "觜火猴", "箕水豹", "毕月乌", "氐土貉", "毕月乌", "轸水蚓", "女土蝠", "尾火虎",
    "昴日鸡", "壁水貐", "箕水豹", "尾火虎", "奎木狼", "心月狐", "张月鹿", "尾火虎", "井木犴",
    "昴日鸡", "柳土獐", "角木蛟", "女土蝠", "室火猪", "觜火猴", "氐土貉", "奎木狼", "牛金牛",
    "箕水豹", "亢金龙", "胃土雉", "房日兔", "翼火蛇", "尾火虎", "轸水蚓", "箕水豹", "尾火虎",
    "尾火虎", "壁水貐", "牛金牛", "亢金龙", "氐土貉", "箕水豹", "翼火蛇", "翼火蛇", "亢金龙",
    "女土蝠", "星日马", "角木蛟", "壁水貐", "井木犴", "角木蛟", "牛金牛", "箕水豹", "柳土獐",
    "室火猪", "张月鹿", "心月狐", "星日马", "角木蛟", "虚日鼠", "亢金龙", "参水猿", "箕水豹",
    "箕水豹", "尾火虎", "翼火蛇", "斗木獬", "参水猿", "心月狐", "尾火虎", "张月鹿", "张月鹿",
    "虚日鼠", "星日马", "斗木獬", "室火猪", "氐土貉", "鬼金羊", "角木蛟", "娄金狗", "斗木獬",
    "井木犴", "壁水貐", "斗木獬", "氐土貉", "星日马", "轸水蚓", "氐土貉"
]
direction_string = ''.join(str(star_to_direction[star]) for star in stars_list)
quaternary_numbers = [direction_string[i:i+4] for i in range(0, len(direction_string), 4)]
decimal_numbers = [int(num, 4) for num in quaternary_numbers if len(num) == 4]
print(''.join(chr(num) for num in decimal_numbers))
#flag{BaguA_M4ster_0v0}
```

## 烟③ | FINISHED

直接全程非预期，力大砖飞

题目说了八位小写密码，ARCHPR硬爆破出密码moximoxi

倒序一下，看起来像是个pdf

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211048.png)

用格式工厂pdf转docx

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211049.png)

右下角有个很小的图片，放大了就是flag

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211050.png)

# Crypto

## ezCrypto | FINISHED

```python
import gmpy2
from Crypto.Util.number import *
e = 65537 
n = 1455925529734358105461406532259911790807347616464991065301847 
c = 69380371057914246192606760686152233225659503366319332065009 
p=1201147059438530786835365194567
q=1212112637077862917192191913841
phi=(p-1)*(q-1)
d=gmpy2.invert(e,phi)
m=pow(c,d,n)
print(long_to_bytes(m))
#flag{fact0r_sma11_N}
```

## 签到 | FINISHED

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211051.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211052.png)

## 神秘dp | FINISHED

```python
from Crypto.Util.number import *
e = 65537
n = 13851998696110232034312408768370264747862778787235362033287301947690834384177869107768578977872169953363148442670412868565346964490724532894099772144625540138618913694240688555684873934424471837897053658485573395777349902581306875149677867098014969597240339327588421766510008083189109825385296069501377605893298996953970043168244444585264894721914216744153344106498382558756181912535774309211692338879110643793628550244212618635476290699881188640645260075209594318725693972840846967120418641315829098807385382509029722923894508557890331485536938749583463709142484622852210528766911899504093351926912519458381934550361 
dp = 100611735902103791101540576986246738909129436434351921338402204616138072968334504710528544150282236463859239501881283845616704984276951309172293190252510177093383836388627040387414351112878231476909883325883401542820439430154583554163420769232994455628864269732485342860663552714235811175102557578574454173473
c = 6181444980714386809771037400474840421684417066099228619603249443862056564342775884427843519992558503521271217237572084931179577274213056759651748072521423406391343404390036640425926587772914253834826777952428924120724879097154106281898045222573790203042535146780386650453819006195025203611969467741808115336980555931965932953399428393416196507391201647015490298928857521725626891994892890499900822051002774649242597456942480104711177604984775375394980504583557491508969320498603227402590571065045541654263605281038512927133012338467311855856106905424708532806690350246294477230699496179884682385040569548652234893413
for k in range(1, e):
    p = (e * dp - 1) // k + 1
    if (e * dp - 1) % k == 0 and isPrime(p) and n % p == 0:
        q = n // p
        if isPrime(q):
            break
phi = (p - 1) * (q - 1)
d = inverse(e, phi)
dq = d % (q-1)
m_p = pow(c, dp, p)
m_q = pow(c, dq, q)
h = (inverse(q, p) * (m_p - m_q)) % p
m = (m_q + h * q)
plaintext = long_to_bytes(m).decode()
print("解密后的明文:", plaintext)
#flag{dp_i5_1eak}
```

## math | FINISHED

观察规律发现，key的递推公式周期性变化，前三项之和加1或减1或不加

```python
from Crypto.Util.number import *
from gmpy2 import next_prime

n = 739243847275389709472067387827484120222494013590074140985399787562594529286597003777105115865446795908819036678700460141950875653695331369163361757157565377531721748744087900881582744902312177979298217791686598853486325684322963787498115587802274229739619528838187967527241366076438154697056550549800691528794136318856475884632511630403822825738299776018390079577728412776535367041632122565639036104271672497418509514781304810585503673226324238396489752427801699815592314894581630994590796084123504542794857800330419850716997654738103615725794629029775421170515512063019994761051891597378859698320651083189969905297963140966329378723373071590797203169830069428503544761584694131795243115146000564792100471259594488081571644541077283644666700962953460073953965250264401973080467760912924607461783312953419038084626809675807995463244073984979942740289741147504741715039830341488696960977502423702097709564068478477284161645957293908613935974036643029971491102157321238525596348807395784120585247899369773609341654908807803007460425271832839341595078200327677265778582728994058920387721181708105894076110057858324994417035004076234418186156340413169154344814582980205732305163274822509982340820301144418789572738830713925750250925049059
c = 229043746793674889024653533006701296308351926745769842802636384094759379740300534278302123222014817911580006421847607123049816103885365851535481716236688330600113899345346872012870482410945158758991441294885546642304012025685141746649427132063040233448959783730507539964445711789203948478927754968414484217451929590364252823034436736148936707526491427134910817676292865910899256335978084133885301776638189969716684447886272526371596438362601308765248327164568010211340540749408337495125393161427493827866434814073414211359223724290251545324578501542643767456072748245099538268121741616645942503700796441269556575769250208333551820150640236503765376932896479238435739865805059908532831741588166990610406781319538995712584992928490839557809170189205452152534029118700150959965267557712569942462430810977059565077290952031751528357957124339169562549386600024298334407498257172578971559253328179357443841427429904013090062097483222125930742322794450873759719977981171221926439985786944884991660612824458339473263174969955453188212116242701330480313264281033623774772556593174438510101491596667187356827935296256470338269472769781778576964130967761897357847487612475534606977433259616857569013270917400687539344772924214733633652812119743

a1, a2, a3 = 22, 40, 75

for i in range(2322):
    if i % 4 == 2:
        a1, a2, a3 = a2, a3, a1 + a2 + a3 - 1
    elif i % 4 == 3:
        a1, a2, a3 = a2, a3, a1 + a2 + a3 + 1
    else:
        a1, a2, a3 = a2, a3, a1 + a2 + a3
p = next_prime(a3)
if n % p == 0:
    q = n // p
    e = 65537
    d = inverse(e, (p - 1) * (q - 1))
    m = pow(c, d, n)
    print(long_to_bytes(m))
b'flag{77310934-21fa-4ee4-a783-dc1865ebab28}'
```

## base1024 | FINISHED

网上有base1024千字文，拿来解密一下

```python
if __name__ == "__main__":
    b_已解字节内容 = h_千字文解码(
        "利师迩鉴石碣遥逍汉玄珍覆穑碣云罗侈平同此竹岱饭乎见槐洛五伦璧策缘芸武秦伤阮空创欲雁刻分超任策迩释机于焉笃僚施迩姿植沙疫书曲亲零零零"
    )  # b_千字文编码)
    b_文本内容 = b_已解字节内容.decode("utf-8")
    print("解码好的:" + b_文本内容)
    # 脑洞竞技 代码逆向 漏洞挖掘 团队协作 密码破译 云端对决
    # flag{脑洞竞技 代码逆向 漏洞挖掘 团队协作 密码破译 云端对决}
```

## 不要忘记仰望星空 |FINISHED

将社会核心价值观解码后，得到了串盲文（实质上是些unicode码

```plain&#x20;text
⡳⠥⠦⠔⠶⠋⡳⠥⠢⠔⠆⠔⡳⠥⠢⠒⠙⠖⡳⠥⠶⠑⠉⠋⡳⠥⠶⠖⠦⠲⡳⠥⠢⠢⠂⠴⡳⠥⠲⠑⠴⠔⡳⠥⠦⠢⠉⠋⡳⠥⠋⠋⠴⠉⡳⠥⠴⠴⠁⡳⠥⠶⠔⠢⠑⡳⠥⠶⠔⠙⠦⡳⠥⠦⠴⠴⠉⡳⠥⠖⠶⠴⠔⡳⠥⠦⠴⠋⠙⡳⠥⠢⠆⠔⠃⡳⠥⠶⠖⠦⠲⡳⠥⠢⠃⠢⠔⡳⠥⠖⠴⠔⠋⡳⠥⠶⠁⠶⠁⡳⠥⠋⠋⠴⠉⡳⠥⠴⠴⠁⡳⠥⠖⠴⠒⠃⡳⠥⠖⠴⠋⠒⡳⠥⠖⠆⠢⠒⡳⠥⠔⠴⠴⠴⡳⠥⠢⠦⠴⠆⡳⠥⠔⠋⠂⠒⡳⠥⠶⠖⠦⠲⡳⠥⠶⠒⠆⠁⡳⠥⠢⠂⠖⠃⡳⠥⠖⠆⠂⠆⡳⠥⠋⠋⠴⠉⡳⠥⠴⠴⠁⡳⠥⠦⠙⠂⠋⡳⠥⠦⠙⠆⠒⡳⠥⠦⠴⠉⠉⡳⠥⠦⠦⠲⠉⡳⠥⠖⠶⠲⠑⡳⠥⠶⠖⠦⠲⡳⠥⠖⠉⠔⠔⡳⠥⠢⠴⠑⠶⡳⠥⠋⠋⠴⠉⡳⠥⠴⠴⠁⡳⠥⠲⠑⠆⠙⡳⠥⠔⠴⠂⠲⡳⠥⠢⠆⠁⠴⡳⠥⠢⠂⠖⠢⡳⠥⠶⠖⠦⠲⡳⠥⠶⠖⠶⠙⡳⠥⠔⠋⠔⠔⡳⠥⠔⠁⠖⠉⡳⠥⠋⠋⠴⠉⡳⠥⠴⠴⠁⡳⠥⠴⠴⠁⡳⠥⠢⠃⠋⠔⡳⠥⠲⠑⠦⠖⡳⠥⠋⠋⠴⠉⡳⠥⠦⠋⠙⠦⡳⠥⠖⠶⠴⠔⡳⠥⠔⠴⠁⠒⡳⠥⠖⠦⠒⠔⡳⠥⠦⠙⠦⠁⡳⠥⠖⠶⠖⠢⡳⠥⠦⠙⠦⠁⡳⠥⠔⠢⠶⠋⡳⠥⠶⠖⠦⠲⡳⠥⠢⠔⠦⠆⡳⠥⠖⠂⠴⠋⡳⠥⠔⠂⠙⠂⡳⠥⠶⠃⠦⠙⡳⠥⠖⠦⠙⠆⡳⠥⠴⠴⠁⡳⠥⠴⠴⠁⡳⠥⠆⠴⠂⠲⡳⠥⠆⠴⠂⠲⡳⠥⠒⠴⠴⠁⡳⠥⠴⠴⠖⠖⡳⠥⠴⠴⠖⠉⡳⠥⠴⠴⠖⠂⡳⠥⠴⠴⠖⠶⡳⠥⠒⠴⠴⠃
```

####

先是社会主义核心价值观解码，再8点盲文解码（选择“英国 美国 计算机8点”）

用这个在线网站就行https://www.lddgo.net/common/braille

```python
print(
    """
    \u897f\u5929\u53d6\u7ecf\u7684\u5510\u4e09\u85cf\uff0c\u000a
    \u795e\u79d8\u800c\u6709\u80fd\u529b\u7684\u5b59\u609f\u7a7a\uff0c\u000a
    \u603b\u60f3\u6253\u9000\u5802\u9f13\u7684\u732a\u516b\u6212\uff0c\u000a
    \u8d1f\u8d23\u80cc\u884c\u674e\u7684\u6c99\u50e7\uff0c\u000a
    \u4e2d\u9014\u52a0\u5165\u7684\u767d\u9f99\u9a6c\uff0c\u000a
    \u000a
    \u5bf9\u4e86\uff0c\u8fd8\u6709\u90a3\u6839\u8d8a\u6765\u8d8a\u957f\u7684\u5982\u610f\u91d1\u7b8d\u68d2\u000a\u000a
    \u2014\u2014\u300a\u0066\u006c\u0061\u0067\u300b
    """
)
```

再unicode解码，得到：



西天取经的唐三藏，

神秘而有能力的孙悟空，

总想打退堂鼓的猪八戒，

负责背行李的沙僧，

中途加入的白龙马，



对了，还有那根越来越长的如意金箍棒



——《flag》

搜索提示找到https://www.douban.com/note/848680051/?\_i=4157717HEPyz0H,4158109HEPyz0H

得到flag{宇宙探索编辑部}，没错，这个flag是根据提示搜来的，没有用到上面的诗。

# Forensics |AK

## 签到 | FINISHED

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211053.jpg)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211054.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211055.jpg)

flag{成都宽窄巷子蜀韵园}

## ① | FINISHED

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211056.png)

flag{2216612d65abe33f05c1662d53a6faf8}

## ② | FINISHED

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211057.png)

一眼克宫

55.754,37.613

flag{755947b6b90b7a9676282f0ff2151e48}

## ③ | FINISHED

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211058.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211059.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211060.png)

flag{8fbbc1224896105a0354bc084de1ed4e}

## ④ | FINISHED

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211061.png)

找它真累啊flag{6129f45f8cc17063cc47828895042b17}

# Web

## ezphp | FINISHED

一些md5弱碰撞和强碰撞，绕过一下，然后反向输出一下flag和flag.sh

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211062.png)

看起来是在环境变量里

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211063.png)

## ez\_python | FINISHED

先进行扫描，找到了/shell

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211064.png)

/?file=可以直接任意读取文件，以此读到app.py和waf.py

app.py

```python
from flask import Flask, request, render_template_string
from flask_limiter import Limiter
from flask_limiter.util import get_remote_address
import waf
app = Flask(__name__)
limiter = Limiter(
    get_remote_address,
    app=app,
    default_limits=["300 per day", "75 per hour"]
)
@app.route('/')
@limiter.exempt
def index():
    file_path = request.args.get('file')
    if file_path and "proc" in file_path:
        return "只过滤了proc，别想用这个了，去读源码", 200
    if file_path:
        try:
            with open(file_path, 'r') as file:
                file_content = file.read()
            return f"{file_content}"
        except Exception as e:
            return f"Error reading file: {e}"
    return "Find the get parameter to read something"
@app.route('/shell')
@limiter.limit("10 per minute")
def shell():
    if request.args.get('name'):
        person = request.args.get('name')
        if not waf.waf_check(person):
            mistake = "Something is banned"
            return mistake
        template = 'Hi, %s' % person
        return render_template_string(template)
    some = 'who you are?'
    return render_template_string(some)
@app.errorhandler(429)
def ratelimit_error(e):
    return "工具？ 毫无意义，去手搓", 429
if __name__ == '__main__':
    app.run(debug=False, host='0.0.0.0', port=8000)
```

waf.py

```python
def waf_check(value):
    dangerous_patterns = ['os', 'set', '__builtins__', '=', '.', '{{', '}}', 'popen', '+', '__']
    for pattern in dangerous_patterns:
        if pattern in value:
            return False
    return True
```

访问/shell，get传参name，存在ssti注入漏洞

焚靖梭的事

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211065.png)

# Reverse |AK

## AmaZing\_BruteForce | FINISHED

先upx脱壳，按小端序输入数据，爆破是不必的，只需知道4位的key即可，其大概率为flag

异或反推出key再反代即可

就算key不是flag，也可以通过{}来确定两位字母，再考虑爆破中间两位

```python
#   v5[0] = 0x363E2315020A0508i64;
#   v5[1] = 0x183F5831552F363Ai64;
s = [
    0x08,
    0x05,
    0x0A,
    0x02,
    0x15,
    0x23,
    0x3E,
    0x36,
    0x3A,
    0x36,
    0x2F,
    0x55,
    0x31,
    0x58,
    0x3F,
    0x18,
]
print(s[0] ^ ord("f"))
print(s[1] ^ ord("l"))
print(s[2] ^ ord("a"))
print(s[3] ^ ord("g"))
key = [110, 105, 107, 101]
for i in range(16):
    print(chr(s[i] ^ key[i % 4]), end="")
# flag{JUST_D0_1T}
```

# PWN

## 真“签到” | FINISHED

难度不大，分析下elf文件，我们先在main里面读到了几条过滤

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211066.png)

显然不能有sh,echo,$0了，否则会报错：Command not allowed

然后我们在filter\_string里面可以发现又有几个过滤，不过呢，只是单纯的删去字母而已啦

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211067.png)

查了表后，这里会自动删掉f,l,a,g,{这五个字母，这里就弄个例子吧

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505203211068.png)

现在问题来了，这题难度不高，都不需要我们构造exp，只要我们能找到除了上面被jail的命令后，我们就能找到flag了

这里先说说碰到的几个坑，首先呢，Unicode是不行的，所以这和pyjail不一样，然后只能尝试Linux命令爆破了

爆破在进行中，先放着

我又审计了上面的伪c代码，我发现那个函数只能处理255个字符，我考虑了下长度漏洞，但是第256个字符开始，这个函数根本不读取，服了



看代码发现，它是先检测sh echo $0再过滤flag{的，可以想到用l将命令隔开，如$l0,过滤后变成$0,那就直接控制服务器了，ls cat随便用。

```python
nc ctf.mardle.cn 34367
$l0

echo 1
1
cat flag
flag{847ec3aa-4ca3-44fd-94cc-4a65fcf64d2c}
```



