#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll T;
    cin >> T;
    
    while(T--)
    {
        ll N, P;
        string s;
        
        cin >> N >> s >> P;
        
        if(s[0]=='e')
        {
            cout << 2*P-1 << endl;
        }
        
        else
        {
            cout << 2*P << endl;
        }
    }
    
    return 0;
}


