#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> res(5, 0);
        map<pair<int, int>, int> mp;
        for (auto & x : coordinates) {
            for (int i = -1; i <= 0; i++) {
                for (int j = -1; j <= 0; j++) {
                    mp[{i + x[0], j + x[1]}]++;
                }
            }
        }
        for (auto it : mp) {
            if (it.first.first < 0 || it.first.first >= m - 1 || it.first.second < 0 || it.first.second >= n - 1) continue;
            res[it.second]++;
        }
        res[0] = (m - 1) * (n - 1);
        for (int i = 1; i < 5; i++) {
            res[0] -= res[i];
        }
        return res;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Solution s;
	vector<vector<int> > v = {{0, 0}, {1, 1}, {0, 2}};
	for (int i = 0; i < 5; i++) {
		cout << s.countBlackBlocks(3, 3, v)[i] << endl;;
	}
	


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
