#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;

#define ll long long

const int iInf=(int)1e9;
const int MOD=(int)1e9;
const int d4x[4]={1,-1,0,0};
const int d4y[4]={0,0,1,-1};
const int d8x[8]={-1,-1,0,1,1,1,0,-1};
const int d8y[8]={0,1,1,1,0,-1,-1,-1};

void solve() {
    int N;
    cin >> N;

    vector<ll> A(N);
    for(auto &a : A)
        cin >> a;

    ll cnt=0;
    sort(A.begin(), A.end());
    for(int i=0; i<N; ++i) {
        int lt=0, rt=N-1;
        while(lt<rt) {
            ll sum=A[lt]+A[rt];
            if(lt==i) {
                ++lt;
                continue;
            }
            if(rt==i) {
                --rt;
                continue;
            }
            if(sum==A[i]) {
                ++cnt;
                break;
            } else if(sum>A[i]) --rt;
            else ++lt;
        }
    }

    cout << cnt;

    return;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(4);
    cout.tie(NULL);
    cin.tie(NULL);

	solve();

    return 0;
}