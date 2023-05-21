#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> multi_ordered_set;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	multi_ordered_set s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		s.insert(v[i]);
	}
	for (int i = 0; i < q; i++) {
		char t;
		long long a, b;
		cin >> t >> a >> b;
		if (t == '?') {
			cout << s.order_of_key(b + 1) - s.order_of_key(a) << endl;
		} else {
			s.erase(s.upper_bound(v[a - 1]));
			v[a - 1] = b;
			s.insert(b);
		}
	}
	
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
