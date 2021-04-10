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
    ll n = nxt();

    ll ans = 0;
    string prev = "";

    for(ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if(i == 0)
        {
            prev = s;
            continue;
        }

        else
        {
            ll n1 = sz(s);
            ll n2 = sz(prev);

            if(n1 > n2)
            {
                prev = s;
                continue;
            }

            else if(n1 == n2)
            {
                // if(s > prev)
                // {
                //     prev = s;
                //     continue;
                // }

                if(s == prev)
                {
                    prev = s + '0';
                    ans++;
                    continue;
                }

                for(ll j = 0; j < n1; j++)
                {
                    if(s[j] > prev[j])
                    {
                        prev = s;
                        break;
                    }

                    else if(s[j] < prev[j])
                    {
                        prev = s + '0';
                        ans++;
                        break;
                    }
                }

                // ans++;
                // prev = s + '0';
            }

            else
            {
                assert(n1 < n2);

                ll ind = 0;

                while(ind < n1 && s[ind] == prev[ind])
                {
                    ind++;
                }

                if(ind == n1)
                {
                    bool all_nines = true;

                    for(ll j = ind; j < n2; j++)
                    {
                        if(prev[j] != '9')
                        {
                            all_nines = false;
                            break;
                        }
                    }

                    if(all_nines)
                    {
                        ans += (n2 + 1 - n1);

                        prev = s;

                        for(ll j = 0; j < (n2 + 1 - n1); j++)
                        {
                            prev += '0';
                        }
                    }

                    else
                    {
                        ans += (n2 - n1);

                        string temp = s;

                        for(ll j=0; j<(n2-n1); j++)
                        {
                            temp += '0';
                        }

                        for(ll j=n2-1; j>=ind; j--)
                        {
                            if(prev[j] != '9')
                            {
                                temp[j] = (char)(prev[j] + 1);

                                for(ll k = j - 1; k >= ind; k--)
                                {
                                    temp[k] = prev[j];
                                }

                                break;
                            }

                            else
                            {
                                // do nothing
                                // temp += '9';
                            }
                        }

                        prev = temp;

                        // ll prev_num = 0;

                        // string temp = "";
                        // for(ll j=ind; j<n2; j++)
                        // {
                        //     temp += prev[j];
                        // }

                        // for(ll j=0; j<sz(temp); j++)
                        // {
                        //     prev_num = prev_num * 10 + (temp[j] - 48);
                        // }

                        // // prev_num = (ll)stoi(temp);
                        // prev_num++;

                        // string concat = "";
                        // while(prev_num)
                        // {
                        //     ll rem = prev_num % 10;
                        //     prev_num /= 10;
                        //     concat = (char)(rem + 48) + concat;
                        // }

                        // // prev = s + to_string(prev_num);
                        // prev = s + concat;
                    }
                }

                else
                {
                    if(s[ind] > prev[ind])
                    {
                        ans += (n2 - n1);
                        prev = s;

                        for(ll j = 0; j < (n2 - n1); j++)
                        {
                            prev += '0';
                        }
                    }

                    else
                    {
                        ans += (n2 + 1 - n1);

                        prev = s;

                        for(ll j = 0; j < (n2 + 1 - n1); j++)
                        {
                            prev += '0';
                        }
                    }
                }
            }
        }

        // cout << i << " " << prev << endl;
    }

    cout << ans << endl;
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
