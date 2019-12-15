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

const ll L = 3e5+5;
const ll M = 5e3+5;

ll last[M];
ll a[M];
ll b[M];
ll c[M];
ll req[M];
// bool defended[M];
ll can[M];

priority_queue <pll> go[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;

    for(ll i=1; i<=n; i++)
    {
        last[i] = i;
    }

    for(ll i=1; i<=n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    for(ll i=0; i<m; i++)
    {
        ll u, v;
        cin >> u >> v;

        // go[u].push(mp(c[v], v));

        last[v] = max(last[v], u);
    }

    for(ll i=1; i<=n; i++)
    {
        go[last[i]].push(mp(c[i], i));
    }

    req[n+1] = 0;
    req[n] = a[n];

    for(ll i=n-1; i>0; i--)
    {
        req[i] = max(a[i], req[i+1] - b[i]);
    }

    ll cur = k;

    ll ans = 0;

    priority_queue <pll> pq;

    for(ll i=1; i<=n; i++)
    {
        pq.push(mp(c[i], last[i]));
    }

    for(ll i=1; i<=n; i++)
    {
        // cout << cur << " * " << req[i] << endl;
        if(req[i] > cur)
        {
            cout << -1 << endl;
            return 0;
        }

        // priority_queue <ll> pq;
        cur += b[i];

        can[i] = max(0LL, cur - req[i+1]);

        // while(!go[i].empty())
        // {

        //     pll top = go[i].top();
        //     pq.push(mp(top, i));
        //     // cout << i << " ** " << top << " " << cur << endl;
        //     go[i].pop();

        //     // if(defended[top.ss])
        //     // {
        //     //     continue;
        //     // }

        //     // ans += top.ff;
        //     // defended[top.ss] = true;
        //     // cur--;
        // }
    }

    while(!pq.empty())
    {
        pll top = pq.top();
        ll which = top.ss;

        pq.pop();

        bool possible = true;

        for(ll i=which; i<=n; i++)
        {
            if(can[i] <= 0)
            {
                possible = false;
                break;
            }
        }

        if(!possible)
        {
            continue;
        }

        ans += top.ff;
        
        for(ll i=which; i<=n; i++)
        {
            can[i]--;
        }
    }
    

    cout << ans << endl;

    return 0;
}