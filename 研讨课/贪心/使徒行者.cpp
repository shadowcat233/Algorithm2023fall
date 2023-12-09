#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 0x7fffffff

typedef struct soldier{
    int a;
    int b;
}soldier;

int cmp(soldier k,soldier l)
{
    return l.a-k.b>k.a-l.b;
}

int main()
{
    int n;
    cin>>n;
    vector<soldier> w(n);
    for(int i=0;i<n;i++)
    {
        cin>>w[i].a>>w[i].b;
    }
    sort(w.begin(),w.end(),cmp);
    int ma=MAX;
    int fear=0;
    for(int i=0;i<n;i++)
    {
        ma=w[i].a-fear<ma?w[i].a-fear:ma;
        fear+=w[i].b;
    }
    cout<<ma<<endl;
    return 0;
}