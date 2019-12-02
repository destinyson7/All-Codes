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

vector <ll> adj[L];

ll cost[L][3];
// bool visited[L];
ll color[L][6];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    for(ll i=1; i<=n; i++)
    {
        cin >> cost[i][0];
    }

    for(ll i=1; i<=n; i++)
    {
        cin >> cost[i][1];
    }

    for(ll i=1; i<=n; i++)
    {
        cin >> cost[i][2];
    }

    for(ll i=0; i<n-1; i++)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll cnt2 = 0, cnt1 = 0;
    ll root = -1;

    for(ll i=1; i<=n; i++)
    {
        if(sz(adj[i]) > 2)
        {
            cout << -1 << endl;
            return 0;
        }

        else if(sz(adj[i]) == 1)
        {
            root = i;
            cnt1++;
        }

        else
        {
            cnt2++;
        }
    }

    if(cnt1 != 2)
    {
        cout << -1 << endl;
        return 0;
    }

    vector <ll> p = {0, 1, 2};

    ll ans = 1e15;

    // cout << root << endl;

    ll which = 0;
    ll put = 0;
    do
    {
        // cout << p << endl;

        for(ll i=1; i<=n; i++)
        {
            // visited[i] = false;
            color[i][which] = -1;
        }

        ll cur = 0;
        color[root][which] = p[0];
        color[adj[root][0]][which] = p[1];

        ll cnt = 2;

        ll ver = adj[root][0];
        ll par = root;

        while(cnt < n)
        {
            for(auto i: adj[ver])
            {
                if(i != par)
                {
                    color[i][which] = p[cnt%3];
                    cnt++;
                    par = ver;
                    ver = i;

                    break;
                }
            }
        }

        for(ll i=1; i<=n; i++)
        {
            cur += cost[i][color[i][which]];
        }

        if(cur < ans)
        {
            put = which;
            ans = cur;
        }

        which++;

    }while(next_permutation(all(p)));

    cout << ans << endl;

    for(ll i=1; i<=n; i++)
    {
        cout << color[i][put]+1 << " ";
    }
    cout << endl;

    return 0;
}