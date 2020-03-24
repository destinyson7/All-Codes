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

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

const ll L = 2e5+5;

bool visited[L];

void solve()
{
    ll n = nxt();
    vector <vector<ll>> adj(n);

    for(ll i=0; i<=n; i++)
    {
        visited[i] = false;
    }

    basic_string <ll> p(n, 0);
    generate(all(p), nxt);

    basic_string <ll> c(n, 0);
    generate(all(c), nxt);

    for(ll i=0; i<n; i++)
    {
        p[i]--;
    }
    
    ll cur = 0;

    for(ll i=0; i<n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;

            adj[cur].pb(i);
            
            for(ll j=p[i]; j!=i; j=p[j])
            {
                visited[j] = true;
                adj[cur].pb(j);
            }

            cur++;
        }
    }

    ll ans = 1e17;

    adj.resize(cur);
    for(auto i: adj)
    {
        ll len = sz(i);

        for(ll j=1; j*j<=len; j++)
        {
            if(len%j == 0)
            {
                for(ll k=0; k<j; k++)
                {
                    bool f = false;

                    for(ll w=k; w<len-j; w+=j)
                    {
                        if(c[i[w+j]] != c[i[w]])
                        {
                            f = true;
                            break;
                        }
                    }

                    if(!f)
                    {  
                        ans = min(ans, j);
                    }
                }

                for(ll k=0; k<len/j; k++)
                {
                    bool f = false;

                    for(ll w=k; w<len-len/j; w+=(len/j))
                    {
                        if(c[i[w+len/j]] != c[i[w]])
                        {
                            f = true;
                            break;
                        }
                    }

                    if(!f)
                    {  
                        ans = min(ans, len/j);
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    T = nxt();

    while(T--)
    {
        solve();
    }

    return 0;
}