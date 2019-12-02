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

    ll cur = sz(s)-1;

    while(cur>=0)
    {
        if(s[cur]=='r')
        {
            if(cur>=5 && s[cur-1]=='e' && s[cur-2]=='s' && s[cur-3]=='a' && s[cur-4]=='r' && s[cur-5]=='e')
            {
                cur-=6;
            }

            else if(cur>=6 && s[cur-1]=='e' && s[cur-2]=='m' && s[cur-3]=='a' && s[cur-4]=='e' && s[cur-5]=='r' && s[cur-6]=='d')
            {
                cur-=7;
            }

            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }

        else if(s[cur]=='e')
        {
            if(cur>=4 && s[cur-1]=='s' && s[cur-2]=='a' && s[cur-3]=='r' && s[cur-4]=='e')
            {
                cur-=5;
            }

            else
            {
                cout << "NO" << endl;
                return 0;
            } 
        }

        else if(s[cur]=='m')
        {
            if(cur>=4 && s[cur-1]=='a' && s[cur-2]=='e' && s[cur-3]=='r' && s[cur-4]=='d')
            {
                cur-=5;
            }

            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }

        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}