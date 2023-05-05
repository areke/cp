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
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 27;
	vector<string> s(N);
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
	priority_queue<array<int, 3> > pq;
	pq.push({0, 0, 1});
	set<array<int, 3> > vis;

	queue<array<int, 3> > q;
	vector<int> types = {'<', '>', '^', 'v'};
	vector<pair<int, int> > dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
	for (int i = 1; i < s.size() - 1; i++) {
		for (int j = 1; j < s[i].length() - 1; j++) {
			if (s[i][j] == '<') {
				q.push({0, i - 1, j - 1});
			} else if (s[i][j] == '>') {
				q.push({1, i - 1, j - 1});
			} else if (s[i][j] == '^') {
				q.push({2, i - 1, j - 1});
			} else if (s[i][j] == 'v') {
				q.push({3, i - 1, j - 1});
			}
		}
	}
	int Y = s.size() - 2;
	int X = s[0].length() - 2;

	cout << "WAT" << endl;
	set<array<int, 3> > bad;
	for (int aa = 0; aa < 2000; aa++) {
		queue<array<int, 3> > next;
		while (!q.empty()) {
			array<int, 3> a = q.front();
			q.pop();
			bad.insert({-aa, a[1] + 1, a[2] + 1});
			pair<int, int> dir = dirs[a[0]];
			int nexti = (dir.first + a[1] + Y) % Y;
			int nextj = (dir.second + a[2] + X) % X;
			//cout << a[0] << " " << a[1] << " " << a[2] << " " << nexti << " " << nextj << endl;
			next.push({a[0], nexti, nextj});
		}
		q = next;

	}
	cout << "WAT" << endl;
	array<int, 3> start;
	
	while (!pq.empty()) {
		array<int, 3> a = pq.top();
		pq.pop();
		if (vis.find(a) != vis.end()) continue;
		if (bad.find(a) != bad.end()) continue;
		vis.insert(a);
		if (a[1] == Y + 1 && a[2] == X) {
			cout << a[1] << " " << a[2] << endl;
			cout << a[0] << endl;
			start = {a[0], a[1], a[2]};
			break;
		}
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (i != 0 && j != 0) continue;
				if (a[1] + i < 0 || a[1] + i >= s.size()) continue;
				if (a[2] + j < 0 || a[2] + j >= s[0].size()) continue;
				array<int, 3> next = {a[0] - 1, a[1] + i, a[2] + j};
				if (s[next[1]][next[2]] == '#') continue;
				pq.push(next);
			}
		}
	}
	pq = {};
	vis.clear();
	pq.push(start);
	while (!pq.empty()) {
		array<int, 3> a = pq.top();
		pq.pop();
		if (vis.find(a) != vis.end()) continue;
		if (bad.find(a) != bad.end()) continue;
		vis.insert(a);
		if (a[1] == 0 && a[2] == 1) {
			cout << a[1] << " " << a[2] << endl;
			cout << a[0] << endl;
			start = {a[0], a[1], a[2]};
			break;
		}
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (i != 0 && j != 0) continue;
				if (a[1] + i < 0 || a[1] + i >= s.size()) continue;
				if (a[2] + j < 0 || a[2] + j >= s[0].size()) continue;
				array<int, 3> next = {a[0] - 1, a[1] + i, a[2] + j};
				if (s[next[1]][next[2]] == '#') continue;
				pq.push(next);
			}
		}
	}
	pq = {};
	vis.clear();
	pq.push(start);
	while (!pq.empty()) {
		array<int, 3> a = pq.top();
		pq.pop();
		if (vis.find(a) != vis.end()) continue;
		if (bad.find(a) != bad.end()) continue;
		vis.insert(a);
		if (a[1] ==Y + 1 && a[2] == X) {
			cout << a[1] << " " << a[2] << endl;
			cout << a[0] << endl;
			start = {a[0], a[1], a[2]};
			break;
		}
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (i != 0 && j != 0) continue;
				if (a[1] + i < 0 || a[1] + i >= s.size()) continue;
				if (a[2] + j < 0 || a[2] + j >= s[0].size()) continue;
				array<int, 3> next = {a[0] - 1, a[1] + i, a[2] + j};
				if (s[next[1]][next[2]] == '#') continue;
				pq.push(next);
			}
		}
	}

	return 0;
}
