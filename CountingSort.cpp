#include <iostream>

using namespace std;

int main() {
    int n[5]={5, 5, 4, 3, 1};
    int A[6]={0,};

    for(int i=0; i<5; ++i)
        ++A[n[i]];
    
    for(int i=0; i<=5; ++i) {
        if(A[i]) {
            for(int j=0; j<A[i]; ++j)
                cout << i << ' ';
        }
    }

    return 0;
}
