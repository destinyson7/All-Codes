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
    
    ll n, m;
    cin >> n >> m;

    ll ans = 0;
    ll res = 0;

    ll t = (n+1)/2;

    if(m%3 == 0)
    {
        ans = t*(m/3);
    }

    else if(m%3 == 1)
    {
        ans = t*(m/3) + (n/3);

        if(n%3 == 2)
        {
            ans++;
        }
    }

    else if(m%3 == 2)
    {
        ans = t*(m/3 + 1);
    }

    t = (m+1)/2;

    if(n%3 == 0)
    {
        res = t*(n/3);
    }

    else if(n%3 == 1)
    {
        res = t*(n/3) + (m/3);

        if(m%3 == 2)
        {
            res++;
        }
    }

    else if(n%3 == 2)
    {
        res = t*(n/3 + 1);
    }

    cout << max(res, ans) << endl;

    return 0;
}