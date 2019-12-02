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

vector <ll> store;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k;
    cin >> n >> k;

    ll cnt = 0;

    for(ll i=1; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            cnt++;
            
            if(i!=(n/i))
            {
                store.pb(n/i);
            }
        }

        if(cnt == k)
        {
            cout << i << endl;
            return 0;
        }
    }

    reverse(all(store));

    k-=cnt;

    if(sz(store) < k)
    {
        cout << -1 << endl;
        return 0;
    }

    cnt = 0;

    cout << store[k-1] << endl;

    return 0;
}