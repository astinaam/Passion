/*
ID: abdulah2
PROG: namenum
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

string s,str;
string ltr[] = {"","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
vector<string>ans;
map<string,int>mp;

void allcombination(vector<string>allvalues,int n,string prefix)
{
    if(n >= sz(allvalues))
    {
        if(mp.count(prefix))
            ans.pb(prefix);
        return;
    }
    for(int i=0;i<allvalues[n].size();++i)
    {
        allcombination(allvalues,n+1,prefix+allvalues[n][i]);
    }
}


void solve()
{
    cin>>s;
    ifstream fin("dict.txt");

    while(fin>>str)
    {
        mp[str] = 1;
        //v.pb(str);
    }
    vector<string>st;
    for(int i=0; i<sz(s); ++i)
    {
        if(s[i]=='1')
        {
            cout<<"NONE"<<endl;
            return;
        }
        st.pb(ltr[s[i]-'0']);
    }
    allcombination(st,0,"");
    for(int i=0;i<sz(ans);++i)
        cout<<ans[i]<<endl;
    if(sz(ans)==0)
        cout<<"NONE"<<endl;
}

int main()
{
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    solve();
    return 0;
}
