#include <iostream>
#include <vector>
#include <future>
#include <chrono>
#include <mutex>
#include <thread>

using namespace std;

mutex mtx;

void insertionSort(std::vector<double>& arr, int left, int right, const string& name) {
    for (int i = 1 + left; i < right; ++i) {
        double key = arr[i];
        int j = i - 1;
        
        // Сдвигаем элементы arr, которые больше key, на одну позицию вправо
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for (int i = left; i < right; i++) {
        this_thread::sleep_for(chrono::milliseconds(10));
        mtx.lock();
        cout << name << ": " << arr[i] << endl;
        mtx.unlock();
    }
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    vector<double> v(n);
    
    srand(time(0));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 1000 / 10.0;
    }

    cout << "Vector before sorting: ";
    for (auto num : v) {
        cout << num << " ";
    }
    cout << "\n=============================\n";

    // Запуск асинхронных задач с использованием future
    auto future1 = async(launch::async, insertionSort, ref(v), 0, n/2, "\t\tthread1");
    auto future2 = async(launch::async, insertionSort, ref(v), n/2, n, "thread2");
    
    // Ожидание завершения первых двух задач
    future1.get();
    future2.get();
    
    cout << "-------------------------------\n";
    
    auto future3 = async(launch::async, insertionSort, ref(v), 0, n, "\tthread3");
    future3.get();

    cout << "\nMain thread finished" << endl;
    return 0;
}