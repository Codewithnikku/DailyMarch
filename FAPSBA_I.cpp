#include <iostream>
#include <vector>
using namespace std;

class FindAllPossibleStableBinaryArraysI {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        long long MOD = 1000000007;
        int maxN = zero + one;
        
        std::vector<long long> fact(maxN + 1, 0);
        std::vector<long long> invFact(maxN + 1, 0);
        
        fact[0] = 1;
        invFact[0] = 1;
        for (int i = 1; i <= maxN; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        
        auto power = [&](long long baseVal, long long exp) {
            long long res = 1;
            baseVal %= MOD;
            while (exp > 0) {
                if (exp & 1) res = (res * baseVal) % MOD;
                baseVal = (baseVal * baseVal) % MOD;
                exp >>= 1;
            }
            return res;
        };
        
        invFact[maxN] = power(fact[maxN], MOD - 2);
        for (int i = maxN - 1; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
        
        auto C = [&](int n, int k) -> long long {
            if (k < 0 || k > n) return 0;
            return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
        };
        
        auto F = [&](int N, int K, int L) -> long long {
            if (K <= 0 || K > N) return 0;
            long long ans = 0;
            int maxJ = (N - K) / L;
            for (int j = 0; j <= maxJ; j++) {
                long long term = C(K, j) * C(N - j * L - 1, K - 1) % MOD;
                if (j & 1) {
                    ans = (ans - term + MOD) % MOD;
                } else {
                    ans = (ans + term) % MOD;
                }
            }
            return ans;
        };

        int maxK = std::min(zero, one + 1);
        std::vector<long long> fOne(maxK + 2, 0);
        for (int k = 1; k <= maxK + 1; k++) {
            fOne[k] = F(one, k, limit);
        }
        
        long long ans = 0;
        for (int k = 1; k <= maxK; k++) {
            long long fz = F(zero, k, limit);
            if (fz == 0) continue;
            long long fo = (fOne[k - 1] + 2 * fOne[k] + fOne[k + 1]) % MOD;
            ans = (ans + fz * fo) % MOD;
        }
        
        return static_cast<int>(ans);
    }
};

int main() {
    FindAllPossibleStableBinaryArraysI fapsba;
    int zero = 2, one = 2, limit = 2;
    cout << fapsba.numberOfStableArrays(zero, one, limit) << endl;
    return 0;
}

/*
# Find All Possible Stable Binary Arrays I

## Intuition
A **stable binary array** is a binary array that uses exactly `zero` zeros and `one` ones such that no more than `limit` identical elements appear consecutively. Instead of generating every possible array (which would be extremely slow), we observe that any binary array can be seen as **alternating groups of 0s and 1s**. Example:


So the array is composed of **groups**. If we decide there are `k` groups of zeros, then the number of groups of ones can only be:
- `k-1` (array starts and ends with 0)
- `k` (array starts with 0 and ends with 1 or vice-versa)
- `k+1` (array starts and ends with 1)

Now the problem becomes counting how many ways we can **distribute numbers into groups**. Each group must contain **at least 1 element** and **at most `limit` elements**. Counting such distributions is done using **combinatorics with inclusion–exclusion**.

---

## Approach
1. Let `MOD = 1e9 + 7`.
2. Precompute **factorials** (`fact`) and **inverse factorials** (`invFact`) up to `zero + one`. This allows fast computation of combinations.
3. Use **fast modular exponentiation** to compute modular inverses using Fermat’s theorem.
4. Implement combination function:
5. Create helper function `F(N, K, L)` which returns the number of ways to divide `N` elements into `K` groups where each group size is **≤ L**.
6. Use **inclusion–exclusion** to remove invalid cases where group size exceeds `limit`:
7. Precompute values for splitting `one` into groups:
8. Iterate possible number of zero groups:
9. For each `k`:
   - Compute ways to split zeros: `fz = F(zero, k, limit)`
   - Ones can have `k-1`, `k`, or `k+1` groups:
10. Add contribution:
11. Return answer modulo `MOD`.

---

## Complexity
Time Complexity:  O((zero + one) + min(zero, one) * ((N-K)/limit))
Space Complexity: O(zero + one)
---

## Code with Step-by-Step Explanation
```cpp
#include <iostream>
#include <vector>
using namespace std;

class FindAllPossibleStableBinaryArraysI {
public:
    int numberOfStableArrays(int zero, int one, int limit) {

        // Step 1: Define MOD and maximum size
        long long MOD = 1000000007;
        int maxN = zero + one;

        // Step 2: Precompute factorials and inverse factorials
        vector<long long> fact(maxN + 1, 0);
        vector<long long> invFact(maxN + 1, 0);

        fact[0] = 1;
        invFact[0] = 1;

        // factorial calculation
        for (int i = 1; i <= maxN; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        // Step 3: Fast exponentiation (binary exponentiation)
        auto power = [&](long long baseVal, long long exp) {
            long long res = 1;
            baseVal %= MOD;

            while (exp > 0) {
                if (exp & 1) res = (res * baseVal) % MOD;
                baseVal = (baseVal * baseVal) % MOD;
                exp >>= 1;
            }
            return res;
        };

        // Step 4: Compute inverse factorial using Fermat's theorem
        invFact[maxN] = power(fact[maxN], MOD - 2);

        for (int i = maxN - 1; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }

        // Step 5: Combination function
        auto C = [&](int n, int k) -> long long {
            if (k < 0 || k > n) return 0;
            return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
        };

        // Step 6: Function to count ways to split N items into K groups
        // each group size <= limit using inclusion-exclusion
        auto F = [&](int N, int K, int L) -> long long {

            if (K <= 0 || K > N) return 0;

            long long ans = 0;

            int maxJ = (N - K) / L;

            for (int j = 0; j <= maxJ; j++) {

                long long term =
                    C(K, j) * C(N - j * L - 1, K - 1) % MOD;

                if (j & 1)
                    ans = (ans - term + MOD) % MOD;
                else
                    ans = (ans + term) % MOD;
            }

            return ans;
        };

        // Step 7: Precompute ways for ones
        int maxK = min(zero, one + 1);

        vector<long long> fOne(maxK + 2, 0);

        for (int k = 1; k <= maxK + 1; k++) {
            fOne[k] = F(one, k, limit);
        }

        // Step 8: Try different numbers of zero groups
        long long ans = 0;

        for (int k = 1; k <= maxK; k++) {

            // ways to divide zeros
            long long fz = F(zero, k, limit);

            if (fz == 0) continue;

            // ones groups can be k-1, k, or k+1
            long long fo =
                (fOne[k - 1] + 2 * fOne[k] + fOne[k + 1]) % MOD;

            ans = (ans + fz * fo) % MOD;
        }

        return (int)ans;
    }
};

int main() {

    FindAllPossibleStableBinaryArraysI obj;

    int zero = 2, one = 2, limit = 2;

    cout << obj.numberOfStableArrays(zero, one, limit) << endl;

    return 0;
}
*/