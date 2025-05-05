#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

#define u_int64 unsigned long long

using namespace std;

// 计算一个集合的所有子集和，并将结果存储在哈希表中
void calculateSubsetSums(const vector<u_int64> &subset, unordered_map<u_int64, vector<u_int64>> &sums)
{
    int n = subset.size();
    u_int64 limit = pow(2, n);
    for (u_int64 i = 0; i < limit; ++i)
    {
        printf("i = %lf\r", (double)i / limit);
        // 遍历所有子集
        u_int64 subsetSum = 0;
        vector<u_int64> currentSubset;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                subsetSum += subset[j];
                currentSubset.push_back(subset[j]);
            }
        }
        sums[subsetSum] = currentSubset;
    }
}

// MITM攻击算法
vector<u_int64> mitmAttack(const vector<u_int64> &r, u_int64 S)
{
    int n = r.size();
    vector<u_int64> left(r.begin(), r.begin() + n / 2);
    vector<u_int64> right(r.begin() + n / 2, r.end());

    unordered_map<u_int64, vector<u_int64>> leftSums;

    // 计算左边所有可能子集的和
    calculateSubsetSums(left, leftSums);

    // 计算右边所有可能子集的和
    n = right.size();
    u_int64 limit = pow(2, n);
    for (u_int64 i = 0; i < limit; ++i)
    {
        // 遍历所有子集
        u_int64 subsetSum = 0;
        vector<u_int64> currentSubset;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                subsetSum += right[j];
                currentSubset.push_back(right[j]);
            }
            if (leftSums.find(S - subsetSum) != leftSums.end())
            {
                printf("found");
                vector<u_int64> result = leftSums[S - subsetSum];
                result.insert(result.end(), currentSubset.begin(), currentSubset.end());
                return result;
            }
        }
    }
    return {}; // 如果没有找到满足条件的子集
}

int main()
{
    vector<u_int64> r = {2826962231, 3385780583, 3492076631, 3387360133, 2955228863, 2289302839, 2243420737, 4129435549, 4249730059, 3553886213, 3506411549, 3658342997, 3701237861, 4279828309, 2791229339, 4234587439, 3870221273, 2989000187, 2638446521, 3589355327, 3480013811, 3581260537, 2347978027, 3160283047, 2416622491, 2349924443, 3505689469, 2641360481, 3832581799, 2977968451, 4014818999, 3989322037, 4129732829, 2339590901, 2342044303, 3001936603, 2280479471, 3957883273, 3883572877, 3337404269, 2665725899, 3705443933, 2588458577, 4003429009, 2251498177, 2781146657, 2654566039, 2426941147, 2266273523, 3210546259, 4225393481, 2304357101, 2707182253, 2552285221, 2337482071, 3096745679, 2391352387, 2437693507, 3004289807, 3857153537, 3278380013, 3953239151, 3486836107, 4053147071};
    u_int64 S = 123342809734;

    vector<u_int64> result = mitmAttack(r, S);

    cout << "Result: ";
    for (u_int64 i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}