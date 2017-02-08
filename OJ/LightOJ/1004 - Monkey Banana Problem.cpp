#include<bits/stdc++.h>

using namespace std;

int t,n;

int main()
{
    scanf("%d",&t);
    for(int cs=1;cs<=t;++cs)
    {
        scanf("%d",&n);
        vector<int>arr[2*n],dp[2*n];
        for(int i=1;i<2*n;++i)
        {
            int lim = i;
            if(i>n) lim =n - (i - n);
            arr[i].push_back(0);
            dp[i].push_back(0);
            //cerr<<i<<" "<<lim<<endl;
            for(int j=0;j<lim;++j)
            {

                int x;
                scanf("%d",&x);
                arr[i].push_back(x);
                dp[i].push_back(x);
            }
        }
        int ans = dp[1][1];
        for(int i=2;i<2*n;++i)
        {
            int lim = i;
            if(i>n) lim = n - (i-n);
            for(int j=1;j<dp[i].size();++j)
            {
                //cerr<<arr[i][j]<<"("<<dp[i][j]<<") ";
                if(i<=n)
                {
                    if(j==1)
                        dp[i][j] = max(dp[i][j],dp[i][j]+dp[i-1][j]);
                    else if(j==i)
                        dp[i][j] = max(dp[i][j]+dp[i-1][j-1],dp[i][j]);
                    else
                        dp[i][j] = max(dp[i][j]+dp[i-1][j-1],dp[i][j]+dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = max(dp[i][j]+dp[i-1][j],dp[i][j]+dp[i-1][j+1]);
                }
            }
           // cerr<<endl;
        }
        ans = max(dp[1][1],dp[2*n - 1][1]);
        printf("Case %d: %d\n",cs,ans);
    }
}
