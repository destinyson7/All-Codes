#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

typedef tree <ll, null_type, greater <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the no. of values greater than val
// find_by_order(k): returns the kth largest element.(0-based)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e5+5;

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

ll modexp(ll a, ll b, ll c)
{   
    a%=c;

    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%c;
        b >>= 1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    ll toPrint = 1;

    for(ll i=0; i<K; i++)
    {   
        ordered_set os;

        ll cur = 0;

        for(ll j=0; j<N; j++)
        {
            ll t;
            cin >> t;

            os.insert(t);
            cur+=os.order_of_key(t);
        }

        if(cur > ans)
        {
            ans = cur;
            toPrint = i+1;
        }

    }

    cout << toPrint << endl;

    return 0;
}