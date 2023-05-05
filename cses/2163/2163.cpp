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
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	long long n, k;
	cin >> n >> k;
	ordered_set s;
	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}
	int cnt = k % s.size();
	while (n--) {
		auto it = s.find_by_order(cnt);
		cout << (*it) << " \n"[s.size() == 1];
		s.erase(it);
		cnt += (k);
		if (s.empty()) break;
		if (cnt >= s.size()) cnt %= s.size();
		
	}



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
