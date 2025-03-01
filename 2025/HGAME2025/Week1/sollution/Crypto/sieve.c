#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void get_phi(int n, int *phi)
{
    for (int i = 2; i <= n; i++)
    {
        phi[i] = i; // 初始化欧拉函数值
    }

    for (int p = 2; p <= n; p++)
    {
        if (phi[p] == p)
        {
            for (int multiple = 2 * p; multiple <= n; multiple += p)
            {
                phi[multiple] = phi[multiple] / p * (p - 1); // 更新欧拉函数值
            }
        }
    }
}

int main()
{
    int n = 715849728;
    long long sum = 0;
    int *phi = (int *)malloc((n + 1) * sizeof(int));

    get_phi(n, phi);

    for (int i = 2; i <= n; i++)
    {
        sum += phi[i];
    }
    printf("sum = %lld\n", sum + 1); // sum = 155763335447735055

    free(phi);
    return 0;
}