#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int cmp(string a, string b)
{
    return a+b>b+a;
}

string largest_num(vector<string>& strs,int n)
{
    sort(strs.begin(),strs.end(),cmp);
    string res;
    for(int i=0;i<n;i++)
    {
        res+=strs[i];
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<string> strs(n);
    for(int i=0;i<n;i++)
    {
        cin>>strs[i];
    }
    cout<<largest_num(strs,n);
    return 0;
}