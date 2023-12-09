#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;


long long quick_mod(long long base, long long exp, long long mod) {
    long long ans = 1;
    for (; exp > 0; exp >>= 1)
    {
        if ((exp & 1) == 1)
        {
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
    }
    return ans;
}

bool isprime(long num,int k=4)
{
    if (num == 1)return false;
    if (num == 2)return true;
    if (num % 2 == 0)return false;
    for (int i = 0; i < k; i++)
    {
        long num_m1 = num - 1;
        int a = 2 + rand() % (num - 4);
        long long a_mod;
        if ((a_mod=quick_mod(a, num_m1,num))!= 1)return false;
        while (num_m1 % 2 == 0)
        {
            num_m1 /= 2;
            if ((a_mod = quick_mod(a, num_m1,num)) == 1)
                continue;
            else if (a_mod != (num-1))return false;
            else break;
        }
    }
    return true;
}



int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        long num;
        scanf("%ld",&num);
        if (isprime(num))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}