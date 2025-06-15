/*
Вариант 5
Реализовать программу, в которой кроме главного создается три отдельных потока:
первый поток сортирует первую половину вещественного массива, второй поток сортирует
вторую половину вещественного массива, третий поток запускается после завершение
первых двух, он сортирует массив полностью (уже частично отсортированный). Каждый
поток имеет свое имя (например, thread1, thread2, thread3), и печатает отсортированный
массив, перед печатью каждого значения элемента массива поток должен напечатать с новой
строки свое имя. После завершения дочерних потоков главный поток выдает сообщение об
окончании работы. Имена потоков и массив передаются в потоковую функцию через ее
параметры, использовать одну потоковую функцию для всех трех потоков. Массив
предварительно до запуска потоков заполняются числами с использованием ГПСЧ. Для
сортировки использовать метод прямого включения
*/

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx;

void insertionSort(vector<double>& arr, int left, int right, const string& name) {
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

    thread thread1(insertionSort, ref(v), 0, n / 2, "\t\tthread1");
    thread thread2(insertionSort, ref(v), n / 2, n, "thread2");
    thread1.join();
    thread2.join();
    cout << "-------------------------------\n";

    thread thread3(insertionSort, ref(v), 0, n, "\tthread3");
    thread3.join();

    cout << "\nMain thread finished" << endl;
}