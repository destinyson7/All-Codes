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

vector <ll> cnt(35);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, M;
    cin >> N >> M;

    for(ll i=0; i<N; i++)
    {
        ll K;
        cin >> K;

        for(ll j=0; j<K; j++)
        {
            ll a;
            cin >> a;
            cnt[a]++;
        }
    }

    ll ans = 0;

    for(ll i=1; i<=M; i++)
    {
        if(cnt[i]==N)
        {
            ans++;
        }
    }

    cout << ans << endl;



    return 0;
}