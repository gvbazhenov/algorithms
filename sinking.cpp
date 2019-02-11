#include <iostream>
#include <vector>
#include <iterator>
#include <random>

void sinkingSort(std::vector<int> &);
void printSequence(std::vector<int> &);

int main()
{
    size_t defaultSize = 10;
    std::vector<int> vector = {};

    std::random_device generator;
    std::uniform_int_distribution<int> distribution(1, 100);

    for (size_t iter = 0; iter != defaultSize; iter++) // random writing
        vector.push_back(distribution(generator));

    printSequence(vector); // printing the original sequence
    sinkingSort(vector);   // proceeding the sorting
    printSequence(vector); // printing the sorted sequence

    return 0;
}

void printSequence(std::vector<int> &vector)
{
    for (std::vector<int>::iterator iter = vector.begin(); iter != vector.end(); iter++)
        std::cout << *iter << ' ';
    std::cout << std::endl;
}

void sinkingSort(std::vector<int> &vector)
{
    int temp = 0;
    bool swapped = 0;
    size_t bias = 0;

    for (size_t outIter = 0; outIter != vector.size() - 1 - bias; outIter++)
    {
        swapped = false;
        for (size_t inIter = 0; inIter != vector.size() - 1 - outIter; inIter++)
        {
            if (vector[inIter] > vector[inIter + 1]) // checking the opportunity to swap elements
            {
                temp = vector[inIter];
                vector[inIter] = vector[inIter + 1];
                vector[inIter + 1] = temp;
                swapped = true;
            }
        }

        if (swapped) bias++; // checking the opportunity to increase bias
        else break;          // observing the case of sorted sequence
    }
}
