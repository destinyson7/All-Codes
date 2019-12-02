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
    
    vector <ll> h1, h2;

    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        h1.pb(a);
    }

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        h2.pb(a);
    }

    ll f = 0, s = 0;

    f+=max(h1[0], h2[0]);
    
    for(ll i=1; i<n; i+=2)
    {
        while(h1[i] == h2[i])
        {
            f+=h1[i];
            i++;
        }

        ll a = 0, b = 0;

        if(h1[i-1] > h2[i-1])
        {
            
        }            
    }


    return 0;
}