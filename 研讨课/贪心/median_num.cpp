#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> nums(m*n);
    for(int i=0;i<m*n;i++)
    {
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int sum=0;
    for(int i=0,off=n*((m-1)/2);i<n;i++)
    {
        sum+=nums[off];
        off+=m/2+1;
    }
    cout<<sum<<endl;
    return 0;
}