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
int st[N][20];
string s;

void solveUsingSparseTable()
{
    n = Int();
    for(int i=0;i<n;++i) arr[i] = Int();

    for(int i = 0;i<n;++i)
        st[i][0] = i;

    for(int j = 1;(1<<j) <= n;++j)
    {
        for(int i=0; i + (1<<(j-1)) < n ; ++i)
        {
            if(arr[st[i][j-1]] <= arr[st[i + (1<<(j-1))][j-1]])
                st[i][j] = st[i][j-1];
            else 
                st[i][j] = st[i + (1<<(j-1))][j-1];
        }
    }

    c = Int();
    while(c--)
    {
        int l = Int(), r = Int();
        int len = r - l + 1;
        int j = log2(len);
        int ans = min(arr[st[l][k]],arr[st[r + 1 - (1<<k)][k]]);
        printf("%d\n",ans);
    }
}

int tree[2*(1<<17)],lazy[2*(1<<17)];

int build(int node,int b,int e)
{
    if(b==e) 
    {
        tree[node] = arr[b];
        return tree[node];
    }
    int mid = (b+e) >> 1;
    return tree[node] = min(build(node*2 + 1,b,mid),build(node*2 + 2, mid+1,e));
}

int query(int node,int b,int e,int qs,int qe)
{
    if(b >= qs && e <= qe) return tree[node];
    if(b > qe || e < qs) return INT_MAX;
    int mid = (b+e) >> 1;
    return min(query(node*2+1,b,mid,qs,qe),query(node*2+2,mid+1,e,qs,qe));
}

void single_update(int node,int b,int e,int ss,int se,int newVal)
{
    if(b > e || b > se || e < ss) return;
    if(b==e)
    {
        tree[node] = newVal;
        return;
    }
    int mid = (b+e) >> 1;
    single_update(node*2+1,b,mid,ss,se,newVal);
    single_update(node*2+2,mid+1,e,ss,se,newVal);
    tree[node] = min(tree[node*2+1],tree[node*2+2]);
}

void lazy_update(int node,int b,int e,int us,int ue,int uval)
{
    if(lazy[node])   //this part would be in query too if lazy propogation used
    {
        tree[node] += (e - b +1 ) * lazy[node]; 
        if(b != e) //not leaf
        {
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(b > e || b > ue || e < us) return;
    if(us <= b && e <= ue)
    {
        tree[node] += (e-b+1)*  uval; 
        if(b != e) //not leaf
        {
            lazy[2*node+1] += uval;
            lazy[2*node+2] += uval;
        } 
        return; 
    }
    int mid = (b+e)>>1;
    lazy_update(node*2+1,b,mid,us,ue,uval);
    lazy_update(node*2+2,mid+1,e,us,ue,uval);
    tree[node] = min(tree[node*2+1],tree[node*2+2]);
}

void segmentTreeApproach()
{
    build(0,0,n-1);
}

void solve()
{
    n = Int();
    for(int i=0;i<n;++i) arr[i] = Int();
    segmentTreeApproach();    
    c = Int();
    while(c--)
    {
        int l = Int(), r = Int();
        int ans = query(0,0,n-1,l,r);
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
