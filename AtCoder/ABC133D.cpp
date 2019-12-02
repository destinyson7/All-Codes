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
 
    ll N;
    cin >> N;

    vector <ll> a;
    vector <ll> ans(N, 0);

    ll sum = 0;

    for(ll i=0; i<N; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);
        
        sum+=t;
    }

    ll cur = 0;

    for(ll i=1; i<N; i+=2)
    {
        cur+=a[i];
    }

    ans[0] = sum-2*cur;

    for(ll i=1; i<N; i++)
    {
        ans[i] = 2*a[i-1] - ans[i-1];
    }

    for(ll i=0; i<N; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;



    return 0;
}