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

void solve()
{
    string A, B;
    cin >> A;
    cin >> B;

    bool f = true;
    ll res = 0, cur = 0;

    ll len1 = sz(A), len2 = sz(B);

    string cat = "";

    for(ll i=0; i<abs(len1-len2); i++)
    {
        cat += "0";
    }

    if(len1 < len2)
    {
        A = cat + A;
        len1 = len2;
    }

    else
    {
        B = cat + B;
        len2 = len1;
    }

    // cout << A << " ** " << B << endl;

    bool check = false;

    for(ll i = len1 - 1; i >= 0; i--)
    {
        if(B[i] == '1')
        {
            check = true;
        }

        if(!f)
        {
            if(A[i] == B[i])
            {
                res = max(res, cur + 1);
                cur = 0;

                if(A[i] == '0')
                {
                    f = true;
                }
            }

            else
            {
                cur++;
                res = max(res, cur);
            }
        }

        else
        {
            if(A[i] == B[i])
            {
                if(A[i] == '1')
                {
                    cur = 0;
                    f = false;
                }
            }
        }
    }

    if(!f)
    {
        cur++;
        res = max(res, cur);
    }

    if(check)
    {
        cout << res + 1 << endl;
    }

    else
    {
        cout << 0 << endl;
    }
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