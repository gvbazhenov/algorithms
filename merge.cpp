void mergeSort(std::vector<int> &, int, int);
void printSequence(std::vector<int> &);
void merge(std::vector<int> &, int, int, int);


int main()
{
    size_t defaultSize = 10;
    std::vector<int> vector = {};

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(1, 100);

    for (size_t iter = 0; iter != defaultSize; iter++)
        vector.push_back(distribution(generator));

    printSequence(vector);
    mergeSort(vector, 0, vector.size() - 1);
    printSequence(vector);

    return 0;
}

void printSequence(std::vector<int> &vector)
{
    for (std::vector<int>::iterator iter = vector.begin(); iter != vector.end(); iter++)
        std::cout << *iter << ' ';
    std::cout << std::endl;
}

void mergeSort(std::vector<int> &vector, int left, int right)
{
    int split = 0;
    if (left < right)
    {
        split = (left + right) / 2;
        mergeSort(vector, left, split);
        mergeSort(vector, split + 1, right);
        merge(vector, left, split, right);
    }
}

void merge(std::vector<int> &vector, int left, int split, int right)
{
    std::vector<int>* tempVector = new std::vector<int>;
    int leftIter = left, rightIter = split + 1;

    while (leftIter < split + 1 && rightIter < right + 1)
    {
        if (vector[leftIter] < vector[rightIter])
            tempVector->push_back(vector[leftIter++]);
        else
            tempVector->push_back(vector[rightIter++]);
    }

    while (leftIter < split + 1)
        tempVector->push_back(vector[leftIter++]);
    while (rightIter < right + 1)
        tempVector->push_back(vector[rightIter++]);

    for (int iter = 0; iter < right - left + 1; iter++)
        vector[left + iter] = (*tempVector)[iter];

    delete tempVector;
}

