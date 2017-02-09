///@author Mahmud
#include<bits/stdc++.h>

using namespace std;
int t,n,k;
unsigned long long dp[33][999];

///iterative dp
void precal()
{
    for(int i=1;i<=30;++i)
    {
        dp[i][0]=1;
        for(int j=1;j<=i;++j)
        {
            if(j==1)
                dp[i][j] = i*i;
            else if(j==i)
            {
                dp[i][j] = i*dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = dp[i-1][j-1]*dp[i][1]/j;
            }
        }
    }
}
///recursive dp
unsigned long long rec(int n,int r)
{
    if(r==1) return dp[n][r]=n*n;
    if(r==0) return dp[n][r]=1;
    if(dp[n][r] != -1) return dp[n][r];
    return dp[n][r] = rec(n-1,r-1)*rec(n,1)/r;
}

int main()
{
    //precal(); //iterative
    scanf("%d",&t);
    for(int cs=1;cs<=t;++cs)
    {
        memset(dp,-1,sizeof dp); //recursive
        scanf("%d%d",&n,&k);
        printf("Case %d: %llu\n",cs,rec(n,k));
    }
}
