#include <bits/stdc++.h>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<pair<int, int>,null_type,less<pair<int, int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ordered_set s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert({i, x});
	}
	for (int i = 0; i < n; i++) {
		int ind;
		cin >> ind;
		ind--;
		auto p = s.find_by_order(ind);
		cout << p->second << " \n"[i == n - 1];
		s.erase(p);
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
