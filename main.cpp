#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

// Функция для обмена двух элементов
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Функция для преобразования массива в кучу
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    double N = 100000;

    vector<int> arr(N);

    // Генерация случайных чисел и заполнение массива
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, N); // Замените 1 и 100 на желаемый диапазон
    for (int i = 0; i < N; ++i) {
        arr[i] = distribution(gen);
    }

    // selectionSort
    auto start = chrono::high_resolution_clock::now();

    selectionSort(arr);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "selectionSort time: " << duration.count() << " ms." << endl;
    // Сброс массива
    random_shuffle(arr.begin(), arr.end());

    // heapSort
    start = chrono::high_resolution_clock::now();

    heapSort(arr);

    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "heapSort time: " << duration.count() << " ms." << endl;

    return 0;
}
