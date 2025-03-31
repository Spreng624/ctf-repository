#include <stdio.h>
#define _DWORD unsigned int

#include <stdio.h>
#include <stdlib.h>
#define delta 0x9e3779b9

void enc(unsigned int *v, unsigned int *key, int n)
{
    unsigned int sum = 0;
    unsigned int y, z, p, rounds, e;

    rounds = 6 + 52 / n;
    y = v[0];
    sum = rounds * delta;

    do
    {
        e = sum >> 2 & 3;
        for (p = n - 1; p > 0; p--)
        {
            z = v[p - 1];
            v[p] -= ((((z >> 5) ^ (y << 2)) + ((y >> 3) ^ (z << 4))) ^ ((key[(p & 3) ^ e] ^ z) + (y ^ sum)));
            y = v[p];
        }
        z = v[n - 1];
        v[0] -= (((key[(p ^ e) & 3] ^ z) + (y ^ sum)) ^ (((y << 2) ^ (z >> 5)) + ((z << 4) ^ (y >> 3))));
        y = v[0];
        sum = sum - delta;
    } while (--rounds);
}

int main()
{
    unsigned int v[12] = {0x5A764F8A, 0x05B0DF77, 0xF101DF69, 0xF9C14EF4, 0x27F03590, 0x7DF3324F, 0x2E322D74, 0x8F2A09BC, 0xABE2A0D7, 0x0C2A09FE, 0x35892BB2, 0x53ABBA12};
    unsigned int key[4] = {0x05201314, 0x52013140, 0x05201314, 0x52013140};
    int n = 2; // 轮数

    for (int j = 0; j < 12; j += 2)
    {
        enc(&v[j], key, n);
    }
    puts((char *)v);
    // The_wind_stops_at_autumn_water_and_I_stop_at_you

    return 0;
}