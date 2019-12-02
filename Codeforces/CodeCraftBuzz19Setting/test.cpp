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
    
    ll T = 1;
    // cin >> T;

    while(T--)
    {
        ll n, k;
        cin >> n >> k;

        if(k%3 == 0)
        {
            n%=(k+1);

            if(n<=(k-2))
            {
                vector <string> v = {"Dhasu is broke", "Dhasu Single is ready to mingle", "Dhasu Single is ready to mingle"};

                cout << v[n%3] << endl;
            }

            else
            {
                cout << "Dhasu Single is ready to mingle" << endl;
            }

        }

        else
        {
            vector <string> v = {"Dhasu is broke", "Dhasu Single is ready to mingle", "Dhasu Single is ready to mingle"};

            cout << v[n%3] << endl;
        }

    }


    return 0;
}