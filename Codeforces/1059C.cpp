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

const ll L = 1e6+5;

vector <ll> res;

void solve(ll n, ll put)
{
    if(n == 3)
    {
        res.pb(put);
        res.pb(put);
        res.pb(put*3);
        return;
    }

    if(n == 2)
    {
        res.pb(put);
        res.pb(put*2);
        return;
    }

    if(n == 1)
    {
        res.pb(put);
        return;
    }

    ll upto = n/2;
    if(n&1)
    {
        upto++;
    }

    for(ll i=1; i<=upto; i++)
    {
        res.pb(put);
    }

    put<<=1;
    n>>=1;

    solve(n, put);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    solve(n, 1);

    for(ll i=0; i<sz(res); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;


    return 0;
}