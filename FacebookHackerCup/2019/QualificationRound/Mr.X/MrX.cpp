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

vector <char> op = {'|', '&', '^'};

char evaluate(char E1, char O, char E2)
{
    if(E1 == 'x')
    {
        for(ll i=0; i<sz(op); i++)
        {
            if(O == op[i])
            {
                if(!i)
                {
                    if(E2 == 'x' || E2 == '0')
                    {
                        // cout << "000" << endl;
                        return 'x';
                    }

                    else
                    {
                        // cout << "001" << endl;
                        return '1';
                    }
                }

                else if(i == 1)
                {
                    if(E2 == 'x' || E2 == '1')
                    {
                        // cout << "010" << endl;
                        return 'x';
                    }

                    else
                    {
                        // cout << "011" << endl;
                        return '0';
                    }
                }

                else
                {
                    if(E2 == 'x')
                    {
                        // cout << "020" << endl;
                        return '0';
                    }

                    else if(E2 == 'X')
                    {
                        // cout << "021" << endl;                        
                        return '1';
                    }

                    else if(E2 == '1')
                    {
                        // cout << "022" << endl;
                        return 'X';
                    }

                    else
                    {
                        // cout << "023" << endl;
                        return 'x';
                    }
                }
            }
        }
    }

    else if(E1 == 'X')
    {
        for(ll i=0; i<sz(op); i++)
        {
            if(O == op[i])
            {
                if(!i)
                {
                    if(E2 == 'x' || E2 == '1')
                    {
                        // cout << "100" << endl;
                        return '1';
                    }

                    else
                    {
                        // cout << "101" << endl;
                        return 'X';
                    }
                }

                else if(i == 1)
                {
                    if(E2 == 'X' || E2 == '1')
                    {
                        // cout << "110" << endl;
                        return 'X';
                    }

                    else
                    {
                        // cout << "111" << endl;
                        return '0';
                    }
                }

                else
                {
                    if(E2 == 'x')
                    {
                        // cout << "120" << endl;
                        return '1';
                    }

                    else if(E2 == 'X')
                    {
                        // cout << "121" << endl;
                        return '0';
                    }

                    else if(E2 == '1')
                    {
                        // cout << "122" << endl;
                        return 'x';
                    }

                    else
                    {
                        // cout << "123" << endl;
                        return 'X';
                    }
                }
            }
        }
    }

    else if(E1 == '1')
    {
        for(ll i=0; i<sz(op); i++)
        {
            if(O == op[i])
            {
                if(!i)
                {
                    return '1';
                }

                else if(i == 1)
                {
                    return E2;
                }

                else
                {
                    if(E2 == 'x')
                    {
                        return 'X';
                    }

                    else if(E2 == 'X')
                    {
                        return 'x';
                    }

                    else if(E2 == '1')
                    {
                        return '0';
                    }

                    else
                    {
                        return '1';
                    }
                }
            }
        }
    }

    else
    {
        for(ll i=0; i<sz(op); i++)
        {
            if(O == op[i])
            {
                if(!i || i == 2)
                {
                    return E2;
                }

                else
                {
                    return '0';
                }
            }
        }
    }

    assert(false);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    for(ll i=1; i<=T; i++)
    {
        string s;
        cin >> s;

        ll len = sz(s);

        // cout << i << " len: " << len << endl;

        if(len == 1)
        {
            if(s == "1" || s == "0")
            {
                cout << "Case #" << i << ": " << 0 << endl;
            }

            else
            {
                cout << "Case #" << i << ": " << 1 << endl;            
            }

            continue;
        }

        vector <char> ans;

        for(ll j=0; j<len; j++)
        {
            ans.pb(s[j]);

            ll cur = sz(ans);

            if(s[j] == ')')
            {
                ans[cur-5] = evaluate(ans[cur-4], ans[cur-3], ans[cur-2]);
               
                ans.pop_back();
                ans.pop_back();
                ans.pop_back();
                ans.pop_back();
            }
        }

        // cout << i << " remaining " << ans[0] << endl;

        if(ans[0] == '1' || ans[0] == '0')
        {
            cout << "Case #" << i << ": " << 0 << endl;
        }

        else
        {
            cout << "Case #" << i << ": " << 1 << endl;
        }
    }

    return 0;
}