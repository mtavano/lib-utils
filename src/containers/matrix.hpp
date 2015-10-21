//          Copyright Marcello Tavano Lanas August 2014
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <vector>
#include <cstddef>

#ifndef MATRIX_HPP
#define MATRIX_HPP


template <class T> class Matrix {
    public: 
        Matrix(const std::size_t& r, const std::size_t& c,const T& fill = T()) :
                                mRows_(r), mColumns_(c), mData_(r*c, fill) {}
    std::size_t rows() const {
        return mRows_; 
    }
    std::size_t columns() const {
        return mColumns_;
    }
    std::size_t elements() const {
        return mData_.size();
    }
    T* operator[] (std::size_t r) {
        return &mData_[r*columns()];
    }
    const T* operator[] (std::size_t r) const {
        return &mData_[r*columns()];
    }
    private:
        size_t mRows_;
        size_t mColumns_;
        std::vector<T> mData_;
};

#endif