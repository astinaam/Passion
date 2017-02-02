/*
ID: abdulah2
PROG: gift1
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(x) (int)x.size()
#define F first
#define S second
#define dbg(n) cerr<<#n<<"="<<n<<endl;
#define dbg2(n,m) cerr<<#n<<=n<<","<<#m<<"="<<m<<endl;

///vars
string s;
int n,a,b;
vector<pair<string,int> > groups;

///functions
int findex(string x)
{
    for(int i=0;i<sz(groups);++i)
    {
        if(x==groups[i].first)
            return i;
    }
}


void solve()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>s;
        groups.pb({s,0});
    }
    for(int i=0;i<n;++i)
    {
        cin>>s;
        cin>>a>>b;
        int idx = findex(s);
        int x;
        if(b!=0)
        {
            x = a%b;
            groups[idx].second += x;
            x = a/b;
            groups[idx].second -= a;
        }

        while(b--)
        {
            cin>>s;
            idx = findex(s);
            groups[idx].S += x;
        }
    }
    for(auto x : groups)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
}

int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    solve();
    return 0;
}

