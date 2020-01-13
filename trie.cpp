struct TrieNode {
    char character;
    bool terminal;
    TrieNode(char character, bool terminal): character(character), terminal(terminal) {}
    std::map<char, TrieNode*> descendants;
};

TrieNode* search(TrieNode* node, std::string source) {
    TrieNode* currentNode = node;
    for (std::string::iterator iter = source.begin(); iter != source.end(); iter++) {
        std::map<char, TrieNode*>::iterator pos = currentNode->descendants.find(*iter);
        if (pos == currentNode->descendants.end())
            return nullptr;
        currentNode = pos->second;
    }
    return currentNode->terminal ? currentNode : nullptr;
}

TrieNode* insert(TrieNode* node, std::string source) {
    TrieNode* currentNode = node;
    for (std::string::iterator iter = source.begin(); iter != source.end(); iter++) {
        std::map<char, TrieNode*>::iterator pos = currentNode->descendants.find(*iter);
        if (pos == currentNode->descendants.end())
            currentNode->descendants.insert(std::pair<char, TrieNode*>(*iter, new TrieNode(*iter, false)));
        currentNode = currentNode->descendants[*iter];
    }
    currentNode->terminal = true;
    return currentNode;
}

void remove(TrieNode* node, std::string source) {
    TrieNode* targetNode = search(node, source);
    targetNode->terminal = false;
}

