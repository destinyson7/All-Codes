#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mm map <ll,ll>
#define mv vector <ll>
#define mp pair <ll,ll>
#define ms set <ll>
#define mq queue <ll>
#define mdq deque <ll>
#define mst stack <ll>
#define mpq priority_queue <ll>
#define mmh priority_queue <ll, vector<ll>, greater<ll> >
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define flush cout.flush();
mv v1,v2;
void factors(ll x,ll rem)
{
    ll tmp=x;
    if(tmp%2==0 && 2>rem)
    {
        v2.push_back(2);
    }
    while(tmp%2==0)
    {
        tmp/=2;
    }
    ll i,sqr=sqrt(tmp);
    for(i=3;i<=sqr;i+=2)
    {
        if(tmp%i==0 && i>rem)
        {
            v2.push_back(i);
        }
        while(tmp%i==0)
        {
            tmp/=i;
        }
    }
    if(tmp>rem)
    {
        v2.push_back(tmp);
    }
}
ll find(ll xl)
{
    ll i,j,x,l=xl;
    cout<<"1 "<<l<<"\n";
    flush
    cin>>x;
    v1.clear();
    v2.clear();
    if(x==-1)
    {
        exit(0);
    }
    if(l*l-x<=0)
    {
        return find(31623);
    }
    factors(l*l-x,x);
    if(v2.size()==1)
    {
        return v2[0];
    }
    ll tmpx=x;
    l-=47;
    cout<<"1 "<<l<<"\n";
    flush
    cin>>x;
    if(x==-1)
    {
        exit(0);
    }
    for(i=0;i<v2.size();i++)
    {
        if(v2[i]>x)
        {
            v1.push_back(v2[i]);
        }
    }
    v2.clear();
    factors(l*l-x,max(x,tmpx));
    for(i=0;i<v1.size();i++)
    {

    }
    for(i=0;i<v1.size();i++)
    {
        for(j=0;j<v2.size();j++)
        {
            if(v1[i]==v2[j])
            {
                return v1[i];
            }
        }
    }
}
int main(void)
{
    ll T,i;
    string s;
    cin>>T;
    while(T--)
    {
        cout<<"2 "<<find(31622)<<"\n";
        flush
        cin>>s;
        if(s[0]=='N')
        {
            exit(0);
        }
    }
    return 0;
}