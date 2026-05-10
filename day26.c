#include <stdio.h>
#include <stdlib.h>

void swap(long long *a, long long *b)
{
    long long temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(long long heap[], int size, int index)
{
    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest])
        {
            smallest = left;
        }

        if (right < size && heap[right] < heap[smallest])
        {
            smallest = right;
        }

        if (smallest == index)
        {
            break;
        }

        swap(&heap[index], &heap[smallest]);

        index = smallest;
    }
}

void heapifyUp(long long heap[], int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
        {
            break;
        }

        swap(&heap[parent], &heap[index]);

        index = parent;
    }
}

void buildHeap(long long heap[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyDown(heap, size, i);
    }
}

long long extractMin(long long heap[], int *size)
{
    long long minValue = heap[0];

    heap[0] = heap[*size - 1];

    (*size)--;

    heapifyDown(heap, *size, 0);

    return minValue;
}

void insertHeap(long long heap[], int *size, long long value)
{
    heap[*size] = value;

    (*size)++;

    heapifyUp(heap, *size - 1);
}

int cookies(int k, int n, int A[])
{
    long long *heap = (long long *)malloc(sizeof(long long) * n);

    for (int i = 0; i < n; i++)
    {
        heap[i] = A[i];
    }

    int size = n;

    buildHeap(heap, size);

    int operations = 0;

    while (size > 1 && heap[0] < k)
    {
        long long first = extractMin(heap, &size);

        long long second = extractMin(heap, &size);

        long long newCookie = first + (2 * second);

        insertHeap(heap, &size, newCookie);

        operations++;
    }

    int result;

    if (heap[0] >= k)
    {
        result = operations;
    }
    else
    {
        result = -1;
    }

    free(heap);

    return result;
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    int A[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    int answer = cookies(k, n, A);

    printf("%d\n", answer);

    return 0;
}