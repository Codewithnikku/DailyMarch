#include <iostream>
#include <vector>
using namespace std;

class DiceThrow{
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= x; j++) {
                for(int k = 1; k <= m; k++) {
                    if(j - k >= 0) {
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
            }
        }
        return dp[n][x];
    }
};

int main(){
    DiceThrow diceThrow;
    int m = 6, n = 3, x = 12;
    cout << diceThrow.noOfWays(m, n, x) << endl;
    return 0;
}

/*
# GFG – Dice Throw (Dynamic Programming)

## Problem

Given:

- `m` = number of faces on a dice  
- `n` = number of dice thrown  
- `x` = required sum  

Find the **number of ways to get sum `x`** when **rolling the dice `n` times**.

Each dice has values from:

```
1 → m
```

---

## Example

Input

```
m = 6
n = 3
x = 12
```

Output

```
25
```

Meaning there are **25 possible ways** to get sum `12` using **3 dice with 6 faces**.

---

# Intuition

If we roll a dice `n` times and want sum `x`, we can think:

```
dp[i][j] = number of ways to get sum j using i dice
```

When we roll the **i-th dice**, it can give values:

```
1, 2, 3 ... m
```

So the transition becomes:

```
dp[i][j] += dp[i-1][j-k]
```

Where:

```
k = dice face value
```

This means:

If the last dice shows `k`, then the remaining `i-1` dice must produce sum `j-k`.

---

# Dynamic Programming Table

```
dp[i][j]
```

Where:

| Variable | Meaning |
|--------|--------|
| `i` | number of dice used |
| `j` | target sum |

---

# Base Case

If **0 dice are thrown**, only sum `0` is possible.

```
dp[0][0] = 1
```

---

# DP Transition

For each dice:

```
for i from 1 → n
    for j from 1 → x
        for k from 1 → m
            if j - k >= 0
                dp[i][j] += dp[i-1][j-k]
```

---

# Algorithm Steps

### Step 1
Create a DP table:

```
dp[n+1][x+1]
```

Initialize with `0`.

---

### Step 2
Set base case

```
dp[0][0] = 1
```

---

### Step 3
Iterate through dice count

```
for i = 1 → n
```

---

### Step 4
Iterate through possible sums

```
for j = 1 → x
```

---

### Step 5
Try all dice faces

```
for k = 1 → m
```

If valid:

```
dp[i][j] += dp[i-1][j-k]
```

---

### Step 6
Return final answer

```
dp[n][x]
```

---

# C++ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

class DiceThrow{
public:
    int noOfWays(int m, int n, int x) {

        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

        dp[0][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= x; j++) {

                for(int k = 1; k <= m; k++) {

                    if(j - k >= 0) {
                        dp[i][j] += dp[i - 1][j - k];
                    }

                }
            }
        }

        return dp[n][x];
    }
};

int main(){

    DiceThrow diceThrow;

    int m = 6;
    int n = 3;
    int x = 12;

    cout << diceThrow.noOfWays(m, n, x) << endl;

    return 0;
}
```

---

# Example Walkthrough

Input

```
m = 6
n = 3
x = 12
```

Dice values range from:

```
1 → 6
```

Possible combinations include:

```
(6,5,1)
(6,4,2)
(5,5,2)
(4,4,4)
...
```

Total ways:

```
25
```

---

# Complexity Analysis

### Time Complexity

```
O(n * x * m)
```

Where:

- `n` = number of dice
- `x` = target sum
- `m` = number of faces

---

### Space Complexity

```
O(n * x)
```

Used for the DP table.

---

# Key Concepts Used

- Dynamic Programming
- 2D DP Table
- State Transition
- Combinatorics with Dice

---

# Summary

✔ Use **DP table `dp[i][j]`** to store ways  
✔ Build answer using **previous dice results**  
✔ Try all possible **dice face values**  
✔ Final answer stored in:

```
dp[n][x]
```

This provides an efficient **Dynamic Programming solution** for the Dice Throw problem.
*/