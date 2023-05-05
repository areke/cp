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
 
vector<long long> l, d;
vector<int> qmin, qbase, qmax;
list<vector<long double> > old_bad;
list<vector<long double> > old_base_bad;
vector<long double> expected;
 
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
	int max_size, num_tenants = 0;
	int cur_size = 0;
	
 
 
	void init(int n, int q) {
		num_tenants = n;
		max_size = q;
		lrus.resize(n), base_lrus.resize(n);
		bad.assign(n, 1), base_bad.assign(n, 1);
		
		for (int i = 0; i < n; i++) {
			lrus[i].init(qmax[i]);
			base_lrus[i].init(qbase[i]);
		}
		total_bad = n;
		total_base_bad = n;
	}
 
	int put(int u, int p) {
		expected[u]++;
		int ret = lrus[u].get(p);
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
		if (lrus[u].size() == lrus[u].max_size) {
			ret = lrus[u].evict();
			cur_size--;
		} else if (cur_size == max_size) {
			vector<pair<long double, int> > v(num_tenants);
			int to_evict = -1;
			long double total_expected = 0;
			for (int i = 0; i < num_tenants; i++) total_expected += expected[i];
			
			for (int i = 0; i < num_tenants; i++) {	
				long double curbad = max((long double)1, bad[i] - base_bad[i]);
				if (old_bad.size() > max_size / 100.0) {
					old_bad.pop_back();
					old_base_bad.pop_back();
				}
				
				if (!old_bad.empty()) {
					long double curbad = max((long double)1, (bad[i] - old_bad.back()[i]) 
									- (base_bad[i] - old_base_bad.back()[i]));
 
				}
				v[i] = {expected[i] / total_expected * curbad * l[i], i};
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