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

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

const ll L = 1e3+5;

ll primes[L];
vector <ll> list_factors;
set <ll> possibles1;
set <ll> possibles2;

vector <vector<ll>> temp1;
vector <vector<ll>> temp2;

void sieve()
{
    for(ll i = 3; i < L; i++)
    {
        if(!primes[i])
        {
            list_factors.pb(i);

            primes[i] = i;

            for(ll j = 2 * i; j < L; j += i)
            {
                if(!primes[j])
                {
                    primes[j] = i;
                }
            }
        }
    }

    for(ll i = 0; i < sz(list_factors); i++)
    {
        for(ll j = i; j < sz(list_factors); j++)
        {
            if(i == j)
            {
                possibles1.insert(list_factors[i]);
            }

            else
            {
                if(list_factors[i] * list_factors[j] < L)
                {
                    possibles1.insert(list_factors[i] * list_factors[j]);
                }
            }
        }
    }

    vector <ll> temp3;
    for(auto i: possibles1)
    {
        temp3.pb(i);
    }

    for(ll i = 0; i < sz(temp3); i++)
    {
        for(ll j = i; j < sz(temp3); j++)
        {
            if(i == j)
            {
                possibles2.insert(temp3[i]);
            }

            else
            {
                if(temp3[i] * temp3[j] < L)
                {
                    possibles2.insert(temp3[i] * temp3[j]);
                }
            }
        }
    }

}

// Returns size of maximum sized subset
// if there is a subset of set[] with sun
// equal to given sum. It returns -1 if there
// is no subset with given sum.
ll isSubsetSum(vector <ll> set, ll n, ll sum)
{
    // The value of subset[i][j] will be true if there
    // is a subset of set[0..j-1] with sum equal to i
    bool subset[sum + 1][n + 1];
    ll count[sum + 1][n + 1];

    // If sum is 0, then answer is true
    for (ll i = 0; i <= n; i++)
    {
        subset[0][i] = true;
        count[0][i] = 0;
    }

    // If sum is not 0 and set is empty,
    // then answer is false
    for (ll i = 1; i <= sum; i++)
    {
        subset[i][0] = false;
        count[i][0] = -1;
    }

    // Fill the subset table in bottom up manner
    for (ll i = 1; i <= sum; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            subset[i][j] = subset[i][j - 1];
            count[i][j] = count[i][j - 1];
            if (i >= set[j - 1])
            {
                subset[i][j] = subset[i][j] ||
                            subset[i - set[j - 1]][j - 1];

                if (subset[i][j])
                    count[i][j] = max(count[i][j - 1],
                                count[i - set[j - 1]][j - 1] + 1);
            }
        }
    }

    return count[sum][n];
}

void solve()
{
    ll n = nxt();

    ll ans = 1;


    for(auto i: temp2)
    {
        vector <ll> todo;

        for(auto j: i)
        {
            if(j <= n)
            {
                todo.pb(j);
            }

            else
            {
                break;
            }
        }

        ll get = isSubsetSum(todo, sz(todo), n);
        if(get != -1)
        {
            ans = max(ans, get);
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    sieve();

    for(ll i : possibles2)
    {
        vector <ll> temp = {i, i * 2};
        temp1.pb(temp);

        for(ll j: possibles2)
        {
            if(j >= i)
            {
                vector <ll> cur = {i, i * j};
                temp1.pb(cur);
            }
        }
    }

    for(auto i: temp1)
    {
        ll mult = i[1]/i[0];

        vector <ll> cur;
        ll now = i[0];

        while(now <= L)
        {
            cur.pb(now);
            now *= mult;
        }

        temp2.pb(cur);
    }

    ll T = 1;
    T = nxt();

    for(ll i=1; i<=T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
