/*
 * Вариант 5. Последовательность Фибоначчи
 */

#include<iostream>
#include<exception>

class FibonacciArrayException : public std::invalid_argument {
    int* invalid_array;
    size_t invalid_size;
public:
    explicit FibonacciArrayException(const std::string& message, const int* arr, size_t size)
    : std::invalid_argument(message), invalid_array(new int[size]), invalid_size(size) {
        for (size_t i = 0; i < size; ++i) {
            invalid_array[i] = arr[i];
        }
    }

    ~FibonacciArrayException() {
        delete[] invalid_array;
    }

    void printInvalidData() const {
        std::cout << "Incorrect Fibonacci sequence: " << std::endl;
        for (size_t i = 0; i < invalid_size; ++i) {
            std::cout << invalid_array[i] << " ";
        }
    }
};

class FibonacciArray
{
    int* array;
    size_t size;

    bool isFibonacciSequence(const int* arr, size_t size) {
        if (size < 2) {
            return false;
        }
        if (arr[0] != 0 || arr[1] != 1) {
            return false;
        }
        for (size_t i = 2; i < size; ++i) {
            if (arr[i] != arr[i - 1] + arr[i - 2]) return false;
        }
        return true;
    }
public:
    FibonacciArray(const int* arr, size_t s) {
        if (!isFibonacciSequence(arr, s)) {
            throw FibonacciArrayException("Provided array is not a Fibonacci sequence", arr, s);
        }
        size = s;
        array = new int[size];
        for (size_t i = 0; i < size; ++i) {
            array[i] = arr[i];
        }
    }

    ~FibonacciArray() {
        delete[] array;
    }

    void print() const {
        std::cout << "Correct Fibonacci sequence:" << std::endl;
        for (size_t i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
    }
};

int main() {
    // Без исключения
    try {
        int correct_arr[] = {0, 1, 1, 2, 3, 5, 8};
        FibonacciArray fa1(correct_arr, 7);
        std::cout << "Successfully created FibonacciArray object:" << std::endl;
        fa1.print();
    } catch (const FibonacciArrayException& err) {
        err.printInvalidData();
    }

    std::cout << "\n----------------------------------------\n";

    // С исключением
    try {
        int wrong_arr[] = {0, 1, 2, 3, 5, 8};
        FibonacciArray fa2(wrong_arr, 6);
        std::cout << "Successfully created FibonacciArray object:" << std::endl;
        fa2.print();
    } catch (const FibonacciArrayException& e) {
        std::cout << "Caught FibonacciArrayException" << std::endl;
        e.printInvalidData();
    }

    return 0;
}