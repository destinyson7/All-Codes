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
    // ios_base::sync_with_stdio(firstalse);
	// cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;
    
    while(T--)
    {
        // cout << "here1" << endl;
        ll A, B;
        cin >> A >> B;
        
        ll N;
        cin >> N;
        
        ll low = A+1;
        ll high = B;
        
        ll mid = low + (high-low)/2;
        ll ans = mid;

        // cout << "here" << endl;
        
        while(low<=high)
        {
            mid = low + (high-low)/2;
            
            cout << mid << endl;
            fflush(stdout);
            
            string s;
            cin >> s;
            
            if(s=="CORRECT")
            {
                break;
            }
            
            else if(s=="TOO_SMALL")
            {
                low = mid+1;
                ans = mid+1;
            }
            
            else
            {
                high = mid-1;
                // ans = mid;
            }

            // cout << low << " " << high << " " << mid << " " << ans << "  OKKK" <<  endl;
        }
    }
    
    return 0;
}