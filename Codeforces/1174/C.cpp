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

ll ans[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    ll cur = 1;

    for(ll i=2; i<=n; i++)
    {
        if(!ans[i])
        {
            ans[i] = cur;

            for(ll j=i*i; j<=n; j+=i)
            {
                if(!ans[j])
                {
                    ans[j] = cur;
                }
            }
            cur++;
        }
    }

    for(ll i=2; i<=n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}