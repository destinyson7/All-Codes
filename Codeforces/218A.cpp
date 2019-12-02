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
    
    ll n, k;
    cin >> n >> k;

    vector <ll> r(2*n+10);

    for(ll i=0; i<2*n+1; i++)
    {
        cin >> r[i];
    }

    for(ll i=1; i<2*n+1; i+=2)
    {
        if(k && r[i]-r[i-1]>1 && r[i]-r[i+1]>1)
        {
            r[i]--;
            k--;
        }
    }    

    assert(k == 0);

    for(ll i=0; i<2*n+1; i++)
    {
        cout << r[i] << " ";
    }
    cout << endl;

    return 0;
}