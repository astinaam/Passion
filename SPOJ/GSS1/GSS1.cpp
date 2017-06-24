#include<bits/stdc++.h>
using namespace std;
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
#define Mahmud main()
#define endl "\n"
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define alla(arr,n) arr,arr+n
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define pb push_back
///Debug
#define dbg1(x) std::cerr<<#x<<"="<<(x)<<endl;
#define dbg2(x,y) std::cerr<<#x<<"="<<(x)<<','<<#y<<"="<<(y)<<endl;
#define dbg3(x,y,z) std::cerr<<#x<<"="<<(x)<<','<<#y<<"="<<(y)<<','<<#z<<"="<<(z)<<endl;
#define dbgArr(arr,n) cerr<<#arr<<"=["; printArray(arr,n,0,93); cerr<<endl;
///traversing
#define rep(n) for(int i=0;i<n;++i)
#define trv(i,t) for(__typeof(t.begin()) i=t.begin();i!=t.end();++i)
///necessary functions
inline ll Int()
{
    ll _x=0,_tmp=1;
    char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar(), _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
inline long double Double()
{
    long double d;
    scanf("%Lf",&d);
    return d;
}
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

///Current Code vars
#define N 100010
long long n,k,c,d;
int arr[N+1],brr[N+1];
///Current Code functions
int tree[2*(1<<17)],maxs[2*(1<<17)],maxp[2*(1<<17)],sum[2*(1<<17)];

void calc(int node)
{
    sum[node] = sum[2*node+1] + sum[2*node+2];
    maxp[node] = max(maxp[node*2+1],sum[node*2+1]+maxp[node*2+2]);
    maxs[node] = max(maxs[node*2+2],sum[node*2+2]+maxs[node*2+1]);
    tree[node] = max(max(tree[node*2+1],tree[node*2+2]),maxs[node*2+1]+maxp[node*2+2]);
}

void build(int node,int b,int e)
{
    //dbg3(node,b,e);
    if(b==e)
    {
        sum[node] = arr[b];
        tree[node] = maxs[node] = maxp[node] = max(INT_MIN,arr[b]);
        return;
    }
    int mid = (b+e)>>1;
    build(node*2+1,b,mid);
    build(node*2+2,mid+1,e);
    calc(node);
}

void query(int node,int b,int e,int qs,int qe,vector<int>&nodes)
{
    if(qs <= b && e <= qe)
    {
        nodes.pb(node);
        return;
    }
   // if(b > qe || e < qs) return INT_MIN;
    int mid = (b+e)>>1;
    if(qe <= mid)  query(node*2+1,b,mid,qs,qe,nodes);
    if(qs > mid)  query(node*2+2,mid+1,e,qs,qe,nodes);
}

int mquery(int l,int r)
{
    vector<int>nodes;
    query(0,0,n-1,l,r,nodes);
    int res = -2e9;
    int t = -2e9;
    for(auto x : nodes)
    {
        res = max(res,tree[x]);
        res = max(res,t+maxp[x]);
        t = max(t+sum[x],maxs[x]);
    }
    return res;
}

void solve()
{
    n = Int();
    for(int i=0;i<n;++i) arr[i] = Int();
    k = Int();
    build(0,0,n-1);
    while(k--)
    {
        int l = Int(), r= Int();
        l--;r--;
        int ans = mquery(l,r);
        printf("%d\n",ans);
    }
}

int Mahmud
{
    // ios_base::sync_with_stdio(0); //cin.tie(0);
  //#ifdef _LOCAL_
    //freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
  //while(1)
    solve();
  //#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
  //#endif
    return 0;
}
