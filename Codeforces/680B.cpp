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
    
    ll n, a;
    cin >> n >> a;

    vector <ll> t(n);

    for(ll i=0; i<n; i++)
    {
        cin >> t[i];
    }

    ll temp = min(n-a, a-1);

    a--;

    ll c = 1;

    ll cnt = 0;

    cnt+=(t[a]==1);

    for(ll i=a+1; i<=a+temp; i++)
    {
        if(t[i] == 1 && t[a-c] == 1)
        {
            cnt+=2;
        }

        c++;
    }

    for(ll i=a+temp+1; i<n; i++)
    {
        cnt+=(t[i]==1);
    }

    for(ll i=a-temp-1; i>=0; i--)
    {
        cnt+=(t[i]==1);
    }

    cout << cnt << endl;

    return 0;
}