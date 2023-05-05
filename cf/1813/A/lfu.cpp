
struct multiLFU : multiCache {
	map<pair<int, int>, pair<int, int> > last_accessed_time;

	void init(int n, int q, int m) {
		multiCache::init(n, q, m);
		for (int i = 0; i < n; i++) {
			lrus[i] = new LFUCache();
			base_lrus[i] = new LFUCache();
			shadow_queues[i] = new LFUCache();
		}
		for (int i = 0; i < n; i++) {
			lrus[i]->init(target_sizes[i]);
			base_lrus[i]->init(qbase[i]);
			shadow_queues[i]->init(min(qmax[i], target_sizes[i] + shadow_size_delta));
		}
	}

	int put(int u, int p) {
		timestamp++;

		int ret = lrus[u]->get(p);
		bool in_shadow_queue = true;

		if (shadow_queues[u]->get(p) == -1) {
			in_shadow_queue = false;
			shadow_queues[u]->max_size = min(qmax[u], lrus[u]->cur_size + shadow_size_delta);
			while (shadow_queues[u]->cur_size && shadow_queues[u]->cur_size >= shadow_queues[u]->max_size) shadow_queues[u]->evict();
			shadow_queues[u]->put(p, p);
		}
		bool in_target_queue = ret != -1;
		
		if (!in_target_queue) {
			bad[u]++;
			total_bad++;
		}
		if (base_lrus[u]->get(p) == -1) {
			if (base_lrus[u]->cur_size == base_lrus[u]->max_size) base_lrus[u]->evict();
			base_lrus[u]->put(p, p);
			total_base_bad++;
			base_bad[u]++;


			
		} else {
			
		}
		if (in_shadow_queue && !in_target_queue) {
			long double cs = max((long double) 0, ((bad[u] - 1) / base_bad[u]) - 1);
			cs *= cs;
			long double c = max((long double) 0, (bad[u] / base_bad[u]) - 1);
			c *= c;
			long double dcdt = (cs - c) * l[u];
			// (2x-2c-1)/c^2 
			long double scale = (base_bad[u] * base_bad[u]);
			resize_targets(u, min(max((long double)-10.0, -dcdt * scale), (long double)10.0));
		}
		if (ret != -1) {
			old_base_bad.push_back(base_bad);
			old_bad.push_back(bad);
			return ret;
		}
		ret = cur_size;
		if (lrus[u]->cur_size == target_sizes[u]) {
			ret = lrus[u]->evict();
			cur_size--;
		} else if (cur_size == max_size) {
			vector<pair<long double, int> > v(num_tenants);
			int to_evict = -1;
			for (int i = 0; i < num_tenants; i++) {
				v[i] = {target_sizes[i] - lrus[i]->cur_size, i};
			}
			sort(v.begin(), v.end());
			for (int i = 0; i < num_tenants; i++) {
				if (lrus[u]->cur_size < qmax[u] && lrus[v[i].second]->cur_size > qmin[v[i].second]) {
					to_evict = v[i].second;
					break;
				} 
			}
			assert(to_evict != -1);
			ret = lrus[to_evict]->evict();
			cur_size--;
		}
		assert(cur_size < max_size);
		lrus[u]->put(p, ret);
		cur_size++;
		old_base_bad.push_back(base_bad);
		old_bad.push_back(bad);
		return ret;
	}

	long double cost() {
		return 0;
	}
};