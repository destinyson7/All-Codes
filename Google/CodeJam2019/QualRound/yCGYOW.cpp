#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;
    
    for(ll j=1; j<=T; j++)
    {
        ll N;
        cin >> N;
        
        string P;
        cin >> P;
    
        string ans;

        for(ll i=0; i<2*N-2; i++)
        {
            if(P[i]=='S')
            {
                ans+='E';
            }

            else
            {
                ans+='S';
            }
        }

        cout << "Case #" << j << ": " << ans << endl;

    }
    
    return 0;
}