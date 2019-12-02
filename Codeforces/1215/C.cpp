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

    ll n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    ll cnt1 = 0, cnt2 = 0;

    for(ll i=0; i<n; i++)
    {
        if(s[i] == 'a')
        {
            cnt1++;
        }

        else
        {
            cnt2++;
        }

        if(t[i] == 'a')
        {
            cnt1++;
        }

        else
        {
            cnt2++;
        }
    }

    if(cnt1%2 == 1 || cnt2%2 == 1)
    {
        cout << -1 << endl;
        return 0;
    }

    ll cnta = 0, cntb = 0;

    vector <ll> f1, s1;

    for(ll i=0; i<n; i++)
    {
        if(s[i] != t[i])
        {
            if(s[i] == 'a')
            {
                cnta++;
                f1.pb(i);
            }

            else
            {
                cntb++;
                s1.pb(i);
            }
        }
    }

    ll save = cnta;
    cnta-=(cnta%2);
    cntb-=(cntb%2);

    vector <pll> ans;
    ll num = 0;

    for(ll i=0; i<cnta; i+=2)
    {
        ans.pb(mp(f1[i], f1[i+1]));
    }

    for(ll i=0; i<cntb; i+=2)
    {
        ans.pb(mp(s1[i], s1[i+1]));
    }

    if(save&1)
    {
        ans.pb(mp(f1[sz(f1)-1], f1[sz(f1)-1]));
        ans.pb(mp(f1[sz(f1)-1], s1[sz(s1)-1]));
    }

    cout << sz(ans) << endl;

    for(auto i: ans)
    {
        cout << i.ff+1 << " " << i.ss+1 << endl;
    }



    return 0;
}