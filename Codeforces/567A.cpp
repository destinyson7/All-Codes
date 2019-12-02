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

    vector <pll> p(n);

    for(ll i=0; i<n; i++)
    {
        cin >> p[i].ff;

        p[i].ss = i+1;
    }

    sort(all(p));

    vector <pll> ans(n+5);

    for(ll i=0; i<n; i++)
    {
        if(i && i<n-1)
        {
            ans[p[i].ss].ff = min(abs(p[i-1].ff-p[i].ff), abs(p[i+1].ff - p[i].ff));
            ans[p[i].ss].ss = max(abs(p[i].ff - p[0].ff), abs(p[n-1].ff - p[i].ff));
        }

        else if(!i)
        {
            ans[p[i].ss].ff = abs(p[i+1].ff - p[i].ff);
            ans[p[i].ss].ss = abs(p[n-1].ff - p[i].ff);   
        }

        else
        {
            ans[p[i].ss].ff = abs(p[i-1].ff-p[i].ff);
            ans[p[i].ss].ss = abs(p[i].ff - p[0].ff);
        }
    }

    for(ll i=1; i<=n; i++)
    {
        cout << ans[i].ff << " " << ans[i].ss << endl;
    }


    return 0;
}