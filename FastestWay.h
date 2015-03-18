

#include<iostream>
using namespace std;


void FastestWayAlgo(int e1,int e2,int *a1,int *a2,int x1,int x2,int *f1,int *f2,int *L1,int *L2,int &L,int *t1,int *t2,int n)
{
	f1[1]=e1+a1[1]; //Entrance time and time at first station in line 1
	f2[1]=e2+a2[1]; //Entrance time and time at first station in line 2
	int i;
	for(i=2;i<n;i++) //loop from station 2 to last station of Line 1
	{
		if(f1[i-1]+a1[i]<f2[i-1]+a1[i]+t2[i-1])
		{
			f1[i]=f1[i-1]+a1[i];
			L1[i]=1;
		}
		else
		{
			f1[i]=f2[i-1]+a1[i]+t2[i-1];
			L1[i]=2;
		}
		if(f2[i-1]+a2[i]<f1[i-1]+a2[i]+t1[i-1]) //loop from station 2 to last station of Line 2
		{
			f2[i]=f2[i-1]+a2[i];
			L2[i]=2;
		}
		else
		{
			f2[i]=f1[i-1]+a2[i]+t1[i-1];
			L2[i]=1;
		}
	}
	
	if(f1[n-1]+x1<f2[n-1]+x2)
	{
		f1[n]=f1[n-1]+x1;
		L=1;
	}
	else
	{
		f1[n]=f2[n-1]+x2;
		L=2;
	}

}
//
int fasttime(int *L1,int *L2,int L,int n,int *f1)
{
	int i=L;
	
	cout<<"Station Number = "<<n<<" is on line = "<<i<<endl;
	int j;
	for(j=n;j>=2;j--)
	{
		if(i==1)
		{
			i=L1[j];
		}
		else
		{
			i=L2[j];
		}
		cout<<"Station Number = "<<j-1<<" is on line = "<<i<<endl;
		//<<"Fastest Time = "<<f1[length+1]<<endl;
	}
	cout<<"Fastest Time = "<<f1[n+1]<<endl;

	return f1[n+1];
}
