#include <cstdint>
#include <cstddef>
#include <utility>
#include <array>
#include <cassert>
#include <type_traits>

#include <specials.h>

namespace BMCPP::Util {
    namespace detail {
        template<size_t... II, typename T, typename Byte = std::byte>
        void copy(std::index_sequence<II...>, std::array<Byte, sizeof...(II)>& d, const T& src) {
            const Byte* s = reinterpret_cast<const Byte*>(&src);
            ((d[II] = s[II]),...);
        }
        template<size_t... II, typename T, typename Byte = std::byte>
        void copy(std::index_sequence<II...>, T& dst, const std::array<Byte, sizeof...(II)>& s) {
            Byte* d = reinterpret_cast<Byte*>(&dst);
            ((d[II] = s[II]),...);
        }
        template<size_t... II, typename T, typename Byte = std::byte, typename... BB>
        void copy(std::index_sequence<II...>, T& dst, const BB&... bb) {
            Byte* d = reinterpret_cast<Byte*>(&dst);
            ((d[II] = bb),...);
        }
        template<size_t... II, typename T, typename Byte = std::byte, typename... BB>
        void copy_r(std::index_sequence<II...>, T& dst, const BB&... bb) {
            Byte* d = reinterpret_cast<Byte*>(&dst);
            ((d[sizeof...(II) - 1 - II] = bb),...);
        }
    }
    template<typename T, typename Byte = std::byte>
    void copy(std::array<Byte, sizeof(T)>& dst, const T& src) {
        detail::copy(std::make_index_sequence<sizeof(T)>{}, dst, src);
    }
    template<typename T, typename Byte = std::byte>
    void copy(T& dst, const std::array<Byte, sizeof(T)>& src) {
        detail::copy(std::make_index_sequence<sizeof(T)>{}, dst, src);
    }
    template<typename T, typename... BB, typename Byte = std::byte>
    void copy(T& dst, const BB&... bb) {
        detail::copy(std::make_index_sequence<sizeof...(BB)>{}, dst, bb...);
    }
    template<typename T, typename... BB, typename Byte = std::byte>
    void copy_r(T& dst, const BB&... bb) {
        detail::copy_r(std::make_index_sequence<sizeof...(BB)>{}, dst, bb...);
    }
    
    struct ByteToIntegral{};
    struct IntegralToByte{};
    
    template<typename Dir, typename T, typename Byte = std::byte> struct ByteUnion;
    
    template<typename T, typename Byte> 
    requires (std::is_same<uint64_t, T>::value || std::is_same<uint32_t, T>::value || std::is_same<uint16_t, T>::value) && 
    (sizeof(T) > 1)
    struct ByteUnion<IntegralToByte, T, Byte> {
        static_assert(sizeof(Byte) == 1);
        inline static constexpr size_t size = sizeof(T);
        typedef T integral_type;
        typedef Byte byte_type;
        
        explicit ByteUnion(const T& v) {
            Util::copy(b, v);
        }
        explicit ByteUnion(const volatile T& v) {
            T tmp{v};
            Util::copy(b, tmp);
        }
        
        Byte operator[](uint8_t i) const {
            if constexpr(std::endian::native == std::endian::little) {
                return b[i];
            }
            else {
                return b[sizeof(T) - 1 - i];
            }
        }
        private:
        std::array<Byte, sizeof(T)> b;
    };
    
    template<typename T, typename Byte>
    requires (std::is_same<uint64_t, T>::value || std::is_same<uint32_t, T>::value || std::is_same<uint16_t, T>::value) && (sizeof(T) > 1)
    struct ByteUnion<ByteToIntegral, T, Byte> {
        static_assert(sizeof(Byte) == 1);
        inline static constexpr size_t size = sizeof(T);
        typedef T integral_type;
        typedef Byte byte_type;
        
        template<typename... B>
        requires (std::is_same<B, Byte>::value || ...) && (sizeof...(B) == sizeof(T))
                explicit ByteUnion(B... vv) : ByteUnion{Endianness::endian_type{}, std::index_sequence_for<B...>{}, vv...} {}
        
        const T& value() const {return a;}     
        private:
        template<size_t... II, typename... B>
        explicit ByteUnion(Endianness::Little, std::index_sequence<II...>, B&&... vv) {
            Util::copy_r(a, vv...);
        }
        template<size_t... II, typename... B>
        explicit ByteUnion(Endianness::Big, std::index_sequence<II...>, B&&... vv) {
            Util::copy(a, vv...);
        }
        private:
        T a;
    };
}
using namespace std::literals;
using namespace BMCPP::Util;

/*volatile */ uint64_t value{0x01020304};

int main(){
    ByteUnion<IntegralToByte, uint64_t> u1{value};
    //    ByteUnion<ByteToIntegral, uint64_t> u1x{value}; // not possible
    auto v1 = std::to_integer<uint8_t>(u1[0]);    
    //    u1.value(); // not possible
    //    assert(v1 == (value & 0xff));
    
    ByteUnion<ByteToIntegral, uint32_t> u2{0x01_byte, 0x02_byte, 0x03_byte, 0x04_byte}; 
    //    ByteUnion<IntegralToByte, uint32_t> u2x{0x01_byte, 0x02_byte, 0x03_byte, 0x04_byte}; // not possible
    auto v2 = u2.value(); 
    //    assert(v2 == value);
    //    u2[0]; // not possible
    
    return v1;
}

