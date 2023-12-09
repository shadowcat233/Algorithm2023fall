#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;


#define MAX 1e9
#define MIN 0


long MinMaxMinusMin(vector<long> nums, int n, int k)
{
    vector<long> b_max(n), b_min(n);
    b_max[n - 1] = nums[n - 1]; b_min[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < b_min[i + 1])
            b_min[i] = nums[i];
        else b_min[i] = b_min[i + 1];
        if (nums[i] > b_max[i + 1])
            b_max[i] = nums[i];
        else b_max[i] = b_max[i + 1];
    }
    vector<long> f_max(n), f_min(n);
    f_max[0] = nums[0]; f_min[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < f_min[i - 1])
            f_min[i] = nums[i];
        else f_min[i] = f_min[i - 1];
        if (nums[i] > f_max[i - 1])
            f_max[i] = nums[i];
        else f_max[i] = f_max[i - 1];
    }
    int mn = 0, mx = 0, ret = MAX;
    for (int i = 0; i <= n - k; i++)
    {
        if (i == 0)
        {
            mn = b_min[k];
            mx = b_max[k];
        }
        else if (i == n - k)
        {
            mn = f_min[n - k - 1];
            mx = f_max[n - k - 1];
        }
        else
        {
            mn = f_min[i - 1] < b_min[i + k] ? f_min[i - 1] : b_min[i + k];
            mx = f_max[i - 1] > b_max[i + k] ? f_max[i - 1] : b_max[i + k];
        }
        ret = mx - mn < ret ? mx - mn : ret;
    }
    return ret;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << MinMaxMinusMin(nums, n, k);
    return 0;
}