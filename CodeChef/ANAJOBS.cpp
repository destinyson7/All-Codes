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

ll ones[L];
ll twos[L];

ll N, K, J;

set <ll> s;
vector <ll> v;

bool check(ll mid)
{
    ll jobs = 0;

    ll store = mid/2;

    if(store == 0)
    {
        for(auto i: v)
        {
            if(twos[i] > 0)
            {
                return false;
            }

            jobs += (ones[i]/K + (ones[i]%K > 0));
        }

        return (jobs <= J);
    }   

    for(auto i: v)
    {
        ll one = ones[i];
        ll two = twos[i];

        ll req = two/store;
        two %= store;

        if(mid & 1)
        {
            one -= req;
        }

        if(two > 0)
        {
            req++;
            one -= (mid - 2*two);
        }

        one = max(one, 0LL);

        req += (one/mid + (one%mid > 0));   

        jobs += (req/K + (req%K > 0));
    }

    if(jobs <= J)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void solve()
{
    // ll N, K, J;
    cin >> N >> K >> J;

    // for(ll i=0; i<=N; i++)
    // {
    //     ones[i] = 0;
    //     twos[i] = 0;
    // }

    for(ll i=0; i<N; i++)
    {
        ll t, sz;
        cin >> t >> sz;
        
        t--;

        if(sz == 1)
        {
            ones[t]++;
        }

        else
        {
            twos[t]++;
        }

        s.insert(t);
    }

    for(auto i: s)
    {
        v.pb(i);
    }

    ll low = 1, high = 1e18;
    ll ans = -1;

    while(low <= high)
    {
        // cout << "*" << endl;
        ll mid = low + (high - low)/2;

        if(check(mid))
        {
            ans = mid;
            high = mid-1;
        }

        else
        {
            low = mid+1;
        }
    }

    cout << ans << endl;

    for(auto i: v)
    {
        ones[i] = 0;
        twos[i] = 0;
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
        s.clear();
        v.clear();

        solve();
    }

    return 0;
}