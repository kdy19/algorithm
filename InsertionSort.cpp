#include <iostream>

using namespace std;

int main() {
	
	int n[5]={5,4,3,2,1};
	int idx=1;
	
	cout << idx << ": ";
	for(int i=0; i<5; ++i)
		cout << n[i] << ' ';
	cout << '\n';
	idx++;
	
	for(int i=1; i<5; ++i) {
		int key=n[i];
		int j=i-1;
		while(j>=0&&n[j]>key) {
			n[j+1]=n[j];
			j--;
		}
		n[j+1]=key;
		
		cout << idx << ": ";
		for(int l=0; l<5; ++l)
			cout << n[l] << ' ';
		cout << '\n';
		idx++;
	}
	
	return 0;
}
