/*
ID: abdulah2
PROG: skidesign
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define X first
#define Y second
#define sz(x) (int)x.size()
#define dbg(n) cerr<<#n<<"="<<n<<endl;
#define dbg2(n,m) cerr<<#n<<"="<<n<<","<<#m<<"="<<m<<endl;
#define err(s) cerr<<s<<":"<<endl;

///vars
int n;
int arr[1111];
int mn,mx,imx,imn;

void solve()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int ans=11111111;
    for(int interval=0;interval<84;interval++)
    {
        mx=0;
        for(int i=0;i<n;++i)
        {
            //dbg2(arr[i],interval);
            if(arr[i]<interval)
            {
                int k = interval - arr[i];
                mx += k*k;
              //  dbg(mx);
            }
            if(arr[i] > interval+17)
            {
                int k = arr[i] - (interval+17);
                mx += k*k;
                //dbg(mx);
            }
        }
        //dbg(mx);
        ans = min(ans,mx);
    }
    cout<<ans<<endl;
}

int main()
{
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    solve();
    return 0;
}

