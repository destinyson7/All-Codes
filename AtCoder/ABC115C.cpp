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

vector <ll> h(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, K;
    cin >> N >> K;

    for(ll i=0; i<N; i++)
    {
        cin >> h[i];
    }

    sort(h.begin(), h.begin()+N);

    ll m = 1e15;

    for(ll i=0; i<=N-K; i++)
    {
        m = min(m, h[i+K-1]-h[i]);
    }

    cout << m << endl;
    

    return 0;
}