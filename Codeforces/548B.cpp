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

const ll L = 500+5;

ll mat[L][L];
ll cnt[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m, q;
    cin >> n >> m >> q;

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            cin >> mat[i][j];
        }
    }

    for(ll i=0; i<n; i++)
    {
        ll cur = 0;
        for(ll j=0; j<m; j++)
        {
            if(mat[i][j] == 1)
            {
                cur++;
            }

            else
            {
                cur = 0;
            }

            cnt[i] = max(cnt[i], cur);
        }
    }

    while(q--)
    {
        ll i, j;
        cin >> i >> j;

        mat[i-1][j-1]^=1;

        ll cur = 0;
        cnt[i-1] = 0;
        for(ll k=0; k<m; k++)
        {
            if(mat[i-1][k] == 1)
            {
                cur++;
            }

            else
            {
                cur = 0;
            }

            cnt[i-1] = max(cnt[i-1], cur);
        }

        ll ans = 0;

        for(ll i=0; i<n; i++)
        {
            ans = max(ans, cnt[i]);
        }

        cout << ans << endl;
    }

    return 0;
}