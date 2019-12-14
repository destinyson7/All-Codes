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

const ll L = 2e5+5;

void solve()
{
    ll n;
    cin >> n;

    ll oz = 0, zo = 0, oo = 0, zz = 0; 
    set <ll> t1, t2, t3, t4;

    map <string, ll> pos;

    for(ll i=0; i<n; i++)
    {
        string a;
        cin >> a;   

        pos[a] = i;

        ll last = sz(a)-1;

        if(a[0] == '1' && a[last] == '0')
        {
            oz++;
            t1.insert(i);
        }

        else if(a[0] == '0' && a[last] == '1')
        {   
            zo++;
            t2.insert(i);
        }

        else if(a[0] == '0' && a[last] == '0')
        {   
            oo++;
            t3.insert(i);
        }

        else
        {
            zz++;
            t4.insert(i);
        }

        reverse(all(a));

        if(pos.find(a) != pos.end())
        {
            t1.erase(i);
            t2.erase(i);
            t3.erase(i);
            t4.erase(i);

            t1.erase(pos[a]);
            t2.erase(pos[a]);
            t3.erase(pos[a]);
            t4.erase(pos[a]);
        }
    }

    if(oz == 0 && zo == 0 && oo > 0 && zz > 0)
    {
        cout << -1 << endl;
        return;
    }

    ll ans = abs(oz - zo)/2;
    ll cnt = 0;

    if(oz >= zo)
    {
        cout << ans << endl;

        for(auto i: t1)
        {
            if(cnt == ans)
            {
                break;
            }

            cout << i+1 << " ";
            cnt++;
        }
        cout << endl;
    }

    else
    {
        cout << ans << endl;

        for(auto i: t2)
        {
            if(cnt == ans)
            {
                break;
            }

            cout << i+1 << " ";
            cnt++;
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}