/*
ID: abdulah2
PROG: wormhole
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
int X[222],Y[222];
int p[222];
int nxt[222];

bool isCycle()
{
    for(int i=1;i<=n;++i)
    {
        int pos = i;
        for(int j=01;j<=n;++j)
        {
            //cerr<<pos<<":"<<p[pos]<<endl;
            pos = nxt[p[pos]];
        }
        if(pos) return true;
    }
    return false;
}

int gen()
{
    int i,tot=0;
    for(i=1;i<=n;++i)
    {
        //cerr<<p[i]<<" ";
        if(p[i]==0) break;
    }
    //cerr<<endl<<i<<endl;
    if(i>=n)
    {
        if(isCycle()) return 1;
        return 0;
    }
    for(int j=i+1;j<=n;++j)
    {
        if(p[j]==0)
        {
            p[i] = j;
            p[j] = i;
            tot += gen();
            p[i] = p[j] = 0;
        }
    }
    return tot;
}


void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>X[i]>>Y[i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            //dbg2(i,j);
            //dbg2(X[i],X[j]);
            //dbg2(Y[i],Y[j]);
            if(X[i] < X[j] && Y[i]==Y[j])
            {
                //dbg(nxt[i]);
                if(nxt[i]==0 || X[j]-X[i] < X[nxt[i]]-X[i])
                {
                    nxt[i] = j;
                }
            }
        }
       // dbg2("err",nxt[i]);
    }
    int ans = gen();
    cout<<ans<<endl;
}

int main()
{
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);
    solve();
    return 0;
}

