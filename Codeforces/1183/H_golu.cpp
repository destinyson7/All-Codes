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
        ll n,t;
        cin>>n>>t;
        ll ar[101][26]={0};
        string s;
        cin>>s;
        for(ll k=0;k<n;k++){
            for(ll i=n;i>1;i--){
                ll y=0;
                for(ll j=0;j<26;j++){
                    y+=ar[i-1][j];
                }
                ar[i][s[k]-'a']=y;
            }
            ar[1][s[k]-'a']=1;
        }
        ll ans=0;
        for(ll i=n;t>0 && i>=1;i--){
            for(ll j=0;t>0 && j<26;j++){
                if(ar[i][j]<=t){
                    ans+=ar[i][j]*(n-i);
                    t-=ar[i][j];
                }
                else{
                    ans+=t*(n-i);
                    t=0;
                }

                cout << t << endl;
            }
        }
        if(t>0){
            ans+=n;
            t--;
        }
        if(t>0){
            cout << "-1\n";
        }
        else
            cout << ans << "\n";
        return 0;       
    }