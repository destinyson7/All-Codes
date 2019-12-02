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
    
    ll r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

    ll a, b, c, d;

    for(ll i=1; i<=9; i++)
    {
        a = i;
        b = r1-a;
        c = c1-a;
        d = c2-b;

        set <ll> s;
        s.insert(a);
        s.insert(b);
        s.insert(c);
        s.insert(d);

        if(sz(s) == 4)
        {
            if(a+d == d1 && b+c == d2 && b<10 && c<10 && d<10 && b && c && d && a+c == c1 && b+d == c2 && a+b == r1 && c+d == r2)
            {
                cout << a << " " << b << endl << c << " " << d << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}