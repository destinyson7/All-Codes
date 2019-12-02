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
vector <ll> adj[L];
ll ans[L];

ll cannot[L][5];

// map <pll, ll> check;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    for(ll i=0; i<n; i++)
    {
        ans[i] = 1;
    }

    // set <ll> f, s, t;

    ll cnt1 = 0, cnt2 = 0, cnt3 = 0;

    for(ll i=0; i<m; i++)
    {
        ll a, b;
        cin >> a >> b;

        a--;
        b--;

        adj[a].pb(b);
        adj[b].pb(a);

        // check[mp(a, b)] = 1;
        // check[mp(b, a)] = 1;
    }

    // f.insert(0);
    ans[0] = 1;
    // cnt1++;

    for(auto j: adj[0])
    {
        // s.insert(j);
        ans[j] = 2;
        // cnt2++;

        cannot[j][1] = -1;
    }

    for(ll i=1; i<n; i++)
    {
        for(auto j: adj[i])
        {
            if(ans[i] == ans[j])
            {
                if(ans[i] == 1)
                {
                    // f.erase(f.find(j));
                    // cnt1--;

                    cannot[j][1] = -1;

                    if(cannot[j][2] != -1)
                    {
                        // s.insert(j);
                        // cnt2++;
                        ans[j] = 2;
                    }

                    else if(cannot[j][3] != -1)
                    {
                        // cnt3++;
                        // t.insert(j);
                        ans[j] = 3;
                    }

                    else
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                } 

                else if(ans[i] == 2)
                {
                    // s.erase(s.find(j));
                    // cnt2--;

                    cannot[j][2] = -1;

                    if(cannot[j][1] != -1)
                    {
                        // f.insert(j);
                        ans[j] = 1;
                    }

                    else if(cannot[j][3] != -1)
                    {
                        // t.insert(j);
                        ans[j] = 3;
                    }

                    else
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                }

                else
                {
                    // t.erase(t.find(j));

                    cannot[j][3] = -1;

                    if(cannot[j][1] != -1)
                    {
                        // f.insert(j);
                        ans[j] = 1;
                    }

                    else if(cannot[j][2] != -1)
                    {
                        // s.insert(j);
                        ans[j] = 2;
                    }

                    else
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
        }
    }

    for(ll i=0; i<n; i++)
    {
        if(ans[i] == 1)
        {
            cnt1++;
        }

        else if(ans[i] == 2)
        {
            cnt2++;
        }

        else if(ans[i] == 3)
        {
            cnt3++;
        }
    }

    if(cnt1 == 0 || cnt2 == 0 || cnt3 == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    if(m != (cnt1*cnt2 + cnt2*cnt3 + cnt3*cnt1))
    {
        cout << -1 << endl;
        return 0;
    }

    for(ll i=0; i<n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}