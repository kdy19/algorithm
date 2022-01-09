#include <iostream>

using namespace std;

int main() {
	
	int n[5]={5,4,3,2,1};
	int idx=1, t;
	
	cout << "Before: ";
	for(int i=0; i<5; ++i)
		cout << n[i] << ' ';
	cout << "\n\n";
	
	cout << "----- Sort start -----\n";
	for(int i=0; i<5; ++i) {
		for(int j=0; j<5; ++j) {
			if(n[i]<n[j]) {
				t=n[i];
				n[i]=n[j];
				n[j]=t;
			}
		}
		
		cout << idx << ": ";
		for(int l=0; l<5; ++l)
			cout << n[l] << ' ';
		cout << '\n';
		idx++;
	}
	cout << "----- Sort end -----\n";
	
	cout << "After: ";
	for(int i=0; i<5; ++i)
		cout << n[i] << ' ';
	cout << "\n\n";

	return 0;
}
