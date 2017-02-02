/*
ID: abdulah2
PROG: milk2
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
#define dbg2(n,m) cerr<<#n<<=n<<","<<#m<<"="<<m<<endl;

///vars
int n;

void solve()
{
    cin>>n;
    int mna=0,mxa=0;

    vector<pair<int,int> >v;
    for(int i=0;i<n;++i)
    {
        int a,b;
        cin>>a>>b;
        v.pb({a,b});
    }
    sort(all(v));
    mna = v[0].X;
    mxa = v[0].Y;
    int ans1=mxa-mna,ans2=0;
    for(int i=1;i<sz(v);++i)
    {
        //cout<<v[i].X<<" "<<v[i].Y<<endl;
        if(v[i].X <= mxa)
        {
            mxa = max(mxa,v[i].Y);
        }
        else
        {
            ans1 = max(ans1,mxa-mna);
            ans2 = max(ans2,v[i].X - mxa);
            mna = v[i].X;
            mxa = v[i].Y;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
}

int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    solve();
    return 0;
}

