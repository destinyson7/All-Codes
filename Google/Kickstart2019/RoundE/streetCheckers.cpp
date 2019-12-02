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

const int L = 1e9;

vector <bool> isPrime(L);

void sieve(int m)
{
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i <= m; i++)
    {
        isPrime[i] = true;
    }

    for(int i = 2; i <= m; i++)
    {
        if(isPrime[i])
        {
            for(int j = 2*i; j <= m; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    vector <pii> p;

    int m = 0;

    for(int t = 1; t <= T; t++)
    {
        int l, r;
        cin >> l >> r;

        p.pb(mp(l, r));
        
        m = max(m, r);
    }

    sieve(m);

    for(int t = 1; t <= T; t++)
    {
        int ans = 0;
        int l, r;
        l = p[t-1].ff;
        r = p[t-1].ss;

        for(int j = l; j <= r; j++)
        {
            int temp = j;

            int cnt = 0;

            while(!(temp&1))
            {
                cnt++;
                temp/=2;
            }

            if(cnt > 3 || (cnt == 3 && temp != 1) || (cnt != 1 && temp != 1 && !isPrime[temp]))
            {
                // cout << j << endl;
                ans++;
            }
        }

        cout << "Case #" << t << ": " << r-l+1-ans << endl;
    }

    return 0;
}