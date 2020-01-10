struct Heap {
    std::vector<int> data;
    Heap(std::vector<int> source);
    void restoreProperty(int position);
    void insert(int value);
    int removeTarget();
};

Heap::Heap(std::vector<int> source) {
    data = source;
    for (int iter = (int) data.size() / 2; iter > -1; iter--)
        restoreProperty(iter);
}

void Heap::restoreProperty(int position) {
    int left = 2 * position + 1, right = 2 * position + 2, target = position;
    
    while (true) {
        if (left < data.size() and data[left] < data[target])
            target = left;
        if (right < data.size() and data[right] < data[target])
            target = right;
        
        if (position == target) break;
        std::swap(data[target], data[position]);
        position = target;
        
        left = 2 * position + 1;
        right = 2 * position + 2;
    }
}

void Heap::insert(int value) {
    data.push_back(value);
    int position = (int) data.size() - 1;
    int parent = (position - 1) / 2;
    
    while (position > 0 and data[parent] > data[position]) {
        std::swap(data[parent], data[position]);
        position = parent;
        parent = (position - 1) / 2;
    }
}

int Heap::removeTarget() {
    int target = data[0];
    data[0] = data[data.size() - 1];
    data.pop_back();
    restoreProperty(0);
    
    return target;
}

void heapSort(std::vector<int>& source) {
    Heap support = Heap(source);
    for (int iter = 0; iter < source.size(); iter++)
        source[iter] = support.removeTarget();
}

