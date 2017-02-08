#include<bits/stdc++.h>

using namespace std;

int n;
long long dp[100];

int main()
{
    dp[0]=1;
    dp[1]=2;
    dp[2]=2;
    dp[3]=3;
    dp[4]=4;
    for(int i=5;i<=76;++i)
    {
        dp[i] = dp[i-1] + dp[i-5];
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",dp[n-1]);
    }
}
