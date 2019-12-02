

    #include<bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
     
    using namespace __gnu_pbds;
    using namespace std;
    // #define gcd(a,b) __gcd(a,b)
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
     
    typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
    // order_of_key(val): returns the number of values less than val
    // find_by_order(k): returns an iterator to the kth largest element (0-based)
     
    ll gcd(ll a, ll b){
        return b==0?a:gcd(b,a%b);
    }
     
        int main(){
            ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            ll n;
            cin>>n;
            while(n--){
                ll c,d;
                cin>>c>>d;
                if(c<0 || d<0 || d<c){
                    cout << "IMPOSSIBLE\n";
                }
                else if(c==0 && d==0){
                    cout << "0\n";
                }
                else if(c==0){
                    cout << "IMPOSSIBLE\n";
                }
                else if(c==1 && d==1){
                    cout << "AMBIGUOUS\n";
                }
                else if(c==1){
                    cout << "IMPOSSIBLE\n";
                }
                else if(c==d){
                    cout << "AMBIGUOUS\n";
                }
                else{
                    cout << (d-c)/(c-1) << " " << (c*c-d)/(c-1) << "\n";
                }
            }
     
            return 0;
        }