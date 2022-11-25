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

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			long long a;
			cin >> a;
			res += a;
		}
		long long maxi = -1;
		for (int i = 0; i < n; i++) {
			long long b;
			cin >> b;
			res += b;
			maxi = max(b, maxi);
		}
		res -= maxi;
		cout <<res << endl;
	}
	return 0;
}
