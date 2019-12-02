#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll t;
    cin >> t;
    while(t)
    {
        t--;
        ll n;
        cin >> n;
        map <ll,vector<pair<ll,ll>>> m;
        for (int i = 0; i < n; ++i)
        {
            ll a, b, c;

            cin >>a >> b >> c;
            m[c].push_back({a,0}); 
            m[c].push_back({b,1}); 
        }

        bool got = true;

        for(auto i: m)
        {
            sort(i.second.begin(), i.second.end());
        // }

        // for(auto i:m)
        // {
            ll cnt = 0;
            for(auto j: i.second)
            {
                // cout << j.first << " " << j.second << endl;
                if(j.second == 0)
                {
                    cnt++;
                }

                else
                {
                    cnt--;
                }

                if(cnt >= 3)
                {
                    got = false;
                    break;
                }
            }
            

            if(got == false)
            {
                break;
            }
        }

        if(got)
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