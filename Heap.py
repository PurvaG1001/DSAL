def heapify(heap, n, i):
    maximum = i
    l = 2 * i + 1
    r = 2 * i + 2

    # if left child exists
    if l < n and heap[i] < heap[l]:
        maximum = l

    # if right child exists
    if r < n and heap[maximum] < heap[r]:
        maximum = r

    # root
    if maximum != i:
        heap[i], heap[maximum] = heap[maximum], heap[i]  # swap root
        heapify(heap, n, maximum)


def heapSort(heap):
    n = len(heap)

    # maxheap
    for i in range(n, -1, -1):
        heapify(heap, n, i)

    # element extraction
    for i in range(n-1, 0, -1):
        heap[i], heap[0] = heap[0], heap[i]  # swap
        heapify(heap, i, 0)


# main
heap = [15, 1, 11, 5, 6, 7, 24, 9, 8, 2]

heapSort(heap)

n = len(heap)

print("Heap array: ")
print(heap)

print("The Sorted array is: ")
print(heap)
