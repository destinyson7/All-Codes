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
ll ans[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, p;
    cin >> n >> p;

    vector <pll> t;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        t.pb(mp(a, i));
    }

    // if(n == 1)
    // {
    //     cout << p+t[0].ff << endl;
    //     return 0;
    // }

    sort(all(t));

    ll curt = 0;

    priority_queue <pll, vector <pll>, greater <pll>> q;

    ll ind = 0;

    // for(ll i=0; i<n; i++)
    // {
    //     if(t[i].ff <= curt)
    //     {
    //         q.push(mp(t[i].ss, t[i].ff));
    //     }

    //     else
    //     {
    //         ind = i;
    //         break;
    //     }
    // }

    // cout << t << endl;

    ll cnt = 0;
    while(cnt < n)
    {
        // cout << curt << " * " << cnt << " * " << ind << endl;
        if(q.empty())
        {
            // cout << "** " << endl;
            curt = t[ind].ff;

            for(ll i=ind; i<n; i++)
            {
                // cout << "*** " << t[i].ff << endl;
                if(t[i].ff <= curt)
                {
                    q.push(mp(t[i].ss, t[i].ff));
                }

                else
                {
                    ind = i;
                    break;
                }

                if(i == n-1)
                {
                    ind = n;
                }
            }

            // cout << ind << endl;
        }

        else
        {
            // cout << q.top() << " *****" << endl;
            curt += p;
            ans[q.top().ff] = curt;
            // cout << q.top().ff << endl;
            q.pop();
            // cout << q.top() << " *********" << endl;

            for(ll i = ind; i < n; i++)
            {
                if(t[i].ff <= curt)
                {
                    q.push(mp(t[i].ss, t[i].ff));
                }

                else
                {
                    ind = i;
                    break;
                }

                if(i == n-1)
                {
                    ind = n;
                }
            }

            cnt++;
        }
    }

    for(ll i=0; i<n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}