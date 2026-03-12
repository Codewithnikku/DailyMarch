# Maximize Spanning Tree Stability with Upgrades

## Problem Overview

We are given:

- `n` nodes representing a graph.
- `edges` where each edge contains:
  - `u` → start node
  - `v` → end node
  - `w` → stability (weight)
  - `type`
    - `1` → **must-use edge**
    - `0` → **flexible edge**
- `k` → number of edges we can **upgrade**.

### Goal

Construct a **spanning tree** while **maximizing the minimum stability** in the tree.

Rules:
- **Must edges must always be included**
- **Flexible edges may be chosen**
- We can **upgrade up to `k` flexible edges**
- Upgrading changes weight from:

```
w → 2 * w
```

If it is **impossible to connect all nodes**, return **-1**.

---

# Intuition

This problem is related to a **Maximum Spanning Tree (MST)** but with additional constraints.

Important ideas:

### 1. Must edges
Must edges **must always be part of the tree**.

If two nodes connected by a must edge are **already connected**, it creates a **cycle**, which means building a valid spanning tree is impossible.

---

### 2. Flexible edges

Flexible edges help us **connect remaining components**.

To maximize stability, we should pick **edges with higher weights first**.

So we sort flexible edges in **descending order of weight**.

---

### 3. Edge upgrades

We can upgrade **k flexible edges**.

Upgrading changes:

```
w → 2w
```

To maximize the **minimum stability of the tree**, we upgrade edges with **small weights first**.

We use a **min heap** to track flexible edges used in the spanning tree.

---

# Tree Structure Example

Example graph:

```
Nodes: 0 1 2 3
```

Edges:

```
Must edge:
0 ---5--- 1

Flexible edges:
1 ---4--- 2
2 ---3--- 3
0 ---2--- 3
```

### Step 1 — Add must edges

```
0 ---5--- 1
```

Components:

```
{0,1}  {2}  {3}
```

---

### Step 2 — Add flexible edges (highest weight first)

```
1 ---4--- 2
```

Components:

```
{0,1,2}  {3}
```

Next:

```
2 ---3--- 3
```

Final spanning tree:

```
0 ---5--- 1
      |
      4
      |
      2 ---3--- 3
```

Minimum stability:

```
min(5,4,3) = 3
```

---

### Step 3 — Upgrade edges

If we upgrade edge `3`:

```
3 → 6
```

Now stability values:

```
5, 4, 6
```

Minimum stability becomes:

```
min(5,4,6) = 4
```

---

# Algorithm Steps

## Step 1 — Initialize DSU

We maintain:

```
parent[]
size[]
components
```

DSU helps with:
- Detecting cycles
- Merging components efficiently

---

## Step 2 — Separate edges

Split edges into:

```
must edges
flexible edges
```

This helps process them differently.

---

## Step 3 — Process must edges

For each must edge:

1. Try to union nodes
2. If union fails → cycle detected
3. Return `-1`

Also track the **minimum stability** among must edges.

---

## Step 4 — Sort flexible edges

Sort flexible edges by weight:

```
descending order
```

This helps build a **maximum spanning tree**.

---

## Step 5 — Build spanning tree

For each flexible edge:

- If union succeeds:
  - Add it to the tree
  - Push weight into **min heap**

This keeps track of **used flexible edges**.

---

## Step 6 — Apply upgrades

Upgrade up to `k` edges.

Process:

```
while k > 0
    take smallest flexible edge
    double its weight
    update minimum stability
```

---

## Step 7 — Check connectivity

If all nodes are not connected:

```
components != 1
```

Return:

```
-1
```

---

# Code Implementation (C++)

```cpp
class Solution {
public:
    int components;
    vector<int> parent, size;

    int Union(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return 0;

        components--;

        if(size[pu] > size[pv]){
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else{
            size[pv] += size[pu];
            parent[pu] = pv;
        }

        return 1;
    }

    int findParent(int node){
        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        components = n;

        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++)
            parent[i]=i;

        vector<vector<int>> must, flex;

        for(auto &it:edges){
            if(it[3]==1)
                must.push_back(it);
            else
                flex.push_back(it);
        }

        int mini = INT_MAX;

        for(auto &it:must){

            int u=it[0];
            int v=it[1];
            int w=it[2];

            mini = min(mini,w);

            if(!Union(u,v))
                return -1;
        }

        sort(flex.begin(),flex.end(),
        [](vector<int>&a,vector<int>&b){
            return a[2] > b[2];
        });

        priority_queue<int,vector<int>,greater<int>> pq;

        for(auto &it:flex){

            int u=it[0];
            int v=it[1];
            int w=it[2];

            if(Union(u,v)){
                pq.push(w);
            }
        }

        while(k-- && !pq.empty()){

            int x = pq.top();
            pq.pop();

            mini = min(mini,2*x);
        }

        if(components!=1)
            return -1;

        if(!pq.empty())
            return min(mini,pq.top());

        return mini;
    }
};
```

---

# Complexity Analysis

### Time Complexity

DSU operations:

```
O(α(n))
```

Sorting flexible edges:

```
O(E log E)
```

Union operations:

```
O(E α(n))
```

Priority queue operations:

```
O(E log E)
```

Final complexity:

```
O(E log E)
```

---

### Space Complexity

Data structures used:

```
parent array → O(n)
size array → O(n)
priority queue → O(E)
```

Total:

```
O(n + E)
```

---

# Key Concepts Used

- **Disjoint Set Union (Union-Find)**
- **Maximum Spanning Tree**
- **Greedy Algorithm**
- **Priority Queue (Min Heap)**
- **Graph Connectivity**

---

# Summary

Steps followed:

1. Initialize DSU
2. Add must edges
3. Sort flexible edges
4. Build maximum spanning tree
5. Track flexible edges
6. Upgrade up to `k` edges
7. Return maximum possible minimum stability

If full connectivity is impossible → return **-1**.

---