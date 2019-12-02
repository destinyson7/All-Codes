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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    vector <ll> f(5, n/5);
    vector <ll> s(5, m/5);

    for(ll i=1; i<=n%5; i++)
    {
        f[i]++;
    }


    for(ll i=1; i<=m%5; i++)
    {
        s[i]++;
    }

    cout << f[0]*s[0] + f[1]*s[4] + f[2]*s[3] + f[3]*s[2] + f[4]*s[1] << endl;
    return 0;
}