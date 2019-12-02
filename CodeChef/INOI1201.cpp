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

vector <pll> p;
ll a[L];
ll b[L];
ll c[L];

bool cmp(pll a, pll b)
{
    if(a.ss == b.ss)
    {
        return a.ff < b.ff;
    }

    return a.ss < b.ss;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N;
    cin >> N;

    // ll sum = 0;

    for(ll i=0; i<N; i++)
    {
        // ll a, b, c;
        cin >> a[i] >> b[i] >> c[i];
        // sum+=a[i];
        p.pb(mp(a[i], b[i]+c[i]));
    }

    sort(all(p), cmp);
    reverse(all(p));

    ll cur = p[0].ff;

    ll time = p[0].ff + p[0].ss;

    // cout << time << endl;

    for(ll i=1; i<N; i++)
    {
        time = max(time, cur + p[i].ff + p[i].ss);

        // cout << time << endl;

        cur+=p[i].ff;
    }

    cout << time << endl;


    return 0;
}