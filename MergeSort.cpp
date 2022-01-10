#include <iostream>

using namespace std;

int a[10];
int t[10];

void merge_sort(int lt, int rt) {
	int p1, p2, p3;
	int mid;
	if(lt<rt) {
		mid=(lt+rt)/2;
		merge_sort(lt, mid);
		merge_sort(mid+1, rt);

		p1=lt;
		p2=mid+1;
		p3=lt;

		while(p1<=mid&&p2<=rt) {
			if(a[p1]<a[p2]) t[p3++]=a[p1++];
			else t[p3++]=a[p2++];
		}
		while(p1<=mid) t[p3++]=a[p1++];
		while(p2<=rt) t[p3++]=a[p2++];

		for(int i=lt; i<=rt; ++i) 
			a[i]=t[i];
	}
}

int main() {

	int n=10;

	for(int i=0; i<n; ++i)
		a[i]=n-i;

	cout << "Before: ";
	for(int i=0; i<n; ++i)
		cout << a[i] << ' ';
	cout << "\n\n";

	merge_sort(0, n-1);

	cout << "After: ";
	for(int i=0; i<n; ++i)
		cout << a[i] << ' ';
	cout << "\n\n";

	return 0;
}
