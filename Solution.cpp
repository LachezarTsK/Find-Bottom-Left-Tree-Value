
#include <queue>
using namespace std;

/*
Struct TreeNode is in-built in the solution file on leetcode.com.
When running the code on the website, do not include this struct.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {

public:
    int findBottomLeftValue(TreeNode* root) const {
        queue<TreeNode*> queue;
        queue.push(root);

        int bottomLeftValue = root->val;

        while (!queue.empty()) {

            TreeNode* currentNode = queue.front();
            queue.pop();

            bottomLeftValue = currentNode->val;

            // 'currentNode->right' must come before 'currentNode->left'
            if (currentNode->right != nullptr) {
                queue.push(currentNode->right);
            }
            if (currentNode->left != nullptr) {
                queue.push(currentNode->left);
            }
        }
        return bottomLeftValue;
    }
};
