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
const ll M = (1LL << 7) + 5;

ll skill[L][10];
ll dp[L][M];
ll parent[L][M];
ll z[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, P, k;
    cin >> N >> P >> k;

    vector <pll> p;

    for(ll i=0; i<L; i++)
    {
        for(ll j=0; j<M; j++)
        {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;

    p.pb(mp(1e15, -1));

    for(ll i=1; i<=N; i++)
    {
        ll x;
        cin >> x;

        p.pb(mp(x, i));
    }

    sort(all(p));
    reverse(all(p));

    for(ll i=1; i<=N; i++)
    {
        for(ll j=0; j<P; j++)
        {
            cin >> skill[i][j];
        }
    }

    for(ll i=1; i<=N; i++)
    {
        for(ll mask=0; mask<(1LL << P); mask++)
        {
            for(ll j=0; j<P; j++)
            {
                if((1LL << j) & mask)
                {
                    if(dp[i-1][mask ^ (1LL << j)] != -1)
                    {
                        // dp[i][mask] = max(dp[i][mask], dp[i-1][mask ^ (1LL << j)] + skill[p[i].ss][j]);
                        
                        if(dp[i-1][mask ^ (1LL << j)] + skill[p[i].ss][j] > dp[i][mask])
                        {
                            dp[i][mask] = dp[i-1][mask ^ (1LL << j)] + skill[p[i].ss][j];
                            parent[i][mask] = (mask ^ (1LL << j));
                        }
                    }
                }
            }

            if(dp[i-1][mask] != -1)
            {
                ll players = __builtin_popcount(mask);
                ll remaining = (i - 1) - players;
                
                ll temp = dp[i-1][mask];

                if(remaining < k)
                {
                    temp += p[i].ff;
                }

                if(temp > dp[i][mask])
                {
                    dp[i][mask] = temp;
                    parent[i][mask] = mask;
                }
            }

            // cout << dp[i][mask] << " ** " << par[i][mask] << endl;
        }
    }

    ll last = (1LL << P) - 1;

    for(ll i=N; i>0; i--)
    {
        ll par = parent[i][last];

        if(par == last)
        {
            ll players = __builtin_popcount(last);
            
            if(i <= players + k)
            {
                z[p[i].ss] = -1;
            }
        }

        else
        {
            ll oth = last ^ par;

            // cout << oth << " ***" << endl;
            last = par;

            for(ll j=0; j<P; j++)
            {
                if((1LL << j) & oth)
                {
                    z[p[i].ss] = j + 1;
                    break;
                }
            }
        }

        // cout << z[p[i].ss] << " *****" << endl;
    }

    cout << dp[N][(1LL << P) - 1] << endl;

    for(ll i=1; i<=N; i++)
    {
        if(!z[i])
        {
            cout << -1 << " ";
        }

        else if(z[i] == -1)
        {
            cout << 0 << " ";
        }

        else
        {
            cout << z[i] << " ";
        }
    }
    cout << endl;

    return 0;
}