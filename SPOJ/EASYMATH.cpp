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

ll lcm(ll a, ll b)
{
    return (a*b)/gcd(a, b);
}

ll ans = 0;

vector <ll> a;

void solve(ll n, ll i)
{
    if(i == 0)
    {
        ans+=n;
    }

    else if(i == 1)
    {
        for(ll j=0; j<5; j++)
        {
            ans-=(n/a[j]);
        }
    }

    else if(i == 2)
    {
        for(ll j=0; j<5; j++)
        {
            for(ll k=j+1; k<5; k++)
            {
                ans+=(n/lcm(a[j], a[k]));
            }
        }
    }

    else if(i == 3)
    {
        for(ll b=0; b<5; b++)
        {
            for(ll c=b+1; c<5; c++)
            {
                for(ll d=c+1; d<5; d++)
                {
                    ans-=(n/lcm(a[b], lcm(a[c], a[d])));
                }
            }
        }
    }

    else if(i == 4)
    {
        for(ll b=0; b<5; b++)
        {
            for(ll c=b+1; c<5; c++)
            {
                for(ll d=c+1; d<5; d++)
                {
                    for(ll e=d+1; e<5; e++)
                    {
                        ans+=(n/lcm(a[b], lcm(a[c], lcm(a[d], a[e]))));
                    }
                }
            }
        }
    }

    else
    {
        ans-=(n/lcm(a[0], lcm(a[1], lcm(a[2], lcm(a[3], a[4])))));
    }
}

const ll L = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        ans = 0;
        a.clear();

        ll n, m, t, d;
        cin >> n >> m >> t >> d;

        a.pb(t);
        a.pb(t+d);
        a.pb(t+2*d);
        a.pb(t+3*d);
        a.pb(t+4*d);

        solve(m, 0);
        // cout << ans << endl;
        solve(m, 1);
        // cout << ans << endl;
        solve(m, 2);
        // cout << ans << endl;
        solve(m, 3);
        // cout << ans << endl;
        solve(m, 4);
        // cout << ans << endl;
        solve(m, 5);

        ll res = ans;

        ans = 0;

        solve(n-1, 0);
        solve(n-1, 1);
        solve(n-1, 2);
        solve(n-1, 3);
        solve(n-1, 4);
        solve(n-1, 5);

        cout << res-ans << endl;

    }
    
    return 0;
}