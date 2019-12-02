using namespace std;

#include <iostream>
#include <deque>

typedef long long int ll;

void printDeque(deque <ll> name)
{
	ll len = name.size();

	cout << "Deque is: ";
	for(ll i=0; i<len; i++)
	{
		cout << name.at(i) << " ";
	}
	cout << endl;
}

int main()
{
	ll Q, K;
	cin >> Q >> K;

	ll ans = 0, c;
	
	deque <ll> arr[2];
	while(Q--)
	{
		ll b, C;
		cin >> b >> C;

		c = C^ans;
		// cout << "c is " << c << endl;

		if(b==1)
		{	
			ll d;
			cin >> d;
			arr[0].push_front(d);
			arr[1].push_front(c);

			// printDeque(arr[0]);
			// printDeque(arr[1]);

			// ll templen = arr[1].size();
			// cout << " color       " << arr[1].at(templen-1) << endl; 
		}

		else if(b==2)
		{
			ll d;
			cin >> d;
			arr[0].push_back(d);
			arr[1].push_back(c);
		}

		else
		{
			// cout << "[" << c-K << ", " << c+K << "]" << endl;
			// ll tempmax=arr[0].at(0), finalmax=arr[0].at(0);
			ll tempmax = 0, finalmax = 0;

			ll len = arr[0].size();

			// for(ll n=0; n<len; n++)
			// {
			// 	if(arr[1].at(n)>=(c-K) && arr[1].at(n)<=(c+K))
			// 	{
			// 		tempmax = arr[0].at(n);
			// 		finalmax = tempmax;
			// 		break;
			// 	}
			// }

			// ll start = 0;
			// ll end = 0;
			for(ll i=0; i<len; i++)
			{
				// cout << arr[1].at(i) << endl;
				if(arr[1].at(i)>=(c-K) && arr[1].at(i)<=(c+K))
				{
					tempmax+=arr[0].at(i);
			
					if(arr[0].at(i) > tempmax)
					{
						tempmax=arr[0].at(i);
						// start = i;
						// end = i;
					}

					if(tempmax > finalmax)
					{
						finalmax=tempmax;
						// end = i;
					}
				}
			}

			// cout << start << " " << end << endl;
			// if(len==0)
			// {
			// 	start = end+1;
			// }

			// for(ll m=start; m<=end; m++)
			// {
			// 	if(arr[1].at(m)>=(c-K) && arr[1].at(m)<=(c+K))
			// 	{
			// 		ll iterator = m;
			// 		arr[0].erase(arr[0].begin()+iterator);
			// 		arr[1].erase(arr[1].begin()+iterator);
			// 		m--;
			// 		end--;
			// 	}
			// }

			ans = finalmax;

			cout << ans << endl;

			// printDeque(arr[0]);
			// printDeque(arr[1]);
		}
	}

	return 0;
}