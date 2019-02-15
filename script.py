import random

def sinking_sort(sequence):
    bias = 0
    for out_iter in range(len(sequence) - 1 - bias):
        swapped = False
        for in_iter in range(len(sequence) - 1 - out_iter):
            if sequence[in_iter] > sequence[in_iter + 1]:  # checking the opportunity to swap elements
                sequence[in_iter], sequence[in_iter + 1] = sequence[in_iter + 1], sequence[in_iter]
                swapped = True
                bias += 1
        if not swapped:
            break

def insertion_sort(sequence):
    for out_iter in range(2, len(sequence)):
        key = sequence[out_iter]
        in_iter = out_iter - 1

        while in_iter > -1 and sequence[in_iter] > key:
            sequence[in_iter + 1] = sequence[in_iter]
            in_iter -= 1
        sequence[in_iter + 1] = key


sequence = [random.randint(1, 100) for it in range(0, 10)]

print(sequence)           # printing the original sequence
insertion_sort(sequence)  # proceeding the sorting
print(sequence)           # printing the sorted sequence
