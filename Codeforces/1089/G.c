#include<stdio.h>
#include<stdlib.h>

typedef long long int ll;
ll a[20];
ll minimum[10];

int main()
{
	ll t;
	scanf("%lld", &t);

	while(t--)
	{
		ll k;
		scanf("%lld", &k);

		ll cnt=0, max, min = 8;
		for(ll i=1; i<=7; i++)
		{
			scanf("%lld", &a[i]);
			a[7+i]=a[i];

			if(a[i]==1)
			{
				cnt++;
	
				if(i<min)
					min=i;

				max = i;
			}
		}

		ll rem = k%cnt;
		// printf("rem %lld\n", rem);

		ll ans;
		
		for(ll h=0; h<10; h++)
		{
			minimum[h]=0;
		}

		if(rem)
		{
			ans = (k/cnt) * 7;
	
			ll cnt2=0, cnt3=0;

			for(ll e=1; e<=7; e++)
			{
				cnt3=0;
				if(a[e]==1)
				{
					ll flag=0;
					cnt2++;
					minimum[cnt2]=ans;

					for(ll f=e; f<=14; f++)
					{
						minimum[cnt2]++;
						// printf("     %lld\n", minimum[cnt2]);

						if(a[f]==1)
						{
							cnt3++;
							// printf("cnt3 %lld\n", cnt3);

							if(cnt3==rem)
							{
								break;
							}
						}
					}
				}
			}

			ll ansmin = ans+8;
			for(ll g=1; g<=cnt2; g++)
			{
				if(minimum[g]<ansmin)
					ansmin=minimum[g];
			}

			printf("%lld\n", ansmin);
		}		
	

		else
		{
			ans = (k/cnt)*7 - 7;
			ll cnt2=0, cnt3=0;
			for(ll e=1; e<=7; e++)
			{
				cnt3=0;

				if(a[e]==1)
				{
					ll flag=0;
					cnt2++;
					minimum[cnt2]=ans;

					for(ll f=e; f<=14; f++)
					{
						minimum[cnt2]++;
						// printf("     %lld\n", minimum[cnt2]);

						if(a[f]==1)
						{
							cnt3++;
							// printf("cnt3 %lld\n", cnt3);

							if(cnt3==cnt)
							{
								break;
							}
						}
					}
				}
			}

			// printf("final cnt3 %lld\n", cnt3);

			ll ansmin = ans+8;
			// printf("ansmin %lld\n", ansmin);
			for(ll g=1; g<=cnt2; g++)
			{
				// printf("minimum[%lld] %lld\n", g, minimum[g]);
				if(minimum[g]<ansmin)
					ansmin=minimum[g];
			}

			printf("%lld\n", ansmin);
		}
	}	

	return 0;
}