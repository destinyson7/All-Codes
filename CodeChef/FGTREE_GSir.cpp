#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long int
#define ld double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
ll pt[102],lt[102],rt[102];
int main()
{
    ll test;
    cin>>test;
    string str;
    while(test--)
    {
        ll n;
        cin>>n;
        stack<ll> s;
        for(ll i=1;i<=n;i++)
        {
            lt[i]=i;
            rt[i]=i;
        }
        for(ll i=1;i<=n;i++)
        {
            // cout<<lt[6]<<endl;
            s.push(i);
            while(sz(s))
            {
                ll x=s.top();
                rt[x]=max(rt[x],i);
                cout<<"Q "<<x<<" "<<lt[x]<<" "<<rt[x]<<endl;
                cin>>str;
                if(str=="Yes")
                {
                    s.pop();
                    bool f=0;
                    if(sz(s))
                    {
                        ll z=s.top();
                        cout<<"Q "<<z<<" "<<lt[z]<<" "<<rt[x]<<endl;
                        cin>>str;
                        if(str=="Yes")
                        {
                            f=1;
                            pt[x]=z;
                            lt[z]=min(lt[z],lt[x]);
                            rt[z]=max(rt[z],rt[x]);
                        }
                    }
                    if(f==0)
                    {
                        ll z=rt[x]+1;
                        pt[x]=z;
                        lt[z]=min(lt[z],lt[x]);
                        rt[z]=max(rt[z],rt[x]);
                        // cout<<x<<" "<<z<<" "<<lt[z]<<" "<<rt[z]<<endl;
                    }
                }
                else
                    break;
            }
        }
        cout<<"A ";
        for(ll i=1;i<=n;i++)
        {
            if(pt[i]>n)
                pt[i]=-1;
            cout<<pt[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}