struct UndirectedGraph {
    int number;
    std::vector<int> *adjacencyList;
    
    UndirectedGraph(int number);
    ~UndirectedGraph();
    void insert(int one, int another);
    void remove(int one, int another);
    
    void breadthFirstSearch(int vert);
    void depthFirstSearch(int vert);
};

UndirectedGraph::UndirectedGraph(int number) {
    this->number = number;
    adjacencyList = new std::vector<int>[number];
}

UndirectedGraph::~UndirectedGraph() {
    delete[] adjacencyList;
}

void UndirectedGraph::insert(int one, int another) {
    std::vector<int>::iterator position = std::find(adjacencyList[one].begin(), adjacencyList[one].end(), another);
    if (position == adjacencyList[one].end()) {
        adjacencyList[one].push_back(another);
        adjacencyList[another].push_back(one);
    }
}

void UndirectedGraph::remove(int one, int another) {
    std::vector<int>::iterator position = std::find(adjacencyList[one].begin(), adjacencyList[one].end(), another);
    if (position != adjacencyList[one].end())
        adjacencyList[one].erase(position);
    
    position = std::find(adjacencyList[another].begin(), adjacencyList[another].end(), one);
    if (position != adjacencyList[another].end())
        adjacencyList[another].erase(position);
}

void UndirectedGraph::breadthFirstSearch(int vert) {
    bool markedVertices[number];
    for (int iter = 0; iter < number; iter++)
        markedVertices[iter] = false;
    
    std::deque<int> traversalQueue;
    markedVertices[vert] = true;
    traversalQueue.push_back(vert);
    
    std::vector<int>::iterator iter;
    
    while (!traversalQueue.empty()) {
        int currentVert = traversalQueue.front();
        std::cout << currentVert << std::endl;
        traversalQueue.pop_front();
        
        for (iter = adjacencyList[currentVert].begin(); iter != adjacencyList[currentVert].end(); iter++)
            if (!markedVertices[*iter]) {
                markedVertices[*iter] = true;
                traversalQueue.push_back(*iter);
            }
    }
}

void UndirectedGraph::depthFirstSearch(int vert) {
    bool markedVertices[number];
    for (int iter = 0; iter < number; iter++)
        markedVertices[iter] = false;
    
    std::stack<int> traversalStack;
    markedVertices[vert] = true;
    traversalStack.push(vert);
    
    std::vector<int>::reverse_iterator iter;
    
    while (!traversalStack.empty()) {
        int currentVert = traversalStack.top();
        std::cout << currentVert << std::endl;
        traversalStack.pop();
        
        for (iter = adjacencyList[currentVert].rbegin(); iter != adjacencyList[currentVert].rend(); iter++)
            if (!markedVertices[*iter]) {
                markedVertices[*iter] = true;
                traversalStack.push(*iter);
            }
    }
}

