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
 
    ll n;
    cin >> n;

    string s;
    cin >> s;

    // ll cnt = n;
    // ll low = 0;
    // ll high = 1;

    ll cnt1 = 0, cnt2 = 0;

    for(ll i=0; i<n; i++)
    {
        if(s[i]=='0')
        {
            cnt1++;
        }

        else
        {
            cnt2++;
        }
    }

    cout << n - 2*min(cnt1, cnt2) << endl;

    return 0;
}