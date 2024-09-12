#include <iostream>
using namespace std;

void reverseString(string &str, int i) {
    if (i >= str.size() / 2) return;
    swap(str[i], str[str.size() - i - 1]);
    reverseString(str, i + 1);
}

int main() {
    string str = "Hello";
    reverseString(str, 0);
    cout << "Reversed String: " << str << endl;
    return 0;
}
