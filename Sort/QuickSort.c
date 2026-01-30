#include <stdio.h>

int partition(int arr[], int left, int right) {
    int val = arr[left]; // 基准数
    while (left < right) {
        while (left < right && arr[right] >= val) {
            right--;
        }
        if (left < right) {
            arr[left] = arr[right];
            left++;
        }
        while (left < right && arr[left] < val) {
            left++;
        }
        if (left < right) {
            arr[right] = arr[left];
            right++;
        }
    }
    arr[left] = val;
    return left;
}

void quicksort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotIndex = partition(arr, left, right);
    quicksort(arr, left, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, right);
}

int main() {
    int arr[] = {12, 35, 1, 89, 74, 52, 78, 55};
    int length = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, length - 1);
    for (int k = 0; k < length; k++) {
        printf("%d ", arr[k]);
    }
    return 0;
}