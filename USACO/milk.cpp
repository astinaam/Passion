/*
ID: abdulah2
PROG: milk
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define X first
#define Y second
#define sz(x) (int)x.size()
#define dbg(n) cout<<#n<<"="<<n<<endl;
#define dbg2(n,m) cout<<#n<<"="<<n<<","<<#m<<"="<<m<<endl;
#define err(s) cerr<<s<<":"<<endl;

///vars
int n,m;
vector<pair<int,int> > v;

void solve()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        v.pb({a,b});
    }
    sort(all(v));
    int w=n,cur=0,cost=0;
    for(int i=0;i<sz(v);++i)
    {
        //cout<<v[i].first<<" "<<v[i].second<<endl;
        if(cur+v[i].second <= w)
        {
            cur += v[i].second;
            cost += v[i].first*v[i].second;
            //dbg2(cur,cost);
            //w -= v[i].second;
            //dbg(w);
        }
        else
        {
            int remain = w - cur;
            cost += remain*v[i].first;
            break;
        }
    }
    cout<<cost<<endl;
}

int main()
{
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    solve();
    return 0;
}

