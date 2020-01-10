int partition(std::vector<int>& source, int left, int right) {
    int position = left, pivot = source[right - 1];
    
    for (int iter = left; iter < right - 1; iter++)
        if (source[iter] < pivot)
            std::swap(source[position++], source[iter]); // Pushing smaller numbers to the left

    std::swap(source[position], source[right - 1]);
    return position;
}

void quickSort(std::vector<int>& source, int left, int right) {
    if (right > left) {
        int position = partition(source, left, right);
        quickSort(source, left, position);
        quickSort(source, position + 1, right);
    }
}

