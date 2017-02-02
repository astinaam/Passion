/*
ID: abdulah2
PROG: ride
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define dbg(n) cerr<<#n<<"="<<n<<endl;
#define dbg2(n,m) cerr<<#n<<=n<<","<<#m<<"="<<m<<endl;

void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    int x1=1,x2=1;
    for(int i=0;i<s1.size();++i)
    {
        int tm = s1[i]-'A';
        tm++;
        x1 *= tm;
    }
    for(int i=0;i<s2.size();++i)
    {
        int tm = s2[i]-'A';
        tm++;
        x2 *= tm;
    }
    if(x1%47 == x2%47)
        cout<<"GO"<<endl;
    else cout<<"STAY"<<endl;
}

int main()
{
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    solve();
    return 0;
}

