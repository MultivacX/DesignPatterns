#ifndef _INTEGER_FACTORIZATION_
#define _INTEGER_FACTORIZATION_

// https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm

void pollards_rho(int n) {
    cout << n << "=";
    for (int i = 2; i * i <= n; ++i) {
        while (i != n) {
            if (n % i == 0) {
                cout << i << "*";
                n /= i;
            } else break;
        }
    }
    if (n != 1) cout << n << endl;
    cout << endl;
}

#endif // !_INTEGER_FACTORIZATION_