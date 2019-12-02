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

const ll L = 1e3+5;

char mat[2*L][2*L];
ll edges[2*L][2*L];
ll visited[2*L][2*L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll R, C;
    cin >> R >> C;

    for(ll i=0; i<2*R-1; i++)
    {
        for(ll j=0; j<2*C-1; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector <pll> go;

    for(ll i=0; i<2*R-2; i+=2)
    {
        for(ll j=0; j<2*C-2; j+=2)
        {
            if(mat[i+1][j] == '|')
            {
                edges[i][j]++;
            }

            if(mat[i][j+1] == '-')
            {
                edges[i][j]++;
            }

            if(mat[i+2][j+1] == '-')
            {
                edges[i][j]++;
            }

            if(mat[i+1][j+2] == '|')
            {
                edges[i][j]++;
            }

            if(edges[i][j] == 3)
            {
                go.pb(mp(i, j));
            }
        }
    }

    ll len = sz(go);

    ll ans = 0;

    for(ll x=0; x<len; x++)
    {
        ll i = go[x].ff;
        ll j = go[x].ss;

        if(i < 0 || i > 2*R-1 || j < 0 || j > 2*C-1)
        {
            continue;
        }

        if(!visited[i][j] && edges[i][j] == 4 && mat[i+1][j+1] != 'x')
        {
            ans++;
            visited[i][j] = 1;
            continue;
        }

        if(visited[i][j] || edges[i][j] != 3)
        {
            continue;
        }

        visited[i][j] = true;
        edges[i][j]++;

        if(mat[i+1][j] != '|')
        {
            mat[i+1][j] = '|';

            go.pb(mp(i, j-2));
            if(j >= 2)
            {
                edges[i][j-2]++;
            }
        }

        if(mat[i][j+1] != '-')
        {
            mat[i][j+1] = '-';

            go.pb(mp(i-2, j));
            if(i >= 2)
            {
                edges[i-2][j]++;
            }
        }

        if(mat[i+2][j+1] != '-')
        {
            mat[i+2][j+1] = '-';

            go.pb(mp(i+2, j));
            if(i <= 2*R-3)
            {
                edges[i+2][j]++;
            }
        }

        if(mat[i+1][j+2] != '|')
        {
            mat[i+1][j+2] = '|';

            go.pb(mp(i, j+2));
            if(j <= 2*C-3)
            {
                edges[i][j+2]++;
            }
        }

        ans++;
        len++;
    }

    // cout << endl << endl << endl;
    // for(ll i=0; i<2*R-1; i++)
    // {
    //     for(ll j=0; j<2*C-1; j++)
    //     {
    //         cout << mat[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << mat << endl;

    cout << ans << endl;

    return 0;
}