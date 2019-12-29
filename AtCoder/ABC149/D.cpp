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

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) 
{
    os << "{ ";
    for(auto& y : x) 
    {
        os << y << " ";
    }
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) 
{
    return os << "[" << p.ff << ", " << p.ss << "]";
}

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

const ll L = 1e5+5;

vector <char> adj[L];
vector <ll> dp[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, K;
    cin >> N >> K;

    ll R, S, P;
    cin >> R >> S >> P;

    string T;
    cin >> T;

    for(ll i=0; i<K; i++)
    {
        ll j = i;

        while(j < N)
        {
            adj[i].pb(T[j]);
            j += K;
        }
    }

    ll res = 0;

    for(ll i=0; i<K; i++)
    {
        if(adj[i][0] == 'r')
        {
            dp[i].pb(P);
        }

        else if(adj[i][0] == 's')
        {
            dp[i].pb(R);
        }

        else
        {
            dp[i].pb(S);
        }

        ll len = sz(adj[i]);

        for(ll j=1; j<len; j++)
        {
            ll temp = 0;

            if(adj[i][j] == 'r')
            {
                temp = P;
            }

            else if(adj[i][j] == 's')
            {
                temp = R;
            }

            else
            {
                temp = S;
            }

            if(T[i + K*j] != T[i + K*(j-1)])
            {
                dp[i].pb(dp[i][j-1] + temp);
                continue;
            }

            ll ans = 0;

            if(j > 1)
            {
                ans = max(dp[i][j-1], dp[i][j-2] + temp);
            }

            else
            {
                ans = max(dp[i][j-1], temp);
            }

            dp[i].pb(ans);
        }

        res += dp[i][len-1];

        // cout << res << endl;
    }

    cout << res << endl;
   
    return 0;
}