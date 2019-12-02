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

const ll L = 25;

vector <ll> b(L);
ll a[L][L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, M, C;
    cin >> N >> M >> C;

    for(ll i=0; i<M; i++)
    {
        cin >> b[i];
    }

    ll ans = 0;

    for(ll i=0; i<N; i++)
    {
        for(ll j=0; j<M; j++)
        {
            cin >> a[i][j];
        }

        ll cur = C;
        for(ll j=0; j<M; j++)
        {
            cur+=a[i][j]*b[j];
        }

        if(cur > 0)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}