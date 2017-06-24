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

///Current Code vars
#define N 1000010
long long n,q,c,d;
int arr[N+1],brr[N+1];
///Current Code functions

struct data
{
    int one,two,yes,p;
    data() {one = 0;two=0;yes=1;p=0;};
    data(int a,int b,int c,int d)
    {
        one = a;
        two = b;
        yes = c;
        p = d;
    }
    void print()
    {
        cerr<<"{"<<one<<","<<two<<","<<yes<<" "<<p<<"}"<<endl;
    }
};

data tree[4*N];

data plas(data onee,data other)
{
    data ret;
    ret.one = other.one + onee.one;
    ret.two = other.two + onee.two;
    ret.yes = other.yes + onee.yes;
    //ret.p   = other.p   + onee.p  ;
    ret.p   = 0;
    return ret;
}

void merge(int node)
{
    int left = node*2+1, right = node*2+2;
    tree[node].one = tree[left].one + tree[right].one;
    tree[node].two = tree[left].two + tree[right].two;
    tree[node].yes = tree[left].yes + tree[right].yes;
    //tree[node].p   = tree[left].p + tree[right].p;
}

void build(int node,int b,int e)
{
    //cerr<<"node "<<b<<" "<<e<<endl;
    if(b==e)
    {
        tree[node] = data(0,0,1,0);
        return;
    }
    int mid = (b+e)/2;
    build(node*2+1,b,mid);
    build(node*2+2,mid+1,e);
    merge(node);
    
}

void propagate(int node,int b,int e)
{
    //cerr<<"propagating "<<node<<" "<<b<<" "<<e<<endl;
    //cerr<<"propagation "<<tree[node].p<<endl;
    //tree[node].p %= 3;
    //cerr<<"propagation "<<tree[node].p<<endl;
    //cerr<<"before propagation "<<endl;
    //cerr<<"parent "; tree[node].print();
    //if(b!=e){
      //  cerr<<"left "; tree[node*2+1].print();
        //cerr<<"right "; tree[node*2+2].print();
    //}
    int on = tree[node].one, tw = tree[node].two, th = tree[node].yes;
    if(tree[node].p==1)
    {   
        tree[node].yes = tw;
        tree[node].one = th;
        tree[node].two = on;
        
        if(b!=e)
        {
            tree[node*2+1].p += 1;
            tree[node*2+2].p += 1;

            tree[node*2+1].p %= 3;
            tree[node*2+2].p %= 3;
        }
        tree[node].p = 0;
    }
    if(tree[node].p==2)
    {
        tree[node].one = tw;
        tree[node].two = th;
        tree[node].yes = on;
        if(b!=e)
        {
            tree[node*2+1].p += 2;
            tree[node*2+2].p += 2;
            tree[node*2+1].p %= 3;
            tree[node*2+2].p %= 3;
        }
        tree[node].p = 0;
    }
    //cerr<<"after propagation "<<endl;
    //cerr<<"parent "; tree[node].print();
    //if(b!=e){
      //  cerr<<"left "; tree[node*2+1].print();
        //cerr<<"right "; tree[node*2+2].print();
    //}
}

data query(int node,int b,int e,int qs,int qe)
{
    //cerr<<"now at "<<node <<" "<<b<<" "<<e<<" "<<tree[node].p<<endl;
    propagate(node,b,e);
    //cerr<<"propagated"<<endl;
    if(b >= qs && e <= qe) return tree[node];
    //cerr<<"invalid"<<endl;
    if(b > qe || e < qs)
    {
        data rt = data(0,0,0,0);
      ///  cerr<<"invalid returned "; rt.print();
        return rt;
    }
    //cerr<<"partial"<<endl;
    int mid = (b+e)/2;
    //cerr<<"mid "<<mid<<endl;
   // if(qe <= mid) return query(node*2+1,b,mid,qs,qe);
   // if(qs > mid) return query(node*2+2,mid+1,e,qs,qe);
    data x1 = query(node*2+1,b,mid,qs,qe);
    //cerr<<"got 1. "; x1.print();
    data x2 = query(node*2+2,mid+1,e,qs,qe);
    //cerr<<"got 2. "; x1.print();
    data x = plas(x1,x2);
    //cerr<<"merging "<<node*2+1<<" "<<node*2+2<<endl;
    //cerr<<"1. "; x1.print();
    //cerr<<"2. "; x2.print();
    //cerr<<"resulting to "; x.print();
    //cerr<<"returned "<<x<<endl;
    return x;
}

// void update(int node,int b,int e,int us,int ue)
// {
//     if(b > e || b > ue || e < us) return;
//     if(b==e)
//     {
//         tree[node].times++;
//       //  dbg1(tree[node].times);
//         tree[node].status = tree[node].times % 3 == 0 ? 1 : 0;
//         tree[node].ans = tree[node].status ? 1 : 0;
//         return;
//     }
//     int mid = (b+e)/2;
//     update(node*2+1,b,mid,us,ue);
//     update(node*2+2,mid+1,e,us,ue);
//     merge(node);
// }

void lazy_update(int node,int b,int e,int us,int ue)
{
   // cerr<<"now in "<<node<<" "<<b<<" "<<e<<endl;
    propagate(node,b,e);
    if(us <= b && e <= ue)
    {
        tree[node].p++;
        propagate(node,b,e);
        return;
    }
    if(b > e || b > ue || e < us) return;
    int mid = (b+e)/2;
    lazy_update(node*2+1,b,mid,us,ue);
    lazy_update(node*2+2,mid+1,e,us,ue);
    merge(node);
   // cerr<<"merging "<<node*2+1<<" "<<node*2+2<<endl;
   // cerr<<"1. ";tree[node*2+1].print();
   // cerr<<"2. ";tree[node*2+2].print();
   // cerr<<"resulting to ";tree[node].print();
}

void solve()
{
     n = Int(); q = Int();
     build(0,0,n-1);
     //return;
     while(q--)
     {
        int op = Int(), l = Int(), r = Int();
        if(op==1)
        {
           // cout<<"====query of "<<l<<" "<<r<<"===="<< " ";
            //cerr<<"====query of "<<l<<" "<<r<<"===="<<endl;
            data ans = query(0,0,n-1,l,r);
           // cerr<<"answer property : "; ans.print();
            printf("%d\n",ans.yes);
        }
        else
        {
          //  cerr<<"====update of "<<l<<" "<<r<<"===="<<endl;
            //cout<<"====update of "<<l<<" "<<r<<"===="<<endl;
            lazy_update(0,0,n-1,l,r);
        }
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
