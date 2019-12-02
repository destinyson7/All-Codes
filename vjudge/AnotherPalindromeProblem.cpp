#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

const ll L = 1e3+5;

ll ans[L][L];

string s;

ll dp(ll i, ll j)
{
    if(ans[i][j]!=1e15)
    {
        return ans[i][j];
    }

    if(i >= j)
    {
        return 0;
    }

    ll a = 1e18;
    ll temp = dp(i+1, j-1);
    
    if(s[i] == s[j])
    {
        a = temp;
    }

    ll b = temp+1;

    ll c = dp(i+1, j) + 1;

    ll d = dp(i, j-1) + 1;

    ans[i][j] =  min(a, min(b, min(c, d)));

    return ans[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    for(ll t=1; t<=T; t++)
    {

        for(ll i=0; i<L; i++)
        {
            for(ll j=0; j<L; j++)
            {
                ans[i][j] = 1e15;
            }
        }

        cin >> s;

        ll len = sz(s);

        cout << "Case " << t << ": " << dp(0, len-1) << endl;
    }

    return 0;
}