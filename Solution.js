
/**
 * @param {TreeNode} root
 * @return {number}
 */
var findBottomLeftValue = function (root) {

    //const {Queue} = require('@datastructures-js/queue');
    const queue = new Queue();
    queue.enqueue(root);

    let bottomLeftValue = root.val;

    while (!queue.isEmpty()) {

        const currentNode = queue.dequeue();
        bottomLeftValue = currentNode.val;

        // 'currentNode.right' must come before 'currentNode.left'
        if (currentNode.right !== null) {
            queue.enqueue(currentNode.right);
        }
        if (currentNode.left !== null) {
            queue.enqueue(currentNode.left);
        }
    }
    return bottomLeftValue;
};

/*
 Function TreeNode is in-built in the solution file on leetcode.com. 
 When running the code on the website, do not include this function.
 */
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}
