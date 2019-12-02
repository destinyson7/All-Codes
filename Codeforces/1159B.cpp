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

const ll L = 3e5+5;

vector <ll> a(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    ll ans = 1e15;

    for(ll i=1; i<=n; i++)
    {
        ans = min(ans, a[i]/max(i-1, n-i));
    }

    cout << ans << endl;
    
    return 0;
}