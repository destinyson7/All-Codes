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

// vector <ll> a(L);
// vector <ll> b(L);

vector < pair <ll, ll> > v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, M;
    cin >> N >> M;

    for(ll i=0; i<N; i++)
    {
        ll a, b;
        cin >> a >> b;
        // cin >> a[i] >> b[i];

        v.pb(mp(a, b));
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    for(ll i=0; i<N; i++)
    {
        if(M<=0)
        {
            break;
        }

        ans+=v[i].ff*min(v[i].ss, M);
        M-=v[i].ss;
    }

    cout << ans << endl;


    

    return 0;
}