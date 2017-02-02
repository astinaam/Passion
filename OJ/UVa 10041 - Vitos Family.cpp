#include<bits/stdc++.h>

using namespace std;

int t,r;
int arr[501];

int main()
{
    while(scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d",&r);
            int a,b=0,sum1=0,sum2=0;
            for(int i=0; i<r; ++i)
            {
                scanf("%d",&arr[i]);
                sum1 += arr[i];
            }
            int predict = sum1 / r;
            int bl = 0, bg = 0;
            int s1=0,s2=30000;
            bool fuck = true;
            for(int i=0; i<r; ++i)
            {
                if(arr[i]<predict)
                {
                    if(s1 < arr[i]) bl = i,s1=arr[i];
                }
                if(arr[i]>predict)
                {
                    if(s2 > arr[i]) bg = i,s2=arr[i];
                }
                if(arr[i]==predict)
                {
                    bl = i;
                    fuck = false;
                    break;
                }
            }
            //cout<<bl<<bg<<sum2<<predict<<endl;
            if(!fuck)
            {
                //puts("fuck");
                for(int i=0; i<r; ++i)
                {
                    sum2 += abs(arr[bl]-arr[i]);
                }
                printf("%d\n",sum2);
                continue;
            }
            for(int i=0;i<r;++i)
            {
                sum2 += abs(arr[bl]-arr[i]);
            }
            int ans = sum1;
            sum2=0;
            for(int i=0;i<r;++i)
            {
                sum2 += abs(arr[bg]-arr[i]);
            }
            ans = min(ans,sum2);
            printf("%d\n",ans);
        }
    }
}
