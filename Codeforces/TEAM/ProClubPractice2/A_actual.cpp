    #include<bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
     
    using namespace __gnu_pbds;
    using namespace std;
    #define gcd(a,b) __gcd(a,b)
    #define ll long long int
    #define ld double
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
            ll t;
            cin>>t;
            while(t--){
                ll a,b;
                cin>>a>>b;
                ve<ll>ar1;
                ve<ll>ar2;
                for(ll i=0,x=10,y;i<10;i++){
                    y=a%x;
                    a-=y;
                    if(y!=0){
                        ar1.pb(y);
                    }
                    if(a==0)break;
                    x*=10;
                }
                for(ll i=0,x=10,y;i<10;i++){
                    y=b%x;
                    b-=y;
                    if(y!=0){
                        ar2.pb(y);
                    }
                    if(b==0)break;
                    x*=10;
                }
                // for(ll i=0;i<ar2.size();i++)
                    // cout << ar2[i] << "\n";
                // for(ll i=ar1.size()-1;i>=ar1.size()-1;i--){
                    cout << ar1[ar1.size()-1] << " x " << ar2[ar2.size()-1] << " ";
                    for(ll j=ar2.size()-2;j>=0;j--){
                        cout << "+ " << ar1[ar1.size()-1] << " x " << ar2[j] << " ";
                    }
                // }
                for(ll i=ar1.size()-2;i>=0;i--){
                    // cout << ar1[i] << " x " << ar2[ar2.size()-1] << " ";
                    for(ll j=ar2.size()-1;j>=0;j--){
                        cout << "+ " << ar1[i] << " x " << ar2[j] << " ";
                    }
                }
                cout << "\n";
            }
            return 0;
        }
     