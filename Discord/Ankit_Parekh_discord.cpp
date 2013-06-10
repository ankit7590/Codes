/*
Ankit Parekh
25 March 2013
ankitparekh8@gmail.com

*/

#include<iostream>
#include<math.h>

using namespace std;

void discord(char arr[],int n,int k);
int floorr(int n,int k);
int ceiling(int n,int k);


int main()
{
	char arr[500];
	int N;
	int k,i;
	while(1)
	{
		cin >> N;
		if(N==0)
		{
			break;
		}
		cin >> k;
		for(i=0;i<N;i++)
		{
			cin >> arr[i];
		}
		discord(arr,N,k);
	}
	
	return 0;
}

void discord(char arr[],int n,int k)
{
	int r,d,i,j,p,temp,z,min,max;
	int D[500][50],R[500][50],out[50];
	d=0;
	r=0;

	min = ceiling(n,k);
	max=floorr(n,k);

	for(i=0;i<n;i++)
	{
		if(arr[i]=='D')
			d++;
		else
			r++;

		if(i>=min-1 && i<max)
		{
		D[i][0]=abs(d-r)*abs(d-r);
		}
		else
		{
			D[i][0]=999;
		}
		R[i][0]=-1;
	}

	min = ceiling(n,k);
	max=floorr(n,k);

	for(p=1;p<k;p++)
	{
		for(i=n-1;i>=0;i--)
		{
			d=0;
			r=0;
			if(i < p)
			{
				D[i][p] = 999;
				R[i][p] = -1;
			}
			else
			{
				for(j=i ; j>i-min ; j--)
				{
					if(arr[j]=='D')
						d++;
					else
						r++;
				}
				
				z=999;
				for(j=min;j<=max;j++)
				{
					if(i-j < min)
					{
						break;
					}
					if(i-j < 0)
					{
						R[i][p]=-1;
						break;
					}
					temp = D[i-j][p-1] + abs(d-r)*abs(d-r);
					if(z>=temp)
					{
						z=temp;
						R[i][p]=i-j;
					}
					if(arr[i-j] =='D')
						d++;
					else
					r++;

				}
				D[i][p]=z;

			}
		}	
	}

	cout << endl << D[n-1][k-1] << "  ";

	j=k-1;
	k=0;
	i=n-1;
	

	while(j>0)
	{
		out[k] = R[i][j];
		k++;
		i=R[i][j];
		j--;
	}

	cout << out[k-1] + 1 << "  ";
	k--;
	while(k>0)
	{
		cout << abs(out[k] - out[k-1]) << "  ";
		k--;
	}
	cout << endl << endl;

}

int floorr(int n,int k)
{
	return (int)((4*n) / (3*k));
}
int ceiling(int n,int k)
{
	if((2*n) % (3*k) ==0)
		return ((2*n) / (3*k));
	else
		return ((2*n) / (3*k))+1;
}