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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, M;
    cin >> N >> M;

    ll mat[N][M];

    for(ll i=0; i<N; i++)
    {
        for(ll j=0; j<M; j++)
        {
            cin >> mat[i][j];
        }
    }

    ll ans = 0;

    vector <pll> p;
    for(ll i=0; i<N; i++)
    {
        ll sum = 0;
        for(ll j=0; j<M; j++)
        {
            sum+=mat[i][j];
        }
        p.pb(mp(sum, L+i));
    }

    for(ll i=0; i<M; i++)
    {
        ll sum = 0;
        for(ll j=0; j<N; j++)
        {
            sum+=mat[j][i];
        }
        p.pb(mp(sum, i));
    }

    sort(all(p));
    reverse(all(p));

    pll top = p[0];
    ans+=top.ff;

    if(top.ss >= L)
    {
        ll row = top.ss - L;

        for(ll i=0; i<M; i++)
        {
            mat[row][i] = 0;
        }
    }

    else
    {
        ll column = top.ss;

        for(ll i=0; i<N; i++)
        {
            mat[i][column] = 0;
        }
    }

    p.clear();
    for(ll i=0; i<N; i++)
    {
        ll sum = 0;
        for(ll j=0; j<M; j++)
        {
            sum+=mat[i][j];
        }
        p.pb(mp(sum, L+i));
    }

    for(ll i=0; i<M; i++)
    {
        ll sum = 0;
        for(ll j=0; j<N; j++)
        {
            sum+=mat[j][i];
        }
        p.pb(mp(sum, i));
    }

    sort(all(p));
    reverse(all(p));

    top = p[0];
    ans+=top.ff;

    if(top.ss >= L)
    {
        ll row = top.ss - L;

        for(ll i=0; i<M; i++)
        {
            mat[row][i] = 0;
        }
    }

    else
    {
        ll column = top.ss;

        for(ll i=0; i<N; i++)
        {
            mat[i][column] = 0;
        }
    }

    p.clear();
    for(ll i=0; i<N; i++)
    {
        ll sum = 0;
        for(ll j=0; j<M; j++)
        {
            sum+=mat[i][j];
        }
        p.pb(mp(sum, L+i));
    }

    for(ll i=0; i<M; i++)
    {
        ll sum = 0;
        for(ll j=0; j<N; j++)
        {
            sum+=mat[j][i];
        }
        p.pb(mp(sum, i));
    }

    sort(all(p));
    reverse(all(p));

    top = p[0];
    ans+=top.ff;

    if(top.ss >= L)
    {
        ll row = top.ss - L;

        for(ll i=0; i<M; i++)
        {
            mat[row][i] = 0;
        }
    }

    else
    {
        ll column = top.ss;

        for(ll i=0; i<N; i++)
        {
            mat[i][column] = 0;
        }
    }

    p.clear();
    for(ll i=0; i<N; i++)
    {
        ll sum = 0;
        for(ll j=0; j<M; j++)
        {
            sum+=mat[i][j];
        }
        p.pb(mp(sum, L+i));
    }

    for(ll i=0; i<M; i++)
    {
        ll sum = 0;
        for(ll j=0; j<N; j++)
        {
            sum+=mat[j][i];
        }
        p.pb(mp(sum, i));
    }

    sort(all(p));
    reverse(all(p));

    top = p[0];
    ans+=top.ff;

    cout << ans << endl;

    return 0;
}