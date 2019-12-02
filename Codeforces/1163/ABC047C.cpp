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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    string s;
    cin >> s;

    ll cnt = 0;
    for(ll i=1; i<sz(s); i++)
    {
        if(s[i]!=s[i-1])
        {
            cnt++;
        }
    }   

    cout << cnt << endl;

    return 0;
}