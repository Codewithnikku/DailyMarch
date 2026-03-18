#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class DistributeCandies{
    public int distCandy(Node root) {
        // code here
        //using optimal approach
        int res = 0;
        if (root == null) return res;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node curr = q.poll();
                if (curr.left != null) q.add(curr.left);
                if (curr.right != null) q.add(curr.right);
            }
            res++;
        }
        return res;
    }
};

int distributeCandies(Node root) {
    DistributeCandies dc = new DistributeCandies();
    return dc.distCandy(root);
}