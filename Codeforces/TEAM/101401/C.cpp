#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
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
#define INF 1e18
typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
 
ll dp[200001] = {0};
ll dpl[200001] = {0};
ll dpr[200001] = {0};
ll hpl[200001] = {0};
ll hpr[200001] = {0};
ll bad[200001] = {0};
 
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string s;
        cin>>s;
        ll n=s.length();
        for(ll i=1;i<n;i++){
            if(s[i]==')' && s[i-1] == ':'){
                hpl[i]=hpl[i-1]+1;
            }
            else{
                hpl[i]=hpl[i-1];
            }
            if(s[i]==':' && s[i-1] == '('){
                bad[i]=bad[i-1]+1;
            }
            else{
                bad[i]=bad[i-1];
            }
        }
        for(ll i=n-2;i>=0;i--){
            if(s[i]==':' && s[i+1] == ')'){
                hpr[i]=hpr[i+1]+1;
            }
            else{
                hpr[i]=hpr[i+1];
            }
        }
        for(ll i=1;i<n;i++){
            if(s[i] == ':' && s[i-1] == '('){
                if(dp[i-1]<0){
                    dp[i]=1;
                    dpl[i]=i-1;
                    dpr[i]=i;
                }
                else{
                    dp[i]=dp[i-1]+1;dpl[i]=dpl[i-1];
                    dpr[i]=i;
                }
            }
            else if(s[i] == ':'){
                if(dp[i-1]<=0){
                    dp[i]=0;dpl[i]=dpr[i]=i;
                }
                else{
                    dp[i]=dp[i-1];dpl[i]=dpl[i-1];
                    dpr[i]=i;
                }
            }
            else if(s[i]==')' && s[i-1] == ':'){
                if(dp[i-1]<=0){
                    dp[i]=-1;
                    dpl[i]=i-1;
                    dpr[i]=i;
                }
                else{
                    dp[i]=dp[i-1]-1;dpl[i]=dpl[i-1];
                    dpr[i]=i;
                }
            }
            else if(s[i] == ')'){
                if(dp[i-1]<0){
                    dp[i]=0;dpl[i]=dpr[i]=i;
                }
                else{
                    dp[i]=dp[i-1];dpl[i]=dpl[i-1];
                    dpr[i]=i;
                }
            }
            else if(s[i] == '(' && s[i-1] == ':'){
                if(dp[i-1]<0){
                    dp[i]=0;
                    dpl[i]=i;
                    dpr[i]=i;
                }
                else if(dp[i-1] == 0){
                    dp[i]=0;
                    if(dpl[i-1]>0 && s[dpl[i-1]-1] == ':')
                        dpl[i]=dpl[i-1];
                    else
                        dpl[i]=i;
                    dpr[i]=i;
                }
                else{
                    dp[i]=dp[i-1];dpl[i]=dpl[i-1];
                    dpr[i]=i;
                }
            }
            else if(s[i] == '('){
                if(dp[i-1]<0){
                    dp[i]=0;dpl[i]=dpr[i]=i;
                }
                else{
                    dp[i]=dp[i-1];dpl[i]=dpl[i-1];
                    dpr[i]=i;
                }
            }
            // cout << dp[i] << " " << dpl[i] << " " << dpr[i] << "\n";
        }
        ll ans=0;
        for(ll i=0,x;i<n;i++){
            x=hpr[dpr[i]+1] + bad[dpr[i]];
            if(dpl[i] != 0){
                x+=hpl[dpl[i]-1] - bad[dpl[i]-1];
                if(s[dpr[i]] == '(' && s[dpl[i]-1] == ':')
                    x++;
            }
            if(s[dpl[i]] == ':' && s[dpr[i]+1] == ')')
                x++;
            ans=max(ans,x);
        }
        cout << ans << "\n";
        return 0;
    }