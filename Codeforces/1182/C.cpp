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
const ll M = 1e6+5;

vector <string> s(L);
ll cnt[L];
ll last[L];
ll h[L];

string vowels = "aeiou";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    // cout << vowels << endl;

    for(ll i=0; i<n; i++)
    {
        cin >> s[i];

        for(ll j=0; j<sz(s[i]); j++)
        {
            for(ll k=0; k<5; k++)
            {
                if(s[i][j]==vowels[k])
                {
                    last[i] = j;
                    cnt[i]++;
                    break;
                }
            }
        }
    }

    for(ll i=0; i<M; i++)
    {
        h[cnt[i]]++;
    }

    for(ll i=0; i<M; i++)
    {
        for(ll j=0; j<M; j++)
        {
            
        }
    }

    return 0;
}