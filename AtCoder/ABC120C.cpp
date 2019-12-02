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

const ll L = 1e5+5;

vector <ll> flag(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin >> s;

    // ll j=1;
    ll cnt1 = 0;
    ll cnt2 = 0;
    for(ll i=0; i<(ll)s.size(); i++)
    {
        if(s[i]=='0')
        {
            cnt1++;
        }

        else
        {
            cnt2++;
        }
    }

    cout << min(cnt1, cnt2)*2 << endl;

    return 0;
}