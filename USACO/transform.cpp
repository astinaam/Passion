/*
ID: abdulah2
PROG: transform
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
#define err(s) cerr<<s<<":"<<endl;

///vars
int n;
string s;
string cng[11];

void change(string arr[],int x)
{
    if(x==90)
    {
        for(int i=0; i<n; ++i)
        {
            int k=0;
            for(int j = n-1 ; j>=0; --j)
            {
                cng[i].pb(arr[j][i]);
            }
        }
    }
    else if(x==180)
    {
        int k=n-1;
        for(int i=0; i<n; ++i)
        {
            string tmp = arr[k--];
            reverse(all(tmp));
            cng[i] = tmp;
        }
    }
    else if(x==270)
    {
        change(arr,90);
        err("changing 90 ");
        for(int i=0; i<n; ++i)
        {
            cerr<<cng[i]<<endl;
        }
        change(cng,90);
        err("changing 90 ");
        for(int i=0; i<n; ++i)
        {
            cerr<<cng[i]<<endl;
        }
        change(cng,90);
        err("changing 90 ");
        for(int i=0; i<n; ++i)
        {
            cerr<<cng[i]<<endl;
        }
    }
}

bool isSame(string x[],string y[])
{
    for(int i=0; i<n; ++i)
    {
        if(x[i]!=y[i])
            return false;
    }
    return true;
}

void solve()
{
    cin>>n;
    string data[n],tm[n],tran[n];
    for(int i=0; i<n; ++i)
    {
        cin>>s;
        data[i]=s;
        tm[i]=s;
    }
    for(int i=0; i<n; ++i)
    {
        cin>>tran[i];
    }

    change(data,90);
    err("changing 90 ");
    for(int i=0; i<n; ++i)
    {
        cerr<<cng[i]<<endl;
    }
    if(isSame(cng,tran))
    {
        cout<<1<<endl;
        return;
    }
    for(int i=0; i<n; ++i)
    {
        cng[i].clear();
    }
    change(data,180);
    err("changing 180 ");
    for(int i=0; i<n; ++i)
    {
        cerr<<cng[i]<<endl;
    }
    if(isSame(cng,tran))
    {
        cout<<2<<endl;
        return;
    }
    for(int i=0; i<n; ++i)
    {
        cng[i].clear();
    }
    change(data,270);
    err("changing 270 ");
    for(int i=0; i<n; ++i)
    {
        cerr<<cng[i]<<endl;
    }
    if(isSame(cng,tran))
    {
        cout<<3<<endl;
        return;
    }
    for(int i=0; i<n; ++i)
    {
        cng[i].clear();
    }
    for(int i=0; i<n; ++i)
    {
        reverse(all(tm[i]));
    }
    int m=0;
    for(int i=0; i<n; ++i)
    {
        if(tm[i]!=tran[i])
        {
            m=1;
            break;
        }
    }
    if(!m)
    {
        cout<<4<<endl;
        return;
    }
    change(tm,90);
    if(isSame(cng,tran))
    {
        cout<<5<<endl;
        return;
    }
    for(int i=0; i<n; ++i)
    {
        cng[i].clear();
    }
    change(tm,180);
    if(isSame(cng,tran))
    {
        cout<<5<<endl;
        return;
    }
    for(int i=0; i<n; ++i)
    {
        cng[i].clear();
    }
    change(tm,270);
    if(isSame(cng,tran))
    {
        cout<<5<<endl;
        return;
    }
    if(isSame(data,tran))
    {
        cout<<6<<endl;
    }
    else
        cout<<7<<endl;
}

int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    solve();
    return 0;
}

