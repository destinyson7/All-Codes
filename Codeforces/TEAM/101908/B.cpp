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

const ll L = 1e2+5;

ll dp[L][L];
ll marbles[L][L];
ll grundy[L][L];

vector <pll> store;

void solve()
{
    for(ll i=0; i<L; i++)
    {
        for(ll j=0; j<L; j++)
        {
            vector <ll> mex;

            for(ll k=1; i-k>=0 && j-k>=0; k++)
            {
                mex.pb(grundy[i-k][j-k]);
            }

            for(ll k=1; i-k >=0; k++)
            {
                mex.pb(grundy[i-k][j]);
            }

            for(ll k=1; j-k >=0; k++)
            {
                mex.pb(grundy[i][j-k]);
            }

            sort(all(mex));

            bool f = false;
            ll m = 0;
            for(ll k=0; i<sz(mex); k++)
            {
                if(mex[k] == mex[k+1])
                {
                    continue;
                }

                if(mex[k] == m)
                {
                    m++;
                }

                else
                {
                    f = true;
                    grundy[i][j] = m;
                    break;
                }
            }

            if(!f)
            {
                grundy[i][j] = m;
            }

            if(i == 0 || j == 0 || i == j)
            {
                grundy[i][j] = 1e15;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N;
    cin >> N;

    for(ll i=0; i<L; i++)
    {
        dp[i][0] = 1;
        dp[0][i] = 1;
        dp[i][i] = 1;
    }

    solve();

    for(ll i=0; i<N; i++)
    {
        ll l, c;
        cin >> l >> c;
        
        marbles[l][c]++;
        store.pb(mp(l, c));
    }

    ll cur_xor = 0;

    for(ll i=0; i<N; i++)
    {
        cur_xor ^= grundy[store[i].ff][store[i].ss];
    }

    if(cur_xor > 0)
    {
        cout << "Y" << endl;
    }

    else
    {
        cout << "N" << endl;
    }

    return 0;
}