#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm kiểm tra xem một số có phải là số nguyên tố hay không
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Hàm kiểm tra xem một số có phải là số siêu nguyên tố hay không
bool isSuperPrime(int num) {
    while (num > 0) {
        if (!isPrime(num)) {
            return false;
        }
        num /= 10;
    }
    return true;
}

// Hàm tìm các số siêu nguyên tố nhỏ hơn hoặc bằng n
vector<int> superPrimeNumber(int n) {
    vector<int> result;
    for (int i = 2; i <= n; ++i) {
        if (isSuperPrime(i)) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    int n;

    cout << "Nhap so n: ";
    cin >> n;

    vector<int> superPrimes = superPrimeNumber(n);

    cout << "Cac so sieu nguyen to nho hon hoac bang " << n << " la: ";
    for (int i = 0; i < superPrimes.size(); ++i) {
        cout << superPrimes[i] << " ";
    }

    return 0;
}