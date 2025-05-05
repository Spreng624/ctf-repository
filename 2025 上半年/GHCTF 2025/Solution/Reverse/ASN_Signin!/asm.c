#include <stdio.h>
#include <string.h>

// 数据部分
unsigned char welcome_msg[] = "Welcome to GHCTF!\r\n";
unsigned char input_msg[] = "Input your flag:";
unsigned char wrong_msg[] = "Wrong!\r\n";
unsigned char right_msg[] = "Right!\r\n";

unsigned char data1[] = {
    0x26, 0x27, 0x24, 0x25, 0x2A, 0x2B, 0x28, 0x00,
    0x2E, 0x2F, 0x2C, 0x2D, 0x32, 0x33, 0x30, 0x00,
    0x36, 0x37, 0x34, 0x35, 0x3A, 0x3B, 0x38, 0x39,
    0x3E, 0x3F, 0x3C, 0x3D, 0x3F, 0x27, 0x34, 0x11};

unsigned char data2[] = {
    0x69, 0x77, 0x77, 0x66, 0x73, 0x72, 0x4F, 0x46,
    0x03, 0x47, 0x6F, 0x79, 0x07, 0x41, 0x13, 0x47,
    0x5E, 0x67, 0x5F, 0x09, 0x0F, 0x58, 0x63, 0x7D,
    0x5F, 0x77, 0x68, 0x35, 0x62, 0x0D, 0x0D, 0x50};

unsigned char buffer1[33]; // 用户输入缓冲区
unsigned char buffer2[33]; // 处理后数据缓冲区

// DO1 函数：交换 DATA1 中的某些字节
void do1()
{
    int cx, di, si = 0;

    for (int i = 0; i < 8; i++)
    {
        di = si;
        di += 4;
        if (di >= 28)
            di -= 28;
        do2(si, di);
        si += 4;
    }
}

// DO2 函数：交换 DATA1[BX] 和 DATA1[DI] 的 4 个字节
void do2(int bx, int di)
{
    unsigned char temp[4];
    memcpy(temp, &data1[bx], 4);
    memcpy(&data1[bx], &data1[di], 4);
    memcpy(&data1[di], temp, 4);
}

// ENC 函数：对 BUFFER1 中的数据进行某种处理
void enc()
{
    int si, di, i;
    unsigned char *buffer_ptr = buffer1 + 2;
    unsigned char *data1_ptr = data1;

    for (si = 0, di = 0; si < 8 * 4; si += 4, di += 4)
    {
        // XOR 操作
        *(unsigned short *)(buffer_ptr + si) ^= *(unsigned short *)(data1_ptr + di + 1);
        *(unsigned short *)(buffer_ptr + si + 2) ^= *(unsigned short *)(data1_ptr + di + 2);
    }
}

void dec()
{
    int si, di, i;
    unsigned char *buffer_ptr = data2;
    unsigned char *data1_ptr = data1;

    for (si = 0, di = 0; si < 8 * 4; si += 4, di += 4)
    {
        // XOR 操作
        *(unsigned short *)(buffer_ptr + si) ^= *(unsigned short *)(data1_ptr + di + 1);
        *(unsigned short *)(buffer_ptr + si + 2) ^= *(unsigned short *)(data1_ptr + di + 2);
    }
}

int main()
{
    do1();
    dec();
    printf("%s\n", data2);
    return 0;
}