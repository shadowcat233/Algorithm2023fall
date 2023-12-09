#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int reverse(string& s, vector<int>& vec)
{
    int n = s.size();
    for (int i = n - 1; i > 0; i--)
    {
        vec.push_back(s[i] - '0');
    }
    if (s[0] != '-')
    {
        vec.push_back(s[0] - '0');
        return 1;
    }
    else return -1;
}

bool bigger(vector<int> s, vector<int> t)
{
    if (s.size() > t.size())return true;
    if (s.size() < t.size())return false;
    int n = s.size();
    for (int i = n-1; i >=0;i--)
    {
        if (s[i] > t[i])return true;
        if (s[i] < t[i])return false;
    }
    return false;
}

int main()
{
    string a, b;
    cin >> a >> b;

    vector<int> numa, numb, sum;
    int signa = reverse(a, numa);
    int signb = reverse(b, numb);
    int na = numa.size(),nb=numb.size();
    int n = max(na, nb);
    int cin = 0;
    int positive=1;
    if (signa == signb)
    {
        for (int i = 0; i < n || cin == 1; i++)
        {
            int d1 = i < na ? numa[i] : 0;
            int d2 = i < nb ? numb[i] : 0;
            int k = d1 + d2 + cin;
            sum.push_back(k % 10);
            cin = k / 10;
        }
        positive = (signa == 1);
    }
    else
    {
        if (bigger(numb, numa))
        {
            vector<int> temp = numa;
            numa = numb;
            numb = temp;
            int t = na;
            na = nb;
            nb = t;
            t = signa;
            signa = signb;
            signb = t;
        }
        positive = signa == 1;
        for (int i = 0; i < n || cin == -1; i++)
        {
            int d1 = i < na ? numa[i] : 0;
            int d2 = i < nb ? numb[i] : 0;

            int k = d1 - d2 + cin;
            sum.push_back((k + 10) % 10);
            cin = k < 0 ? -1 : 0;
        }
        
    }
    n = sum.size();
    int zero=1;
    for(int i=0;i<n;i++)
    {
        if(sum[i]!=0)
        {
            zero=0;
            break;
        }
    }
    if (!positive&&!zero)cout << "-";
    int i;
    for(i=n-1;sum[i]==0&&i>0;i--);
    for (; i >= 0; i--)
    {
        cout << sum[i];
    }
    cout << endl;
    return 0;
}