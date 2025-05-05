import re


def find_plus_sequences(file_path):
    with open(file_path, "r") as file:
        ind = 0
        for line in file:
            line = line.strip()  # 去除行首尾的空白字符
            if not line:
                continue  # 跳过空行

            ind += 1

            # 使用正则表达式找到所有的连续"+"序列
            plus_sequences = re.findall(r"\++", line)

            # 统计前两段连续"+"的数量
            count = 0
            found_sequences = []
            for seq in plus_sequences:
                if count >= 2:
                    break
                found_sequences.append(len(seq))
                count += 1

            # 输出结果
            if found_sequences:
                # print(f"当前行: {line}")
                # print(f"第一次连续+的数量: {found_sequences[0]}")
                # if len(found_sequences) > 1:
                #     print(f"第二次连续+的数量: {found_sequences[1]}")
                # print()  # 空行分隔不同行的输出
                # print(found_sequences)
                # print(ind, end=" ")
                print(chr(found_sequences[0] * found_sequences[1]), end="")


# 调用函数，传入文件路径
# file_path = "2025\XYCTF2025\sollution\\bf.txt"  # 替换为你的文件路径
# find_plus_sequences(file_path)
# flag{W3lC0me_t0_XYCTF_2025_Enj0_1t!}

data = [0, 0]
ptr = 0
ptr += 1
data[ptr] += 4
while data[ptr] != 0:
    ptr -= 1
    data[ptr] += 6
    ptr += 1
    data[ptr] -= 1

print(data)
ptr -= 1

while data[ptr] != 0:
    data[ptr] -= 1
print(data)
