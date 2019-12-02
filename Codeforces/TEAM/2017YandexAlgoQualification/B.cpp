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

const ll L = 20;
const ll M = 105;

// string rooms[L][M];

map <string, map <ll, string>> store;

// map <string, map <string, string>> offices;

// vector <string> cities;
// map <string, vector <string>> offices;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll c;
    cin >> c;

    for(ll i=0; i<c; i++)
    {
        string s;
        ll n;
        cin >> s >> n;

        for(ll j=0; j<n; j++)
        {
            string t, a;
            cin >> t >> a;

            // cout << "here" << endl;

            for(ll k=0; k<24; k++)
            {
                if(t[k] == '.')
                {
                    if(store[s].find(k) == store[s].end())
                    {
                        // cout << a << endl;
                        store[s][k] = a;
                    }
                }
            }

            // offices[s][a] = t;
        }
    }

    ll m;
    cin >> m;

    while(m--)
    {
        ll b;
        cin >> b;

        vector <string> v;

        for(ll i=0; i<b; i++)
        {
            string temp;
            cin >> temp;
            v.pb(temp);
        }

        bool f = true;
        for(ll i=0; i<24; i++)
        {
            vector <string> ans;
            f = true;

            for(ll j=0; j<b; j++)
            {
                if(store[v[j]].find(i) == store[v[j]].end())
                {
                    f = false;
                    break;
                }

                else
                {
                    ans.pb(store[v[j]][i]);
                }
            }

            if(f)
            {
                cout << "Yes ";
                for(auto print: ans)
                {
                    cout << print << " ";
                }
                cout << endl;

                break;
            }
        }

        if(!f)
        {
            cout << "No" << endl;
        }
        
    }

    return 0;
}