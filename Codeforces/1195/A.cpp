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
    
    ll n, k;
    cin >> n >> k;

    vector <ll> v;
    map <ll, ll> cnt;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        v.pb(a);

        cnt[a]++;
    }

    ll rem = 0;

    ll ans = 0;

    for(auto i: cnt)
    {
        if(i.ss & 1)
        {
            ans+=(i.ss - 1);
            rem++;
        }

        else
        {
            ans++;
        }

    }

    if(rem&1)
    {
        ans+=(rem/2 + 1);
    }

    else
    {
        ans+=(rem/2);
    }
    

    cout << ans << endl;

    return 0;
}