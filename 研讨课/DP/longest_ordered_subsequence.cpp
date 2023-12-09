#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int LOS(vector<int> nums, int n)
{
    int vec[n];
    vec[0]=nums[0];
    int pv=0;
    for(int i=1;i<n;i++)
    {
        if(nums[i]>vec[pv])
        {
            vec[++pv]=nums[i];
            continue;
        }
        else if(i<n)
        {
            auto iter=lower_bound(vec,vec+pv,nums[i]);
            *iter=nums[i];
        }
    }
    return pv+1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<LOS(nums,n)<<endl;
    return 0;
}