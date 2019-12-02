#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd __gcd
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e5+5;
const ll mod = 1e9+7;

ll modexp(ll a, ll b, ll c)
{
    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%c;
        b>>=1;
    }

    return ans;
}

ll modmul(ll a, ll b, ll c)
{
    ll ans = 0;

    while(b)
    {
        if(b&1)
        {
            ans = (ans+a)%c;
        }

        a = (a+a)%c;
        b>>=1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        ll K;
        cin >> K;

        cout << modmul(5, modexp(2, K, mod), mod) << endl;
    }

    return 0;
}