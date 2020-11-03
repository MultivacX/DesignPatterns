// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc

#include <algorithm>
#include <iostream>
#include <array>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

array<int64_t, 2> decode(const string& program) {
    static const int64_t M = 1000000000;
    static unordered_map<char, array<int64_t, 2>> D{
        {'N', {0, -1}}, {'S', {0, 1}},
        {'W', {-1, 0}}, {'E', {1, 0}},
    };
    
    int64_t x = 0;
    int64_t y = 0;

    stack<int> times;
    stack<array<int64_t, 2>> xy;

    auto update = [&](int64_t moveX, int64_t moveY){
        if (times.empty()) {
            x = (x + moveX + M) % M;
            y = (y + moveY + M) % M;
        } else {
            xy.top()[0] = (xy.top()[0] + moveX + M) % M;
            xy.top()[1] = (xy.top()[1] + moveY + M) % M;
        }
    };

    for (char c : program) {
        if (D.count(c)) {
            update(D[c][0], D[c][1]);
        } else if ('2' <= c && c <= '9') {
            times.push(c - '0');
            xy.push({0, 0});
        } else if (c == ')') {
            int64_t t = times.top(); times.pop();
            auto xy_ = xy.top(); xy.pop();
            update(t * xy_[0], t * xy_[1]);
        }
    }

    return {x + 1, y + 1};
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        string program;
        cin >> program;

        auto xy = decode(program);
        
        cout << "Case #" << i << ": " << xy[0] << " " << xy[1] << endl;
    }
    return 0;
}