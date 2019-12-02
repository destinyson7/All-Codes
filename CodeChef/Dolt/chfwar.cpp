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
ll arr[1000006];
ll findans(ll N,ll pos)
{
    if(N==2)
    {
        return 0;
    }
    ll i,f1=1,s,co=(pos+1)%(N-1),l1=2,l2=1,posl,posr=0,reml,remr;
    if((pos+1)%2)
    {
        reml=(pos/2)+1;
        remr=N-pos-1;
        posl=pos;
        s=arr[pos];
    }
    else
    {
        reml=(pos+1)/2;
        remr=N-pos-1;
        posl=pos-1;
        if(posl<0)
        {
            posl+=(N-1);
        }
        s=0;
    }
    reml+=(remr-1);
    // cout<<"pos : "<<pos<<"\n";
    // cout<<"posl : "<<posl<<"\n";
    // cout<<"reml : "<<reml<<"\n";
    // cout<<"remr : "<<remr<<"\n";
    if(posl<=0)
    {
        posl=posr;
        reml=remr;
        f1=0;
    }
    while(reml>1)
    {
        if(f1)
        {
            if(!(reml%2))
            {
                posl-=l1;
                if(posl<=0)
                {
                    f1=0;
                }
            }
            else
            {
                reml++;
                s+=arr[posl];
            }
            reml/=2;
            if(!(remr%2))
            {
                posr-=l2;
                if(posr<0)
                if(posr%(N-1)==0)
                {
                    posr=0;
                }
                else
                {
                    posr=posr+(N-1)*(1-(posr/(N-1)));
                }
            }
            else
            {
                remr++;
            }
            remr/=2;
            if(f1==0)
            {
                posl=posr;
                reml=remr;
            }
        }
        else
        {
            if(!(reml%2))
            {
                posl-=l2;
                if(posl<0)
                if(posl%(N-1)==0)
                {
                    posl=0;
                }
                else
                {
                    posl=posl+(N-1)*(1-(posl/(N-1)));
                }
            }
            else
            {
                reml++;
                s+=arr[posl];
            }
            reml/=2;
        }
        l1*=2;
        l2*=2;
        // cout<<"pos : "<<pos<<"\n";
        // cout<<"posl : "<<posl<<"\n";
        // cout<<"reml : "<<reml<<"\n";
        // cout<<"remr : "<<remr<<"\n";
    }
    return s;
}
int main(void)
{
    fastio
    ll T,i,N,F,mini,P,tmp;
    cin>>T;
    while(T--)
    {
        cin>>N;
        mini=1e18;
        P=-1;
        for(i=0;i<N-1;i++)
        {
            cin>>arr[i];
        }
        cin>>F;
        for(i=1;i<N;i++)
        {
            if(arr[i%(N-1)]<=F)
            {
                tmp=findans(N,i-1);
                if(tmp<mini)
                {
                    P=i+1;
                    mini=tmp;
                    if(P==N)
                    {
                        P=1;
                    }
                }
                else
                {
                    if(tmp==mini && i+1==N)
                    {
                        P=1;
                    }
                }
                // cout<<(i+1==N? 1:i+1)<<" "<<tmp<<"\n";
            }
        }
        if(P==-1)
        {
            cout<<"impossible\n";
        }
        else
        {
            cout<<"possible\n"<<P<<" "<<mini+F<<"\n";
        }
    }
    return 0;
}