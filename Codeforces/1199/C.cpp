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
    
    ll n, I;
    cin >> n >> I;

    ll m = 8*I;

    vector <ll> a;
    map <ll, ll> fre;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);
    }

    sort(all(a));

    vector <ll> dis;

    dis.pb(a[0]);
    fre[0]++;
    ll cnt = 0;
    ll ans = n;

    for(ll i=1; i<n; i++)
    {
        if(a[i-1] != a[i])
        {
            dis.pb(a[i]);
            cnt++;
        }

        fre[cnt]++;        
    }

    ll bits = 1;

    ll cur = fre[0];
    ll c = 0;

    for(ll i=1; i<=cnt; i++)
    {
        bits++;

        ll req = n*(ll)(ceil(log2(bits)));

        if(req > m)
        {
            break;
        }

        c = i;
        cur+=fre[c];
    }

    ans = n-cur;

    for(ll i=c+1; i<=cnt; i++)
    {
        cur+=fre[i];
        cur-=fre[i-c-1];

        if(n - cur < ans)
        {
            ans = n - cur;
        }
    }

    cout << ans << endl;



    return 0;
}