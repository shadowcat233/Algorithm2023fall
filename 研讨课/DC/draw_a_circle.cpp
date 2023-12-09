#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

#define INT_MAX 0x7fffffff

struct node {
    double x;
    double y;
};


int cmpx(node a, node b)
{
    if (a.x < b.x)return 1;
    if (a.x > b.x)return 0;
    if (a.y < b.y)return 1;
    else return 0;
}

int cmpy(node a, node b)
{
    if (a.y < b.y)return 1;
    if (a.y > b.y)return 0;
    if (a.x < b.x)return 1;
    else return 0;
}

double dist(node a, node b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double find_min(vector<node>& points, int left, int right)
{
    if (left == right)return INT_MAX;
    if (right - left == 1)return dist(points[left], points[right]);

    //int n = points.size();
    int mid = (left + right) / 2;
    double posx = (points[mid].x + points[mid + 1].x) / 2;
    double dist_l = find_min(points,left, mid);
    double dist_r = find_min(points,mid + 1, right);
    double dist_lr = dist_l < dist_r ? dist_l : dist_r;
    double min_dist = dist_lr;

    vector<int> t(right-left+1);
    int nt=0;
    for(int i=left;i<=right;i++)
    {
        if(abs(points[i].x-posx)<=min_dist)
            t[nt++]=i;
    }

    for(int i=0;i<nt-1;i++)
    {
        for(int j=i+1;j<nt&&j<i+3;j++)
        {
            if(abs(points[t[i]].y-points[t[j]].y)<min_dist)
            {
                double k=dist(points[t[i]],points[t[j]]);
                min_dist=k<min_dist? k:min_dist;
            }
        }
    }

    /*
    vector<node> yp;
    for (int i = left; i <= right; i++)
    {
        if (abs(points[i].x - posx) <= dist_lr)
            yp.push_back(points[i]);
    }
    int ny = yp.size();
    sort(yp.begin(), yp.end(), cmpy);
    for (int i = 0; i < ny - 1; i++)
    {
        for (int j = i + 1; j < ny; j++)
        {
            int minx=min_dist;
            if (abs(yp[i].x-yp[j].x)>minx)continue;
            if (abs(yp[i].y - yp[j].y) < min_dist)
            {
                double t = dist(yp[i], yp[j]);
                if(t < min_dist)
                {
                    min_dist=t;
                    minx=abs(yp[i].x-yp[j].x);
                }
            }
            else break;
        }
    }*/
    return min_dist;
}

int main()
{
    int n;
    cin >> n;
    vector<node> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end(), cmpx);
    double min_r = find_min(points, 0, n - 1) / 2;
    printf("%.3f\n", min_r);
    return 0;
}