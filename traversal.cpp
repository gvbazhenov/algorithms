struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data): value(data), left(nullptr), right(nullptr) {}
};

void visitNode(TreeNode* node) {
    std::cout << node->value << std::endl;
}

void recursivePreOrder(TreeNode* root) {
    if (root != nullptr) {
        visitNode(root);
        recursiveInOrder(root->left);
        recursiveInOrder(root->right);
    }
}

void recursiveInOrder(TreeNode* root) {
    if (root != nullptr) {
        recursiveInOrder(root->left);
        visitNode(root);
        recursiveInOrder(root->right);
    }
}

void recursivePostOrder(TreeNode* root) {
    if (root != nullptr) {
        recursiveInOrder(root->left);
        recursiveInOrder(root->right);
        visitNode(root);
    }
}

void iterativePreOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    std::stack<TreeNode*> traversalStack;
    stack.push(root);
    TreeNode* currentNode = nullptr;
    
    while (!traversalStack.empty()) {
        currentNode = traversalStack.top();
        traversalStack.pop();
        visit(currentNode);
        if (currentNode->right != nullptr)
            traversalStack.push(currentNode->right);
        if (currentNode->left != nullptr)
            traversalStack.push(currentNode->left);
    }
}

void iterativeInOrder(TreeNode* root) {
    std::stack<TreeNode*> traversalStack;
    TreeNode* currentNode = root;
    
    while (!traversalStack.epmty() or currentNode != nullptr) {
        if (currentNode != nullptr) {
            traversalStack.push(currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = traversalStack.top();
            traversalStack.pop();
            visit(currentNode);
            currentNode = currentNode->right;
        }
    }
}

void iterativePostOrder(TreeNode* root) {
    std::stack<TreeNode*> traversalStack;
    TreeNode* currentNode = root;
    TreeNode* topNode = nullptr;
    TreeNode* lastVisitedNode = nullptr;
    
    while (!traversalStack.epmty() or currentNode != nullptr)
        if (currentNode != nullptr) {
            traversalStack.push(currentNode);
            currentNode = currentNode->left;
        } else {
            topNode = traversalStack.top();
            if (topNode->right != nullptr and lastVisitedNode != topNode->right)
                currentNode = topNode->right;
            else {
                visit(topNode);
                lastVisitedNode = topNode;
                stack.pop();
            }
        }
}

