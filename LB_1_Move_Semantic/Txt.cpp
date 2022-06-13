#include "Txt.h"
#include <string>
size_t l1::Txt::size() 
{

    if (my_file_.is_open()) {

        int lines_count = 0;

        std::string unused;
        while (std::getline(my_file_, unused)) 
        {
            ++lines_count;
        }

        size_ = lines_count;

        data_ = new std::string[lines_count];


        my_file_.clear();
        my_file_.seekg(0, my_file_.beg);

        lines_count = 0;

        while (std::getline(my_file_, data_[lines_count++]));

        my_file_.close();
    }

    return size_;
}

l1::Txt::Txt(const char* filename) 
{
    my_file_.open(filename);
}

l1::Txt::~Txt() 
{
    if (my_file_.is_open()) {
        my_file_.close();
    }
    delete[] data_;
}

l1::Txt::Txt(const Txt& arr) : size_(arr.size_) 
{
    data_ = new std::string[size_];
    for (int i = 0; i < size_; ++i)
        data_[i] = arr.data_[i];
}

l1::Txt& l1::Txt::operator=(const Txt& arr) 
{
    if (&arr == this)
        return *this;

    delete[] data_;

    size_ = arr.size_;
    data_ = new std::string[size_];

    for (int i = 0; i < size_; ++i)
        data_[i] = arr.data_[i];

    return *this;
}

l1::Txt::Txt(Txt&& arr) noexcept : size_(arr.size_), data_(arr.data_) 
{
    arr.size_ = 0;
    arr.data_ = nullptr;
}

l1::Txt& l1::Txt::operator=(Txt&& arr) noexcept 
{
    if (&arr == this)
        return *this;

    delete[] data_;

    size_ = arr.size_;
    data_ = arr.data_;
    arr.size_ = 0;
    arr.data_ = nullptr;

    return *this;
}