#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

const ll L = 1e3+5;

ll ans[L];

vector <pll> sorted;
vector <pll> nots;
vector <pll> lat;

ll overlap[L][L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    for(ll i=0; i<m; i++)
    {
        ll t, l, r;
        cin >> t >> l >> r;

        if(t == 0)
        {
            nots.pb(mp(l, r));
        }

        else
        {
            for(ll j=l; j<r; j++)
            {
                overlap[j][j+1] = 1;
            }

            sorted.pb(mp(l, r));
        }
    }


    sort(all(sorted));
    sort(all(nots));
    reverse(all(nots));

    for(auto i: nots)
    {
        bool f = false;

        for(auto j: lat)
        {
            if(i!=j)
            {
                if(i.ff<=j.ff && i.ss>=j.ss)
                {
                    f=true;
                    break;
                }
            }
        }

        if(!f)
        {
            lat.pb(mp(i.ff, i.ss));
        }
    }

    sort(all(lat));
    reverse(all(lat));

    for(auto i: lat)
    {
        bool f = false;

        for(ll j=i.ff; j<i.ss; j++)
        {
            if(!overlap[j][j+1])
            {
                f=true;
                break;
            }
        }

        if(!f)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    // ll cur = 1;

    // for(auto i: sorted)
    // {
    //     for(ll j=i.ff; j<=i.ss; j++)
    //     {
    //         ans[j] = cur;
    //     }

    //     cur++;
    // }

    for(ll i=0; i<=n; i++)
    {
        ans[i] = 1;
    }

    for(auto i: lat)
    {
        for(ll j=i.ff; j<i.ss; j++)
        {
            if(!overlap[j][j+1])
            {
                ans[j] = ans[j+1]+1;
                break;
            }
        }

    }

    // for(auto i: sorted)
    // {
    //     for(ll j=i.ff+1; j<=i.ss; j++)
    //     {
    //         if(ans[j]<ans[j-1])
    //         {
    //             cout << "NO" << endl;
    //             return 0;
    //         }
    //     }
    // }

    cout << "YES" << endl;
    for(ll i=1; i<=n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}