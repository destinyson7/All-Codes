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
vector <vector <ll>> pos;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector <ll> ff(n, 0);
    vector <ll> ss(n, 0);

    for(ll i=0; i<n; i++)
    {
        ff[i] = (s[i] == 'W');
    }

    ll flips = 0;

    // ll num = 0;

    for(ll i=0; i<n; i++)
    {
        if(s[i] != s[i+1])
        {
            vector <ll> v;

            v.pb(0);
            // v.pb(1);
            ll cur = 2;

            // ll j = i+1;
            i++;

            while(i < n && s[i] != s[i+1])
            {
                v.pb(cur-1);
                cur++;
                i++;
            }
            v.pb(cur-1);

            flips += ((cur/2) + (cur & 1));

            pos.pb(v);
            
            // num++;
        }
    }

    // k = min(k, flips);

    // while(k--)
    // {
    //     for(ll i=0; i<n; i++)
    //     {
    //         ll left = (i-1+n)%n;
    //         ll middle = i;
    //         ll right = (i+1)%n;

    //         if(ff[left] + ff[middle] + ff[right] >= 2)
    //         {
    //             ss[middle] = 1;
    //         }

    //         else
    //         {
    //             ss[middle] = 0;
    //         }
    //     }

    //     ff = ss;
    // }

    ll num = 0;

    for(ll i=0; i<n; i++)
    {
        if(s[i] == s[i+1])
        {
            cout << s[i];
        }

        else
        {
            vector <ll> v = pos[num];
            ll len = sz(v);
            ll mid = (len/2) + (len&1);
            for(auto j: v)
            {
                if(j < mid)
                {
                    if(j >= k)
                    {
                        cout << s[i];
                    }

                    else
                    {
                        if(j & 1)
                        {
                            
                        }
                    }
                }

                else
                {
                    ll rem = len - 1 - j;

                    if(rem >= k)
                    {
                        cout << s[i+len-1];
                    }

                    else
                    {
                        if(rem & 1)
                        {

                        }

                        else
                        {

                        }
                    }
                }

                i++;
            }

            num++;
        }
    }
    cout << endl;

    return 0;
}