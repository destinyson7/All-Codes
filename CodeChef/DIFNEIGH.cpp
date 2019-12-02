#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll grid[56][56];
ll grid2[56][56];
ll grid3[56][56];

int main()
{
	ll T;
	cin >> T;

	for(ll i=1; i<=52; i++)
	{	
		ll cur=0;
		for(ll j=1; j<=52; j+=2)
		{
			if(i%4==1)
			{
				grid[i][j]=cur+1;
				grid[i][j+1]=cur+1;
				cur++;
				cur%=2;
			}

			else if(i%4==2)
			{
				grid[i][j]=cur+3;
				grid[i][j+1]=cur+3;
				cur++;
				cur%=2;
			}

			else if(i%4==3)
			{
				grid[i][j]=cur+2;
				grid[i][j+1]=cur+2;

				if(grid[i][j]%2==1)
				{
					grid[i][j]-=2;
					grid[i][j+1]-=2;
				}

				cur++;
				cur%=2;
			}

			else
			{
				grid[i][j]=cur+4;
				grid[i][j+1]=cur+4;
					
				if(grid[i][j]%2==1)
				{
					grid[i][j]-=2;
					grid[i][j+1]-=2;
				}	

				cur++;
				cur%=2;
			}
		}
	}

	ll cur2=0;
	for(ll i=1; i<=52; i++)
	{
		grid2[1][i]=cur2+1;
		grid2[2][i]=cur2+1;

		cur2++;
		cur2%=3;
	}

	ll cur3=0;
	for(ll j=1; j<=52; j++)
	{
		grid3[j][1] = cur3+1;
		grid3[j][2] = cur3+1;

		cur3++;
		cur3%=3;
	}

	while(T--)
	{
		ll N, M;
		cin >> N >> M;

		if(N==2)
		{	
			// ll cur=0, K=1;
			// for(ll a=1; a<=M; a++)
			// {
			// 	grid2[1][a]=cur+1;
			// 	grid2[2][a]=cur+1;

			// 	cur++;
			// 	cur%=3;
			// }

			ll K=1;

			for(ll a=1; a<=M; a++)
			{
				K = max(K, grid2[1][a]);
			}

			cout << K << endl;
			for(ll p=1; p<=N; p++)
			{
				for(ll q=1; q<=M; q++)
				{
					cout << grid2[p][q] << " ";
				}
				cout << endl;
			}
		}

		else if(M==2)
		{	
			// ll cur=0, K=1;
			// for(ll a=1; a<=N; a++)
			// {
			// 	grid2[a][1]=cur+1;
			// 	grid2[a][2]=cur+1;

			// 	cur++;
			// 	cur%=3;
			// }

			ll K=1;

			for(ll a=1; a<=N; a++)
			{
				K = max(K, grid3[a][1]);
			}

			cout << K << endl;
			for(ll p=1; p<=N; p++)
			{
				for(ll q=1; q<=M; q++)
				{
					cout << grid3[p][q] << " ";
				}
				cout << endl;
			}
		}

		else if((M<N || N==1) && M>1)
		{
			ll K=1;
			for(ll a=1; a<=N; a++)
			{
				for(ll b=1; b<=M; b++)
				{
					K = max(K, grid[a][b]);
				}
			}

			// cout << "K: ";
			cout << K << endl;

			for(ll p=1; p<=N; p++)
			{
				for(ll q=1; q<=M; q++)
				{
					cout << grid[p][q] << " ";
				}
				cout << endl;
			}
		}

		else
		{
			ll K=1;
			for(ll a=1; a<=N; a++)
			{
				for(ll b=1; b<=M; b++)
				{
					K = max(K, grid[b][a]);
				}
			}

			// cout << "K: ";
			cout << K << endl;

			for(ll p=1; p<=N; p++)
			{
				for(ll q=1; q<=M; q++)
				{
					cout << grid[q][p] << " ";
				}
				cout << endl;
			}
		}		
	}

	return 0;
}