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
#include <assert.h>
#include <array>
#include <list>
#include <cstring>
using namespace std;

// 
// k = 2
// 1 3 2 4

// 5 3 1 2

// k = 3
// 1 2 3 4 5 6
// 7 7 7 3 3 3

// 1->4
// 2->4
// 3->4
// 4->0
// 5->0
// 6->0
// 1->7
// 2->7
// 3->7
// 4->3
// 5->3
// 6->3

//1 -> 5
//2 -> 3
//3 -> 1
//4 -> 2

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> b(n + 2);
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}
		int k = 0;
		for (int i = 1; i <= n; i++) {
			if (b[i] < i) {
				break;
			}
			k = i;
		}
		vector<vector<int> > v(n + 2);
		for (int i = 1; i <= n; i++) {
			v[b[i]].push_back(i);
		}
		int start = -1;
		if (v[0].size()) {
			start = 0;
		} else {
			start = n + 1;
		}

		priority_queue<array<int, 3> > pq;
		pq.push({-0, (int) v[0].size(), start});

		vector<int> res(n + 1);
		int cur = 0;
		while (!pq.empty()) {
			array<int, 3> top = pq.top();
			pq.pop();
			res[cur++] = top[2];
			for (int i = 0; i < v[top[2]].size(); i++) {
				int next = v[top[2]][i];
				//cout << i << " " << top[2] << " " << next << endl;
				pq.push({top[0] - 1, (int) -v[next].size(), next});
			}
		}
		//assert(k >= 1 && k <= n);
		cout << k << endl;
		for (int i = 1; i <= n; i++) {
			cout << res[i] << " ";
			assert(res[i] >= 1 && res[i] <= n);
		}
		cout << endl;

		
	}
	return 0;
}
