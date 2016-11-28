///Abdullah Al Mahmud
///Khulna University

#include<bits/stdc++.h>

using namespace std;

const unsigned int M = 1000000007;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9+21;
const long long LINF = (long long) 1e18;
const long double PI = 2 * acos((long double)0);

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef complex<double> point;

#define Mahmud main()
#define endl "\n"
///STL
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
///Debug
#define dbg(x) std::cerr<<"["<<__LINE__<<"]"<<#x<<"="<<(x)<<endl;
#define dbg1(x) std::cerr<<#x<<"="<<(x)<<endl;
#define dbg2(x,y) std::cerr<<#x<<"="<<(x)<<','<<#y<<"="<<(y)<<endl;
#define dbg3(x,y,z) std::cerr<<#x<<"="<<(x)<<','<<#y<<"="<<(y)<<','<<#z<<"="<<(z)<<endl;
#define dbgArr(arr,n) cerr<<#arr<<"=["; printArray(arr,n,0,93); cerr<<endl;
///traversing
#define rep(n) for(int i=0;i<(n);++i)
#define per(n) for(int j=0;j<(n);++j)
#define PER(s,e) for(int j=(s);j<=(e);++j)
#define REP(s,e) for(int i=(s);i<=(e);++i)
#define trv(i,t) for(__typeof(t.begin()) i=t.begin();i!=t.end();++i)
///STL Print
template<class x,class y>
void printArray(x arr[],y sizeOfArray,y from=0,y e=10)
{
    for(y i=from; i<sizeOfArray; ++i)
        cout<<arr[i]<<((i<sizeOfArray-1)?" ":"");
    cout<<(char)e;
}
template<class x,class y>
inline ostream &operator<<(ostream &os,const pair<x,y>& p)
{
    os<<"{"<<p.fi<<" "<<p.se<<"}";
    return os;
}
template<class x,class y>
inline ostream &operator<<(ostream &os,const map<x,y>& m)
{
    for(typename map<x,y>::const_iterator itr=m.begin(); itr!=m.end(); ++itr)
        os<<itr->fi<<"="<<itr->se<<endl;
    return os;
}
template<class x>
inline ostream &operator<<(ostream &os,const set<x>& s)
{
    for(typename set<x>::const_iterator itr=s.begin(); itr!=s.end(); ++itr)
        os<<((itr==s.begin())?"":" ")<<*itr;
    return os;
}
template<class x>
inline ostream &operator<<(ostream &os,const vector<x>& s)
{
    for(typename vector<x>::const_iterator itr=s.begin(); itr!=s.end(); ++itr)
        os<<((itr==s.begin())?"":" ")<<*itr;
    return os;
}
///STL input
template<class x,class y>
inline istream &operator>>(istream& in,pair<x,y>& p)
{
    in >> p.fi >> p.se;
    return in;
}
template<class x>
inline istream &operator>>(istream& in,vector<x>& v)
{
    if(sz(v)) for(x &gt : v) in>>gt;
    else
    {
        string s;
        x obj;
        while(s.empty())
        {
            getline(in,s);
            if(!in) return in;//if empty
        }
        stringstream ss(s);
        while(ss>>obj) v.pb(obj);
    }
    return in;
}
template<class x>
inline istream &operator>>(istream& in,set<x>& v)
{
    string s;
    x obj;
    while(s.empty())
    {
        getline(in,s);
        if(!in) return in;//if empty
    }
    stringstream ss(s);
    while(ss>>obj) v.insert(obj);

    return in;
}

#define bitcount(n) __builtin_popcount(n)
#define EPS 1e-9
///necessary functions
ll lcm(ll a,ll b)
{
    return a/__gcd(a,b)*b;
}
int ton(string x)
{
    int y;
    std::istringstream ss(x);
    ss >> y;
    return y;
}
template<typename T>
string tostring(T x)
{
    ostringstream ss;
    ss << x ;
    return ss.str();
}
///UVa 821 - Page Hopping
///Current Code vars
#define MAX 100000
int n;
string s;
vector<int>graph[101];
///Current Code functions

void solve()
{
    int a,b,x=0;
    int cs=1;
    set<int>nodes;
    while(1)
    {
        while(cin>>a>>b && a!=0 && b!=0)
        {
            graph[a].pb(b);
            x++;
            nodes.insert(a);
            nodes.insert(b);
        }
        int sz = nodes.size();
        vi dist(101,0);
        int cmb = sz*(sz-1);
        int ts=0;
        for(auto elm : nodes)
        {
            queue<int>q;
            q.push(elm);
           // dbg1(elm);
            int sgsum=0;
            bool visited[101];
            memset(visited,false,sizeof visited);
            visited[elm]=true;
            int track[101];
            memset(track,0,sizeof track);
            while(!q.empty())
            {
                int val = q.front();
                q.pop();
                for(auto ad : graph[val])
                {
                  //  dbg2(ad,val);
                    if(!visited[ad])
                    {
                        sgsum += track[val]+1;
                        track[ad] = track[val]+1;
                        visited[ad]=true;
                        q.push(ad);
                    }
                }
            }
           // dbg1(sgsum);
           // int ss=0;
            //rep(101) ss+=track[i];
           // dbg1(ss);
            ts += sgsum;
        }
        //cout<<endl<<ts<<" "<<cmb<<endl;
        double ans = (double)ts/(double)cmb;
        cout<<"Case "<<cs++<<": ";
        cout<<"average length between pages = ";
        cout<<fixed<<setprecision(3)<<ans;
        cout<<" clicks"<<endl;
        x=0;
        nodes.clear();
        for(int i=0;i<101;++i)
            graph[i].clear();
        cin>>a>>b;
        if(a==0 and b==0) break;
        graph[a].pb(b);
        nodes.insert(a);
        nodes.insert(b);
        x++;
    }

}


int Mahmud
{
    ios_base::sync_with_stdio(0); cin.tie(0);
//#ifdef _LOCAL_
    //freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
////while(1)
    solve();

//#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
//#endif
    return 0;
}
