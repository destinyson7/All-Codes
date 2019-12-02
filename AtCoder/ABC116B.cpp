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
    
    ll s;
    cin >> s;

    if(s==2 || s==1)
    {
        cout << "4" << endl;
        return 0;
    }

    ll cnt= 1;
    while(1)
    {
        if(s==4)
        {
            cout << cnt+3 << endl;
            return 0;
        }

        if(s%2==0)
        {
            s/=2;
        }

        else
        {
            s*=3;
            s++;
        }

        cnt++;
    }

    return 0;
}