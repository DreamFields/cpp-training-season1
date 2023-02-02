/*
 * @Author: Meng Tian
 * @Date: 2023-02-02 15:58:26
 * @Descripttion: iterator overwrite
 */
#include <iostream>
#include <vector>

using Array2D = std::vector<std::vector<char>>;

Array2D generate_array() {
    Array2D arr;
    arr.push_back({ 0, 0, 0, 117, 0, 0, 110 });
    arr.push_back({ 0, 108, 101, 0, 97, 0, 0, 0, 0 });
    arr.push_back({ 115, 0, 104, 0 });
    arr.push_back({ 0, 0, 32, 99 });
    arr.push_back({ 114, 0, 0, 0, 101, 97, 0, 0, 0, 0, 0, 0, 116, 0, 0 });
    arr.push_back({ 0, 0, 105, 0, 0, 118, 0 });
    arr.push_back({ 105, 116, 0, 121, 0, 0 });
    return arr;
}

class Iterator {
public:
    using value_type = char;
    using pointer = char*;
    using refereence = char&;

    // TODO: Define the constructor
    Iterator(const Array2D& arr, std::vector<char>::const_iterator current_ptr, Array2D::const_iterator row_ptr):
        arr_(arr), _current_ptr(current_ptr), _row_ptr(row_ptr)
    {}

    const char& operator*() const {
        // TODO: Your code here
        return *_current_ptr;
    }

    const char* operator->() const {
        // TODO: Your code here
        return &(operator*());
    }

    Iterator& operator++() {
        // TODO: Your code here
        // skip null characters
        do {
            if ((_current_ptr + 1) != (*_row_ptr).end()) {
                ++_current_ptr;
            }
            else {
                ++_row_ptr;
                if (_row_ptr != arr_.end()) {
                    _current_ptr = (*_row_ptr).begin();
                }
                else {
                    _current_ptr = (*(arr_.end() - 1)).end();
                }
            }
        } while (*_current_ptr == 0 && _current_ptr != (*(arr_.end() - 1)).end());

        return *this;
    }

    bool operator==(const Iterator& other) const {
        // TODO: Your code here
        // objects of the same class are friends with each other
        return _current_ptr == other._current_ptr;
    }

    bool operator!=(const Iterator& other) const {
        // No need to change this
        return !(*this == other);
    }
private:
    const Array2D& arr_;
    std::vector<char>::const_iterator _current_ptr;
    Array2D::const_iterator _row_ptr;
};

// * Iterate over every character in an Array2D in a flattend way, i.e., every
//   char in a row, then the next row.
// * You SHOULD skip the null characters (e.g. 0 or '\0').
class Flatten {
public:
    explicit Flatten(const Array2D& arr): arr_(arr) {
        // TODO: Your code here
    }

    Iterator begin() const {
        // TODO: Your code here
        std::vector<char>::const_iterator iter = (*arr_.begin()).begin();
        Array2D::const_iterator row_ptr = arr_.begin();
        Iterator begin = Iterator(arr_, iter, row_ptr);
        
        // skip null characters
        while (*begin == 0) ++begin;
        return begin;
    }
    Iterator end() const {
        // TODO: Your code here
        std::vector<char>::const_iterator iter = (*(arr_.end() - 1)).end();
        Array2D::const_iterator row_ptr = arr_.end();
        return Iterator(arr_, iter, row_ptr);
    }

private:
    const Array2D& arr_;
};

int main() {
    auto arr = generate_array();

    // Range-based for loop
    // Ranges are sequences of elements, including arrays, containers, and any other type supporting the functions begin and end.
    for (char c : Flatten(arr)) {
        std::cout << c;
    }

    std::cout << std::endl;
    return 0;
}
