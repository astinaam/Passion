/*
ID: abdulah2
PROG: dualpal
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
int n,s;

string tos(int x)
{
    ostringstream ss;
    ss << x;
    return ss.str();
}

string conversion(int x,int b)
{
    string done;
    // dbg(x);
    while(x)
    {
        int rm = x%b;
        if(rm==10)
            done.pb('A');
        else if(rm==11)
            done.pb('B');
        else if(rm==12)
            done.pb('C');
        else if(rm==13)
            done.pb('D');
        else if(rm==14)
            done.pb('E');
        else if(rm==15)
            done.pb('F');
        else if(rm==16)
            done.pb('G');
        else if(rm==17)
            done.pb('H');
        else if(rm==18)
            done.pb('I');
        else if(rm==19)
            done.pb('J');
        else if(rm==20)
            done.pb('K');
        else
            done.pb(rm+'0');
        x /= b;
    }
    //dbg(done);
    string rv = done;
    reverse(all(rv));
    //dbg(rv);
    return rv;
}

void solve()
{
    cin>>n>>s;
    int p=0;
    for(int i=s+1; p < n; ++i)
    {
        int x=0;
        for(int j=2; j<=10; ++j)
        {
            if(x>=2)
                break;
            string xx = conversion(i,j);
            string xy = xx;
            reverse(all(xy));
            if(xy==xx)
                x++;
        }
        if(x>=2)
        {
            p++;
            cout<<i<<endl;
        }
    }
}

int main()
{
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    solve();
    return 0;
}

