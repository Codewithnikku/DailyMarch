class MoveAllZerosToEnd {
    void pushZerosToEnd(int[] arr) {
        // code here
        int n = arr.length;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j++;
            }
        }
    }
}

public class MAZTE {
    public static void main(String[] args) {
        int[] arr = {1, 2, 0, 4, 3, 0, 5, 0};
        MoveAllZerosToEnd obj = new MoveAllZerosToEnd();
        obj.pushZerosToEnd(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }   
    }
}


/*
Greeks For Greeks: Move all zeros to end of array
    Approach:
    1. Initialize j = 0.
    2. Iterate over the array.
    3. For each element arr[i], if arr[i] != 0, then swap arr[i] with arr[j] and increment j.
    4. After the loop, all the zeros will be at the end of the array.

    Optimal Approach:
    1. Initialize j = 0.
    2. Iterate over the array.
    3. For each element arr[i], if arr[i] != 0, then swap arr[i] with arr[j] and increment j.
    4. After the loop, all the zeros will be at the end of the array.

    pseudo code:
    1. Initialize j = 0.
    2. Iterate over the array.
    3. For each element arr[i], if arr[i] != 0, then swap arr[i] with arr[j] and increment j.
    4. After the loop, all the zeros will be at the end of the array.

    void pushZerosToEnd(int[] arr) {
        // code here
        int n = arr.length;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j++;
            }
        }
    }

    Time Complexity: O(n)
    Space Complexity: O(1)
 */