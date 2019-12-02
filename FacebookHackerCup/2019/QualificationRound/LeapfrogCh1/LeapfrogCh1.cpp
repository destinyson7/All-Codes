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
    
    ll T;
    cin >> T;

    for(ll i=1; i<=T; i++)
    {
        string s;
        cin >> s;

        ll len = sz(s);

        if(len == 2)
        {
            cout << "Case #" << i << ": " << "N" << endl;
        }

        else
        {
            ll cnt1 = 0;
            ll cnt2 = 0;

            for(ll j=1; j<len; j++)
            {
                if(s[j]=='.')
                {
                    cnt1++;
                }

                else
                {
                    cnt2++;
                }
            }

            if(cnt2 >= cnt1 && cnt1>0)
            {
                cout << "Case #" << i << ": " << "Y" << endl;
            }

            else
            {
                cout << "Case #" << i << ": " << "N" << endl;
            }
        }
    }

    return 0;
}