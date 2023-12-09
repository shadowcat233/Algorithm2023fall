#include<iostream>
using namespace std;

#define MAX_N 1000
#define INF 0x7fffffff

int min(int a, int b) 
{
    return a < b ? a : b;
}

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	int n;
	scanf("%d", &n);
	int taste[MAX_N+1], health[MAX_N+1], price[MAX_N+1];
	for(int i = 1; i <= n; i++)
		scanf("%d %d %d", &health[i], &taste[i], &price[i]);
	
	int dp[MAX_N+1][MAX_N+1][MAX_N+1];
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
	printf("%d\n", dp[x][y][n]);
	return 0;
}