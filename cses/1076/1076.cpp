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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

using namespace std;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> multi_ordered_set;
	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, n;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	multi_ordered_set s;
	for (int i = 0; i < n; i++) {
		s.insert(a[i]);
		if (s.size() > k) {
			s.erase(s.upper_bound(a[i - k]));
		}
		if (s.size() == k) {
			cout << *s.find_by_order((k - 1) / 2) << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
