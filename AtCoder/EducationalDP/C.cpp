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

const ll L = 1e5+5;

ll a[L], b[L], c[L];
ll ans[L][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N;
    cin >> N;

    for(ll i=0; i<N; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    ans[0][0] = max(b[0], c[0]);
    ans[0][1] = max(a[0], c[0]);
    ans[0][2] = max(a[0], b[0]);

    for(ll i=1; i<N; i++)
    {
        ans[i][0] = max(ans[i-1][1]+a[i], ans[i-1][2]+a[i]);
        ans[i][1] = max(ans[i-1][0]+b[i], ans[i-1][2]+b[i]);
        ans[i][2] = max(ans[i-1][0]+c[i], ans[i-1][1]+c[i]);    
    }

    // for(ll i=0; i<N; i++)
    // {
    //     cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    // }

    cout << max(ans[N-1][0], max(ans[N-1][1], ans[N-1][2])) << endl;

    return 0;
}