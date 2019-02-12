import random

def swap(seq, index_left, index_right):
    seq[index_left], seq[index_right] = seq[index_right], seq[index_left]

def sinking_sort(sequence):
    bias = 0
    for out_iter in range(len(sequence) - 1 - bias):
        swapped = False
        for in_iter in range(len(sequence) - 1 - out_iter):
            if sequence[in_iter] > sequence[in_iter + 1]:
                swap(sequence, in_iter, in_iter + 1)
                swapped = True
                bias += 1
        if not swapped:
            break

sequence = [random.randint(1, 100) for it in range(0, 10)]

print(sequence)
sinking_sort(sequence)
print(sequence)

