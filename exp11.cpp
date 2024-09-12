#include <iostream>
using namespace std;
void copyString(char* source, char* dest) {
    if (*source == '\0') {
        *dest = '\0';
        return;
    }
    *dest = *source;
    copyString(source + 1, dest + 1);
}
int main() {
    char source[] = "Hello";
    char dest[20];
    copyString(source, dest);
    cout << "Copied String: " << dest << endl;
    return 0;
}
