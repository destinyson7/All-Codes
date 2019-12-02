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
    
    ll n;
    cin >> n;

    vector <ll> a;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);
    }

    ll f = 0;

    ll cnt = 0;

    for(ll i=1; i<n; i++)
    {
        if(!f && a[i] < a[i-1])
        {
            f = 1;
            cnt++;
        }

        else if(f && a[i] > a[i-1])
        {
            f = 0;
            cnt++;
        }
    }

    if(cnt < 2)
    {
        cout << "YES" << endl;
    }

    else
    {
        cout << "NO" << endl;
    }


    return 0;
}