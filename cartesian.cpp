const int WTF = 3141331;

struct CartesianTreeNode {
    int value;
    int priority;
    int size;
    CartesianTreeNode* left;
    CartesianTreeNode* right;
    CartesianTreeNode(int value, int priority): value(value), priority(priority),
                                                size(1), left(nullptr), right(nullptr) {}
};

int getSize(CartesianTreeNode* node) {
    if (node == nullptr)
        return 0;
    else
        return node->size;
}

void restoreSize(CartesianTreeNode* node) {
    if (node != nullptr)
        node->size = 1 + getSize(node->left) + getSize(node->right);
}

CartesianTreeNode* merge(CartesianTreeNode* leftNode, CartesianTreeNode* rightNode) {
    if (leftNode == nullptr)
        return rightNode;
    else if (rightNode == nullptr)
        return leftNode;
    else if (leftNode->priority > rightNode->priority) {
        leftNode->right = merge(leftNode->right, rightNode);
        restoreSize(leftNode);
        return leftNode;
    } else {
        rightNode->left = merge(leftNode, rightNode->left);
        restoreSize(rightNode);
        return rightNode;
    }
}

std::pair<CartesianTreeNode*, CartesianTreeNode*> split(CartesianTreeNode* node, int value) {
    if (node == nullptr)
        return std::make_pair(nullptr, nullptr);
    else if (value > node->value) {
        std::pair<CartesianTreeNode*, CartesianTreeNode*> nodePair = split(node->right, value);
        node->right = nodePair.first;
        restoreSize(node);
        return std::make_pair(node, nodePair.second);
    } else {
        std::pair<CartesianTreeNode*, CartesianTreeNode*> nodePair = split(node->left, value);
        node->left = nodePair.second;
        restoreSize(node);
        return std::make_pair(nodePair.first, node);
    }
}

CartesianTreeNode* insert(CartesianTreeNode* node, CartesianTreeNode* insertedNode) {
    if (node == nullptr)
        return insertedNode;
    else if (insertedNode->priority > node->priority) {
        std::pair<CartesianTreeNode*, CartesianTreeNode*> nodePair = split(node, insertedNode->value);
        insertedNode->left = nodePair.first;
        insertedNode->right = nodePair.second;
        restoreSize(insertedNode);
        return insertedNode;
    } else {
        if (insertedNode->value < node->value)
            node->left = insert(node->left, insertedNode);
        else
            node->right = insert(node->right, insertedNode);
        restoreSize(node);
        return node;
    }
}

CartesianTreeNode* remove(CartesianTreeNode* node, int value) {
    if (node->value == value) {
        CartesianTreeNode* temp = node;
        node = merge(node->left, node->right);
        delete temp;
    } else {
        if (value < node->value)
            node->left = remove(node->left, value);
        else
            node = remove(node->right, value);
    }
    restoreSize(node);
    return node;
}

CartesianTreeNode* search(CartesianTreeNode* node, int value) {
    if (node == nullptr or value == node->value)
        return node;
    else if (value < node->value)
        return search(node->left, value);
    else
        return search(node->right, value);
}

int searchStat(CartesianTreeNode* node, int order) {
    if (order > node->size or order < 1)
        return WTF;
    if (order == getSize(node->left) + 1)
        return node->value;
    else if (order < getSize(node->left) + 1)
        return searchStat(node->left, order);
    else {
        order -= getSize(node->left) + 1;
        return searchStat(node->right, order);
    }
}

