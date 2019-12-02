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

    ll m = 10;
    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;
   
        m = min(a, m);
    }

    ll m2 = 15;

    for(ll i=0; i<10; i++)
    {
        ll a;
        cin >> a;

        m2 = min(a, m2);
    }

    if(m >= m2)
    {
        cout << "10" << endl;
    }

    else
    {
        cout << m << endl;
    }


    return 0;
}