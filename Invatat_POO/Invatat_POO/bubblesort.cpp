#include <iostream>
#include<string>
using namespace std;

void bubble(int array[], int size) {
    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << array[i];
    }
    cout << "\n";
}

int main() {
    int data[] = { -2, 45, 0, 11, -9 };
    int size = sizeof(data) / sizeof(data[0]);

    bubble(data, size);

    cout << "Rezultat sortat:\n";
    printArray(data, size);
}