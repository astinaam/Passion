#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int n;
    cin>>n;
    vector<int> arr[n];
    for(int i=0; i<n; ++i)
        arr[i].push_back(i);
    string s,str;
    int a,b;
    while(cin>>s && s!="quit")
    {
        cin>>a>>str>>b;
        if(a==b) continue;
        int pa,ai,pb,bi;
        bool fa=false,fb=false;
        for(int i=0; i<n; ++i)
        {
            int idx;
            if(!fa)
            {
                idx = find(arr[i].begin(),arr[i].end(),a)-arr[i].begin();
                if(idx < arr[i].size())
                {
                    fa = true;
                    pa = idx;
                    ai = i;
                }
            }
            if(!fb)
            {
                idx = find(arr[i].begin(),arr[i].end(),b)-arr[i].begin();
                if(idx < arr[i].size())
                {
                    fb = true;
                    pb = idx;
                    bi = i;
                }
            }

        }

        if(s=="move")
        {
            if(ai==bi) continue;
            if(str=="onto")
            {
                for(auto i=arr[bi].begin()+pb+1;i!=arr[bi].end();)
                {
                    int tm = *i;
                    arr[bi].erase(i);
                    arr[tm].push_back(tm);
                }
                arr[bi].push_back(a);
                for(auto i=arr[ai].begin()+pa+1;i!=arr[ai].end();)
                {

                    int tm = *i;
                    arr[ai].erase(i);
                    arr[tm].push_back(tm);

                }

                arr[ai].erase(arr[ai].begin()+pa);
            }
            else if(str=="over")
            {
                arr[bi].push_back(a);

                for(auto i=arr[ai].begin()+pa+1;i!=arr[ai].end();)
                {
                    int tm = *i;
                    arr[ai].erase(i);
                    arr[tm].push_back(tm);
                }

                arr[ai].erase(arr[ai].begin()+pa);
            }
        }
        else if(s=="pile")
        {
            if(str=="onto")
            {
                if(ai==bi) continue;
                for(auto i=arr[bi].begin()+pb+1;i!=arr[bi].end();)
                {
                    int tm = *i;
                    arr[bi].erase(i);
                    arr[tm].push_back(tm);
                }
                arr[bi].insert(arr[bi].end(),arr[ai].begin()+pa,arr[ai].end());
                arr[ai].erase(arr[ai].begin()+pa,arr[ai].end());
            }
            else if(str=="over")
            {
                if(ai==bi) continue;
                arr[bi].insert(arr[bi].end(),arr[ai].begin()+pa,arr[ai].end());
                arr[ai].erase(arr[ai].begin()+pa,arr[ai].end());
            }
        }
//        puts("currently:");
//        for(int i=0; i<n; ++i)
//        {
//            cout<<i<<":";
//            for(auto x : arr[i])
//                cout<<" "<<x;
//            cout<<"\n";
//        }
    }

    for(int i=0; i<n; ++i)
    {
        cout<<i<<":";
        for(auto x : arr[i])
            cout<<" "<<x;
        cout<<"\n";
    }
}
