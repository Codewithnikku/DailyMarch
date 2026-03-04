#include <iostream>
#include <vector>
using namespace std;

class SpecialPositionsInBinaryMatrix {
public:
  int numSpecial(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int specialPositions = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == 1) {
          int rowSum = 0, colSum = 0;
          for (int k = 0; k < n; k++) {
            rowSum += mat[k][j];
          }
          for (int k = 0; k < m; k++) {
            colSum += mat[i][k];
          }
          if (rowSum == 1 && colSum == 1) {
            specialPositions++;
          }
        }
      }
    }
    return specialPositions;
  }
};

int main() {
  SpecialPositionsInBinaryMatrix spibm;
  vector<vector<int>> mat = {{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
  cout << spibm.numSpecial(mat) << endl;
  return 0;
}

/*
Leetcode: 1582. Special Positions in a Binary Matrix
Given:
A binary matrix mat of size m x n, where each row represents a row of seats in a
theater. A seat is represented by a 1, and an empty seat is represented by a 0.
A special position is defined as a seat that is the only 1 in its row and
column.

Return the number of special positions in mat.

Intuition:
We need to find the number of special positions in the matrix.
A special position is defined as a seat that is the only 1 in its row and
column. We can iterate over each seat in the matrix and check if it is a special
position. If it is, we increment the count of special positions. At the end, we
return the count of special positions.

Approach Steps:
1. Initialize n = mat.length, m = mat[0].length.
2. Initialize specialPositions = 0.
3. Iterate over the rows i.
4. For each row i, iterate over the columns j.
5. If mat[i][j] == 1, check if it is a special position.
6. If it is, increment specialPositions.
7. Return specialPositions.

Complexity:
Time Complexity: O(n^2)
Space Complexity: O(1)

Code Steps:
step1: int n = mat.size();
        int m = mat[0].size();
        int specialPositions = 0;
-> Declare Variables rowSum, colSum.

step2: Iterate over the rows i.
        For each row i, iterate over the columns j.
        step3:
        If mat[i][j] == 1, check if it is a special position.
        If it is, increment specialPositions.
        If it is not, continue to the next seat.
step4:
        After iterating over all seats, return specialPositions.
*/