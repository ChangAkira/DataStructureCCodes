#include <stdio.h>
#include <vector>
using namespace std;
void merge(int arr[], int i, int j, int mid) {
    int pos1 = i, pos2 = mid + 1;
    // 需要额外的空间来存储归并后的有序段，否则原数组会被覆盖。为了方便此处使用C++的vector。如果用C语言的话，需要可变内存空间，链表是最好实践。
    vector<int> tmp;
    tmp.reserve(j - i + 1);
    while (pos1 <= mid && pos2 <= j) {
        if (arr[pos1] < arr[pos2]) {
            tmp.push_back(arr[pos1]);
            pos1++;
        }
        if (arr[pos2] < arr[pos1]) {
            tmp.push_back(arr[pos2]);
            pos2++;
        }
    }
    while (pos1 <= mid) {
        tmp.push_back(arr[pos1]);
        pos1++;
    }
    while (pos2 <= j) {
        tmp.push_back(arr[pos2]);
        pos2++;
    }
    // 放回去
    for (int k = i; k <= j; k++) {
        arr[k] = tmp[k - i]; // tmp是从0开始的
    }
}

void mergeSort(int arr[], int i, int j) {
    if (i == j) {
        // 剩余一个元素时
        return;
    }
    int mid = (i + j) / 2;
    mergeSort(arr, i, mid);
    mergeSort(arr, mid + 1, j);

    // 向上回溯，回溯的过程中，合并子问题的解
    merge(arr, i, j, mid); //[i,mid]和[mid+1,j]区间合并
}

int main() {
    int arr[] = {12, 35, 1, 89, 74, 52, 78, 55};
    int length = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, length - 1);
    for (int k = 0; k < length; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
    return 0;
}