
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
 
 
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ll n;
        cin>>n;
        ve<ll>ar(n);
        lr(n){
            cin>>ar[i];
        }
        ve<ll>vi(n,0);
        deque<pi>st;
        st.pb(mk(0,1));
        vi[0]=1;
        for(ll i=1;i<n;i++){
            if(ar[i]>ar[st.front().fi]){
                while(!st.empty())st.pop_back();
                st.pb(mk(i,1));
                vi[i]=1;continue;
            }
            while(ar[i]>ar[st.back().fi]){
                st.pop_back();
            }
            st.push_back(mk(i,st.back().se+1));
            vi[i]=st.back().se;
        }
        ll sum=0;
        for(ll i=0;i<n;i++){
            ll tr=0,mx=0,val=0,y=0;
            val=vi[i];
            for(ll j=i;j<n;j++){
                if(vi[j]==val){
                    mx=max(mx,y);y=0;
                    tr++;
                }
                else if(vi[j]<val){
                    mx=max(mx,y);y=0;
                    val=vi[j];tr++;
                }
                else if(vi[j]==(val+1)){
                    y++;
                }
                mx=max(mx,y);
                sum+=tr;
                if(mx>1)
                    sum+=mx-1;
            }
        }
        cout << sum << "\n";
        return 0;
    }