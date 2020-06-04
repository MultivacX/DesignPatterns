#ifndef _MANACHER_
#define _MANACHER_

string manacher(string s) {
    const int N = s.length();
    if (N <= 1) return s;

    vector<char> arr(2 * N + 1, '\0');
    for (int i = 0; i < N; ++i)
        arr[2 * i + 1] = s[i];
    vector<int> len(2 * N + 1, 0);

    // max-len palindrome
    // \0, arr[1], \0
    int center_max = 1;
    len[center_max] = 1;
    // right-most palindrome
    int center = 1;
    len[center] = 1;
    for (int i = 2; i < 2 * N + 1 - len[center_max]; ++i) {
        // mirror
        // __ j ... center ... i __
        int j = center - (i - center);
        if (j >= 0) len[i] = min(len[j], len[center] - (i - center));

        int l = i - len[i] - 1;
        int r = i + len[i] + 1;
        while (l >= 0 && r <= 2 * N && arr[l] == arr[r]) {
            ++len[i];
            l = i - len[i] - 1;
            r = i + len[i] + 1;
        }

        if (i + len[i] > center + len[center])
            center = i;

        if (len[i] > len[center_max]) 
            center_max = i;
    }

    string ans;
    for (int i = center_max - len[center_max]; i <= center_max + len[center_max]; ++i)
        if (arr[i] != '\0') ans += arr[i];
    return ans;
}

map<int, set<string>> palindromes(string s) {
    map<int, set<string>> ans;
    for (int i = 0; i < s.length(); ++i) {
        int l = i;
        int r = i;
        while (l - 1 >= 0 && r + 1 < s.length() && s[l - 1] == s[r + 1]) {
            --l;
            ++r;
        }
        ans[r - l + 1].insert(s.substr(l, r - l + 1));

        l = i;
        r = i + 1;
        if (r == s.length() || s[l] != s[r]) continue;
        while (l - 1 >= 0 && r + 1 < s.length() && s[l - 1] == s[r + 1]) {
            --l;
            ++r;
        }
        ans[r - l + 1].insert(s.substr(l, r - l + 1));
    }
    return ans;
}

#endif // _MANACHER_