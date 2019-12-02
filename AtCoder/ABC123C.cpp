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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N;
    ll a[5];

    cin >> N;

    for(ll i=0; i<5; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    for(ll i=0; i<5; i++)
    {
        if(N%a[i]==0)
        {
            ans = max(ans, N/a[i]);
        }

        else
        {
            ans = max(ans, N/a[i]+1);
        }
    }

    cout << ans+4 << endl;    

    return 0;
}