#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <queue>
#include <list>
#include <cstring>
#include <assert.h>

using namespace std;

long long solve(int x, vector<vector<int> > & v, vector<long long> & dp, set<int> & vis) {
    if (vis.find(x) != vis.end()) return dp[x];
    vis.insert(x);
    long long res = 1;
    for (int i = 0; i < v[x].size(); i++) {
        res += solve(v[x][i], v, dp, vis);
    }
    return dp[x] = res;
}

int main() {
    int tests;
    cin >> tests;
    int test = 0;
    while (tests--) {
        test++;
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int> > v(n);
        vector<vector<int> > r(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if (a[x] > a[y]) {
                v[x].push_back(y);
            } else if (a[x] < a[y]) {
                v[y].push_back(x);
            }
        }
        vector<long long> dpv(n, 0);
        vector<long long> dpr(n, 0);
        set<int> vis;
        for (int i = 0; i < n; i++) {
            if (vis.find(i) == vis.end()) {
                solve(i, v, dpv, vis);
            }
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = max(dpv[i], res);
        }
        cout << "Case #" << test << ": " << res << endl; 
    }
}