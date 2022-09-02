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
const int MOD=(int)1e9+9;
const int d4x[4]={1,-1,0,0};
const int d4y[4]={0,0,1,-1};
const int d8x[8]={-1,-1,0,1,1,1,0,-1};
const int d8y[8]={0,1,1,1,0,-1,-1,-1};

vector<int> A[501];
bool chk[501];
int dist[501];

void solve() {
	int n, m;
    cin >> n >> m;

    for(int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    int q;
    cin >> q;
    for(int k=0; k<q; ++k) {
        int a, u, v;
        cin >> a >> u >> v;

		if(a==1) {
			A[u].push_back(v);
			A[v].push_back(u);
		} else {
			vector<int>::iterator iter;
			for(iter=A[u].begin(); iter!=A[u].end(); ++iter) {
				if(*iter==v) break;
			}
			A[u].erase(iter);

			for(iter=A[v].begin(); iter!=A[v].end(); ++iter) {
				if(*iter==u) break;
			}
			A[v].erase(iter);
		}


        memset(chk, 0, sizeof(chk));
        for(int i=1; i<=n; ++i)
            dist[i]=iInf;

        queue<int> Q;
        Q.push(1);
        dist[1]=0;
        while(!Q.empty()) {
            int x=Q.front();
            Q.pop();

            for(int i=0; i<A[x].size(); ++i) {
                if(dist[A[x][i]]>dist[x]+1) {
                    dist[A[x][i]]=dist[x]+1;
                    Q.push(A[x][i]);
                }
            }
        }

        for(int i=1; i<=n; ++i) {
            if(dist[i]==iInf) cout << "-1 ";
            else cout << dist[i] << ' ';
        }
        cout << '\n';
    }
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	solve();

	return 0;
}
