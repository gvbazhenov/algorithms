import random

def sinking_sort(sequence):
    bias = 0
    for out_iter in range(len(sequence) - 1 - bias):
        swapped = False
        for in_iter in range(len(sequence) - 1 - out_iter):
            if sequence[in_iter] > sequence[in_iter + 1]:
                temp = sequence[in_iter]
                sequence[in_iter] = sequence[in_iter + 1]
                sequence[in_iter + 1] = temp
                swapped = True
        if swapped:
            bias += 1
        else:
            break

sequence = [random.randint(1, 100) for i in range(0, 10)]

print(sequence)
sinking_sort(sequence)
print(sequence)
