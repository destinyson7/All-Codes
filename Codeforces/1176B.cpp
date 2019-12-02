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

const ll L = 1e2+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        ll ans = 0;
        ll b = 0;
        ll c = 0;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin >> a;

            if(a%3 == 0)
            {
                ans++;
            }

            else if(a%3 == 1)
            {
                b++;
            }

            else
            {
                c++;
            }
        }

        ans+=min(b, c);
        
        ll t = min(b, c);
        b-=t;
        c-=t;

        ans+= abs(c-b)/3;

        cout << ans << endl;
    }
    

    return 0;
}