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

sequence = [random.randint(1, 100) for it in range(0, 10)]

print(sequence)
sinking_sort(sequence)
print(sequence)

