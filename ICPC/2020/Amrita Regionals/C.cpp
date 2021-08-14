// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define lu unsigned long long int
#define pi pair<ll, ll>
#define pll pair<ll, ll>
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair
#define ve vector
#define vll ve<ll>
#define vpl ve<pll>
#define lr(n) for(ll i = 0; i < n; i++)
#define ltr(i, l, r) for (ll i = l; i <= r; i++)
#define rtl(i, l, r) for (ll i = r; i >= l; i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define be begin
#define sz(a) (ll)(a.size())
#define con continue
#define ret return
#define endl "\n"
// const ll INF = 1e18;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

ll mod = 1e9+7;

// ll mult(ll x, ll y){
//     ll rem=1;
//     while(y){
//         if(y&1){
//             rem=(rem*x)%mod;
//         }
//         x=(x*x)%mod;
//         y>>=1;
//     }
//     return rem;
// }

const ll R = 1e6 + 5;
ll seive[R] = {0};

ll vi[100001];
ve<ve<ll>> gr(100001);

void dfs(ll x) {
    vi[x] = 1;
    for(auto i: gr[x]) {
        if (vi[i]) continue;
        dfs(i);
    }
}

void solve(ll T){
    ll n;
    cin>>n;
    ve<ll>ar(n+1);
    for(ll i = 1; i <= n; i++) {
        cin>>ar[i];
        gr[i].clear();
        vi[i] = 0;
    }

    map<ll, ll> mp;
    ll minPrime = R;
    for(ll i = 1; i <= n; i++) {
        ll x = ar[i];
        while(x != 1) {
            ll pr = seive[x];
            minPrime = min(minPrime, pr);
            x /= pr;
            if(mp.find(pr) == mp.end()) {
                mp[pr] = i; continue;
            }
            ll prev = mp[pr];
            mp[pr] = i;
            if (prev == i) continue;
            gr[i].pb(prev);
            gr[prev].pb(i);
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        if (vi[i]) continue;
        dfs(i);
        ans++;
    }

    ans = min(2 * ans, minPrime * (ans - 1));
    cout << ans << "\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // std::cout << std::unitbuf;

    for(ll i = 2; i < R; i++) {
        if (seive[i] != 0) continue;
        for(ll j = i; j < R; j += i) {
            seive[j] = i;
        }
    }

    ll T=1;
    cin>>T;
    for(ll t=1;t<=T;t++){
        solve(t);
    }
    return 0;
}
