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

ll a[L];
ll b[L];
ll ans1[L];
ll ans2[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    ll N, Q;
    cin >> N >> Q;

    for(ll i=0; i<N; i++)
    {
        cin >> a[i];
    }

    for(ll i=0; i<N; i++)
    {
        cin >> b[i];
    }

    return 0;
}