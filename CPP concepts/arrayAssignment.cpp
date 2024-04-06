#include <algorithm>
#include <cstddef>                     
#include <iostream>
#include <string>
#include <concepts>

template <typename T, std::size_t N>   
class Array{

 public:
    template <typename T2>
    Array<T, N>& operator = (const Array<T2, N>& arr) requires std::convertible_to<T2, T>;           // (1)
    template<typename, std::size_t> friend class Array;
    std::size_t getSize() const;
 private:
    T elem[N];
    
};

template <typename T, std::size_t N> 
std::size_t Array<T, N>::getSize() const { return N; }

template<typename T, std::size_t N>
template<typename T2>
Array<T, N>& Array<T, N>::operator = (const Array<T2, N>& arr) requires std::convertible_to<T2, T> { // (2)
    std::copy(std::begin(arr.elem), std::end(arr.elem), std::begin(elem));
    return *this;
}

int main() {

    std::cout << '\n';

    Array<float, 5> floatArr;  
    Array<float, 5> floatArr2;
    floatArr.getSize();
    
    floatArr2 = floatArr;             
     
    
    Array<double, 5> doubleArr;       
    doubleArr = floatArr;             

    Array<std::string, 5> strArr;
    // doubleArr = strArr;            // (3)
    
}