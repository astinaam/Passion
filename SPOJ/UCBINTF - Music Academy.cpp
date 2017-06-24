#include<bits/stdc++.h>

using namespace std;

string s;
int frq[26];

int main()
{
    cin>>s;
    char last;
    for(int i=0;i<s.size();++i)
    {
        last = s[i];
        if(s[i]=='|')
        {
            //cout<<s[i]<<s[i+1]<<endl;
            frq[s[i+1]-'A']++;
        }
        else if(i==0)
        {
            frq[s[i]-'A']++;
        }
    }
    int a=0,c=0;

    a = frq[0] + frq[3] + frq[4];
    c = frq[2] + frq[5] + frq[6];
    //cout<<a<<" "<<c<<endl;
    if(a==c)
    {
        if(last=='C')
            cout<<"C-dur"<<endl;
        else
            cout<<"A-mol"<<endl;
    }
    else if(a > c)
    {
        cout<<"A-mol"<<endl;
    }
    else
        cout<<"C-dur"<<endl;
}
