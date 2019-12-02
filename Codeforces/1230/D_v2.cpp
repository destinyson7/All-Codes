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

const ll L = 7e3+5;
const ll M = 65;

ll a[L], b[L];

ll s[L][M];
vector <pll> h[M];
ll included[L];
ll put[L][M];

vector <pair <ll, pll>> p;

map <ll, vector <ll>> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    if(n == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(ll i=0; i<n; i++)
    {
        cin >> b[i];
        m[a[i]].pb(i);

        ll temp = a[i];

        ll cnt = 0;
        while(temp)
        {
            if(temp&1)
            {
                s[i][cnt] = 1;
                h[cnt].pb(mp(b[i], i));
            }

            else
            {
                s[i][cnt] = 0;
            }

            temp >>= 1;
            cnt++;
        }
    }

    ll tot = 0;
    for(auto i: m)
    {
        if(sz(i.ss) > 1)
        {
            ll temp = i.ff;

            ll cnt = 0;
            while(temp)
            {
                if(temp&1)
                {
                    put[tot][cnt] = 1;
                }

                temp >>= 1;
                cnt++;
            }
        }

        tot++;
    }

    ll ans = 0;

    for(ll i=0; i<M; i++)
    {
        if(sz(h[i]) == 1)
        {
            included[h[i][0].ss] = true;

            // cout << i << " " << "here" << endl;
        }
    }

    ll in = 0;

    for(ll i=0; i<n; i++)
    {
        bool f = true;

        if(!included[i])
        {
            for(ll j=0; j<tot; j++)
            {
                f = true;
                ll temp = a[i];

                ll cnt = 0;

                while(temp)
                {
                    if(temp & 1)
                    {
                        if(put[j][cnt] == 0)
                        {
                            f = false;
                            break;
                        }
                    }

                    temp >>= 1;
                    cnt++;
                }

                if(f)
                {
                    in++;
                    included[i] = 1;
                    ans += b[i];
                    break;
                }
            }
        }

    }   

    if(in >= 2)
    {
        cout << ans << endl;
    }

    else
    {
        cout << 0 << endl;
    }

    return 0;
}