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
