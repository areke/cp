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
#include <assert.h>
#include <queue>
#include <list>
#include <cstring>
using namespace std;

pair<vector<int>, int> solve(vector<vector<int> > & v, vector<bool> & lasts, bool & can, bool last = false) {
    //cout << v.size() << endl;
    int cur = 0;
    int p = 0;
    priority_queue<vector<int> > pq;
    vector<int> res;
    set<int> vis;
    while (p < v.size() && v[p][0] <= cur) {
        if (!last || (last && lasts[v[p][2] - 1])) {
            pq.push({v[p][1], v[p][2]});
            vis.insert(v[p][2]);
            p++;
            
        }
    }
    p = 0;
    while (!pq.empty()) {
        vector<int> top = pq.top();
        pq.pop();
        cur += top[0];
        res.push_back(top[1]);
        if (cur < 0) {
            can = false;
        }
        while (p < v.size() && v[p][0] <= cur) {
            if (vis.find(v[p][2]) == vis.end()) {
                pq.push({v[p][1], v[p][2]});
                vis.insert(v[p][2]);
            }
            p++;
            
        }
    }
    return {res, cur};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
    cin >> n;
    vector<bool> lasts(n);
    vector<vector<int> > v;
    vector<vector<int> > v2;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        string s;
        int cnt = 0;
        cin >> s;
        int mini = 0;
        lasts[i] = s[s.length() - 1] == ')';
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '(') {
                cnt++;
            } else {
                cnt--;
            }
            mini = min(mini, cnt);
        }
        int mini2 = 0;
        int cnt2 = 0;
        for (int j = s.length() - 1; j >= 0; j--) {
            if (s[j] ==')') cnt2++;
            else cnt2--;
            mini2 = min(mini2, cnt2);
        }
        
        if (cnt >= 0) {
            vector<int> vv = {-mini, cnt, i + 1};
            v.push_back(vv);
        } else {
            vector<int> vv = {-mini2, cnt2, i + 1};
            v2.push_back(vv);
        }
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    bool can = true;
    pair<vector<int>, int> res1 = solve(v, lasts, can);
    pair<vector<int>, int> res2 = solve(v2, lasts, can, true);

    if (!can || res1.first.size() + res2.first.size() != n || res1.second != res2.second) {
        cout << "impossible" << endl;
    } else {
        for (int i = 0; i < res1.first.size(); i++) {
            cout << res1.first[i] << endl;
        }
        for (int j = 0; j < res2.first.size(); j++) {
            cout << res2.first[res2.first.size() - 1 - j] << endl;
        }
    }
	return 0;
}
