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

vector <ll> factors;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N;
    cin >> N;

    ll ans = 1e15;

    for(ll i=1; i*i<=N; i++)
    {
        if(N%i==0)
        {
            ll a = i;
            ll b = N/i;

            ll cnt1 = 0;
            ll cnt2 = 0;
            while(a)
            {
                cnt1++;
                a/=10;
            }

            while(b)
            {
                cnt2++;
                b/=10;
            }

            ll c = max(cnt1, cnt2);

            ans = min(ans, c);
        }
    }

    cout << ans << endl;

    return 0;
}