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

bool cmp(pll a, pll b)
{
    if(a.ff == b.ff)
    {
        return a.ss > b.ss;
    }

    return a.ff < b.ff;
}

vector <pll> p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, d;
    cin >> n >> d;

    for(ll i=0; i<n; i++)
    {
        ll m, s;
        cin >> m >> s;

        p.pb(mp(m, s));
    }

    sort(all(p), cmp);

    ll i=0;
    
    ll ans = 0;

    for(i=0; i<n; i++)
    {
        if(p[i].ff - p[0].ff >= d)
        {
            break;
        }

        ans+=p[i].ss;
    }

    ll start = 0;
    ll end = i;

    ll cur = ans;

    while(end<n)
    {
        if(p[end].ff - p[start].ff >= d)
        {
            cur-=p[start].ss;
            start++;
        }

        else
        {
            cur+=p[end].ss;
            end++;

            ans = max(cur, ans);
        }
    }

    cout << ans << endl;


    return 0;
}