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
    
    double x1, y1, x2, y2, x3, y3, x4, y4;
    // cin >> x >> y;

    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
    {
        if(x1 == x3 && y1 == y3)
        {
            cout << fixed << setprecision(3) << x4+x2-x1 << " " << y4+y2-y1 << endl;
        }

        else if(x1 == x4 && y1 == y4)
        {
            cout << fixed << setprecision(3) << x3+x2-x1 << " " << y3+y2-y1 << endl;
        }

        else if(x2 == x4 && y2 == y4)
        {
            cout << fixed << setprecision(3) << x3+x1-x2 << " " << y3+y1-y2 << endl;
        }

        else if(x2 == x3 && y2 == y3)
        {
            cout << fixed << setprecision(3) << x4+x1-x2 << " " << y4+y1-y2 << endl;
        }
    }

    return 0;
}