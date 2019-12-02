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
    
    ll N;
    cin >> N;

    for(ll i=N; ; i++)
    {
        ll temp = i;

        ll cur = 0;
        ll prev = temp%10;
        ll flag = 0;
        
        while(temp)
        {
            cur = temp%10;
            if(cur!=prev)
            {
                flag = 1;
                break;
            }
            prev = cur;
            temp/=10;
        }

        if(!flag)
        {
            cout << i << endl;
            return 0;
        }
    }


    return 0;
}