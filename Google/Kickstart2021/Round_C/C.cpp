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
ll x;

double eps = 0.000001;

typedef struct ever
{
    double val;
    ll r, p, s;
    ll par;
} ever;

void solve()
{
    ll w = nxt(), e = nxt();

    // ll r = 0, p = 0, s = 0;

    double pr = 0.0, pp = 0.0, ps = 0.0;
    string ans = "";

    // double we_get = 0.0;

    ever dp[70][3];

    for(ll i=0; i<70; i++)
    {
        for(ll j=0; j<3; j++)
        {
            dp[i][j].val = 0.0;
            dp[i][j].r = 0;
            dp[i][j].p = 0;
            dp[i][j].s = 0;
            dp[i][j].par = -1;
        }
    }

    for(ll i=1; i<=60; i++)
    {
        if(i == 1)
        {
            pr = (double)1/(double)3;
            pp = (double)1/(double)3;
            ps = (double)1/(double)3;

            double er = pr * (double)e + ps * (double)w + 0;
            double ep = pp * (double)e + pr * (double)w + 0;
            double es = ps * (double)e + pp * (double)w + 0;

            dp[i][0].val = er;
            dp[i][0].r++;
            dp[i][0].par = -1;


            dp[i][1].val = ep;
            dp[i][1].p++;
            dp[i][1].par = -1;


            dp[i][2].val = es;
            dp[i][2].s++;
            dp[i][2].par = -1;

            continue;
        }


        double pr1 = (double)dp[i-1][0].r/(double)(i-1);
        double pp1 = (double)dp[i-1][0].p/(double)(i-1);
        double ps1 = (double)dp[i-1][0].s/(double)(i-1);

        double pr2 = (double)dp[i-1][1].r/(double)(i-1);
        double pp2 = (double)dp[i-1][1].p/(double)(i-1);
        double ps2 = (double)dp[i-1][1].s/(double)(i-1);

        double pr3 = (double)dp[i-1][2].r/(double)(i-1);
        double pp3 = (double)dp[i-1][2].p/(double)(i-1);
        double ps3 = (double)dp[i-1][2].s/(double)(i-1);

        double er1 = pr1 * (double)e + ps1 * (double)w + 0;
        double ep1 = pp1 * (double)e + pr1 * (double)w + 0;
        double es1 = ps1 * (double)e + pp1 * (double)w + 0;

        double er2 = pr2 * (double)e + ps2 * (double)w + 0;
        double ep2 = pp2 * (double)e + pr2 * (double)w + 0;
        double es2 = ps2 * (double)e + pp2 * (double)w + 0;

        double er3 = pr3 * (double)e + ps3 * (double)w + 0;
        double ep3 = pp3 * (double)e + pr3 * (double)w + 0;
        double es3 = ps3 * (double)e + pp3 * (double)w + 0;

        for(ll j=0; j<3; j++)
        {
            if(j == 0)
            {
                double fer = max({dp[i-1][0].val + er1, dp[i-1][1].val + er2, dp[i-1][2].val + er3});

                dp[i][j].val = fer;

                dp[i][j].r++;

                if(abs(dp[i-1][0].val + er1 - fer) < eps)
                {
                    dp[i][j].par = 0;
                }

                else if(abs(dp[i-1][1].val + er2 - fer) < eps)
                {
                    dp[i][j].par = 1;
                }

                else
                {
                    dp[i][j].par = 2;
                }
            }

            else if(j == 1)
            {
                double fep = max({dp[i-1][0].val + ep1, dp[i-1][1].val + ep2, dp[i-1][2].val + ep3});

                dp[i][j].val = fep;

                dp[i][j].p++;

                if(abs(dp[i-1][0].val + ep1 - fep) < eps)
                {
                    dp[i][j].par = 0;
                }

                else if(abs(dp[i-1][1].val + ep2 - fep) < eps)
                {
                    dp[i][j].par = 1;
                }

                else
                {
                    dp[i][j].par = 2;
                }
            }

            else
            {
                double fes = max({dp[i-1][0].val + es1, dp[i-1][1].val + es2, dp[i-1][2].val + es3});

                dp[i][j].val = fes;

                dp[i][j].s++;

                if(abs(dp[i-1][0].val + es1 - fes) < eps)
                {
                    dp[i][j].par = 0;
                }

                else if(abs(dp[i-1][1].val + es2 - fes) < eps)
                {
                    dp[i][j].par = 1;
                }

                else
                {
                    dp[i][j].par = 2;
                }
            }
        }
    }

    double fmaxi = max({dp[60][0].val, dp[60][1].val, dp[60][2].val});

    if(abs(fmaxi - dp[60][0].val) < eps)
    {
        string haha = "R";
        ll cur = 0;

        for(ll i=60; i>0; i--)
        {
            if(dp[i][cur].par == 0)
            {
                haha += "R";
            }

            else if(dp[i][cur].par == 1)
            {
                haha += "P";
            }

            else
            {
                haha += "S";
            }

            cur = dp[i][cur].par;
        }

        reverse(all(haha));

        cout << haha << endl;
    }

    else if(abs(fmaxi - dp[60][1].val) < eps)
    {
        string haha = "P";
        ll cur = 1;

        for(ll i=60; i>0; i--)
        {
            if(dp[i][cur].par == 0)
            {
                haha += "R";
            }

            else if(dp[i][cur].par == 1)
            {
                haha += "P";
            }

            else
            {
                haha += "S";
            }

            cur = dp[i][cur].par;
        }

        reverse(all(haha));

        cout << haha << endl;
    }

    else
    {
        string haha = "S";
        ll cur = 2;

        for(ll i=60; i>0; i--)
        {
            if(dp[i][cur].par == 0)
            {
                haha += "R";
            }

            else if(dp[i][cur].par == 1)
            {
                haha += "P";
            }

            else
            {
                haha += "S";
            }

            cur = dp[i][cur].par;
        }

        reverse(all(haha));

        cout << haha << endl;
    }

    // cout << "we_get: " << we_get << endl;

    // cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    T = nxt();
    x = nxt();

    for(ll i=1; i<=T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
