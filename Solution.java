
import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        int bottomLeftValue = root.val;

        while (!queue.isEmpty()) {

            TreeNode currentNode = queue.poll();
            bottomLeftValue = currentNode.val;

            // 'currentNode.right' must come before 'currentNode.left'
            if (currentNode.right != null) {
                queue.add(currentNode.right);
            }
            if (currentNode.left != null) {
                queue.add(currentNode.left);
            }
        }
        return bottomLeftValue;
    }
}

/*
Class TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
