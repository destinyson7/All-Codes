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

const ll L = 105;

vector <ll> h;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    ll N;
    cin >> N;

    for(ll i=0; i<N; i++)
    {
        ll a;
        cin >> a;

        h.pb(a);
    }   

    ll cur = 0;
    ll ans = 0;

    while(1)
    {
        // cur = 0;
        while(h[cur]==0)
        {
            cur++;

            if(cur==N)
            {
                cout << ans << endl;
                return 0;
            }
        }

        for(ll i=cur; i<N; i++)
        {
            if(h[i])
            {
                h[i]--;
            }

            else
            {
                break;
            }
        }

        ans++;
    }

    // cout << ans << endl;

    return 0;
}