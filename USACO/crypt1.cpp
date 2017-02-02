/*
ID: abdulah2
PROG: crypt1
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

int arr[111];

bool chk(int num,int lim1,int lim2)
{
    if(num < lim1 || num>lim2) return false;
    while(num)
    {
        bool x = false;
        int rm = num%10;
        for(int i=0;i<n;++i)
        {
            if(arr[i]==rm)
            {
                x = true;
                break;
            }
        }
        if(!x) return false;
        num /= 10;
    }
    return true;
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int tm;
        cin>>tm;
        arr[i]=tm;
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                int num = arr[i]*100+arr[j]*10+arr[k];
                for(int l=0;l<n;++l)
                {
                    int p = arr[l];
                    if(!chk(p*num,100,999)) continue;
                    for(int m=0;m<n;++m)
                    {
                        int q = arr[m];
                        if(!chk(q*num,100,999)) continue;
                        int gn = p*10 + q;
                        if(chk(gn*num,1000,9999))
                        {
                            dbg2(p*num,q*num);
                            dbg(gn*num);
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    solve();
    return 0;
}

