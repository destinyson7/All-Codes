#include<bits/stdc++.h>
using namespace std;
#define gcd(a,b) __gcd(a,b)
#define ll long long int
#define ld unsigned long long int
#define pi pair<ll,ll>
#define pb push_back
#define pf push_front
#define pu push
#define po pop
#define fi first
#define se second
#define mk make_pair
#define ve vector
#define lr(n) for(ll i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define be begin

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            ll sum=0;
            ve<ll>ar(n);
            lr(n){
                cin>>ar[i];
                sum+=ar[i];
            }
            ll a=0,b=0,c=0,mi=0,ma=0;
            ll k,x;
            cin>>k>>x;
            ve<ll>ra(n);
            ll mini=0,maxi=0;
            for(ll i=0;i<n;i++){
                ra[i]=ar[i]^x;
                ra[i]-=ar[i];
                if(ra[i]>0){
                    if(ma==0)
                        ma=ra[i];
                    else
                        ma=min(ma,ra[i]);
                    a++;
                    maxi+=ra[i];
                    sum+=ra[i];
                }
                else if(ra[i]<0){
                    b++;
                    mini+=ra[i];
                    if(mi==0)
                        mi=ra[i];
                    else
                        mi=max(mi,ra[i]);
                }
                else c++;
            }
            
            if(k%2==1){
                if(n!=k){
                    cout << sum << "\n";
                    continue;
                }
                cout << max(sum+mini,sum-maxi) << "\n";
                continue;
            }
            if(n!=k){
                if(a%2==0 || c>0){
                    cout << sum << "\n";
                    continue;
                }
                if(b==0)
                    sum-=ma;
                else if(ma+mi>=0)
                    sum+=mi;
                else
                    sum-=ma;
                cout << sum << "\n";
                continue;
            }
            cout << max(sum-maxi,sum+mini) << "\n";
        }
        return 0;
    }

