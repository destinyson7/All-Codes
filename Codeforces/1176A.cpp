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
    
    ll q;
    cin >> q;

    while(q--)
    {
        ll n;
        cin >> n;

        ll ans = 0;

        while(n!=1)
        {
            if(n%2 == 0)
            {
                n/=2;
                ans++;
            }

            else if(n%3 == 0)
            {
                n/=3;
                n*=2;
                ans++;
            }

            else if(n%5 == 0)
            {
                n/=5;
                n*=4;

                ans++;
            }

            else
            {
                ans = -1;
                break;
            }

        }

        cout << ans << endl;
    }

    return 0;
}