/*
ID: abdulah2
PROG: beads
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(x) (int)x.size()
#define dbg(n) cerr<<#n<<"="<<n<<endl;
#define dbg2(n,m) cerr<<#n<<"="<<n<<","<<#m<<"="<<m<<endl;

///vars
int n;
string s;

void solve()
{
    cin>>n;
    cin>>s;
    int mx=0;
    for(int i=0;i<sz(s);++i)
    {
        int c=0;
        bool b=false,r=false;
        for(int j=i;c!=n;++j)
        {
           // cout<<s[j];
            if(s[j]=='b')
            {
                if(r) break;
                b=true;
            }
            else if(s[j]=='r')
            {
                if(b) break;
                r=true;
            }
            c++;
            if(j==sz(s)-1)
            {
                j=-1;
            }
        }
        //cout<<endl;
        b = false,r=false;
        int j,d=0;
        if(i==0) j=sz(s)-1;
        else j=i-1;
        for(;d!=n;--j)
        {
            //dbg(j);
          //  cout<<s[j];
            if(s[j]=='b')
            {
                if(r) break;
                b=true;
            }
            else if(s[j]=='r')
            {
                if(b) break;
                r=true;
            }
            d++;
            if(j==0)
            {
                j=sz(s);
            }
        }
       /// cout<<endl;
       // dbg2(c,d);
        if(c+d >= n)
        {
            mx = max(mx,n);
        }
        else
        {
            mx = max(mx,c+d);
        }
    }
    cout<<mx<<endl;
}

int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    solve();
    return 0;
}

