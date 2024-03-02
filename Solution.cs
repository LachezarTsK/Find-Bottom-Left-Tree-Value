
using System;
using System.Collections.Generic;

public class Solution
{
    public int FindBottomLeftValue(TreeNode root)
    {
        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);

        int bottomLeftValue = root.val;

        while (queue.Count > 0)
        {
            TreeNode node = queue.Dequeue();
            bottomLeftValue = node.val;

            // 'currentNode.right' must come before 'currentNode.left'
            if (node.right != null)
            {
                queue.Enqueue(node.right);
            }
            if (node.left != null)
            {
                queue.Enqueue(node.left);
            }
        }
        return bottomLeftValue;
    }
}

/*
Class TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
