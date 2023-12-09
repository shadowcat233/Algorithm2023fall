#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node{
    int x;
    int y;
}node;

int cmp1(node a,node b)
{
    return a.x!=b.x?a.x<b.x:a.y<b.y;
}


int rectangle(vector<node> nodes, int sz, int n, int m)
{
    int ans = 0;
    sort(nodes.begin(), nodes.end(), cmp1);
    for (int i = 0; i < sz - 1; i++)
    {
        int s = (nodes[i + 1].x - nodes[i].x) * m;
        ans = s > ans ? s : ans;
        int hu = m-nodes[i].y, hd = nodes[i].y;
        int k = 0;
        for (int j = i + 1; j < sz; j++)
        {
            int h1 = nodes[j].y - nodes[i].y;
            int h2 = -h1;
            int w = nodes[j].x - nodes[i].x;
            //ans=w*(hu+hd)>ans?w*(hu+hd):ans;
            if (h1 > 0 && h1 <= hu)
            {
                int h=(k==1)?hu:(hu+hd);
                ans = h * w > ans ? h * w : ans;
                hu = h1;
            }
            else if (h2 > 0 && h2 <= hd)
            {
                int h = (k == 1) ? hd : (hu + hd);
                ans = h * w > ans ? h * w : ans;
                hd = h2;
            }
            else if(h1==0) k = 1;
        }
        int hh1 = k == 0 ? (hu + hd) : hu > hd ? hu : hd;
        int hu1 = hu, hd1 = hd;
        int s2 = hh1 * (n - nodes[i].x);
        ans = s2 > ans ? s2 : ans;

        hu = m - nodes[i].y; hd = nodes[i].y;
        k = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            int h1 = nodes[j].y - nodes[i].y;
            int h2 = -h1;
            int w = nodes[j].x - nodes[i].x;
            //ans=w*(hu+hd)>ans?w*(hu+hd):ans;
            if (h1 > 0 && h1 <= hu)
            {
                int h = (k == 1) ? hu : (hu + hd);
                ans = h * w > ans ? h * w : ans;
                hu = h1;
            }
            else if (h2 > 0 && h2 <= hd)
            {
                int h = (k == 1) ? hd : (hu + hd);
                ans = h * w > ans ? h * w : ans;
                hd = h2;
            }
            else if(h1==0) k = 1;
        }
        int hh2 = k == 0 ? (hu + hd) : hu > hd ? hu : hd;
        s2 = hh2 * nodes[i].x;
        hu = hu1 < hu ? hu1 : hu;
        hd = hd1 < hd ? hd1 : hd;
        int hh = hu>hd?hu:hd;
        s2 = n * hh>s2?n*hh:s2;
        ans = s2 > ans ? s2 : ans;
    }

    return ans;
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<node> nodes(k+4);
    nodes[0]={0,0};
    nodes[1]={n,0};
    nodes[2]={0,m};
    nodes[3]={n,m};
    for(int i=0;i<k;i++)
    {
        scanf("%d %d",&nodes[i+4].x,&nodes[i+4].y);
    }
    cout<<rectangle(nodes,k+4,n,m);
    return 0;
}