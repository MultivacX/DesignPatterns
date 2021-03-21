#ifndef _KMP_
#define _KMP_

vector<int> get_next(const string& p) {
	const int N = p.length();
	vector<int> next(N + 1, 0); // move right 1 step for convenience
	next[0] = -1;
	int i = 0; // suffix idx
	int j = -1; // prefix idx
	while (i < N) {
		if (j == -1 || p[i] == p[j]) next[++i] = ++j;
		else j = next[j]; // fallback
	}
	return next;
}

// WA: "aaa", "a"
int kmp(const string& s, const string& p) {
	const int M = s.length();
	const int N = p.length();
	if (N == 0) return -1;
	if (M < N) return -1;
	if (M == N) return s == p ? 0 : -1;

	auto next = get_next(p);
	int i = 0;
	int j = -1;
	while (i < M && j < N) {
		if (j == -1 || s[i] == p[j]) ++i, ++j;
		else j = next[j]; // fallback
	}
	if (j == N) return i - j;
	return -1;
}

#endif // _KMP_
