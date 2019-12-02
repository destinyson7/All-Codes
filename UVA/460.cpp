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
    
    ll T;
    cin >> T;

    while(T--)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;

        if(x1 < x3 && x2 <= x3)
        {
            cout << "No Overlap" << endl;
            // continue;
        }

        else if(x1 > x3 && x1 >= x4)
        {
            cout << "No Overlap" << endl;
            // continue;
        }

        else if(y1 < y3 && y2 <= y3)
        {
            cout << "No Overlap" << endl;
            // continue;
        }

        else if(y1 > y3 && y1 >= y4)
        {
            cout << "No Overlap" << endl;
            // continue;
        }

        else
        {
            vector <ll> x = {x1, x2, x3, x4};
            vector <ll> y = {y1, y2, y3, y4};

            sort(all(x));
            sort(all(y));

            cout << x[1] << " " << y[1] << " " << x[2] << " " << y[2] << endl;
        }

        if(T)
        {
            cout << endl;
        }
    }


    return 0;
}