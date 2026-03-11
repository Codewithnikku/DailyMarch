class ComplementOfBaseTenInteger{
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int mask = 1;
        while(mask < n) mask = (mask << 1) | 1;
        return mask ^ n;
    }
};

/*
# Complement of Base 10 Integer

## Problem
Given an integer `n`, return the **bitwise complement** of its binary representation.

The complement flips every bit:
- `0 → 1`
- `1 → 0`

Example:

Input  
n = 5  

Binary representation:
5 = 101

Complement:
010 = 2

Output:
2

---

# Intuition

The complement means **flipping all bits**, but only within the **significant bits of the number**.

Example:

5 = 101

We only flip **3 bits**, not all 32 bits.

101
↓
010

To do this:

1. Create a **mask** containing all `1`s with the same number of bits as `n`.
2. XOR (`^`) the mask with `n`.

Example:

n    = 101  
mask = 111  
--------------  
ans  = 010  

---

# Approach

Steps:

1. Handle special case:
   - If `n = 0`, return `1`.

2. Create a **mask** with all bits set to `1` up to the highest bit of `n`.

Example:

n = 5 = 101

mask generation:
1  
11  
111  

3. Use **XOR** to flip the bits.

mask ^ n

---

# Code

```cpp
class ComplementOfBaseTenInteger{
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int mask = 1;

        while(mask < n)
            mask = (mask << 1) | 1;

        return mask ^ n;
    }
};
```

---

# Line by Line Explanation

### Class Definition
```cpp
class ComplementOfBaseTenInteger{
```
Creates a class to group the solution method.

---

### Function Definition
```cpp
int bitwiseComplement(int n)
```
Function that takes integer `n` and returns its bitwise complement.

---

### Edge Case
```cpp
if(n == 0) return 1;
```

Binary of `0` is:
0

Complement is:
1

So return `1`.

---

### Initialize Mask
```cpp
int mask = 1;
```

Start with mask:
1

This will grow to match the bit length of `n`.

---

### Create All-1 Mask
```cpp
while(mask < n)
    mask = (mask << 1) | 1;
```

Operations used:

**Left Shift `<<`**

```
mask << 1
```

Moves bits left and adds `0`.

Example:

1 → 10

**Bitwise OR `|`**

```
| 1
```

Adds `1` to the last bit.

Example progression:

mask = 1  → 001  
mask = 3  → 011  
mask = 7  → 111  

Loop stops when mask ≥ n.

---

### Compute Complement
```cpp
return mask ^ n;
```

`^` is **XOR operator**.

XOR rule:

| A | B | A^B |
|---|---|----|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|0|

Example:

n    = 101  
mask = 111  
--------------  
ans  = 010  

Result = `2`.

---

# Example Walkthrough

Input:
n = 5

Binary:
101

Mask creation:
1  
11  
111  

XOR:

111  
101  
----  
010  

Output:
2

---

# Time Complexity
O(log n)

Because mask generation depends on the **number of bits in n**.

---

# Space Complexity
O(1)

Only a few variables are used.
*/