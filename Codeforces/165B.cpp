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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    ll n, k;
    cin >> n >> k;

    ll low = 1;
    ll high = n*k;

    ll ans = high;

    while(low <= high)
    {
        ll mid = low + (high-low)/2;

        ll cur = 0;
        ll t = mid;

        while(t)
        {
            cur+=t;
            
            t/=k;
        }

        if(cur < n)
        {
            low = mid+1;
        }

        else
        {
            ans = mid;
            high = mid-1;
        }
    }

    cout << ans << endl;


    return 0;
}