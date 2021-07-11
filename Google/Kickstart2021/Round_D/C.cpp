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

const ll L = 1e5 + 5;
const ll mod = 1e9 + 7;

// ll a[L];
// ll b[L];

// ll pref[L];

void solve()
{
    ll n = nxt(), m = nxt();

    // for(ll i = 0; i < L; i++)
    // {
    //     pref[i] = 0;
    // }

    set <pll> s;

    for(ll i = 1; i <= n; i++)
    {
        // cin >> a[i] >> b[i];

        // pref[a[i]]++;
        // pref[b[i] + 1]--;

        ll a = nxt(), b = nxt();

        s.insert(mp(a, b));
    }

    // set <ll> s;

    // for(ll i = 1; i <= L - 5; i++)
    // {
    //     pref[i] += pref[i - 1];

    //     if(pref[i])
    //     {
    //         s.insert(i);
    //         // cout << i << endl;
    //     }
    // }

    for(ll i = 1; i <= m; i++)
    {
        ll cur = nxt();

        auto it = s.lower_bound(mp(cur + 1, -1));

        if(it != s.begin())
        {
            it--;

            pll temp = *it;
            ll range_l = temp.ff, range_r = temp.ss;

            if(range_l <= cur && range_r >= cur)
            {
                cout << cur << " ";
                s.erase(it);

                if(range_l + 1 <= cur)
                {
                    s.insert(mp(range_l, cur - 1));
                }

                if(cur + 1 <= range_r)
                {
                    s.insert(mp(cur + 1, range_r));
                }
            }

            else if(range_r <= cur)
            {
                it++;

                if(it != s.end())
                {
                    if((cur - range_r) <= ((*it).ff - cur))
                    {
                        cout << range_r << " ";
                        it--;

                        s.erase(it);

                        if(range_l + 1 <= range_r)
                        {
                            s.insert(mp(range_l, range_r - 1));
                        }
                    }

                    else
                    {
                        cout << (*it).ff << " ";

                        ll temp_l = (*it).ff + 1, temp_r = (*it).ss;

                        s.erase(it);
                        if(temp_l <= temp_r)
                        {
                            s.insert(mp(temp_l, temp_r));
                        }
                    }
                }

                else
                {
                        cout << range_r << " ";
                        it--;

                        s.erase(it);

                        if(range_l + 1 <= range_r)
                        {
                            s.insert(mp(range_l, range_r - 1));
                        }
                }
            }

            else
            {
                cout << "blah ";
                assert(false);
            }
        }

        else
        {
            // cout << s << endl;

            // cout << *(s.upper_bound(mp(cur, 1e18 + 3))) << endl;
            // cout << "here ";

            pll temp = *it;
            ll range_l = temp.ff, range_r = temp.ss;

            if(range_l <= cur && range_r >= cur)
            {
                cout << cur << " ";
                s.erase(it);

                if(range_l + 1 <= cur)
                {
                    s.insert(mp(range_l, cur - 1));
                }

                if(cur + 1 <= range_r)
                {
                    s.insert(mp(cur + 1, range_r));
                }
            }

            else if(cur > range_r)
            {
                cout << range_r << " ";
                s.erase(it);

                if(range_l + 1 <= range_r)
                {
                    s.insert(mp(range_l, range_r - 1));
                }
            }

            else if(cur < range_l)
            {
                cout << range_l << " ";
                s.erase(it);

                if(range_l + 1 <= range_r)
                {
                    s.insert(mp(range_l + 1, range_r));
                }
            }

            else
            {
                cout << "blah ";
                assert(false);
            }
        }

    }

    cout << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    T = nxt();

    for(ll i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
