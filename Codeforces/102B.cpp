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
    
    string n;
    cin >> n;

    ll len = sz(n);

    if(len == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    ll cur = 0;

    for(ll i=0; i<len; i++)
    {
        cur+=(n[i]-48);
    }

    ll ans = 0;

    while(true)
    {
        ans++;

        if(cur < 10)
        {
            cout << ans << endl;
            break;
        }

        ll t = 0;

        while(cur)
        {
            t+=(cur%10);
            cur/=10;
        }

        cur = t;
    }

    return 0;
}