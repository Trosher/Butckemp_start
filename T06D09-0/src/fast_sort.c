#include <stdio.h>
#define NMAX 10

void fast_sort(int *numbers, int left, int right);
int input(int *data, int len);
void output(int *data, int len);
void heapSort(int *numbers, int array_size);
void siftDown(int *numbers, int root, int bottom);
void copy_masiv(int *data1, int *data2, int len);

int main() {
    int data1[NMAX];
    int data2[NMAX];
    int len = 10;
    int *p1 = data1;
    int *p2 = data2;
    if (input(p1, len) == 1) {
        return 0;
    } else {
        copy_masiv(p1, p2, len);
        fast_sort(p1, 0, len - 1);
        output(p1, len);
        printf("\n");
        heapSort(p2, len);
        output(p2, len);
    }
    return 0;
}

void copy_masiv(int *data1, int *data2, int len) {
    for (int i = 0; i < len; i++)
        data2[i] = data1[i];
}

void output(int *data, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d", data[i]);
        if (i < len - 1)
            printf(" ");
    }
}

void siftDown(int *numbers, int root, int bottom) {
  int maxChild;
  int done = 0;
  while ((root * 2 <= bottom) && (!done)) {
    if (root * 2 == bottom)
      maxChild = root * 2;
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    if (numbers[root] < numbers[maxChild]) {
      int temp = numbers[root];
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    } else {
      done = 1;
    }
  }
}

void heapSort(int *numbers, int array_size) {
  for (int i = (array_size / 2); i >= 0; i--)
    siftDown(numbers, i, array_size - 1);
  for (int i = array_size - 1; i >= 1; i--) {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i - 1);
  }
}

void fast_sort(int *numbers, int left, int right) {
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left < right) {
      while ((numbers[right] >= pivot) && (left < right))
        right--;
        if (left != right) {
        numbers[left] = numbers[right];
        left++;
      }
      while ((numbers[left] <= pivot) && (left < right))
        left++;
      if (left != right) {
        numbers[right] = numbers[left];
        right--;
      }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
      fast_sort(numbers, left, pivot - 1);
    if (right > pivot)
      fast_sort(numbers, pivot + 1, right);
}

int input(int *data, int len) {
    float test_data;
    char c;
    for (int i = 0; i < len; i++) {
        if (scanf("%f%c", &test_data, &c) == 2 && \
            (c == '\n' || c ==  ' ')) {
            *data = test_data;
            if (!(*data == test_data) && !(test_data)) {
                printf("n/a");
                return 1;
            }
            data++;
        } else {
            printf("n/a");
            return 1;
        }
    }
    return 0;
}
