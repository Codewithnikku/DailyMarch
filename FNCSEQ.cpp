#include <iostream>
#include <vector>
using namespace std;

class Fancy {
public:
    const long long MOD = 1000000007;
    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    long long modInv(long long x) {
        long long res = 1, p = MOD - 2;
        while (p) {
            if (p & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            p >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long x = ((val - add) % MOD + MOD) % MOD;
        x = (x * modInv(mul)) % MOD;
        arr.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % MOD;
    }
};

int main() {
    Fancy fancy;
    fancy.append(2);
    fancy.addAll(3);
    fancy.multAll(2);
    cout << fancy.getIndex(0) << endl; // 6
    cout << fancy.getIndex(1) << endl; // 10
    cout << fancy.getIndex(2) << endl; // -1
    return 0;
}

/*
LeetCode 1622 Fancy Sequence
Intuition:
We can use a vector to store the sequence.
We can use a variable to store the current multiplicative identity.
We can use a variable to store the current additive identity.

Approach steps:
1. Initialize the vector to store the sequence.
2. Initialize the multiplicative identity to 1.
3. Initialize the additive identity to 0.
4. For each append operation, append the value to the vector.
5. For each addAll operation, add the value to the additive identity.
6. For each multAll operation, multiply the value to the multiplicative identity.
7. For each getIndex operation, check if the index is valid. If not, return -1. Otherwise, return the value at the index after applying the multiplicative identity and the additive identity.

Code Steps 

Decleration:
class Fancy {
public:
    const long long MOD = 1000000007;
    vector<long long> arr;
    long long mul = 1;
    long long add = 0;
};

step 1:
Fancy() {
    arr.clear();
    mul = 1;
    add = 0;
}

step 2:
void append(int val) {
    long long x = ((val - add) % MOD + MOD) % MOD;
    x = (x * this->modInv(mul)) % MOD;  
    arr.push_back(x);
}

step 3:
void addAll(int inc) {
    add = (add + inc) % MOD;
}

step 4:
void multAll(int m) {
    mul = (mul * m) % MOD;
    add = (add * m) % MOD;
}

step 5:
int getIndex(int idx) {
    if (idx >= arr.size()) return -1;
    return (arr[idx] * mul + add) % MOD;
}

Code Complexity:
Time Complexity: O(1) for each operation.
Space Complexity: O(n) where n is the number of elements in the sequence.
*/