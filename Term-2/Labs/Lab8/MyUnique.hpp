#pragma once

template<class T>
class UniquePointer
{
	T *ptr = nullptr;
public:
	explicit UniquePointer(T *ptr);
	~UniquePointer();
	UniquePointer(UniquePointer&& other) noexcept;
	UniquePointer& operator=(UniquePointer&& other) noexcept;
	T *get() const;
	T &operator*();
	T *operator->();
	void reset(T* p = nullptr) noexcept;

	UniquePointer(const UniquePointer&) = delete;
	UniquePointer& operator=(const UniquePointer&) = delete;
};