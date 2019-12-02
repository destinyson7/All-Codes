#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd __gcd
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 2e5+5;

ll mod = 998244353;

vector <ll> a(L);
vector <ll> b(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];

        // cout << a[i] << " " << i+1 << " " << n-i << " ";
        a[i]*=((i+1)*(n-i));
        // cout << a[i] << endl;
    }

    for(ll i=0; i<n; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.begin()+n);
    sort(b.begin(), b.begin()+n);
    reverse(b.begin(), b.begin()+n);

    ll ans = 0;

    for(ll i=0; i<n; i++)
    {
        // cout << a[i] << " " << b[i] << endl;
        a[i]%=mod;

        ans = (ans + a[i]*b[i])%mod;
    }

    cout << ans << endl;

    return 0;
}