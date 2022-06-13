#pragma once
#pragma once
#include<fstream>

namespace l1 {
    class Txt 
    {

        std::string* data_ = nullptr;
        int size_ = 0;
        std::ifstream my_file_;

    public:
        size_t size();
        Txt() = default;
        explicit Txt(const char* filename);
        ~Txt();
        Txt(const Txt& arr);
        Txt& operator=(const Txt& arr);
        Txt(Txt&& arr) noexcept;
        Txt& operator=(Txt&& arr) noexcept;
    };
}