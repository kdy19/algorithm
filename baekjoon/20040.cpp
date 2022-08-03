#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
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

int parent[500001];

int Find(int x) {
    if(x==parent[x])
        return x;
    else
        return parent[x]=Find(parent[x]);
}

bool Union(int x, int y) {
    x=Find(x);
    y=Find(y);

    if(x==y) return true;
    parent[y]=x;

    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; ++i)
        parent[i]=i;

    vector<pair<int, int>> line;
    for(int i=0; i<m; ++i) {
        int u, v;
        cin >> u >> v;

        line.push_back(make_pair(u, v));
    }

    int cnt=0;
    for(auto &p : line) {
        int u=p.first;
        int v=p.second;

        bool ok=Union(u, v);

        ++cnt;

        if(ok) {
            cout << cnt;
            return ;
        }

    }

    cout << 0;

    return;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

	solve();

    return 0;
}