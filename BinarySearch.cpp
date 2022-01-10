#include <iostream>

using namespace std;

int main() {
	
	int a[5]={10,20,30,40,50};
	int n=5;
	
	int lt=0, rt=n-1;
	int target=20;
	
	while(lt<=rt) {
		int mid=(lt+rt)/2;
		cout << "lt:" << lt << " mid:" << mid << " rt:" << rt << '\n';
		if(a[mid]==target) {
			cout << "Find";
			break;
		} 
		else if(a[mid]<target)
			lt=mid+1;
		else
			rt=mid-1;
	}
	
	return 0;
}
