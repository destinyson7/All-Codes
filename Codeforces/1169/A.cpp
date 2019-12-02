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

const ll L = 1e2+5;

ll f[L];
ll s[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;

    a--;
    x--;
    b--;
    y--;

    while(1)
    {
        if(a==b)
        {
            cout << "YES" << endl;
            return 0;
        }

        else if(a==x || b==y)
        {
            cout << "NO" << endl;
            return 0;
        }

        a++;
        b--;
        b+=n;
        a%=n;
        b%=n;
    }


    return 0;
}