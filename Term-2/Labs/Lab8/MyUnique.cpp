#include "MyUnique.hpp"
#include <utility>

template<class T, typename...Args>
UniquePointer<T> MakeUniquePointer(const Args& ... args)
{
	return UniquePointer(new T(args...));
}

template<class T>
UniquePointer<T>::UniquePointer(T *p) : ptr(p) {}

template<class T>
UniquePointer<T>::~UniquePointer() {
	delete ptr;
}

template<class T>
UniquePointer<T>::UniquePointer(UniquePointer&& other) noexcept : ptr(std::move(other.ptr)) {}

template <class T>
T* UniquePointer<T>::get() const {
	return ptr;
}

template <class T>
T& UniquePointer<T>::operator*() {
	return *ptr;
}

template <class T>
T* UniquePointer<T>::operator->() {
	return ptr;
}

template <class T>
void UniquePointer<T>::reset(T* p = nullptr) noexcept {
	delete ptr;
	ptr = p;
}