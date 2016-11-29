#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s,t;
    while(cin>>s>>t)
    {
        int j = 0;
        int sz = s.size();
        for(int i=0;i<t.length();++i)
        {
            if(s[j]==t[i])
            {
                j++;
            }
        }
        if(j == sz) puts("Yes");
        else puts("No");
    }
}
