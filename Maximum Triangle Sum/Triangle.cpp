/*
Ankit Parekh
22 April 2013
ankitparekh8@gmail.com
*/


#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<conio.h>

using namespace std;


int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main()
{
	vector<vector<int>> v1;
	ifstream fp("input.txt");
	string line;



	int i=0;
	while(getline(fp,line))
	{
		vector<int> v2;
		istringstream iss(line);

		for(int j=0;j<=i;j++)
		{
			int num;
			if(iss >> num)
			{
				v2.push_back(num);
			}
		}
		v1.push_back(v2);
		i++;
	}
	
	//To Test if the input file is read correctly
	/*  
	for(i=0;i<v1.size();i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout << v1[i][j] << "  " ;
		}
		cout << endl;
	}
	*/

	//Bottom-up evaluation
	for(i=v1.size()-2;i>=0;i--)
	{
		for(int j=0;j<=i;j++)
		{
			v1[i][j] = max(v1[i][j] + v1[i+1][j] , v1[i][j] + v1[i+1][j+1]);
		}
	}

	cout << v1[0][0];
	

	/*
	Top-Down evaluation can also be done at the time of reading the file as follows
    ------------------- 
	1. Read the first line of the file and store it at v1[0][0]
	2. i=1 
	3. while(file has more lines)
	   {
	        vector<int> v2;
		    istringstream iss(line);

		    for(int j=0;j<=i;j++)
		    {
			    int num;
			    if(iss >> num)
			    {
				    if(j==0)
					{
					    v2.push_back(num + v1[i-1][0]);
					}
					else if(j==i)
					{
						v2.push_back(num + v1[i-1][i-1]);
					}
					else
					{
						v2.push_back( max(num + v1[i-1][j-1] , num + v1[i-1][j] ) );
					}
			    }
		    }
		    v1.push_back(v2);
		    i++;  
	     }
	   4. Find maximum element in (i-1)th row.
	   5. Print the maximum element
	*/





	getch();
	return 0;
}



	