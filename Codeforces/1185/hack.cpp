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
 
    int n;
    cin >>n;

    for(int i=0; i<n; i++)
    {
        string s, t;
        cin >> s >> t;

        int cnt = 0;

        bool ok=false;
        bool ok2 = true;
    
        for(int j=0; j<t.size(); j++)
        {
            if(j == 0)
            {
                if(t[j]==s[cnt])
                {
                    cnt++;
                }

                else
                {
                    break;
                }
            }

            else
            {
                if(t[j] == s[cnt])
                {
                    cnt++;
                }

                else if(t[j]!=s[cnt-1])
                {
                    ok2 = false;
                    break;
                }
            }
        }

        if(cnt == s.size())
        {
            ok = true;
        }

        if(ok && ok2)
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