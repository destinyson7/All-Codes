using namespace std;

#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long int ll;

int main()
{
    ll T;
    cin >> T;
    
    while(T--)
    {
        ll n;
        cin >> n;
     
        ll sum=0;
    
        sum+=(3*(((n-1)/3)*((n-1)/3 + 1))/2);
        sum+=(5*((n-1)/5)*((n-1)/5 + 1)/2);
        sum-=(15*((n-1)/15)*((n-1)/15 + 1)/2);
        
        cout << sum << endl;
    }
    
    return 0;
}