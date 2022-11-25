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
		int p = n / 2;
		int p2 = n;
		if (n % 2 == 1) {
			cout << p + 1 << " ";
			for (int i = 0; i < n / 2; i++) {
				cout << p2 << " " << p << " ";
				p--;
				p2--;
			}
			cout << endl;
		} else {
			for (int i = 0; i < n / 2; i++) {
				cout << p << " " << p2 << " ";
				p--;
				p2--;
			}
			cout << endl;
		}
	}
	return 0;
}
