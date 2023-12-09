#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;


bool is_ok(vector<int> dist, int min_len, int step)
{
    int sum = 0,i = 1, t = 0;
    int n=dist.size();
 	while (i<n)
  	{
        sum = dist[i++];
        while (i < n && sum < min_len)
        {
            sum += dist[i++];
            t++;
        }
        if (t > step) return false; 
  	}
  	if (sum < min_len && t == step) return false; 
   	return true;
}

int river(vector<int>& rocks, int L, int N, int M)
{
    if(N==M)return L;
    int n = rocks.size();
    vector<int> dist(n);
    int ans=rocks[1];
    for (int i = 1; i < n; i++)
    {
        dist[i] = rocks[i] - rocks[i - 1];
        ans = min(ans,dist[i]);
    }
    int max_dist = L / (N - M);
    int min_dist = ans;
    int mid;
    while (min_dist <= max_dist)
    {
        mid = (min_dist + max_dist) / 2;
        bool ok = is_ok(dist, mid, M);
        if (ok) {
            ans = mid;
            min_dist = mid+1;
        }
        else {
            max_dist = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int L, N, M;
    cin >> L >> N >> M;
    vector<int> rocks;
    rocks.push_back(0);
    rocks.push_back(L);
    for (int i = 0; i < N; i++)
    {
        int m;
        cin >> m;
        rocks.push_back(m);
    }
    sort(rocks.begin(), rocks.end());
    cout << river(rocks, L, N, M) << endl;
    return 0;
}