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
    
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1!=x2 && y1!=y2)
    {
        if(abs(x1-x2)!=abs(y1-y2))
        {
            cout << -1 << endl;
            return 0;
        }

        cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
    }

    else if(x1 == x2)
    {
        cout << x1 + y2 - y1 << " " << y2 << " " << x1 + y2 - y1 << " " << y1 << endl;
    }

    else
    {
        cout << x2 << " " << y2 + x2 - x1 << " " << x1 << " " << y2 + x2 - x1 << endl;
    }

    return 0;
}