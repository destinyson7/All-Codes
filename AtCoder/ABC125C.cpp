#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e5+5;

vector <ll> a(L);
vector <ll> l(L);
vector <ll> r(L);
vector <ll> m(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N;
    cin >> N;

    for(ll i=1; i<=N; i++)
    {
        cin >> a[i];
    }    

    for(ll i=1; i<=N; i++)
    {
        l[i] = 1;
        r[i] = 1;
    }

    l[0] = 0;
    r[N] = 0;
    
    for(ll i=1; i<=N; i++)
    {
        l[i] = __gcd(l[i-1], a[i]);
    }

    for(ll i=N; i>0; i--)
    {
        r[i] = __gcd(a[i], r[i+1]);
    }

    ll ans = 1;
    for(ll i=1; i<=N; i++)
    {
        m[i] = __gcd(l[i-1], r[i+1]);
        ans =  max(ans, m[i]);
    }

    cout << ans << endl;

    return 0;
}