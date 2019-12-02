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

ve<ll>ha(200001,0);

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ll n;
        cin>>n;
        ll x;
        lr(n){
            cin>>x;
            ha[x]++;

            // cout << ha[x] << endl;  
        }
        ve<ll>p(200001,0);ll f=1;
        lr(n){
            cin>>x;
            if(x!=i+1){
                f=0;
            }
            p[x]=i+1;
        }
        if(f){
            cout << "0\n";
            return 0;
        }
        ll ans=0;
        if(ha[1]==0){
            x=p[1];ll h=0;
            for(ll i=x+1;i<=n;i++){
                if(p[i+1-x]!=i){
                    h=1;
                    break;
                }
            }
            if(!h){
                for(ll i=n+2-x;i<=n;i++){
                    if(ha[i]==1)
                        continue;
                    else{
                        if(p[i]<=i-1-(n+1-x))
                            continue;
                        else{
                            h=1;
                            break;
                        }
                    }
                }
            }
            if(!h){
                cout << x-1 << "\n";
                return 0;
            }
        }
        f=0;
        for(ll i=1;i<=n;i++){
            if(ha[i]==1){
                continue;
            }
            else{
                if(p[i]<i+f);
                else
                    f+=p[i]-i-f+1;
            }
        }
        ans+=f+n;
        cout << ans << "\n";
        return 0;

    }