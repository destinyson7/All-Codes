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

    // cout << x << " " << y << " ";

    ll tempx = x, tempy = y;

    if(x < 0)
    {
        x = -x;
    }

    if(y < 0)
    {
        y = -y;
    }

    string ans = string(200, '#');
    set <ll> s;

    bool swapped = false;

    if(x > y)
    {
        swap(x, y);
        swap(tempx, tempy);
        swapped = true;
    }

    ll temp = x;
    ll cnt = 0;

    bool current = true;

    while(temp > 0)
    {
        if(temp & 1)
        {
            s.insert(cnt);

            if(x == tempx)
            {
                ans[cnt] = 'E';
            }

            else
            {
                ans[cnt] = 'W';
            }

        }

        cnt++;
        temp >>= 1;
    }

    bool f = true;
    string res = string(200, '#');

    temp = y;
    cnt = 0;

    while(temp > 0)
    {
        if(temp & 1)
        {
            if(!s.count(cnt))
            {
                if(y == tempy)
                {
                    res[cnt] = 'N';
                }

                else
                {
                    res[cnt] = 'S';
                }
            }

            else
            {
                f = false;
                break;
            }
        }

        cnt++;
        temp >>= 1;
    }

    if(f)
    {
        for(ll i=0; i<200; i++)
        {
            if(res[i] != '#')
            {
                ans[i] = res[i];
            }
        }
    }

    else
    {
        // cout << ans << endl;
        // cout << s << endl;

        ll other = (1LL << (ll)log2(y));
        other <<= 1;

        ll bit = (ll)log2(other);

        if(s.count(bit))
        {
            // cout << "*" << endl;
            // cout << "IMPOSSIBLE" << endl;
            current = false;
            // return;
        }

        else
        {
            s.insert(bit);

            if(y == tempy)
            {
                ans[bit] = 'N';
            }

            else
            {
                ans[bit] = 'S';
            }

        }

        temp = other - y;
        cnt = 0;

        while(temp > 0)
        {
            if(temp & 1)
            {
                if(!s.count(cnt))
                {
                    s.insert(cnt);

                    if(y == tempy)
                    {
                        ans[cnt] = 'S';
                    }

                    else
                    {
                        ans[cnt] = 'N';
                    }
                }

                else
                {
                    // cout << "**" << endl;
                    // cout << "IMPOSSIBLE" << endl;
                    current = false;
                    break;
                    // return;
                }
            }

            cnt++;
            temp >>= 1;
        }
    }

    string final = "";
    bool got = false;

    for(ll i=0; i<200; i++)
    {
        if(ans[i] == '#')
        {
            got = true;
        }

        else if(got)
        {
            // cout << "***" << endl;
            // cout << "IMPOSSIBLE" << endl;
            current = false;
            break;
            // return;
        }

        else
        {
            final += ans[i];
        }
    }

    // cout << final << endl;

    if(swapped)
    {
        swap(tempx, tempy);
        swap(x, y);

        for(ll i=0; i<sz(final); i++)
        {
            if(final[i] == 'N')
            {
                final[i] = 'E';
            }

            else if(final[i] == 'S')
            {
                final[i] = 'W';
            }

            else if(final[i] == 'E')
            {
                final[i] = 'N';
            }

            else
            {
                final[i] = 'S';
            }
        }
    }

    
    if(current)
    {
        // cout << tempx << " " << tempy << " ";
        cout << final << endl;
    }

    else
    {
        // cout << x << " " << y << " " << tempx << " " << tempy << endl;

        ans = string(200, '#');
        while(!s.empty())
        {
            s.erase(s.begin());
        }

        swapped = false;

        if(x < y)
        {
            swap(x, y);
            swap(tempx, tempy);
            swapped = true;
        }

        temp = x;
        cnt = 0;

        current = true;

        while(temp > 0)
        {
            if(temp & 1)
            {
                s.insert(cnt);

                if(x == tempx)
                {
                    ans[cnt] = 'E';
                }

                else
                {
                    ans[cnt] = 'W';
                }

            }

            cnt++;
            temp >>= 1;
        }

        f = true;
        res = string(200, '#');

        temp = y;
        cnt = 0;

        while(temp > 0)
        {
            if(temp & 1)
            {
                if(!s.count(cnt))
                {
                    if(y == tempy)
                    {
                        res[cnt] = 'N';
                    }

                    else
                    {
                        res[cnt] = 'S';
                    }
                }

                else
                {
                    f = false;
                    break;
                }
            }

            cnt++;
            temp >>= 1;
        }

        if(f)
        {
            for(ll i=0; i<200; i++)
            {
                if(res[i] != '#')
                {
                    ans[i] = res[i];
                }
            }
        }

        else
        {
            // cout << ans << endl;
            // cout << s << endl;

            ll other = (1LL << (ll)log2(y));
            other <<= 1;

            ll bit = (ll)log2(other);

            if(s.count(bit))
            {
                // cout << "*" << endl;
                cout << "IMPOSSIBLE" << endl;
                // current = false;
                return;
            }

            else
            {
                s.insert(bit);

                if(y == tempy)
                {
                    ans[bit] = 'N';
                }

                else
                {
                    ans[bit] = 'S';
                }

            }

            temp = other - y;
            cnt = 0;

            while(temp > 0)
            {
                if(temp & 1)
                {
                    if(!s.count(cnt))
                    {
                        s.insert(cnt);

                        if(y == tempy)
                        {
                            ans[cnt] = 'S';
                        }

                        else
                        {
                            ans[cnt] = 'N';
                        }
                    }

                    else
                    {
                        // cout << "**" << endl;
                        cout << "IMPOSSIBLE" << endl;
                        // current = false;
                        // break;
                        return;
                    }
                }

                cnt++;
                temp >>= 1;
            }
        }

        final = "";
        got = false;

        for(ll i=0; i<200; i++)
        {
            if(ans[i] == '#')
            {
                got = true;
            }

            else if(got)
            {
                // cout << "***" << endl;
                cout << "IMPOSSIBLE" << endl;
                // current = false;
                // break;
                return;
            }

            else
            {
                final += ans[i];
            }
        }

        // cout << final << endl;

        if(swapped)
        {
            swap(tempx, tempy);

            for(ll i=0; i<sz(final); i++)
            {
                if(final[i] == 'N')
                {
                    final[i] = 'E';
                }

                else if(final[i] == 'S')
                {
                    final[i] = 'W';
                }

                else if(final[i] == 'E')
                {
                    final[i] = 'N';
                }

                else
                {
                    final[i] = 'S';
                }
            }
        }

        cout << final << endl;
    }
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