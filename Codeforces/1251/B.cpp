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

    ll Q;
    cin >> Q;

    while(Q--)
    {
        ll n;
        cin >> n;

        ll cnt0 = 0, cnt1 = 0;

        vector <ll> lens;

        for(ll i=0; i<n; i++)
        {
            string s;
            cin >> s;

            for(ll j=0; j<sz(s); j++)
            {
                if(s[j] == '0')
                {
                    cnt0++;
                }

                else
                {
                    cnt1++;
                }
            }

            lens.pb(sz(s));
        }

        sort(all(lens));

        // ll ans = 0;

        // for(ll i=0; i<n-1; i++)
        // {
        //     if(lens[i] & 1)
        //     {
        //         if(cnt0 < cnt1)
        //         {
        //             if(cnt1 >= (lens[i]-1))
        //             {
        //                 cnt1 -= (lens[i]-1);
        //             }

        //             else
        //             {
        //                 break;
        //             }

        //             if(cnt0)
        //             {
        //                 cnt0--;
        //             }

        //             else
        //             {
        //                 cnt1--;
        //             }
        //         }

        //         else
        //         {
        //             if(cnt0 >= (lens[i]-1))
        //             {
        //                 cnt0 -= (lens[i]-1);
        //             }

        //             else
        //             {
        //                 break;
        //             }

        //             if(cnt1)
        //             {
        //                 cnt1--;
        //             }

        //             else
        //             {
        //                 cnt0--;
        //             }
        //         }
        //     }

        //     else
        //     {
                
        //     }
        // }

        // ll len = lens[n-1];

        ll sum = 0;
        for(ll i=0; i<n-1; i++)
        {
            sum += lens[i];
        }

        ll len = lens[n-1];

        ll ans = n-1;

        if(len & 1)
        {
            if(sum%2 == 0 && cnt0%2 == 1 && cnt1%2 == 1)
            {
                // do nothing
            }

            if(sum%2 == 0 && cnt0%2 == 0 && cnt1%2 == 1)
            {
                ans++;
            }

            if(sum%2 == 0 && cnt0%2 == 1 && cnt1%2 == 0)
            {
                ans++;
            }

            if(sum%2 == 0 && cnt0%2 == 0 && cnt1%2 == 0)
            {
                // do nothing
            }

            if(sum%2 == 1 && cnt0%2 == 1 && cnt1%2 == 1)
            {
                ans++;
            }

            if(sum%2 == 1 && cnt0%2 == 0 && cnt1%2 == 1)
            {
                // do nothing
            }

            if(sum%2 == 1 && cnt0%2 == 1 && cnt1%2 == 0)
            {
                // do nothing
            }

            if(sum%2 == 1 && cnt0%2 == 0 && cnt1%2 == 0)
            {
                ans++;
            }   
        }

        else
        {
            if(sum%2 == 0 && cnt0%2 == 1 && cnt1%2 == 1)
            {
                // do nothing
            }

            if(sum%2 == 0 && cnt0%2 == 0 && cnt1%2 == 1)
            {
                // do nothing
            }

            if(sum%2 == 0 && cnt0%2 == 1 && cnt1%2 == 0)
            {
                // do nothing
            }

            if(sum%2 == 0 && cnt0%2 == 0 && cnt1%2 == 0)
            {
                ans++;
            }

            if(sum%2 == 1 && cnt0%2 == 1 && cnt1%2 == 1)
            {
                // do nothing
            }

            if(sum%2 == 1 && cnt0%2 == 0 && cnt1%2 == 1)
            {
                ans++;
            }

            if(sum%2 == 1 && cnt0%2 == 1 && cnt1%2 == 0)
            {
                ans++;
            }

            if(sum%2 == 1 && cnt0%2 == 0 && cnt1%2 == 0)
            {
                // do nothing
            }   
        }

        cout << ans << endl;

    }

    return 0;
}