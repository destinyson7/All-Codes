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
    
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll cnt1 = 0, cnt2 = 0;

    if(s[0]=='-')
    {
        cnt1--;
    }

    for(ll i=0; i<sz(s); i++)
    {
        if(s[i]=='-')
        {   
            cnt1++;
        }

        else
        {
            cnt2++;
        }

        if(cnt1>cnt2)
        {
            cnt1--;
        }
    }

    // cout << cnt1 << " " << cnt2 << endl;

    if(cnt1 >= cnt2)
    {
        cout << 0 << endl;
    }

    else
    {
        cout << cnt2 - cnt1 << endl;
    }

    return 0;
}