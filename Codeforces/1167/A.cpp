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
    
    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        string s;
        cin >> s;

        ll flag = 0;

        for(ll i=0; i<n; i++)
        {
            if(s[i]=='8')
            {
                if(i+10<n)
                {
                    // cout << "YES" << endl;
                    flag = 1;
                    break;
                }

                else
                {
                    // cout << "NO" << endl;
                    // return 0;
                    flag = 0;
                    break;
                }
            }
        }

        if(flag)
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }    

    return 0;
}