struct AVLTreeNode {
    int height;
    int value;
    AVLTreeNode* left;
    AVLTreeNode* right;
    AVLTreeNode(int data): height(1), value(data), left(nullptr), right(nullptr) {}
};

int getHeight(AVLTreeNode* node) {
    if (node == nullptr)
        return 0;
    else
        return node->height;
}

void restoreHeight(AVLTreeNode* node) {
    if (node != nullptr)
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

int balanceFactor(AVLTreeNode* node) {
    return getHeight(node->right) - getHeight(node->left);
}

AVLTreeNode* rotateRight(AVLTreeNode* node) {
    AVLTreeNode* tempNode = node->left;
    node->left = tempNode->right;
    tempNode->right = node;
    
    restoreHeight(node);
    restoreHeight(tempNode);
    return tempNode;
}

AVLTreeNode* rotateLeft(AVLTreeNode* node) {
    AVLTreeNode* tempNode = node->right;
    node->right = tempNode->left;
    tempNode->left = node;
    
    restoreHeight(node);
    restoreHeight(tempNode);
    return tempNode;
}

AVLTreeNode* balance(AVLTreeNode* node) {
    restoreHeight(node);
    if (balanceFactor(node) == 2) { // Right subtree appears higher
        if (balanceFactor(node->right) < 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    } else if (balanceFactor(node) == -2) { // Left subtree appears higher
        if (balanceFactor(node->left) > 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    return node;
}

AVLTreeNode* insert(AVLTreeNode* node, int value) {
    if (node == nullptr)
        return new AVLTreeNode(value);
    if (value < node->value)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);
    return balance(node);
}

AVLTreeNode* searchMinValueNode(AVLTreeNode* node) {
    if (node->left == nullptr)
        return node;
    else
        return searchMinValueNode(node->left);
}

AVLTreeNode* separateMinValueNode(AVLTreeNode* node) {
    if (node->left == nullptr)
        return node->right;
    else
        node->left = separateMinValueNode(node->left);
    return balance(node);
}

AVLTreeNode* remove(AVLTreeNode* node, int value) {
    if (node == nullptr)
        return node;
    if (value < node->value)
        node->left = remove(node->left, value);
    else if (value > node->value)
        node->right = remove(node->right, value);
    else {
        AVLTreeNode* leftNode = node->left;
        AVLTreeNode* rightNode = node->right;
        delete node;
        
        if (rightNode == nullptr)
            return leftNode;
        else {
            AVLTreeNode* minValueNode = searchMinValueNode(rightNode);
            minValueNode->left = leftNode;
            minValueNode->right = separateMinValueNode(rightNode);
            return balance(minValueNode);
        }
    }
    return balance(node);
}

