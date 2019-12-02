#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool check(vector <int> numbers)
{
	ll temp = numbers[0] + numbers[1] + numbers[2];

	if(numbers[3]+numbers[4]+numbers[5]==temp
	&& numbers[6]+numbers[7]+numbers[8]==temp
	&& numbers[0]+numbers[3]+numbers[6]==temp
	&& numbers[1]+numbers[4]+numbers[7]==temp
	&& numbers[2]+numbers[5]+numbers[8]==temp)
	{
		return true;
	}

	return false;

}

class MNS{
public:
	int combos(vector <int> numbers)
	{
		sort(numbers.begin(), numbers.end());

		ll ans = 0;
		do
		{
			if(check(numbers))
			{
				ans++;
			}

		} while(next_permutation(numbers.begin(), numbers.end()));
	
		return ans;
	}

};