#include <iostream>

using namespace std;

int main() {
	
	int n[5]={5,4,3,2,1};
	int t;

	for(int i=0; i<5; ++i) {
		for(int j=0; j<5; ++j) {
			if(n[i]<n[j]) {
				t=n[i];
				n[i]=n[j];
				n[j]=t;
			}
		}
	}
	
	for(int i=0; i<5; ++i)
		cout << n[i] << ' ';
	
	return 0;
}
