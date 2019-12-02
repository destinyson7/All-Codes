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

// ll cnt[L][L][5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    vector <string> s;

    ll ans = 0;

    for(ll i=0; i<n; i++)
    {
        string t;
        cin >> t;

        s.pb(t);
    }

    vector <ll> a;

    for(ll i=0; i<m; i++)
    {
        ll num;
        cin >> num;

        a.pb(num);
    }

    for(ll i=0; i<m; i++)
    {
        map <char, ll> cnt;
        ll check = 0;
        for(ll j=0; j<n; j++)
        {
            char c = s[j][i];
            cnt[c]++;
        }

        for(char k='A'; k<='E'; k++)
        {
            check = max(check, cnt[k]);
        }

        // cout << check << " " << a[i] endl;

        ans+=(check*a[i]);
    }

    cout << ans << endl;

    return 0;
}