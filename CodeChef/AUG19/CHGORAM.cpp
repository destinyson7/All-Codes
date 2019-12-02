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
// order_of_key(val): returns the no. of values less than val
// find_by_order(k): returns the kth largest element.(0-based)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e5+5;

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

vector <ll> adj[L];
ll st[L], en[L];
bool visited[L];

ll n = 0;

// Binary Indexed Tree Template Source: https://github.com/Ashishgup1/Competitive-Coding/blob/master/BIT%20-%20Binary%20Indexed%20Tree%20(Fenwick%20Tree).cpp
struct BIT
{
    ll N;
    vector<ll> bit;

    void init(ll n)
    {
        N = n;
        bit.assign(n + 1, 0);
    }

    void update(ll idx, ll val)
    {
        while(idx <= N)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    void updateMax(ll idx, ll val)
    {
        while(idx <= N)
        {
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }

    ll pref(ll idx)
    {
        ll ans = 0;
        while(idx > 0)
        {
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }

    ll rsum(ll l, ll r)
    {
        return pref(r) - pref(l - 1);
    }

    ll prefMax(ll idx)
    {
        ll ans = -2e15;
        while(idx > 0)
        {
            ans = max(ans, bit[idx]);
            idx -= idx & -idx;
        }
        return ans;
    }
};

void eulerTour(ll s)
{
    assert(!visited[s]);

    visited[s] = true;
    n++;

    st[s] = n;

    for(auto i: adj[s])
    {
        if(!visited[i])
        {
            eulerTour(i);
        }
    } 

    en[s] = n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T;
    cin >> T;

    while(T--)
    {
        
        ll res = 0;

        ll N;
        cin >> N;

        BIT tree;
        tree.init(N+5);

        for(ll i=0; i<=N; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }

        vector <ll> p;

        for(ll i=0; i<3; i++)
        {
            ll t;
            cin >> t;

            p.pb(t);
        }

        for(ll i=0; i<N-1; i++)
        {
            ll u, v;
            cin >> u >> v;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        n = 0;
        eulerTour(1);

        // for(ll i=1; i<=N; i++)
        // {
        //     cout << st[i] << " " << en[i] << endl;
        // }

        for(ll i=N; i>0; i--)
        {
            ll moref = 0, lesss = 0, mores = 0, resf = 0, ress = 0;

            for(ll j=0; j<sz(adj[i]); j++)
            {
                ll t = 0, te = 0;

                if(st[adj[i][j]] < st[i])
                {
                    t = tree.rsum(0, st[i]-1) + tree.rsum(en[i]+1, N);
                        
                    // cout << "ft " << t << endl;

                    resf+=t;
                    ress+=(t*t);

                    te = N-en[i]+st[i]-1;
                }

                else
                {
                    t = tree.rsum(st[adj[i][j]], en[adj[i][j]]);

                    // cout << "st " << t << endl;

                    resf+=t;
                    ress+=(t*t);

                    te = en[adj[i][j]] - st[adj[i][j]] + 1;
                    
                }


                moref+=(te*te);
                te-=t;
                lesss+=te;
                mores+=(te*te);
            }

            tree.update(st[i], 1);

            ll total = (N-1)*(N-1);
            total-=moref;
            total >>= 1;

            ll ansf = resf*resf;
            ansf-=ress;
            ansf >>= 1;

            ll anss = lesss*lesss;
            anss-=mores;
            anss >>= 1;

            if(p[1] == 2)
            {
                // assert(false);
                res+=(total - ansf - anss);
            }

            else if(p[1] == 3)
            {
                // assert(false);
                res+=anss;
            }

            else if(p[1] == 1)
            {
                // assert(false);
                res+=ansf;
            }

            // cout << res << " " << moref << " " << lesss << " " << mores << " " << resf << " " << ress << endl;
            
            // cout << "tree" << endl;
            // for(ll i=0; i<=N; i++)
            // {
            //     cout << tree.bit[i] << " ";
            // }
            // cout << endl;
        }

        cout << res << endl;
    }

    return 0;
}