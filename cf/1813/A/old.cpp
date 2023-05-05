#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <unordered_map>
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
 
vector<long double> l, d;
vector<int> qmin, qbase, qmax;
list<vector<long double> > old_bad;
list<vector<long double> > old_base_bad;
vector<long double> expected;
int shadow_size_delta = 50;
 
struct LRU {
	int max_size = 0;
	int cur_size = 0;
 
	void init(int sz) {
		max_size = sz;
	}
 
	unordered_map<int, list<pair<int, int> >::iterator> m;
	list<pair<int, int> > l;
	int get(int k) {
		if (!m.count(k)) return -1;
		return (*(m[k])).second;
	}
 
	int evict() {
		assert(!l.empty());
		m.erase(m.find(l.back().first));
		int ret = l.back().second;
		l.pop_back();
		cur_size--;
		return ret;
	}
 
	void put(int k, int v) {
		l.push_front({k, v});
		m[k] = l.begin();
		cur_size++;
	}
 
	int size() {
		return cur_size;
	}
};
 
 
struct multiLRU {
	vector<LRU> lrus, base_lrus, shadow_lrus;
	long double total_bad, total_base_bad;
	vector<long double> base_bad, bad;
	vector<int> target_sizes;
	int max_size, num_tenants = 0;
	int cur_size = 0;
	void resize_targets(int u, int delta) {
		int n = num_tenants;
		int old_size = target_sizes[u];\
		target_sizes[u] = max(min(qmax[u], target_sizes[u] + delta), qmin[u]);
		int left = old_size - target_sizes[u];
		// left negative -> we need to decrease other things 
 
		long double total = 0;
		for (int i = 0; i < n; i++) {
			total += target_sizes[i];
		}
		vector<int> old_target_sizes = target_sizes;
		vector<bool> vis(n, false);
		while (left != 0) {
			int old_left = left;
			for (int i = 0; i < n; i++) {
				int old_size = target_sizes[i];
				target_sizes[i] = max(qmin[i], min(target_sizes[i] + (int)(left * (old_target_sizes[i] / total)), qmax[i]));
				left -= (target_sizes[i] - old_size);
			}
			for (int i = 0; i < n; i++) {
				if (vis[i]) continue;
				
				if (target_sizes[i] == qmax[i] && left > 0) {
					vis[i] = true;
					total -= old_target_sizes[i];
				} else if (target_sizes[i] == qmin[i] && left < 0) {
					vis[i] = true;
					total -= old_target_sizes[i];
				}
			}
			if (left == old_left) {
				for (int i = 0; i < n; i++) {
					if (left > 0 && target_sizes[i] < qmax[i]) {
						target_sizes[i]++;
						left--;
					} else if (left < 0 && target_sizes[i] > qmin[i]) {
						target_sizes[i]--;
						left++;
					}
				}
			}
		}
		int tot = 0;
		for (int i = 0; i < n; i++) {
			tot += target_sizes[i];
		}
		assert(tot == max_size);
 
	}
 
	void init(int n, int q) {
		num_tenants = n;
		max_size = q;
		lrus.resize(n), base_lrus.resize(n), shadow_lrus.resize(n), target_sizes.assign(n, 0);
		bad.assign(n, 1), base_bad.assign(n, 1);
		long double total = 0;
		int left = q;
		for (int i = 0; i < n; i++) {
			total += d[i] * sqrt(l[i]);
			left -= qmin[i];
			target_sizes[i] = qmin[i];
		}
		vector<bool> vis(n, false);
		while (left != 0) {
			int old_left = left;
			for (int i = 0; i < n; i++) {
				int old_size = target_sizes[i];
				target_sizes[i] = min((int)(left * (d[i] * sqrt(l[i]) / total)) + target_sizes[i], qmax[i]);
				left -= target_sizes[i] - old_size;
			}
			for (int i = 0; i < n; i++) {
				if (target_sizes[i] == qmax[i] && !vis[i]) {
					vis[i] = true;
					total -= d[i] * sqrt(l[i]);
				}
			}
			if (left == old_left) {
				for (int i = 0; i < n; i++) {
					if (left > 0 && target_sizes[i] < qmax[i]) {
						target_sizes[i]++;
						left--;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			lrus[i].init(target_sizes[i]);
			base_lrus[i].init(qbase[i]);
			shadow_lrus[i].init(min(qmax[i], target_sizes[i] + shadow_size_delta));
		}
		total_bad = n;
		total_base_bad = n;
	}
 
	int put(int u, int p) {
		expected[u]++;
		int ret = lrus[u].get(p);
		bool in_shadow_queue = true;
		if (shadow_lrus[u].get(p) == -1) {
			in_shadow_queue = false;
			shadow_lrus[u].max_size = min(qmax[u], target_sizes[u] + shadow_size_delta);
			while (shadow_lrus[u].size() >= shadow_lrus[u].max_size) shadow_lrus[u].evict();
			shadow_lrus[u].put(p, p);
		}
 
		if (base_lrus[u].get(p) == -1) {
			if (base_lrus[u].size() == base_lrus[u].max_size) base_lrus[u].evict();
			base_lrus[u].put(p, p);
			total_base_bad++;
			base_bad[u]++;
		}
		if (ret != -1) {
			old_base_bad.push_back(base_bad);
			old_bad.push_back(bad);
			return ret;
		}
		
		bad[u]++;
		total_bad++;
		ret = cur_size;
		
		if (in_shadow_queue) {
			long double cs = max((long double) 0, ((bad[u] - 1) / base_bad[u]) - 1);
			cs *= cs;
			long double c = max((long double) 0, (bad[u] / base_bad[u]) - 1);
			c *= c;
			long double dcdt = (cs - c) * l[u];
			// (2x-2c-1)/c^2 
			long double scale = (base_bad[u] * base_bad[u]);
			resize_targets(u, min(max((long double)-10.0, -dcdt * scale), (long double)10.0));
		}
		if (lrus[u].cur_size == target_sizes[u]) {
			ret = lrus[u].evict();
			cur_size--;
		} else if (cur_size == max_size) {
			vector<pair<long double, int> > v(num_tenants);
			int to_evict = -1;
			for (int i = 0; i < num_tenants; i++) {
				v[i] = {target_sizes[i] - lrus[i].cur_size, i};
			}
			sort(v.begin(), v.end());
			for (int i = 0; i < num_tenants; i++) {
				if (lrus[u].size() < qmax[u] && lrus[v[i].second].size() > qmin[v[i].second]) {
					to_evict = v[i].second;
					break;
				} 
			}
			assert(to_evict != -1);
			ret = lrus[to_evict].evict();
			cur_size--;
		}
		assert(cur_size < max_size);
		lrus[u].put(p, ret);
		cur_size++;
		old_base_bad.push_back(base_bad);
		old_bad.push_back(bad);
		return ret;
	}
};
 
int main() {
	int n, q, m;
	cin >> n >> q >> m;
	l.resize(n), d.resize(n), expected.assign(n, 1);
	
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	multiLRU lru;
	qmin.resize(n), qbase.resize(n), qmax.resize(n);
 
	for (int i = 0; i < n; i++) {
		cin >> qmin[i] >> qbase[i] >> qmax[i];
	}
	lru.init(n, q);
	long double total_base_bad = n;
	long double total_bad = n;
	for (int i = 0; i < m; i++) {
		int u, p;
		cin >> u >> p;
		u--;
		int res = lru.put(u, p) + 1;
		assert(1 <= res && res <= q);
		cout << res << endl;
		cout.flush();
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}