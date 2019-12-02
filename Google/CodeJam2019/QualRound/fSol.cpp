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
        string s;
        cin >> s;
        
        ll len = s.length();
        
        string ans1 = "";
        string ans2 = "";
        for(ll i=0; i<len; i++)
        {
            if(s[i]=='4')
            {
                ans2+='1';
                ans1+='3';
            }
            
            else
            {
                ans1+=s[i];
                ans2+='0';
            }
        }
        
        string fans2 = "";
        ll l = ans2.length();
        
        ll flag = 0;
        for(ll i=0; i<l; i++)
        {
            if(flag==1)
            {
                fans2+=ans2[i];
            }
            
            else
            {
                if(ans2[i]!='0')
                {
                    flag = 1;
                    fans2+=ans2[i];
                }
            }
        }
        
        cout << "Case #" << j << ": " << ans1 << " " << fans2 << endl;
    }
    
    return 0;
}