#include <iostream>

// Function with O(1) time complexity
void constantTimeExample(int n) {
    std::cout << "Constant time example: " << n << std::endl;
}

// Function with O(n) time complexity
void linearTimeExample(int arr[], int size) {
    std::cout << "Linear time example: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Function with O(n^2) time complexity
void quadraticTimeExample(int arr[], int size) {
    std::cout << "Quadratic time example: " << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << arr[i] << ", " << arr[j] << std::endl;
        }
    }
}

// Function with O(n) space complexity
void linearSpaceExample(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
    std::cout << "Linear space example: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
}

// Function with O(1) space complexity
void constantSpaceExample(int n) {
    int result = n * n;
    std::cout << "Constant space example: " << result << std::endl;
}

int main() {
    int n = 5;
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    constantTimeExample(n);
    linearTimeExample(arr, size);
    quadraticTimeExample(arr, size);
    linearSpaceExample(n);
    constantSpaceExample(n);

    return 0;
}