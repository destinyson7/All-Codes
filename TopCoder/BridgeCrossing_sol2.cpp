#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

class BridgeCrossing{
 public:
    int minTime(vector <int> times)
    {     
        ll n = times.size();
        ll len = n;
        
        sort(times.begin(), times.begin()+n);
        
        ll cost = 0, cost2=0, actcost = 0;
        while(n>3)
        {
            cost=times[1] + times[0] + times[n-1] + times[1];
			n-=2;
            
            cost2=(times[0]+times[len-1]);
            len--;
            
            cost2+=(times[0]+times[len-1]);
            len--;
            
           	if(cost < cost2)
            {
                actcost+=cost;
            }
            
            else
            {
                actcost+=cost2;
            }                   
        }
       
        if(n==1)
        {
            actcost+=times[0];
        }   
        
        else if(n==2)
        {
            actcost+=max(times[1], times[0]);
        }
        
        else
        {
            actcost+=(times[0]+times[1]+times[2]);
        }
        
        return actcost;            
    }
};