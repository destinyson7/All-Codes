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
#define SZ 26

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

ll cnt[SZ][L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;

    ll len = sz(s);

    for(ll i=0; i<SZ; i++)
    {
        for(ll j=0; j<len; j++)
        {
            if((s[j] - 97) == i)
            {
                cnt[i][j+1] = cnt[i][j] + 1;
            }

            else
            {
                cnt[i][j+1] = cnt[i][j];
            }


            // cout << cnt[i][j+1] << " ";
        }
        // cout << endl;
    }

    ll q;
    cin >> q;

    while(q--)
    {
        ll l, r;
        cin >> l >> r;

        if(l == r)
        {
            cout << "Yes" << endl;
            continue;
        }

        l--;

        bool possible = true;

        for(ll i=0; i<SZ; i++)
        {
            // cout << cnt[i][r] << " " << cnt[i][l] << " " << r-l << endl;
            ll cur = cnt[i][r] - cnt[i][l];

            if(r-l == cur)
            {
                possible = false;
                break;
            }
        }

        if(!possible)
        {
            cout << "No" << endl;
            continue;
        }

        if(s[r-1] == s[l])
        {
            ll temp = 0;

            for(ll i=0; i<SZ; i++)
            {
                if(cnt[i][r] != cnt[i][l])
                {
                    temp++;

                    if(temp >= 3)
                    {
                        // cout << "Yes" << endl;
                        possible = true;
                        break;
                    }
                }
            }

            if(temp <= 2)
            {
                possible = false;
            }
        }

        if(!possible)
        {
            cout << "No" << endl;
        }

        else
        {
            cout << "Yes" << endl;
        }
    }

    return 0;
}