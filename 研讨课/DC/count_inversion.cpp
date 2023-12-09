#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int merge(vector<long long>& nums, int start, int end, bool last)
{
    if (end<=start)return 0;
    int cnt = 0;
    int mid = (start + end) / 2;
    cnt += merge(nums, start, mid,false);
    cnt += merge(nums, mid + 1, end,false);
    vector<long long> new_nums;
    for (int i = mid,j=end; i >= start&&j>=mid+1;)
    {
        if (nums[i] > nums[j] * 3)
        {
            cnt += (j - mid);
            i--;
        }
        else j--;
    }
    if(!last)
    {
    int i = start, j = mid + 1;
    for (; i <= mid && j <= end;)
    {
        if (nums[i] < nums[j])
        {
            new_nums.push_back(nums[i++]);
            continue;
        }
        new_nums.push_back(nums[j++]);
    }
    while (i <= mid)new_nums.push_back(nums[i++]);
    while (j <= end)new_nums.push_back(nums[j++]);
    for (int k = 0; k + start <= end; k++) nums[start+k] = new_nums[k];
    }
    return cnt;
}
/*
int count_invert(vector<long long>& nums, int n)
{
    int cnt=0;
    int mn=0,mx=n-1,mid;
    merge()
    return cnt;
}*/

int main()
{
    int n;
    cin >> n;
    vector<long long> nums;
    for (int i = 0; i < n; i++)
    {
        long long m;
        cin >> m;
        nums.push_back(m);
    }
    cout << merge(nums, 0, n - 1,true) << endl;
    return 0;
}