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

const ll L = 1e5+5;

// vector <ll> cnt(30);

vector <ll> occur[30];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll m;
    cin >> m;

    vector <string> t;

    for(ll i=0; i<m; i++)
    {
        string a;
        cin >> a;

        t.pb(a);
    }

    for(ll i=0; i<26; i++)
    {
        occur[i].pb(-1);
    }



    for(ll i=0; i<n; i++)
    {
        // cnt[s[i]-'a']++;

        occur[s[i]-'a'].pb(i+1);

    }

    for(ll i=0; i<m; i++)
    {
        vector <ll> cnt(30, 0);

        for(ll j=0; j<sz(t[i]); j++)
        {
            cnt[t[i][j]-'a']++;
        }

        ll ans = 0;

        for(ll i=0; i<26; i++)
        {
            // cout << cnt[i] << " " << sz(occur[i]) << endl;
            ans = max(ans, occur[i][cnt[i]]);
        }

        cout << ans << endl;
    }


    return 0;
}