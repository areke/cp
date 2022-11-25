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
#include <list>
#include <cstring>
using namespace std;

vector<long long> extendEuclid(long long a, long long b) {
	vector<long long> x = {1,0,a}, y = {0,1,b};
	// we know that 1*a+0*b=a and 0*a+1*b=b
	for (;y[2];swap(x,y)) { // run extended Euclidean algo
		long long k = x[2]/y[2];
		for (int i = 0; i < 3; i++) x[i] -= k*y[i];
		// keep subtracting multiple of one equation from the other
	}
	return x; // x[0]*a+x[1]*b=x[2], x[2]=gcd(a,b)
}

int main() {
	int tests;
	cin >> tests;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> v;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			long long r, b;
			cin >> r >> b;
			res += b;
			v[i] = r - b;
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int maxind = -1;
		for (int i = 0; i < n; i++) {
			if (v[i] < 0) break;
			maxind = i;
		}
		vector<long long> p(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			p[i] = p[i - 1] + v[i - 1];
		}
		int m;
		cin >> m;
		vector<long long> results(m);
		for (int i = 0; i < m; i++) {
			long long x, y;
			cin >> x >> y;
			vector<long long> eg = extendEuclid(x, y);
			long long gcd = eg[2];


			// 
			// a* x + b *y = gcd(x, y)
			// g = gcd(x, y)
			// eg[0] - (y / eg[2]) * r
			// eg[1] - (x / eg[2]) * r
			if (n % eg[2] != 0) results[i] = -1;
			else {

			}
			// a*x + b*y = n;


		}
	}
	return 0;
}
