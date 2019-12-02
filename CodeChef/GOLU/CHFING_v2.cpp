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

ll mod = 1e9+7;

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ll t;
        cin>>t;
        while(t--){
            ld n,k;
            cin>>n>>k;
            ld x=k,l=n-1;
            ld h;
            if((x-1)%l==0)
                h=(x-1)/l;
            else
                h=(x-1)/l + 1;

            ld y = (h%mod*((x-1)%mod))%mod,z;
            if(h%2==0)
                z = h/2%mod*((h-1)%mod);
            else
                z = h%mod*((h-1)/2%mod);
            z = z%mod*(l%mod);
            z = z%mod;
            cout << (mod + y-z)%mod << "\n";
        }
        return 0;
    }

