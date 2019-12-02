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

vector <ll> h(25);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    ll N;
    cin >> N;

    for(ll i=0; i<N; i++)
    {
        cin >> h[i];
    }

    ll ans = 1;
    ll m = h[0];

    for(ll i=1; i<N; i++)
    {
        if(h[i] >= m)
        {
            ans++;
        }

        m = max(m, h[i]);
    }

    cout << ans << endl;

    return 0;
}