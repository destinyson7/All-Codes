#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool visited[10];
ll n;
ll mini = 1500;

void Solve(vector <int> times, ll left, ll cost)
{
    if(left==1)
    {
        mini = times[0];
        return;
    }
    
    for(ll i=0; i<n; i++)
    {
        for(ll j=i+1; j<n; j++)
        {
            if(visited[i]==false && visited[j]==false)
            {
                visited[i]=true;
                visited[j]=true;

                cost += max(times[i], times[j]);
                
                if(left==2)
                {
                    if(cost<mini)
                    {
                        mini = cost;
                    }
                }

                else
                {
                    ll sendBack = 0;
                    ll minCost = 150;
                    for(ll k=0; k<n; k++)
                    {
                        if(visited[k]==true)
                        {
                            if(times[k] < minCost)
                            {
                                minCost = times[k];
                                sendBack = k;
                            }
                        }
                    }

                    visited[sendBack]=false;
                    Solve(times, left-1, cost+minCost);
                    visited[sendBack]=true;
                }
                
                visited[i]=false;
                visited[j]=false;
                cost-=max(times[i], times[j]);
            }           
        }
    }    
}

class BridgeCrossing{
 public:
    int minTime(vector <int> times)
    {     
        n = times.size();
        
        Solve(times, n, 0);       
        
        return mini;
    }
};