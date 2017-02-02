/*
ID: abdulah2
PROG: palsquare
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
int b;

string tos(int x)
{
    ostringstream ss;
    ss << x;
    return ss.str();
}

string conversion(int x)
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
    cin>>b;
    for(int i=1;i<=300;++i)
    {
        int x = i*i;
        string xx = conversion(x);
        string xxx = conversion(i);
        string xy = xx;
        reverse(all(xy));
        if(xy==xx)
            cout<<xxx<<" "<<xx<<endl;
    }
}

int main()
{
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    solve();
    return 0;
}
