#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define N 100010
long long n,k,c,d;
int arr[N+1],brr[N+1];
///Current Code functions

struct data{
    int suffix,prefix,sum,ans;
    data()
    {
        suffix = prefix = ans = INT_MIN;
        sum = 0;
    }
    data(int a,int b,int c,int d)
    {
        sum = a;
        suffix = b;
        prefix = c;
        ans = d;
    }
    void priint()
    {
        cerr<<"{"<<sum<<","<<suffix<<","<<prefix<<","<<ans<<"}"<<endl;
    }
};

data tree[2*(1<<17)];

void merge(int node)
{
    int left = node*2 + 1, right = node*2 + 2;
    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].suffix = max(tree[right].suffix,tree[right].sum+tree[left].suffix);
    tree[node].prefix = max(tree[left].prefix,tree[left].sum+tree[right].prefix);
    tree[node].ans = max(max(tree[left].ans,tree[right].ans),tree[left].suffix+tree[right].prefix);
}

void build(int node,int b,int e)
{
    //cerr<<"node in "<<node<<" "<<b<<" "<<e<<endl;
    if(b==e)
    {
      //  cerr<<"entered!"<<endl;
        tree[node] = data(arr[b],arr[b],arr[b],arr[b]);
        return;
    }
    int mid = (b+e)/2;
    build(node*2+1,b,mid);
    build(node*2+2,mid+1,e);
    merge(node);
    //cerr<<"merging "<<node*2+1<<","<<node*2+2<<endl;
    //cerr<<"1. "; tree[node*2+1].priint();
    //cerr<<"2. "; tree[node*2+2].priint();
    //cerr<<"resulting to : "; tree[node].priint();
}

data query(int node,int b,int e,int qs,int qe)
{
    //cerr<<"node in "<<node<<" "<<b<<" "<<e<<endl;
    if(b >= qs && e <= qe) 
        {
      //      cerr<<"returned "; tree[node].priint();
            return tree[node];
        }
    //cerr<<"invalid"<<endl;
    if(b > qe || e < qs) return data(0,-100000,-100000,-100000);
    //cerr<<"partial"<<endl;
    int mid = (b+e)/2;
    data d1 = query(node*2+1,b,mid,qs,qe);
    data d2 = query(node*2+2,mid+1,e,qs,qe);
    //cerr<<"merging "<<node*2+1<<","<<node*2+2<<endl;
    //cerr<<"1. "; d1.priint();
    //cerr<<"2. "; d2.priint();
    data ret;
    ret.sum = d1.sum + d2.sum;
    ret.suffix = max( d2.suffix , d2.sum + d1.suffix);
    ret.prefix = max(d1.prefix, d1.sum + d2.prefix);
    ret.ans = max(max(d1.ans,d2.ans),d1.suffix+d2.prefix);
    //cerr<<"resulting to : "; ret.priint();
    return ret;
}

void update(int node,int b,int e,int us,int ue,int val)
{
    //cerr<<"now in "<<node<<" "<<b<<" "<<e<<endl;
    //cerr<<"invalid"<<endl;
    if(b > ue || e < us || b > e) return;
    if(b==e)
    {
    //    cerr<<"in leaf!"<<endl;
        tree[node] = data(val,val,val,val);
        return;
    }
    //cerr<<"partial"<<endl;
    int mid = (b+e)/2;
    update(node*2+1,b,mid,us,ue,val);
    update(node*2+2,mid+1,e,us,ue,val);
    merge(node);
    //cerr<<"merging "<<node*2+1<<","<<node*2+2<<endl;
    //cerr<<"1. "; tree[node*2+1].priint();
    //cerr<<"2. "; tree[node*2+2].priint();
    //cerr<<"resulting to : "; tree[node].priint();
}

void solve()
{
    n = Int();
    for(int i=0;i<n;++i) arr[i] = Int();
    build(0,0,n-1);
    int q = Int();
    //tree[2].priint();
    while(q--)
    {
        int p,l,r;
        p = Int();
        l = Int();
        r = Int();
        if(p==0)
        {
            update(0,0,n-1,l-1,l-1,r);
        }
        else
        {
            int ans = query(0,0,n-1,l-1,r-1).ans;
            printf("%d\n",ans);
        }
    }
}

int main()
{
    solve();
    return 0;
}
