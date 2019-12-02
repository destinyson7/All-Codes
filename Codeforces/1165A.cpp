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
    
    ll n, x, y;
    cin >> n >> x >> y;

    string s;
    cin >> s;

    ll cnt = 0;

    for(ll i=n-x; i<n; i++)
    {
        if(i == n-y-1)
        {
            if(s[i]!='1')
            {
                cnt++;
            }
        }

        else
        {
            if(s[i]!='0')
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}