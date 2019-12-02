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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    ll step, mod;

    while(cin >> step >> mod)
    {
        ll t = min(step, mod);

        bool f = true;

        for(ll i=2; i<=t; i++)
        {
            if(step%i == 0 && mod%i == 0)
            {
                f = false;
                break;
            }
        }

        ll a = step, b = mod;

        ll dig1 = 0;
        ll dig2 = 0;

        while(step)
        {
            dig1++;
            step/=10;
        }

        while(mod)
        {
            dig2++;
            mod/=10;
        }

        if(f)
        {
            for(ll i=1; i<=10-dig1; i++)
            {
                cout << " ";
            }
            cout << a;

            for(ll i=1; i<=10-dig2; i++)
            {
                cout << " ";
            }
            cout << b;

            cout << "    Good Choice" << endl << endl;
        }

        else
        {
            for(ll i=1; i<=10-dig1; i++)
            {
                cout << " ";
            }
            cout << a;

            for(ll i=1; i<=10-dig2; i++)
            {
                cout << " ";
            }
            cout << b;

            cout << "    Bad Choice" << endl << endl;
        }
    }


    return 0;
}