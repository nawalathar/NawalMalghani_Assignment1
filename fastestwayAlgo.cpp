#include "FastestWay.h"

int main()
{
	int e1=6,e2=7,x1=4,x2=1;
	int a1[8]={1,2,3,4,5,6,7,1};
	int a2[8]={7,6,5,4,3,2,1,1};
	int t1[7]={9,8,7,6,5,4,1};
	int t2[7]={8,6,4,2,1,3,1};
	int f1[9],f2[9],L1[9],L2[9],L;
	FastestWayAlgo(e1,e2,a1,a2,x1,x2,f1,f2,L1,L2,L,t1,t2,7);
	
	int x = fasttime(L1,L2,L,6,f1);
	int expected = 28;


	if(x == expected) {

	cout << "Test Passed: " << x << "/" << expected << endl;
	
	} else {
	
	cout << "Test Failed: " << x << "/" << expected << endl;
	}
	return 0;
}
