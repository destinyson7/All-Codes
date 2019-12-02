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

vector <ll> a;

bool f = true;

ll fun(ll N, ll from, ll to, ll temp)
{
    if(N == 0)
    {
        return 0;
    }

    if(a[N-1] == from)
    {
        return fun(N-1, from, temp, to);
    }

    if(a[N-1] == to)
    {
        N--;
        return (1<<N) + fun(N, temp, to, from);
    }

    f = false;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N;
    cin >> N;

    for(ll i=0; i<N; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);
    }

    ll ans = fun(N, 1, 2, 3);

    if(!f)
    {
        cout << -1 << endl;
    }

    else
    {
        cout << ans << endl;
    }

    return 0;
}