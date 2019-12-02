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

const ll L = 5e5+5;

ll res = 0;
vector <pll> adj[L];
bool visited[L];

pll dfs(ll s, ll k)
{
    priority_queue <ll> pq;

    assert(!visited[s]);

    visited[s] = true;

    for(auto i: adj[s])
    {
        if(!visited[i.ff])
        {
            pll cur = dfs(i.ff, k);

            ll check = i.ss - cur.ss;

            if(cur.ff >= k && check > 0)
            {
                // cout << "** " << check << " **" << endl;
                pq.push(check);
            }

            else if(cur.ff < k)
            {
                // cout << "* " << i.ss << " *" << endl;
                pq.push(i.ss);
            }
        }
    }

    ll m = 1e15;

    ll cal = 0;

    // cout << pq.size() << " * " << s << endl;

    while(!pq.empty() && cal < k)
    {
        ll top = pq.top();
        pq.pop();

        if(top < m)
        {
            m = top;
        }

        res += top;
        cal++;
    }

    // cout << s << " " << res << endl;
    return mp(cal, m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll q;
    cin >> q;

    while(q--)
    {
        res = 0;
        ll n, k;
        cin >> n >> k;
        
        for(ll i=0; i<=n; i++)
        {
            visited[i] = false;
            adj[i].clear();
        }

        for(ll i=0; i<n-1; i++)
        {
            ll u, v, w;
            cin >> u >> v >> w;

            adj[u].pb(mp(v, w));
            adj[v].pb(mp(u, w));
        }

        priority_queue <ll> pq2;
        visited[1] = true;


        for(auto i: adj[1])
        {
            if(!visited[i.ff])
            {
                pll cur2 = dfs(i.ff, k);

                ll check2 = i.ss - cur2.ss;

                if(cur2.ff >= k && check2 > 0)
                {
                    // cout << "** " << check2 << " **" << endl;
                    pq2.push(check2);
                }

                else if(cur2.ff < k)
                {
                    // cout << "* " << i.ss << " *" << endl;
                    pq2.push(i.ss);
                }
            }
        }

        ll cal2 = 0;
        while(!pq2.empty() && cal2 < k)
        {
            res += pq2.top();
            pq2.pop();
            cal2++;
        }

        // cout << 1 << " " << res << endl;
        cout << res << endl;
    }

    return 0;
}