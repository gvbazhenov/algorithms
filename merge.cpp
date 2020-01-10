void merge(std::vector<int>& source, int left, int mid, int right) {
    int leftSize = mid - left + 1, rightSize = right - mid, leftIter = 0, rightIter = 0;
    int leftArray[leftSize + 1], rightArray[rightSize + 1];
    
    for (int iter = 0; iter < leftSize; iter++)
        leftArray[iter] = source[left + iter];
    leftArray[leftSize] = Infinity;
    
    for (int iter = 0; iter < rightSize; iter++)
        rightArray[iter] = source[mid + iter + 1];
    rightArray[rightSize] = Infinity;
    
    for (int iter = left; iter <= right; iter++) {
        if (leftArray[leftIter] < rightArray[rightIter]) {
            source[iter] = leftArray[leftIter];
            leftIter++;
        } else {
            source[iter] = rightArray[rightIter];
            rightIter++;
        }
    }
}

void mergeSort(std::vector<int>& source, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(source, left, mid);
        mergeSort(source, mid + 1, right);
        merge(source, left, mid, right);
    }
}

