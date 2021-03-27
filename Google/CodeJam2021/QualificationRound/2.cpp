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

const ll L = 1e5+5;

void solve()
{
    ll x = nxt(), y = nxt();

    string s;
    cin >> s;

    ll n = sz(s);

    for(ll i=0; i<n; i++)
    {
        if(s[i] == '?')
        {
            ll start = i;
            ll end = -1;

            for(ll j = i + 1; j < n; j++)
            {
                if(s[j] != '?')
                {
                    end = j - 1;
                    break;
                }
            }

            if(end == -1)
            {
                end = n  - 1;
            }

            if(start > 0 && end < n - 1)
            {
                if(s[start - 1] == s[end + 1])
                {
                    for(ll j=start; j<=end; j++)
                    {
                        s[j] = s[start - 1];
                    }
                }

                else
                {
                    for(ll j=start; j<=end; j++)
                    {
                        s[j] = s[start - 1];
                    }
                }
            }

            else if(start > 0)
            {
                for(ll j=start; j<=end; j++)
                {
                    s[j] = s[start - 1];
                }
            }

            else if(end < n-1)
            {
                for(ll j=start; j<=end; j++)
                {
                    s[j] = s[end + 1];
                }
            }

            else
            {
                if(x < 0 || y < 0)
                {
                    if(x < 0 && y < 0)
                    {
                        if(x < y)
                        {
                            for(ll j=start; j<=end; j+=2)
                            {
                                s[j] = 'C';

                                if(j + 1  <= end)
                                {
                                    s[j + 1] = 'J';
                                }
                            }
                        }

                        else
                        {
                            for(ll j=start; j<=end; j+=2)
                            {
                                s[j] = 'J';

                                if(j + 1  <= end)
                                {
                                    s[j + 1] = 'C';
                                }
                            }
                        }
                    }

                    else if(x < 0)
                    {
                        if(-x >= y)
                        {
                            for(ll j=start; j<=end; j+=2)
                            {
                                s[j] = 'C';

                                if(j + 1  <= end)
                                {
                                    s[j + 1] = 'J';
                                }
                            }

                            if((end - start + 1) & 1)
                            {
                                s[end] = 'J';
                            }
                        }

                        else
                        {
                            s[start] = 'C';

                            for(ll j=start+1; j<=end; j++)
                            {
                                s[j] = 'J';
                            }
                        }
                    }

                    else if(y < 0)
                    {
                        if(-y >= x)
                        {
                            for(ll j=start; j<=end; j+=2)
                            {
                                s[j] = 'J';

                                if(j + 1  <= end)
                                {
                                    s[j + 1] = 'C';
                                }
                            }

                            if((end - start + 1) & 1)
                            {
                                s[end] = 'C';
                            }
                        }

                        else
                        {
                            s[start] = 'J';
                            for(ll j=start+1; j<=end; j++)
                            {
                                s[j] = 'C';
                            }
                        }
                    }
                }

                else
                {
                    for(ll j=start; j<=end; j++)
                    {
                        s[j] = 'C';
                    }
                }

            }
        }
    }

    ll ans = 0;

    for(ll i=0; i<n-1; i++)
    {
        if(s[i] == 'J' && s[i+1] == 'C')
        {
            ans += y;
        }

        else if(s[i] == 'C' && s[i+1] == 'J')
        {
            ans += x;
        }
    }

    cout << s << " " << ans << endl;
    // cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    T = nxt();

    for(ll i=1; i<=T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
