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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N;
    ll ans = 0;

    cin >> N;

    for(ll i=0; i<N; i++)
    {
        ll a;
        cin >> a;

        ans = __gcd(ans, a);
    }

    cout << ans << endl;

    return 0;
}