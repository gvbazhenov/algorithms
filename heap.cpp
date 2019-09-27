struct Heap {
    std::vector<int> data;
    Heap(std::vector<int>& source);
    void recreate(int position, int size);
    void sort();
};

Heap::Heap(std::vector<int>& source) {
    data = source;
    for (int iter = (int)data.size() / 2; iter > -1; iter--)
        recreate(iter, (int)data.size());
}

void Heap::recreate(int position, int size) {
    int left, right, greatest;
    
    while (true) {
        left = 2 * position + 1;
        right = 2 * position + 2;
        greatest = position;
        
        if (left < size and data[left] > data[greatest])
            greatest = left;
        if (right < size and data[right] > data[greatest])
            greatest = right;
        
        if (position == greatest) break;
        std::swap(data[greatest], data[position]);
        position = greatest;
    }
}

void Heap::sort() {
    for (int iter = (int)data.size() - 1; iter > 0; iter--) {
        std::swap(data[0], data[iter]);
        recreate(0, iter);
    }
}

