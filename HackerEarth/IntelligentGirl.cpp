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

const ll L = 1e4+5;

ll ans[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string S;
    cin >> S;

    ll cur = 0;

    for(ll i=sz(S)-1; i>=0; i--)
    {
        ll t = (ll)(S[i]-48);

        if(t%2 == 0)
        {
            cur++;
        }

        ans[i] = cur;
    }

    for(ll i=0; i<sz(S); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}