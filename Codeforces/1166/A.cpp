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

string s[L];
vector <ll> cnt(505);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        cin >> s[i];

        cnt[(ll)s[i][0]]++;
    }

    ll ans = 0;

    for(ll i=0; i<505; i++)
    {
        ll t = cnt[i]/2;
        ans+=max((ll)0, ((t*(t-1))/2));
        
        t = cnt[i]-t;
        ans+=max((ll)0, ((t*(t-1))/2));
    }

    cout << ans << endl;

    return 0;
}