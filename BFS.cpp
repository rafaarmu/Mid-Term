#include <iostream>
#include <queue>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void bfs(TreeNode* root) {
    std::queue<TreeNode*> m_queue;
    m_queue.push(root);

    TreeNode* cur;
    while (!m_queue.empty()) {
        cur = m_queue.front();
        m_queue.pop();

        // Do some kind of search/checking or operation
        std::cout << "Visiting: " << cur->data << std::endl;

        if (cur->left)
            m_queue.push(cur->left);
        if (cur->right)
            m_queue.push(cur->right);
    }
}

int main() {
    // Create a simple binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "BFS traversal of the tree: ";
    bfs(root);

    // Don't forget to free the allocated memory in a complete program
    // (This is just a simple example, so memory cleanup is omitted here)

    return 0;
}