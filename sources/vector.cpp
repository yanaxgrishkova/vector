#include "vector.hpp"
#include <iostream>

vector_t::vector_t() : size_(0), capacity_(0), ptr_(nullptr)
{}

vector_t::vector_t(unsigned int size)
{
	size_ = size;
	capacity_ = size;
	ptr_ = new int[size];
}

vector_t::vector_t(const vector_t& other)
{
	size_ = other.size_;
	capacity_ = other.capacity_;
	ptr_ = new int[capacity_];
	for (int i = 0; i < capacity_; i++)
	{
		ptr_[i] = other.ptr_[i];
	}
}

auto vector_t::operator=(const vector_t& other)->vector_t&
{
	if (&other == this)
		return *this;
		delete[] ptr_;
	for (int i = 0; i < capacity_; i++)
	{
		ptr_[i] = other.ptr_[i];
	}
	return *this;
}

vector_t::~vector_t() noexcept
{
	delete[] ptr_;
}

auto vector_t::size() const noexcept -> unsigned int
{
	return size_;
}

auto vector_t::capacity() const noexcept -> unsigned int
{
	return capacity_;
}

auto vector_t::push_back(int value) -> void
{
	vector_t copy;
	if (capacity_ == size_)
	{
		copy.ptr_ = new int[capacity_];
		for (int i = 0; i < capacity_; i++)
		{
			copy.ptr_[i] = ptr_[i];
		}
		delete[] ptr_;
		capacity_ *= 2;
		ptr_ = new int[capacity_];
		for (int i = 0; i < capacity_; i++)
		{
			ptr_[i] = copy.ptr_[i];
		}
		ptr_[size_] = value;
	}
	else ptr_[size_] = value;
}

auto vector_t::operator[](unsigned int index) const noexcept -> int
{
	return ptr_[index];
}
