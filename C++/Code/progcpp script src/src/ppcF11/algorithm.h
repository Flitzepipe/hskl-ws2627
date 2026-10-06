#pragma once

#include <algorithm>
#include <memory>

namespace std {
    template<typename T> 
    T* begin(const std::unique_ptr<T[]>& ptr) {
        return ptr.get();
    }
}
namespace FProg {
    template<typename C>
    bool find(const C& c, typename C::value_type& what) {
        return (std::find(std::begin(c), std::end(c), what) != std::end(c));
    }
    
    template<typename T>
    void sort(T& c) {
        std::sort(std::begin(c), std::end(c));
    }
    
    template<typename C1, typename C2>
    void copy(const C1& c1, const C2& c2) {
        using std::begin;
        using std::end;
        std::copy(begin(c1), end(c1), begin(c2));
    }
    
    template<typename T, typename... TT>
    struct any_of {
        any_of(const T& first, const TT&... rest) : mData{first, rest...}{}  
        template<auto I>
        const auto& get() const {
            return std::get<I>(mData);
        }
    private:
        std::tuple<T, TT...> mData;
    };
    template<auto I, typename... TT>
    const auto& get(const any_of<TT...>& a) {
        return a.template get<I>();
    }    
    template<typename L, typename... TT>
    bool operator==(const L& lhs, const any_of<TT...>& rhs) {
        return [&]<auto... II>(std::index_sequence<II...>){
            return ((lhs == get<II>(rhs)) || ...);
        }(std::make_index_sequence<sizeof...(TT)>{});
    }
    
}
