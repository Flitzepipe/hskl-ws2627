#pragma once

#include "common.h"

namespace FProg {
    template<typename T> struct propagate_const;
    template<typename T> auto begin(const propagate_const<T>&);
    // Propagate-const wrapper
    // ähnlich std::experimental::propagate_const (bei pointer-like types), jedoch für array-like types
    template<typename T>
    struct propagate_const final {
        friend auto begin<>(const propagate_const&);
        propagate_const() = default;
        propagate_const(T&& a) : array{std::move(a)}{}
        const auto& operator[](size_t index) const {
            return array[index];
        }   
        auto& operator[](size_t index){
            return array[index];
        }   
        explicit operator bool() const {
            return !!array;
        }
        void swap(propagate_const& o) {
            using std::swap;
            swap(array, o.array);
        }
        void swap(T& o) {
            using std::swap;
            swap(array, o);
        }
    private:
        T array;
    };
    template<typename T>
    void swap(propagate_const<T>& a, propagate_const<T>& b) {
        a.swap(b);
    } 
    template<typename T>
    void swap(propagate_const<T>& a, T& b) {
        a.swap(b);
    } 
    
    template<typename T>
    auto begin(const propagate_const<T>& a) {
        using std::begin;
        return begin(a.array);
    }
    
    template<typename T>
    auto end(const propagate_const<T>& a) {
        using std::end;
        return end(a.array);
    }
}
