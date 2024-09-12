#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {3, 1, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Min: " << *min_element(arr, arr + n) << endl;
    cout << "Max: " << *max_element(arr, arr + n) << endl;
    return 0;
}
