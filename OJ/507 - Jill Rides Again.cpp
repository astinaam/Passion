#include<bits/stdc++.h>

using namespace std;


int main()
{
    int r;
    cin>>r;
    for(int cs=1; cs<=r; ++cs)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n-1; ++i)
        {
            cin>>arr[i];
        }
        int a=0,b=0,ans=0,mx=0,s=0;
        for(int i=0; i<n-1; ++i)
        {
            ans += arr[i];
            if(ans<0)
            {
                s=i+1;
                ans=0;
            }

            if(ans >mx)
            {
                mx = ans;
                a = s;
                b = i+1;
            }
            else if(ans==mx)
            {
                if(i+1-s > b-a)
                {
                    a = s;
                    b = i+1;
                }
                else if(i+1-s == b-a)
                {
                    if(s < a)
                    {
                        a = s;
                        b = i+1;
                    }
                }
            }

        }
        if(mx <=0)
            cout<<"Route "<<cs<<" has no nice parts"<<endl;
        else
            cout<<"The nicest part of route "<<cs<<" is between stops "<<a+1<<" and "<<b+1<<endl;
    }
}
