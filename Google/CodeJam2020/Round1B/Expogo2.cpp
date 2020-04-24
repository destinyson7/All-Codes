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

string go(ll x, ll y, ll bit, char replace)
{
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

    ll temp = x;
    ll cnt = 0;

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
                    ans[cnt] = 'N';
                }

                else
                {
                    ans[cnt] = 'S';
                }
            }

            else
            {
                return "IMPOSSIBLE";
            }
        }

        cnt++;
        temp >>= 1;
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
            return "IMPOSSIBLE";
        }

        else
        {
            final += ans[i];
        }
    }

    return final;
}

string go2(ll x, ll y, ll bit, char replace, bool fl)
{
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
    ans[bit] = replace;

    set <ll> s;

    ll temp = x;
    ll cnt = 0;

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

    temp = y;
    cnt = 0;

    while(temp > 0)
    {
        if(temp & 1)
        {
            if(!s.count(cnt))
            {
                if(!fl)
                {
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
                    if(y == tempy)
                    {
                        ans[cnt] = 'N';
                    }

                    else
                    {
                        ans[cnt] = 'S';
                    }
                }
                
            }

            else
            {
                return "IMPOSSIBLE";
            }
        }

        cnt++;
        temp >>= 1;
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
            return "IMPOSSIBLE";
        }

        else
        {
            final += ans[i];
        }
    }

    return final;
}

string go3(ll x, ll y, ll bit, char replace, bool fl)
{

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
    ans[bit] = replace;

    set <ll> s;

    ll temp = x;
    ll cnt = 0;

    while(temp > 0)
    {
        if(temp & 1)
        {
            s.insert(cnt);

            if(!fl)
            {
                 if(x == tempx)
                {
                    ans[cnt] = 'W';
                }

                else
                {
                    ans[cnt] = 'E';
                }   
            }
            
            else
            {
                if(x == tempx)
                {
                    ans[cnt] = 'E';
                }

                else
                {
                    ans[cnt] = 'W';
                }   
            }
        }

        cnt++;
        temp >>= 1;
    }

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
                    ans[cnt] = 'N';
                }

                else
                {
                    ans[cnt] = 'S';
                }
            }

            else
            {
                return "IMPOSSIBLE";
            }
        }

        cnt++;
        temp >>= 1;
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
            return "IMPOSSIBLE";
        }

        else
        {
            final += ans[i];
        }
    }

    return final;
}

void solve()
{
    ll x = nxt(), y = nxt();

    string ans = "IMPOSSIBLE";

    string a = go(x, y, -1, 'a');
    if(a != "IMPOSSIBLE")
    {
        ans = a;
    }

    // cout << a << endl;

    string b = go(y, x, -1, 'a');
    if(b != "IMPOSSIBLE")
    {
        if(sz(b) < sz(ans))
        {
            for(ll i=0; i<sz(b); i++)
            {
                if(b[i] == 'N')
                {
                    b[i] = 'E';
                }

                else if(b[i] == 'S')
                {
                    b[i] = 'W';
                }

                else if(b[i] == 'E')
                {
                    b[i] = 'N';
                }

                else
                {
                    b[i] = 'S';
                }
            }

            ans = b;
        }
    }

    // cout << b << endl;

    ll other = (1LL << (ll)log2(max(-y, y)));
    other <<= 1;
    ll bit = log2(other);
    other -= max(-y, y);

    if(y < 0)
    {
        other = -other;
    }

    string c = "IMPOSSIBLE";
    string e = "IMPOSSIBLE";
    
    if(y < 0)
    {

        c = go2(x, other, bit, 'S', false);
        e = go2(other, x, bit, 'S', false);
    }

    else
    {
        c = go2(x, other, bit, 'N', false);
        e = go2(other, x, bit, 'S', false);
    }



    // cout << c << endl;

    if(c != "IMPOSSIBLE" && sz(c) < sz(ans))
    {   
        ans = c;
    }

    if(e != "IMPOSSIBLE" && sz(e) < sz(ans))
    {
        for(ll i=0; i<sz(e); i++)
            {
                if(e[i] == 'N')
                {
                    e[i] = 'E';
                }

                else if(e[i] == 'S')
                {
                    e[i] = 'W';
                }

                else if(e[i] == 'E')
                {
                    e[i] = 'N';
                }

                else
                {
                    e[i] = 'S';
                }
            }

            ans = e;
    }

    ll other2 = (1LL << (ll)log2(max(-x, x)));
    other2 <<= 1;
    ll bit2 = log2(other2);
    other2 -= max(-x, x);
    string d = "IMPOSSIBLE"; 
    string f = "IMPOSSIBLE"; 

    if(x < 0)
    {
        other2 = -other2;
    }

    if(x < 0)
    {
        d = go3(other2, y, bit2, 'W', false);
        f = go3(y, other2, bit2, 'W', false);
    }

    else
    {
        d = go3(other2, y, bit2, 'E', false);
        f = go3(y, other2, bit2, 'E', false);
    }

    if(d != "IMPOSSIBLE" && sz(d) < sz(ans))
    {
        ans = d;
    }

     if(f != "IMPOSSIBLE" && sz(f) < sz(ans))
    {
        for(ll i=0; i<sz(f); i++)
            {
                if(f[i] == 'N')
                {
                    f[i] = 'E';
                }

                else if(f[i] == 'S')
                {
                    f[i] = 'W';
                }

                else if(f[i] == 'E')
                {
                    f[i] = 'N';
                }

                else
                {
                    f[i] = 'S';
                }
            }

            ans = f;
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