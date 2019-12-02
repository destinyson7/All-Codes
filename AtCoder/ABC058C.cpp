#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 55;

// vector <string> s(L);

ll ccnt[1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        string s;
        cin >> s;

        ll tcnt[1005];

        for(ll j=97; j<123; j++)
        {
            tcnt[j] = 0;
        }

        for(ll j=0; j<sz(s); j++)
        {
            tcnt[(ll)s[j]]++;
        }

        for(ll j=97; j<123; j++)
        {
            if(i)
            {
                ccnt[j] = min(ccnt[j], tcnt[j]);
            }

            else
            {
                ccnt[j] = tcnt[j];
            }
        }
    }

    for(ll i=97; i<123; i++)
    {
        for(ll j=0; j<ccnt[i]; j++)
        {
            cout << (char)i;
        }
    }
    cout << endl;

    return 0;
}