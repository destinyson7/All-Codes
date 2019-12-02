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

map <ll, ll> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, k;
    cin >> n >> k;

    // vector <ll> a;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        m[t]++;

        // a.pb(t);
    }

    // sort(all(a));

    deque <pll> q;

    for(auto i: m)
    {
        // cout <<  i.ff << " " << i.ss << endl;
        q.pb(mp(i.ff, i.ss));
    }

    while(k > 0)
    {
        if(sz(q) == 1)
        {
            break;
        }


        if(q.front().ss <= q.back().ss)
        {
            if(k >= q.front().ss)
            {
                pll top = q.front();

                q.pop_front();

                // if(q.front().ff == top.ff + 1)
                // {
                //     k-=q.front().ss;
                //     pll s = q.front();
                //     q.pop_front();
                //     q.push_front(mp(s.ff, top.ss+s.ss));
                // }

                // else
                // {
                    ll req = q.front().ff - top.ff;

                    if(k >= req*top.ss)
                    {
                        k -= req*top.ss;
                        pll s = q.front();
                        q.pop_front();
                        q.push_front(mp(s.ff, s.ss + top.ss));
                        // q.push_front(mp(top.ff+1, top.ss));
                    }

                    else
                    {
                        ll can = k/top.ss;

                        k-=top.ss*can;

                        q.push_front(mp(top.ff + can, top.ss));
                        // cout << q.back().ff - (top.ff + can) << endl;
                        // return 0;
                    }
                // }
            }

            else
            {
                break;
            }
        }

        else
        {
            // cout << "**" << endl;
            if(k >= q.back().ss)
            {
                // cout << "*" << endl;
                pll top = q.back();

                q.pop_back();

                // if(q.back().ff == top.ff - 1)
                // {
                //     k-=q.back().ss;
                //     pll s = q.back();
                //     q.pop_back();
                //     q.pb(mp(s.ff, top.ss+s.ss));
                // }

                // else
                // {
                    // cout << "**" << endl;
                    // q.push_back(mp(top.ff-1, top.ss));

                    ll req = top.ff - q.back().ff;

                    if(k >= req*top.ss)
                    {
                        // cout << "***" << endl;
                        k -= req*top.ss;
                        pll s = q.back();
                        q.pop_back();
                        q.pb(mp(s.ff, s.ss + top.ss));
                        // q.push_front(mp(top.ff+1, top.ss));
                    }

                    else
                    {
                        ll can = k/top.ss;

                        k -= top.ss*can;
                        q.pb(mp(top.ff - can, top.ss));
                        // cout << top.ff - can - q.front().ff << endl;
                        // return 0;
                    }
                // }
            }

            else
            {
                break;
            }
        }
    }

    cout << q.back().ff - q.front().ff << endl;

    return 0;
}