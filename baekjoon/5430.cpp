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
    int T;
    cin >> T;

    while(T--) {
        string p, x;
        int n;
        cin >> p >> n;
        cin >> x;

        string s;
        deque<int> dq;
        for(int i=0; i<x.size(); ++i) {
            if(x[i]==',') {
                dq.push_back(stoi(s));
                s="";
            }
            if(48<=x[i]&&x[i]<=57)
                s+=x[i];
        }
        if(s!="")
            dq.push_back(stoi(s));

        int rev=1;
        bool ok=1;
        for(int i=0; i<p.size(); ++i) {
            if(p[i]=='D'&&dq.empty()) {
                cout << "error\n";
                ok=0;
                break;
            } else if(p[i]=='R') {
                rev*=-1;                
            } else {
                if(rev==1) {
                    dq.pop_front();
                } else {
                    dq.pop_back();
                }
            }
        }

        if(ok) {
            if(dq.size()==0)
                cout << "[]\n";
            else if(dq.size()==1) 
                cout << '[' << dq.front() << "]\n";
            else {
                vector<int> prn;
                deque<int>::iterator iter;
                if(rev==1) {
                    for(iter=dq.begin(); iter!=dq.end(); ++iter) 
                        prn.push_back(*iter);
                    cout << '[' << prn[0] << ",";
                    for(int i=1; i<prn.size()-1; ++i)
                        cout << prn[i] << ',';
                    cout << prn[prn.size()-1] << "]\n";
                } else {
                    for(iter=dq.begin(); iter!=dq.end(); ++iter) 
                        prn.push_back(*iter);
                    cout << '[' << prn[prn.size()-1] << ",";
                    for(int i=prn.size()-2; i>0; --i)
                        cout << prn[i] << ',';
                    cout << prn[0] << "]\n";

                }
            }
        }
    }

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