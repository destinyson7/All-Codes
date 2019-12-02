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

const ll L = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll L, R;
    cin >> L >> R;

    ll ans = 1e18;
    
    if(R-L >= 2019)
    {
        cout << 0 << endl;
        return 0;
    }
    
    else
    {
        for(ll i=L; i<=R; i++)
        {
            for(ll j=i+1; j<=R; j++)
            {
                ans = min(ans, (i*j)%2019);
            }
        }
    }

    cout << ans << endl;

    return 0;
}