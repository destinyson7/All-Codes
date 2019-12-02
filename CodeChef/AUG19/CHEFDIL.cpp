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
        string s;
        cin >> s;

        ll len = sz(s);

        bool f = false;

        for(ll i=0; i<len; i++)
        {
            if(s[i] == '0')
            {
                f = true;
            }

            else
            {
                f = false;

                if(i<len-1)
                {
                    if(s[i+1] == '1')
                    {
                        s[i+1] = '0';
                    }

                    else
                    {
                        s[i+1] = '1';
                    }
                }
            }
        }

        if(f)
        {
            cout << "LOSE" << endl;
        }

        else
        {
            cout << "WIN" << endl;
        }
    }

    return 0;
}