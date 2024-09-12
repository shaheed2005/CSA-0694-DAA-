#include <iostream>
using namespace std;

void findMinMax(int arr[], int left, int right, int &min, int &max) {
    if (left == right) {
        if (arr[left] < min) min = arr[left];
        if (arr[left] > max) max = arr[left];
        return;
    }
    if (right == left + 1) {
        if (arr[left] < arr[right]) {
            if (arr[left] < min) min = arr[left];
            if (arr[right] > max) max = arr[right];
        } else {
            if (arr[right] < min) min = arr[right];
            if (arr[left] > max) max = arr[left];
        }
        return;
    }
    int mid = (left + right) / 2;
    findMinMax(arr, left, mid, min, max);
    findMinMax(arr, mid + 1, right, min, max);
}

int main() {
    int arr[] = {1, 3, 5, 2, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0], max = arr[0];
    findMinMax(arr, 0, n - 1, min, max);
    cout << "Min: " << min << ", Max: " << max << endl;
    return 0;
}
