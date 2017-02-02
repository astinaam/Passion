/*
ID: abdulah2
PROG: barn1
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
int m,s,c;
int cow[201];
int mem[222];

void solve()
{
    cin>>m>>s>>c;
    int bgaps=0,ans=0;
    vector<pair<int,int> >v;
    for(int i=0;i<c;++i)
    {
        cin>>cow[i];
    }
    sort(cow,cow+c);
    for(int i=1;i<c;++i)
    {
        dbg2(cow[i],cow[i-1]);
        mem[i-1] = cow[i]-cow[i-1];
        dbg(mem[i-1]);
    }
    sort(mem,mem+c-1,greater<int>());
    for(int i=0;i<m-1 && i<c-1;++i)
    {
        dbg2(i,mem[i]);
        ans += mem[i]-1;
    }
    int tot = cow[c-1] - cow[0] + 1;
    cerr<<tot<<endl;
    cout<<tot - ans<<endl;
}

int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    solve();
    return 0;
}

