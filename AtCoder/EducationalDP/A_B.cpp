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

ll h[L];
ll m[L];

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

    m[0] = 0;
    
    // for(ll i=1; i<=K; i++)
    // {
    //     m[i] = abs(h[i] - h[0]);
    // }

    for(ll i=1; i<N; i++)
    {
        m[i] = 1e15; 
        for(ll j=i-1; j>=0 && j>=i-K; j--)
        {
            m[i] = min(m[i], m[j]+abs(h[i]-h[j]));
        }    
    }

    cout << m[N-1] << endl;

    return 0;
}