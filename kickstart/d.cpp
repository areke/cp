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

int dfs(int x, vector<int> & p, vector<bool> & vis) {
    if (vis[x]) return 0;
    vis[x] = 1;
    return 1 + dfs(p[x], p , vis);
}

int main() {
    int tests;
    cin >> tests;
    int test = 0;
    while (tests--) {
        test++;
        int n;
        cin >> n;
        vector<int> p(n);
        //zcout << "???" << endl;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        vector<bool> vis(n, false);
        map<int, int> m;
        vector<pair<int, int> > v;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                m[dfs(i, p, vis)]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            int p = 1;
            while (m[i] >= p) {
                v.push_back(make_pair((i * p), p));

                m[i] -= p;
                p *= 2;
            }
            if (m[i] > 0) {
                v.push_back(make_pair((m[i] * i), m[i]));
            }
        }
        
        vector<int> dp(n + 1, 1e9);
        dp[0] = -1;
        int maxi = 0;

        priority_queue<int> pq;

        for (int i = 0; i < v.size(); i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (j + v[i].first > n) continue;
                dp[j + v[i].first] = min(dp[j] + v[i].second, dp[j + v[i].first]);
            }
        }
        int cur = 0;
        vector<int> mini(n + 1, 1e9);
        mini[n] = dp[n];
        for (int i = n - 1; i >= 0; i--) {
            mini[i] = min(mini[i + 1], dp[i]);
        }
        cout << "Case #" << test << ": ";
        for (int i = 1; i <= n; i++) {
            int res = min(dp[i], mini[i] + 1);
            cout << res;
            if (i == n) cout << endl;
            cout << " ";
        }
    }
}