#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int, int> m;
        for (int x : nums) {
            m[x]++;
        }
        for (int i = 0; i < moveFrom.size(); i++) {
            int y = m[moveFrom[i]];
            m[moveFrom[i]] = 0;
            m[moveTo[i]] += y;
        }
        vector<int> v;
        for (auto it : m) {
            if (it.second) {
                v.push_back(it.first);
            }
        }
        return v;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> nums = {1, 6, 7, 8};
	vector<int> moveFrom = {1, 7, 2};
	vector<int> moveTo = {2, 9, 5};
	Solution s = Solution();
	auto  res = s.relocateMarbles(nums, moveFrom, moveTo);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " \n"[i == res.size() - 1];
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
