const int Infinity = 1000;

struct SegmentTree {
    std::vector<int> data;
    SegmentTree(std::vector<int>& source);
    int revealMinValue(int left, int right);
    void update(int position, int value);
};

SegmentTree::SegmentTree(std::vector<int>& source) {
    data = source;
    int temp = 1;
    while (temp < source.size()) temp *= 2;
    data.resize(2 * temp, Infinity);
    
    for (int iter = temp; iter < 2 * temp; iter++)
        data[iter] = data[iter - temp];
    for (int iter = temp - 1; iter > 0; iter--)
        data[iter] = std::min(data[2 * iter], data[2 * iter + 1]);
}

int SegmentTree::revealMinValue(int left, int right) {
    int answer = Infinity;
    int temp = (int) data.size() / 2;
    left += temp; right += temp;
    while (left <= right) {
        if (left % 2 != 0)
            answer = std::min(answer, data[left]);
        if (right % 2 == 0)
            answer = std::min(answer, data[right]);
        left = (left + 1) / 2; right = (right - 1) / 2;
    }
    return answer;
}

void SegmentTree::update(int position, int value) {
    int temp = (int) data.size() / 2;
    position += temp;
    data[position] = value;
    while (position /= 2)
        data[position] = std::min(data[2 * position], data[2 * position + 1]);
}

