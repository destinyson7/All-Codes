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
vector < pair <ll, ll> > v[L];
vector <string> store(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, M;
    cin >> N >> M;

    for(ll i=1; i<=M; i++)
    {
        ll P, Y;
        cin >> P >> Y;
        v[P].pb(mp(Y, i));
    }

    for(ll i=1; i<=N; i++)
    {
        sort(v[i].begin(), v[i].end());

        ll t = i;

        string temp = "";
        ll cnt = 0;
        while(t)
        {
            temp+=(char)(t%10+48);
            t/=10;
            cnt++;
        }

        reverse(temp.begin(), temp.end());

        cnt = 6-cnt;
        while(cnt--)
        {
            temp = '0' + temp;
        }

        for(ll j=0; j<sz(v[i]); j++)
        {
            string tem = "";
            ll te = j+1;

            ll count = 0;

            while(te)
            {
                tem+=(char)(te%10+48);
                te/=10;
                count++;
            }

            reverse(tem.begin(), tem.end());

            count = 6-count;

            while(count--)
            {
                tem = '0' + tem;
            }

            store[v[i][j].ss] = temp + tem;
        }
    }

    for(ll i=1; i<=M; i++)
    {
        cout << store[i] << endl;
    }

    return 0;
}