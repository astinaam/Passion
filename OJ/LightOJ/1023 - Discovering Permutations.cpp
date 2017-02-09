///@author Mahmud
#include<bits/stdc++.h>

using namespace std;

int t,n,k;
int cnt;

int chk[26],arr[26];

void permutation(int x)
{
    if(x==n)
    {
        for(int i=0;i<n;++i)
            printf("%c",arr[i]+'A');
        puts("");
        cnt++;
        return;
    }
    if(cnt >= k) return;
    for(int i=0;i<n;++i)
    {
        if(!chk[i])
        {
            arr[x] = i;
            chk[i] = 1;
            permutation(x+1);
            chk[i] = 0;  //backtracking
        }
    }
}

int main()
{
    scanf("%d",&t);
    for(int cs=1;cs<=t;++cs)
    {
        scanf("%d%d",&n,&k);
        printf("Case %d:\n",cs);
        int arr[n];
        for(int i=0;i<n;++i)
            arr[i]=i;
        memset(chk,0,sizeof chk);
        permutation(0);
        cnt=0;
    }
}
