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

pll a[L];
vector <ll> adj[32];
ll covered[32];
ll dont[L];

void solve()
{
    for(ll i=0; i<32; i++)
    {
        adj[i].clear();
        covered[i] = 0;
    }

    for(ll i=0; i<L; i++)
    {
        dont[i] = 0;
    }

    ll N;
    cin >> N;

    ll total_or = 0;

    for(ll i=0; i<N; i++)
    {
        cin >> a[i].ff;
        a[i].ss = i;

        ll temp = a[i].ff;

        total_or |= a[i].ff;

        ll cnt = 0;
        while(temp)
        {
            if(temp & 1)
            {
                adj[cnt].pb(i);
            }

            temp >>= 1;
            cnt++;
            // cout << "* " << cnt << endl;
        }
    }

    vector <pll> req;

    for(ll i=0; i<32; i++)
    {
        if(sz(adj[i]) == 1)
        {
            // covered[i] = 1;
            if(dont[adj[i][0]] == 1)
            {
                continue;
            }

            req.pb(mp(a[adj[i][0]].ff, adj[i][0]));
            // cout << i << " ** " << adj[i][0] << endl;;
            dont[adj[i][0]] = 1;

            ll temp2 = a[adj[i][0]].ff;
            
            ll cnt2 = 0;

            while(temp2)
            {
                if(temp2 & 1)
                {
                    covered[cnt2] = 1;
                }

                cnt2++;
                temp2 >>= 1;
            }
        }
    }

    for(ll i=0; i<32; i++)
    {
        if(covered[i] == 0)
        {
            // f  = true;
            if(sz(adj[i]) == 0)
            {
                // covered[i] = 1;
                continue;
            }
            ll m = -1;
            ll ind = -1;
            for(auto j: adj[i])
            {
                if(dont[a[j].ss] == 1)
                {
                    continue;
                }

                ll temp = a[j].ff;
                ll cnt = 0;

                ll cur = 0;

                while(temp)
                {
                    if(temp & 1)
                    {
                        if(covered[cnt] == 0)
                        {
                            cur++;
                        }
                    }

                    temp >>= 1;
                    cnt++;
                }

                if(cur > m || (cur == m && a[j].ff > a[ind].ff))
                {
                    ind = a[j].ss;
                    m = cur;
                }
            }

            ll ele = a[ind].ff;
            ll bit = 0;
            // cout << "*** " << i << endl;
            req.pb(mp(a[ind].ff, ind));
            dont[ind] = 1;
            while(ele)
            {
                if(ele & 1)
                {
                    covered[bit] = 1;
                }

                bit++;
                ele >>= 1;
            }
        }
    }

    sort(all(req));
    ll siz = sz(req);

    vector <ll> final;

    for(auto i: req)
    {
        // cout << i.ss << " ****" << endl;
        final.pb(i.ss);
    }

    ll sum_or = 0;

    for(ll i=0; i<siz; i++)
    {
        ll cur_or = 0;
        // cout << i.ff << " " << i.ss << endl;

        for(ll j=i+1; j<siz; j++)
        {
            cur_or |= a[final[j]].ff;
        }

        sum_or += cur_or;
    }

    sum_or += (N-siz+1)*total_or;

    cout << sum_or << endl;
    for(ll i=0; i<N; i++)
    {
        if(dont[i] == 0)
        {
            cout << a[i].ss+1 << " ";
        }
    }
    // cout << "*" << endl;
    for(auto i: final)
    {
        cout << i+1 << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T;
    cin >> T;

    while(T--)
    {
        solve();
    }


    return 0;
}