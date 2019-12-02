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

vector <ll> u(L);
vector <ll> h(L);
vector <ll> store(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=1; i<=n; i++)
    {
        cin >> u[i];
    }

    ll m = -1;
    ll ans = -1;
    for(ll i=1; i<=n; i++)
    {
        store[h[u[i]]+1]++;
        store[h[u[i]]]--;
        
        h[u[i]]++;

        m = max(m, h[u[i]]);

        if(store[i]==1 || store[1]==i || (store[m]*m==(i-1) && store[1]==1) || (store[m-1]*(m-1)==(i-m) && store[m]==1))
        {
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}