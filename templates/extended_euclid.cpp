// ax + by = gcd(a, b)

vector<long long> extend_euclid(long long a, long long b) {
	// we know that (1 * a) + (0 * b) = a and (0 * a) + (1 * b) = b
	vector<long long> x = {1, 0, a};
	vector<long long> y = {0, 1, b};

	// run extended Euclidean algo
	while (y[2] > 0) {
		// keep subtracting multiple of one equation from the other
		long long k = x[2] / y[2];
		for (int i = 0; i < 3; i++) {
			x[i] -= k * y[i];
		}
		swap(x, y);
	}
	return x;  // x[0] * a + x[1] * b = x[2], x[2] = gcd(a, b)
}