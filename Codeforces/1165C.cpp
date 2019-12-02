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

    ll prevChar = 0;

    ll cnt = 0;

    string ans = "";

    for(ll i=0; i<n; i++)
    {
        if(s[i] == prevChar)
        {
            cnt++;
        }

        else
        {
            ans+=s[i];

            if(prevChar == 0)
            {
                prevChar = s[i];
            }

            else
            {
                prevChar = 0;
            }
        }
    }

    if(sz(ans)&1)
    {
        cnt++;
        ans.pop_back();
    }

    cout << cnt << endl << ans << endl;

    return 0;
}