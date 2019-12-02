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

    string S;
    cin >> S;

    ll cnt = 0;
    ll ans = 0;
    for(ll i=0; i<(ll)S.size(); i++)
    {
        if(S[i]=='A' || S[i]=='C' || S[i]=='G' || S[i]=='T')
        {
            cnt++;
            ans = max(cnt, ans);
        }

        else
        {
            cnt = 0;
        }
    }

    cout << ans << endl;
    

    return 0;
}