#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

#define ll long long

const int iInf=(int)1e9;
const int MOD=(int)1e9;
const int d4x[4]={1,-1,0,0};
const int d4y[4]={0,0,1,-1};
const int d8x[8]={-1,-1,0,1,1,1,0,-1};
const int d8y[8]={0,1,1,1,0,-1,-1,-1};

vector<int> prepro(string p) {
	int m=p.size();
	vector<int> pi(m);
	pi[0]=0;
	int j=0;
	for(int i=1; i<m; ++i) {
		while(j>0&&p[i]!=p[j]) 
			j=pi[j-1];
		if(p[i]==p[j]) {
			pi[i]=j+1;
			++j;
		} else {
			pi[i]=0;
		}
	}

	return pi;
}

vector<int> kmp(string s, string p) {
	vector<int> pi=prepro(p);
	vector<int> ans;
	int n=s.size();
	int m=p.size();

	int j=0;
	for(int i=0; i<n; ++i) {
		while(j>0&&s[i]!=p[j])
			j=pi[j-1];

		if(s[i]==p[j]) {
			if(j==m-1) {
				ans.push_back(i-m+1);
				j=pi[j];
			} else {
				++j;
			}
		}
	}

	return ans;
}

void solve() {
	string s, p;
	getline(cin, s);
	getline(cin, p);

	vector<int> match=kmp(s, p);
	cout << match.size() << '\n';

	for(auto index : match) 
		cout << index+1 << ' ';

}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}

