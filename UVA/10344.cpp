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

vector <char> operators = {'+', '-', '*'};

bool possible = false;

vector <ll> a(5);

void backtrack(ll node, char cur_op, ll res)
{
    if(node == 5)
    {
        // cout << res << endl;

        if(res == 23)
        {
            possible = true;
        }

        return;
    }

    if(cur_op == '+')
    {
        res += a[node];
    }

    else if(cur_op == '-')
    {
        res -= a[node];
    }

    else
    {
        res *= a[node];
    }

    for(ll i=0; i<3; i++)
    {
        backtrack(node+1, operators[i], res);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true)
    {
        possible = false;
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

        ll check = 0;

        for(ll i=0; i<5; i++)
        {
            check += (a[i]*a[i]);
        }

        if(check == 0)
        {
            break;
        }

        sort(all(a));

        do
        {
            // cout << a << endl;

            ll res = a[0];

            for(ll i=0; i<3; i++)
            {
                backtrack(1, operators[i], res);
            }

        } while(next_permutation(all(a)));
        
        if(possible)
        {
            cout << "Possible" << endl;
        }

        else
        {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}