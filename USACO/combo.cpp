/*
ID: abdulah2
PROG: combo
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
int n,a,b,c,ma,mb,mc;

bool chk1(int a, int b)
{
    if(abs(a-b)<=2) return 1;
    if(abs(a-b)>=n-2) return 1;
    return 0;
}

bool chk(int a1,int b1,int c1,int a2,int b2,int c2)
{
    return (chk1(a1,a2) && chk1(b1,b2) && chk1(c1,c2));
}


void solve()
{
    cin>>n;
    cin>>a>>b>>c;
    cin>>ma>>mb>>mc;
    int ans=0;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            for(int k=1; k<=n; ++k)
            {
                if(chk(i,j,k,a,b,c) || chk(i,j,k,ma,mb,mc))
                {
                    //cerr<<i<<","<<j<<","<<k<<endl;
                    ans++;
                }

            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    solve();
    return 0;

}

