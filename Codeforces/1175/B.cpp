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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll check = 4294967295;

    // cout << check << endl;

    ll t;
    cin >> t;

    ll ans = 0;
    // ll cur = 0;

    ll f = 0;

    stack <ll> st;
    stack <ll> put;

    while(t--)
    {
        if(ans > check || ans < 0)
        {
            f = 1;
            break;
            // cout << "OVERFLOW!!!" << endl;
            // return 0;
        }

        if(!st.empty())
        {
            if(put.top() > check || put.top() < 0)
            {
                f = 1;
                break;
            }
        }

        string s;
        cin >> s;

        // cout << s << endl;

        if(s[0]=='a')
        {
            // cur++;
            if(st.empty())
            {
                ans++;

                if(ans > check || ans < 0)
                {
                    f = 1;
                    break;
                }
            }

            else
            {
                ll bbb = put.top();
                bbb++;

                if(bbb > check || bbb <0)
                {
                    f = 1;
                    break;
                }

                put.pop();
                put.push(bbb);
            }
        }

        else if(s[0]=='f')
        {
            ll temp;
            cin >> temp;

            st.push(temp);
            put.push(0);
        }

        else if(s[0]=='e')
        {
            ll addd = st.top()*put.top();

            // cout << st.top() << " " << put.top() << endl;

            if(st.top()<0 || st.top()>check || put.top() < 0 || put.top()>check || addd > check || addd < 0)
            {
                f = 1;
                break;
            }
            
            put.pop();
            st.pop();
            
            if(st.empty())
            {
                ans+=addd;
                // cur = 0;

                if(ans > check || check < 0)
                {
                    f = 1;
                    break;
                }
                // continue;
            }

            else
            {
                ll bb = put.top();

                // cout << "put top: " << put.top() << endl;
                bb+=addd;
                put.pop();

                put.push(bb);

                if(bb>check || bb<0)
                {
                    f = 1;
                    break;
                }
                
                // cout << st.top() << " " << put.top() << endl;
            }


        }

        if(ans > check || ans < 0)
        {
            f = 1;
            break;
        }
        // cout << ans << endl;
    }

    if(f || ans > check || ans < 0)
    {
        cout << "OVERFLOW!!!" << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}