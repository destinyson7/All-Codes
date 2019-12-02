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

const ll L = 50+5;

ll mat[L][L];
bool visited[L][L];

bool f = false;

ll n, m;

void dfs(ll i, ll j, pll par)
{
    if(visited[i][j])
    {
        // cout << i << " " << j << " " << par << endl;
        f = true;
        return;
    }

    visited[i][j] = true;

    if(i >= 1)
    {
        if(i-1 != par.ff || j != par.ss)
        {
            if(mat[i][j] == mat[i-1][j])
            {
                dfs(i-1, j, mp(i, j));
            }
        }
    }

    if(j >= 1)
    {
        if(i != par.ff || j-1 != par.ss)
        {
            if(mat[i][j] == mat[i][j-1])
            {
                dfs(i, j-1, mp(i, j));
            }
        }
    }

    if(i < n-1)
    {
        if(i+1 != par.ff || j != par.ss)
        {
            if(mat[i][j] == mat[i+1][j])
            {
                dfs(i+1, j, mp(i, j));
            }
        }
    }

    if(j < m-1)
    {
        if(i != par.ff || j+1 != par.ss)
        {
            if(mat[i][j] == mat[i][j+1])
            {
                dfs(i, j+1, mp(i, j));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // ll n, m;
    cin >> n >> m;

    for(ll i=0; i<n; i++)
    {
        string s;
        cin >> s;

        for(ll j=0; j<m; j++)
        {
            mat[i][j] = s[j] - 'A';
        }
    }

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(!visited[i][j])
            {
                dfs(i, j, mp(-1, -1));

                if(f)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}