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

const ll L = 60+5;

ll grid[L][L];
ll pref1[L][L];
ll pref2[L][L];

void solve()
{
    ll r, c;
    cin >> r >> c;

    bool present = false;
    bool other = false;

    for(ll i=0; i<r; i++)
    {
        string s;
        cin >> s;

        for(ll j=0; j<c; j++)
        {
            pref1[i][j] = 0;
            pref2[i][j] = 0;
            if(s[j] == 'A')
            {
                grid[i][j] = 1;
                present = true;
            }

            else
            {
                grid[i][j] = 0;
                other = true;
            }
        }
    }

    if(!other)
    {
        cout << 0 << endl;
        return;
    }

    if(!present)
    {
        cout << "MORTAL" << endl;
        return;
    }

    ll cur1 = 0, cur2 = 0;
    for(ll i=0; i<c; i++)
    {
        cur1 += grid[0][i];
        cur2 += grid[r-1][i];
    }

    if(cur1 == c || cur2 == c)
    {
        cout << 1 << endl;
        return;
    }

    ll cur3 = 0, cur4 = 0;

    for(ll i=0; i<r; i++)
    {
        cur3 += grid[i][0];
        cur4 += grid[i][c-1];
    }

    if(cur3 == r || cur4 == r)
    {
        cout << 1 << endl;
        return;
    }

    for(ll i=0; i<r; i++)
    {
        ll cur = 0;

        for(ll j=0; j<c; j++)
        {
            cur += grid[i][j];
            pref1[i][j] = cur;

            // cout << pref1[i][j] << " ";
        }
        // cout << endl;

        if(cur == c)
        {
            cout << 2 << endl;
            return;
        }

    }

    for(ll i=0; i<c; i++)
    {
        ll cur = 0;

        for(ll j=0; j<r; j++)
        {
            cur += grid[j][i];
            pref2[j][i] = cur;

            // cout << pref2[j][i] << " ";
        }
        // cout << endl;

        if(cur == r)
        {
            cout << 2 << endl;
            return;
        }
    }

    for(ll j=0; j<c; j++)
    {
        if(pref1[0][j] + pref1[r-1][c-1] - pref1[r-1][j] == c)
        {
            cout << 2 << endl;
            return;
        }
    }

    for(ll i=0; i<r; i++)
    {
        if(pref2[i][0] + pref2[r-1][c-1] - pref2[i][c-1] == r)
        {
            cout << 2 << endl;
            return;
        }
    }

    ll sum = grid[0][0] + grid[0][c-1] + grid[r-1][0] + grid[r-1][c-1];

    if(sum > 0)
    {
        cout << 2 << endl;
        return;
    }


    // cout << "***" << endl;

    for(ll i=0; i<r; i++)
    {
        for(ll j=0; j<c; j++)
        {        
            for(ll k=0; k<r; k++)
            {
                // cout << i << " * " << j << " * " << k << endl;
                // cout << pref1[i][j] << " " << pref1[k][c-1] << " " << pref1[k][j] << endl;
                if(pref1[i][j] + pref1[k][c-1] - pref1[k][j] == c)
                {
                    cout << 3 << endl;
                    return;
                } 
            }
        }
    }

    // cout << "****" << endl;

    for(ll i=0; i<c; i++)
    {
        for(ll j=0; j<r; j++)
        {
            for(ll k=0; k<c; k++)
            {
                if(pref2[j][i] + pref2[r-1][k] - pref2[j][k] == r)
                {
                    cout << 3 << endl;
                    return;
                }
            }
        }
    }


    for(ll i=0; i<c; i++)
    {
        if(grid[0][i] == 1)
        {
            cout << 3 << endl;
            return;
        }

        if(grid[r-1][i] == 1)
        {
            cout << 3 << endl;
            return;
        }
    }

    for(ll i=0; i<r; i++)
    {
        if(grid[i][0] == 1)
        {
            cout << 3 << endl;
            return;
        }

        if(grid[i][c-1] == 1)
        {
            cout << 3 << endl;
            return;
        }
    }

    cout << 4 << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}