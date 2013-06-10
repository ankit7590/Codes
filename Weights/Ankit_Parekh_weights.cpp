/*
Ankit Parekh
25 March 2013
ankitparekh8@gmail.com
*/

#include<map>
#include<vector>
#include<iostream>

using namespace std;
void weights(int A[],int N);
int main()
{
	int N,i;
	int A[101];
	A[0]=0;
	while(1)
	{
		cin >> N;
		if(N==0)
			break;

		cout << endl;
		for(i=1;i<=N;i++)
		{
			cin >> A[i];
		}
		weights(A,N);

	}

	return 0;
}

void weights(int A[],int N)
{
	int i,e1,e2,count,size,j;
	vector<int> v;
	map<int,int> H;
	vector<int>::iterator e,s;
	H[A[1]]=1;
	
	v.push_back(A[1]);
	
	for(i=2;i<=N;i++)
	{
		size=v.size();
		for(j=0; j<size ; j++)
		{
			e1 = abs(v.at(j) + A[i]);
			e2 = abs(v.at(j) - A[i]);

			if(H.find(A[i]) == H.end())
			{
				H[A[i]]=1;
				v.push_back(A[i]);
			}

			if(e1 > 0)
			{
				if(H.find(e1) == H.end() )
				{
					H[e1] = 1;
					v.push_back(e1);
				}
			}

			if(e2 > 0)
			{
				if(H.find(e2) == H.end() )
				{
					H[e2] = 1;
					v.push_back(e2);
				}
			}
			
		}
	}

	count=0;
	/*for(s=v.begin();s!=v.end();s++)   //For printing the weights
	{
		cout << *s << endl;
		count++;
	}*/
	cout << "\n\nCount :: " << v.size() << endl << endl ;

}
