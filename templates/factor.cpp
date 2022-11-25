

bool isPrime(long long x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) return false;
	}
	return true;
}

//returns list of prime factors with their counts
vector<pair<long long, long long> > factor(long long a) {
	vector<pair<long long, long long> > res;
	for (int j = 2; j <= sqrt(a); j++) {
		if (!isPrime(j)) continue;
		int cnt = 0;
		while (a % j == 0) {
			cnt ++;
			a /= j;
		}
		if (cnt) {
			res.push_back({j, cnt});
		}
	}
	if (a != 1) {
		res.push_back({a, 1});
	}
	return res;
}