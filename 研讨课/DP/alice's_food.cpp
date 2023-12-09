#include<iostream>
#include<vector>
using namespace std;

#define MAX_N 1000
#define INF 0x7fffffff

int min(int a, int b) 
{
    return a < b ? a : b;
}

int dp[MAX_N+1][MAX_N+1][MAX_N+1];

int solve(int x, int y, int n, const vector<int>& health, const vector<int>& taste, const vector<int>& price)
{
    for(int i = 1; i <= n; i++)
    {
        dp[0][0][i] = 0;
    }
    for(int i = 0; i <= x; i++)
    {
        for(int j = 0; j <= y; j++)
        {
            dp[i][j][0] = INF;
        }
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 0; i <= x; i++)
        {
            for(int j = 0; j <= y; j++)
            {
                if(health[k] >= i && taste[k] >= j)
                {
                    dp[i][j][k] = min(dp[i][j][k-1], price[k]);
                }
                else if(health[k] >= i)
                {
                    if(dp[0][j-taste[k]][k-1] == INF){
                        dp[i][j][k] = dp[i][j][k-1];
                    }
                    else
                    {
                        dp[i][j][k] = min(dp[i][j][k-1], dp[0][j-taste[k]][k-1] + price[k]);
                    }
                }
                else if(taste[k] >= j)
                {
                    if(dp[i-health[k]][0][k-1] == INF)
                    {
                        dp[i][j][k] = dp[i][j][k-1];
                    }
                    else
                    {
                        dp[i][j][k] = min(dp[i][j][k-1], dp[i-health[k]][0][k-1] + price[k]);
                    }
                }
                else
                {
                    if(dp[i-health[k]][j-taste[k]][k-1] == INF)
                    {
                        dp[i][j][k] = dp[i][j][k-1];
                    }
                    else
                    {
                        dp[i][j][k] = min(dp[i][j][k-1], dp[i-health[k]][j-taste[k]][k-1] + price[k]);
                    }
                }
            }
        }
    }
    return dp[x][y][n];
}

int main()
{
    int x, y;
    cin>>x>>y;
    int n;
    cin>>n;
    vector<int> health(n+1), taste(n+1), price(n+1);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &health[i], &taste[i], &price[i]);
    }
    cout<<solve(x, y, n, health, taste, price)<<endl;
    return 0;
}
