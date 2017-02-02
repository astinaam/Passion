/*
ID: abdulah2
PROG: friday
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(x) (int)x.size()
#define dbg(n) cerr<<#n<<"="<<n<<endl;
#define dbg2(n,m) cerr<<#n<<=n<<","<<#m<<"="<<m<<endl;

///vars
int n;
int frq[7];

bool isLeapyear(int x)
{
    if(x%4) return false;
    else if(x%100) return true;
    else if(x%400) return false;
    else return true;
}

void solve()
{
    cin>>n;
    int day=2;
    for(int i=1900;i<1900+n;++i)
    {
        for(int j=1;j<=12;++j)
        {
            int fq = day + 12;
            fq %= 7;
            frq[fq]++;
            //cout<<"year="<<i<<" month="<<j<<endl;

            if(j==2 || j==4 || j==6 || j==9 || j==11)
            {
                if(j==2)
                {
                    if(isLeapyear(i))
                    {
                        day += 29;
                    }
                    else
                        day += 28;
                }
                else
                {

                    day += 30;
                }
                day %= 7;
            }
            else
            {
                day += 31;
                day %= 7;
            }
        }
    }
    for(int i=0;i<6;++i)
        cout<<frq[i]<<" ";
    cout<<frq[6]<<endl;
}

int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    solve();
    return 0;
}

