#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long int arr[100005];
long long int store[100005];
long long int store2[100005];
long long int arr1[400020];
long long int store3[400020];
char s[300005];

int main()
{
	long long int N, Q, K;
	scanf("%lld %lld %lld", &N, &Q, &K);

	long long int cnt=0, cnt1=0;

	for(long long int i=1; i<=N; i++)
	{
		scanf("%lld", &arr[i]);

		if(arr[i])
		{
			cnt1++;
		}

		else
		{
			// store[cnt++]=cnt1;
	
			store[cnt++]=cnt1;	

			cnt1=0;
		}	

		if(i==N)
		{
			store[cnt++]=cnt1;
		}
			
	}
	
	scanf("%s", s);

	long long int max = store[0];

	// printf("store ");
	for(long long int j=0; j<cnt; j++)
	{
		// printf("%lld ", store[j]);

		if(store[j]>max)
		{
			max=store[j];
		}

		store2[store[j]]++;
	}
	// printf("\n");

	// printf("store2 ");
	// for(long long int k=0; k<=max; k++)
	// {
	// 	printf("%lld ", store2[k]);
	// }
	// printf("\n");

	for(long long int k=1; k<=N; k++)
	{
		arr1[k]=arr[k];
		arr1[k+N]=arr[k];
		arr1[k+2*N]=arr[k];
	}

	for(long long int b=0; b<cnt; b++)
	{
		store3[b]=store[b];
		store3[b+cnt]=store[b];
		store3[b+2*cnt]=store[b];
	}

	// printf("store3 ");
	// for(long long int c=0; c<3*cnt; c++)
	// {
	// 	printf("%lld ", store3[c]);
	// }
	// printf("\n");

	long long int start= 2*N+1, start2=2*cnt;
	long long int end= 3*N, end2=3*cnt-1;
	long long int ans=max;

	// for(long long int k=1; k<=3*N; k++)
	// {
	// 	printf("%lld ", arr1[k]);
	// }
	// printf("\n");

	for(long long int a=0; a<Q; a++)
	{
		if(s[a]=='!')
		{
			if(arr1[end]==1)
			{
				if(store3[end2]==0)
				{
					end2--;
					start2--;
				}	

				store2[store3[end2]]--;
				store2[store3[end2]-1]++;
				// printf("end2 is %lld, store3[end2] is %lld, store2[store3[end2]] is %lld store2[store3[end2]-1] is %lld\n", end2, store3[end2], store2[store3[end2]], store2[store3[end2]-1]);

				if(end2>=0 && end2<3*cnt)
					store3[end2]--;
				if((end2-cnt)>=0 && (end2-cnt)<3*cnt)
					store3[end2-cnt]--;
				if((end2-2*cnt)>=0 && (end2-2*cnt)<3*cnt)
					store3[end2-2*cnt]--;
				if((end2+cnt)>=0 && (end2+cnt)<3*cnt)
					store3[end2+cnt]--;
				if((end2+2*cnt)>=0 && (end2+2*cnt)<3*cnt)
					store3[end2+2*cnt]--;

				store2[store3[start2]]--;
				store2[store3[start2]+1]++;

				if(start2>=0 && start2<3*cnt)
					store3[start2]++;
				if((start2+cnt)>=0 && (start2+cnt)<3*cnt)
					store3[start2+cnt]++;
				if((start2+2*cnt)>=0 && (start2+2*cnt)<3*cnt)
					store3[start2+2*cnt]++;
				if((start2-cnt)>=0 && (start2-cnt)<3*cnt)
					store3[start2-cnt]++;
				if((start2-2*cnt)>=0 && (start2-2*cnt)<3*cnt)
					store3[start2-2*cnt]++;

			}

			else
			{
				end2--;
				start2--;
			}

			// printf("max is %lld store2[max] is %lld and start2 is %lld store3[start2] is %lld\n", max, store2[max], start2, store3[start2]);
			// printf("store2[2] is %lld\n", store2[2]);
			if(store2[max]!=0)
			{
				if(store3[start2]>max)
				{
					max=store3[start2];
				}
			}

			else
			{
				max--;

				if(store3[start2]>max)
				{
					max=store3[start2];
				}
			}

			end--;	
			
			// printf("store3 ");
			// for(long long int c=0; c<3*cnt; c++)
			// {
			// 	printf("%lld ", store3[c]);
			// }
			// printf("\n");		

		}

		else
		{
			if(max<=K)
			{
				printf("%lld\n", max);
			}

			else
			{
				printf("%lld\n", K);
			}
		}			
	}

	return 0;
}