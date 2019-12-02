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

const ll L = (1LL << 20) + 1;
ll pens[L], f[L];

void cal(ll k, ll mask)
{
    if(f[mask] == 1)
    {
        return;
    }

    pens[mask] = k;
    f[mask] = 1;

    for(ll i=0; i<20; i++)
    {
        if((mask & (1LL << i)) > 0)
        {
            cal(k, mask - (1LL << i));
        }
    }
}

const ll M = 1e6+5;
ll print[M];

void solve()
{
    ll N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    for(ll i=0; i<L; i++)
    {
        f[i] = 0;
        pens[i] = 0;
    }

    for(ll i=1; i<=K; i++)
    {
        string temp;
        cin >> temp;

        ll len = sz(temp);

        ll mask = 0;
        for(ll j = 0; j<len; j++)
        {
            mask |= (1LL << (temp[j] - 97));
        }

        cal(i, mask);
    }

    ll mask_n = 0, left = 0;

    for(ll i=0; i<N; i++)
    {
        ll store = mask_n;

        mask_n |= (1LL << (s[i] - 97));
        if(f[mask_n] != 1)
        {
            for(ll j = left; j < i; j++)
            {
                print[j] = pens[store];
            }

            left = i;

            mask_n = (1LL << (s[i] - 97));
        }
    }

    for(ll i=left; i<N; i++)
    {
        print[i] = pens[mask_n];
    }

    for(ll i=0; i<N; i++)
    {
        cout << print[i] << " ";
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