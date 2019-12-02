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
    
    ll n;
    cin >> n;

    while(n--)
    {
        string s;
        cin >> s;

        string t;
        cin >> t;

        ll first = 0;
        ll second = 0;

        ll lens = sz(s);
        ll lent = sz(t);
        ll cur = s[0];
        ll prev = -1;

        ll f = 0;

        for(ll i=0; i<sz(t); i++)
        {
            if(prev != cur)
            {
                while(t[i]==prev)
                {
                    i++;
                }

                if(f==1 && i != lent)
                {
                    f = 0;
                    break;
                }
            }

            if(t[i]==cur)
            {
                prev = cur;
                cur = s[++first];
            }

            else
            {
                break;
            }

            if(first == lens)
            {
                f = 1;
                // break;
            }
        }

        if(f)
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