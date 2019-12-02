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

    for(ll i=1; i<=T; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if(a<b+c && b<a+c && c<a+b)
        {
            if(a==b && b==c)
            {
                cout << "Case " << i << ": Equilateral" << endl;
            }

            else if(a==b || b==c || c==a)
            {
                cout << "Case " << i << ": Isosceles" << endl;
            }

            else
            {
                cout << "Case " << i << ": Scalene" << endl;
            }
        }

        else
        {
            cout << "Case " << i << ": Invalid" << endl;
        }
    }


    return 0;
}