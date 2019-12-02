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

const ll L = 2e5+5;

vector <ll> d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        d.pb(t);
    }

    ll low = 0;
    ll high = n;

    ll ans = 0;

    while(low <= high)
    {
        ll mid = low + (high-low)/2;

        ll sum1 = 0, sum3 = 0;

        for(ll i=0; i<=mid; i++)
        {
            sum1+=d[i];
        }

        ll i = 0;

        for(i=n-1; i>mid; i--)
        {
            sum3+=d[i];

            if(sum1 == sum3)
            {
                ans = sum1;

                low = mid+1;

                break;
            }

            else if(sum3 > sum1)
            {
                low = mid+1;
                break;
            }
        }

        if(sum3 < sum1)
        {
            high = mid-1;
        }
    }

    cout << ans << endl;

    return 0;
}