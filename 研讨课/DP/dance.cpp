#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

const int score[4][4]={{0,3,2,4},{1,0,3,2},{3,2,0,2},{1,3,2,0}};
const int INF=0x7fffffff;

int char2num(char a)
{
    int k=(a=='L')?0:(a=='R')?1:(a=='U')?2:3;
    return k;
}


int energy(string s)
{
    int n=s.size();
    int dp[4][4][n+1];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<=n;k++)
                dp[i][j][k]=INF;
        }
    }
    dp[0][1][0]=0;

    for(int k=1;k<=n;k++)
    {
        int nk=char2num(s[k-1]);
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(i!=nk&&j!=nk)continue;
                if(i==j)continue;
                int ml=INF;
                for(int m=0;m<4;m++)
                {
                    if(dp[m][j][k-1]!=INF&&score[m][i]+dp[m][j][k-1]+1<ml)
                    {
                        ml=score[m][i]+dp[m][j][k-1]+1;
                    }
                }
                int mr=INF;
                for(int m=0;m<4;m++)
                {
                    if(dp[i][m][k-1]!=INF&&score[m][j]+1+dp[i][m][k-1]<mr)
                    {
                        mr=score[m][j]+dp[i][m][k-1]+1;
                    }
                }
                dp[i][j][k]=ml<mr?ml:mr;
            }
        }
    }
    int ans=INF;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            ans=dp[i][j][n]<ans?dp[i][j][n]:ans;
        }
    }
    return ans;
}

int main()
{
    int row;
    cin>>row;
    string s;
    for(int i=0;i<row;i++)
    {
        cin>>s;
        cout<<energy(s)<<endl;
    }
    return 0;
}