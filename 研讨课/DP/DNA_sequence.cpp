#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int score(char a, char b)
{
    if(a==b)return 0;
    if((a=='C'&&b=='G')||(a=='G'&&b=='C'))return 4;
    return 5;
}

int dna(string s, string t)
{
    int ns=s.size();
    int nt=t.size();
    vector<vector<int>> dp(nt+1,vector<int>(ns+1));//row:s,col:t
    dp[0][0]=0;
    for(int i=1;i<=ns;i++)
    {
        dp[0][i]=dp[0][i-1]+3;
    }
    for(int i=1;i<=nt;i++)
    {
        dp[i][0]=dp[i-1][0]+3;
    }
    for(int i=1;i<=nt;i++)
    {
        for(int j=1;j<=ns;j++)
        {
            int k=dp[i-1][j]<dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
            int sc=score(t[i-1],s[j-1]);
            k=dp[i-1][j-1]+sc<k+3?dp[i-1][j-1]+sc:k+3;
            dp[i][j]=k;
        }
    }
    return dp[nt][ns];
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<dna(s,t)<<endl;
    return 0;
}