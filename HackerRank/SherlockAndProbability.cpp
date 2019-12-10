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

void solve()
{
    ll N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    ll ones = 0;
    ll res = 0;

    ll l = 0, r = 0;

    bool first = true;

    ll total = 0;

    for(ll i=0; i<N; i++)
    {
        if(s[i] == '1')
        {
            total++;
            if(first)
            {
                first = false;

                for(ll j = i; j <= i+K && j < N; j++)
                {
                    if(s[j] == '1')
                    {
                        ones++;
                    }
                }

                l = i, r = min(i+K, N-1);

                res += ones;
            }

            else
            {
                // cout << "* " << mp(l, r) << endl;
                
                for(ll j = l; j < i; j++)
                {
                    if(s[j] == '1')
                    {
                        ones--;
                    }
                }

                // cout << "** " << ones << endl;

                for(ll j=r+1; j<=i+K && j<N; j++)
                {
                    if(s[j] == '1')
                    {
                        ones++;
                    }
                }

                // cout << "*** " << ones << endl;

                l = i, r = min(i+K, N-1);

                res += ones;
            }
        }

        // cout << i << " " << ones << " " << res << " " << mp(l, r) << endl;
    }

    if(first)
    {
        cout << "0/1" << endl;
    }

    else
    {
        res <<= 1;
        res -= total;

        ll den = N*N;

        ll g = gcd(res, den);

        res/=g;
        den/=g;

        cout << res << "/" << den << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T;
    cin >> T;

    while(T--)
    {
        solve();
    }

    return 0;
}