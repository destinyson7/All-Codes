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
    
    ll a, x, y;
    cin >> a >> x >> y;

    if(y%a == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    if(y < a)
    {
        ll t = a/2;

        if(a%2 == 0)
        {
            t--;
        }

        if(abs(x) <= t)
        {
            cout << 1 << endl;
        }

        else
        {
            cout << -1 << endl;
        }

        return 0;
    }

    ll cur = 1;
    y-=a;

    cur += (y/(2*a))*3+1;

    y%=(2*a);

    if(y > a)
    {
        cur++;

        ll temp = a;

        if(abs(x) < temp)
        {
            if(!x)
            {
                cout << -1 << endl;
                return 0;
            }

            if(x > 0)
            {
                cur++;
            }

            cout << cur << endl;
        }

        else
        {
            cout << -1 << endl;
        }
    }

    else
    {

        ll temp = a/2;

        if(a%2 == 0)
        {
            temp--;
        }

        if(abs(x) <= temp)
        {
            cout << cur << endl;
        }

        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}