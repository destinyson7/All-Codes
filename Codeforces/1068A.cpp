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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, M, K, L;
    cin >> N >> M >> K >> L;

    ll t = L+K;

    ll ans = t/M;
    
    
    if(t%M)
    {
        ans++;
    }

    if(ans*M > N)
    {
        cout << -1 << endl;
    }

    else
    {
        cout << ans << endl;
        
    }



    return 0;
}