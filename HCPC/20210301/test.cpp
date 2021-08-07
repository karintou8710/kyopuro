#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>
using namespace std;

long long calc(long long a, long long n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n % 2 == 1) return (a * calc(a, n - 1));
    long long t = calc(a, n / 2);

    if (t > 1E9 / t) return -1;

    return t * t;
}

int main(void) {
    int A, R, N;
    cin >> A >> R >> N;

    long long res = calc(R, N - 1);

    if (res < 0) {
        cout << "large" << endl;
        return 0;
    }

    if (res > 1E9 / A) {
        cout << "large" << endl;
        return 0;
    }

    cout << A * res << endl;

    return 0;
}