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
    
    ll n;
    cin >> n;

    ll ans = 0;

    ll mul = 1;

    while(n)
    {
        if(n<10)
        {
            if(n%10>4 && n%10<9)
            {
                ans+=(mul*(9-(n%10)));
            }

            else
            {
                ans+=(mul*(n%10));
            }
        }

        else
        {
            if(n%10>4)
            {
                ans+=(mul*(9-(n%10)));
            }

            else
            {
                ans+=(mul*(n%10));
            }
        }

        // cout << n << " " << ans << endl;

        n/=10;
        mul*=10;
    }

    cout << ans << endl;
    return 0;
}