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

vector <ll> cnt(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    ll cur = 0;
    for(ll i=0; i<(ll)S.size(); i++)
    {
        if(S[i]=='A' && S[i+1]=='C')
        {
            cnt[i] = cur;
            cur++;
            i++;
            cnt[i] = cur;
        }

        else
        {
            cnt[i] = cur;
        }

        // cout << cnt[i] << " at i=" << i << endl;
    }

    while(Q--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << cnt[r]-cnt[l] << endl; 
    }

    return 0;
}