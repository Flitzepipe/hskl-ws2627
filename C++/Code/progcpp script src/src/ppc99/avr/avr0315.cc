////////////////////////////////////////////////////////////
//                Laufzeit  GrÃ¶ÃŸe         Merkmal                      Autor      Funktion
// deinterleave0: 752 us    156           Maske+Schleife               Eckhart    ok
// deinterleave4: 264 us    194(72+122)   portabel                     asdfasd    odd<->even vertauscht 
// deinterleave5: 152 us    432(176+256)  even_odd_Tab. mit shift      Leo        ok
// deinterleave2: 152 us    284           ausgerolltes if+or           Peter D.   ok
// deinterleave1: 100 us    146           __buildin_avr_insert_bits    Mario M.   odd<->even vertauscht
// deinterleave3:  88 us    385(102+256)  even_odd-Tabelle mit union   Anja       ok

#include <inttypes.h>       // uint8_t
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/sfr_defs.h>   // bit_is_set
#include <util/delay.h>     // _delay_ms
#include <stdint.h>
#include <utility>
#include <array>
#include <tuple>

#if 0
const uint8_t even_odd_bits[] PROGMEM = {
    0,  1, 16, 17,  2,  3, 18, 19, 32, 33, 48, 49, 34, 35, 50, 51,
    4,  5, 20, 21,  6,  7, 22, 23, 36, 37, 52, 53, 38, 39, 54, 55,
    64, 65, 80, 81, 66, 67, 82, 83, 96, 97,112,113, 98, 99,114,115,
    68, 69, 84, 85, 70, 71, 86, 87,100,101,116,117,102,103,118,119,
    8,  9, 24, 25, 10, 11, 26, 27, 40, 41, 56, 57, 42, 43, 58, 59,
    12, 13, 28, 29, 14, 15, 30, 31, 44, 45, 60, 61, 46, 47, 62, 63,
    72, 73, 88, 89, 74, 75, 90, 91,104,105,120,121,106,107,122,123,
    76, 77, 92, 93, 78, 79, 94, 95,108,109,124,125,110,111,126,127,
    128,129,144,145,130,131,146,147,160,161,176,177,162,163,178,179,
    132,133,148,149,134,135,150,151,164,165,180,181,166,167,182,183,
    192,193,208,209,194,195,210,211,224,225,240,241,226,227,242,243,
    196,197,212,213,198,199,214,215,228,229,244,245,230,231,246,247,
    136,137,152,153,138,139,154,155,168,169,184,185,170,171,186,187,
    140,141,156,157,142,143,158,159,172,173,188,189,174,175,190,191,
    200,201,216,217,202,203,218,219,232,233,248,249,234,235,250,251,
    204,205,220,221,206,207,222,223,236,237,252,253,238,239,254,255
};

// Maske und Schleife
inline void deinterleave0( uint32_t in, uint16_t* odd_p, uint16_t* even_p)
{
    uint32_t mask = 0x80000000;
    uint16_t odd = 0;
    uint16_t even = 0;
    
    while( mask > 0)
    {
        even = even << 1;
        if(( mask & in) > 0)
        {
            even = even | 0x0001;
        }
        mask = mask >> 1;
        
        odd = odd << 1;
        if(( mask & in) > 0)
        {
            odd = odd | 0x0001;
        }
        mask = mask >> 1;
    }
    
    *odd_p  = odd;
    *even_p = even;
}


////////////////////////////////////////////////////////////
// __builtin_avr_insert_bits
inline void deinterleave1( uint32_t in, uint16_t* odd, uint16_t* even)
{
    uint8_t i0, i1, i2, i3, el, eh, ol, oh;
    
    i0 = in;
    i1 = in >> 8;
    i2 = in >> 16;
    i3 = in >> 24;
    
    el = __builtin_avr_insert_bits (0x88886420, i0, 0);
    el = __builtin_avr_insert_bits (0x6420ffff, i1, el);
    ol = __builtin_avr_insert_bits (0x88887531, i0, 0);
    ol = __builtin_avr_insert_bits (0x7531ffff, i1, ol);
    eh = __builtin_avr_insert_bits (0x88886420, i2, 0);
    eh = __builtin_avr_insert_bits (0x6420ffff, i3, eh);
    oh = __builtin_avr_insert_bits (0x88887531, i2, 0);
    oh = __builtin_avr_insert_bits (0x7531ffff, i3, oh);
    
    *even= oh << 8 | ol;
    *odd= eh << 8 | el;
}


////////////////////////////////////////////////////////////
// ausgerollte if,or Schleife
inline void deinterleave2( uint32_t in, uint16_t* odd_p, uint16_t* even_p)
{
    uint16_t odd = 0;
    uint16_t even = 0;
    
    if( in & 1UL<<0 ) odd |= 1UL<<0;
    if( in & 1UL<<1 ) even |= 1UL<<0;
    if( in & 1UL<<2 ) odd |= 1UL<<1;
    if( in & 1UL<<3 ) even |= 1UL<<1;
    
    if( in & 1UL<<4 ) odd |= 1UL<<2;
    if( in & 1UL<<5 ) even |= 1UL<<2;
    if( in & 1UL<<6 ) odd |= 1UL<<3;
    if( in & 1UL<<7 ) even |= 1UL<<3;
    
    
    if( in & 1UL<<8 ) odd |= 1UL<<4;
    if( in & 1UL<<9 ) even |= 1UL<<4;
    if( in & 1UL<<10 ) odd |= 1UL<<5;
    if( in & 1UL<<11 ) even |= 1UL<<5;
    
    if( in & 1UL<<12 ) odd |= 1UL<<6;
    if( in & 1UL<<13 ) even |= 1UL<<6;
    if( in & 1UL<<14 ) odd |= 1UL<<7;
    if( in & 1UL<<15 ) even |= 1UL<<7;
    
    if( in & 1UL<<16 ) odd |= 1UL<<8;
    if( in & 1UL<<17 ) even |= 1UL<<8;
    if( in & 1UL<<18 ) odd |= 1UL<<9;
    if( in & 1UL<<19 ) even |= 1UL<<9;
    
    if( in & 1UL<<20 ) odd |= 1UL<<10;
    if( in & 1UL<<21 ) even |= 1UL<<10;
    if( in & 1UL<<22 ) odd |= 1UL<<11;
    if( in & 1UL<<23 ) even |= 1UL<<11;
    
    if( in & 1UL<<24 ) odd |= 1UL<<12;
    if( in & 1UL<<25 ) even |= 1UL<<12;
    if( in & 1UL<<26 ) odd |= 1UL<<13;
    if( in & 1UL<<27 ) even |= 1UL<<13;
    
    if( in & 1UL<<28 ) odd |= 1UL<<14;
    if( in & 1UL<<29 ) even |= 1UL<<14;
    if( in & 1UL<<30 ) odd |= 1UL<<15;
    if( in & 1UL<<31 ) even |= 1UL<<15;
    *odd_p  = odd;
    *even_p = even;
}



// Tabelle mit Union
void deinterleave3( uint32_t in, volatile uint16_t* odd_p, volatile uint16_t* even_p) {
    union {
        uint8_t u8;
        struct {
            uint8_t a : 4;
            uint8_t b : 4;
        } s;
    } u8u4;
    union {
        uint16_t u16;
        struct {
            uint16_t a : 4;
            uint16_t b : 4;
            uint16_t c : 4;
            uint16_t d : 4;
        } s;
    } odd, even;
    
    union 
    {
        uint32_t u32;
        uint8_t  u8[4];
    } u32u8;
    
    u32u8.u32 = in;
    
    u8u4.u8 = even_odd_bits[ u32u8.u8[ 3]];
    even.s.d  = u8u4.s.b;
    odd.s.d   = u8u4.s.a;
    
    u8u4.u8 = even_odd_bits[ u32u8.u8[ 2]];
    even.s.c  = u8u4.s.b;
    odd.s.c   = u8u4.s.a;
    
    u8u4.u8 = even_odd_bits[ u32u8.u8[ 1]];
    even.s.b  = u8u4.s.b;
    odd.s.b   = u8u4.s.a;
    
    u8u4.u8 = even_odd_bits[ u32u8.u8[ 0]];
    even.s.a  = u8u4.s.b;
    odd.s.a   = u8u4.s.a;
    
    *odd_p  = odd.u16;
    *even_p = even.u16;
}

class U8U4 {
public:
    constexpr inline U8U4(uint8_t v = 0) : data{v}{}
    constexpr inline uint8_t high() const {
        return (data >> 4) & 0x0f;
    }
    constexpr inline void high(uint8_t v) {
        data = ((v << 4) & 0xf0) | (data & 0x0f);
    }
    constexpr inline uint8_t low() const {
        return data & 0x0f;
    }
    constexpr inline void low(uint8_t v) {
        data = (v & 0x0f) | (data & 0xf0);
    }
    constexpr inline uint8_t value() const {
        return data;
    }
private:
    uint8_t data{};
};

class U16U4 {
public:
    constexpr inline void d(uint8_t v) {
        high.high(v);
    }
    constexpr inline void c(uint8_t v) {
        high.low(v);
    }
    constexpr inline void b(uint8_t v) {
        low.high(v);
    }
    constexpr inline void a(uint8_t v) {
        low.low(v);
    }
    constexpr inline uint16_t value() const {
        return (high.value() << 8) + low.value(); 
    }
private:
    U8U4 high;
    U8U4 low;
};
#endif

#include <string.h>

#if 0
class U32U8 {
public:
    inline U32U8(uint32_t v) {
        //        memcpy(data, &v, sizeof(uint32_t)); // assumes little_endian, not constexpr
        const uint8_t* uv = reinterpret_cast<const uint8_t*>(&v); // not constexpr
        if constexpr(std::endian::native == std::endian::little) {
            data[0] = *uv++;
            data[1] = *uv++;
            data[2] = *uv++;
            data[3] = *uv;
        }
        else {
            data[3] = *uv++;
            data[2] = *uv++;
            data[1] = *uv++;
            data[0] = *uv;
        }
        //        data[0] = v & 0xff; // endian-neutral code -> bigger
        //        v >>= 8;
        //        data[1] = v & 0xff;
        //        v >>= 8;
        //        data[2] = v & 0xff;
        //        v >>= 8;
        //        data[3] = v & 0xff;
    }
    inline uint8_t operator[](uint8_t i) const {
        return data[i];
    }
private:
    uint8_t data[4]{};
};


// Tabelle mit Union
void deinterleave6(uint32_t in, volatile uint16_t* odd_p, volatile uint16_t* even_p) {
    U16U4 odd, even;
    U32U8 u32u8 = in;
    U8U4 u8u4 = even_odd_bits[u32u8[3]];
    
    even.d(u8u4.high());
    odd.d(u8u4.low());
    
    u8u4 = even_odd_bits[u32u8[2]];
    even.c(u8u4.high());
    odd.c(u8u4.low());
    
    u8u4 = even_odd_bits[u32u8[1]];
    even.b(u8u4.high());
    odd.b(u8u4.low());
    
    u8u4 = even_odd_bits[u32u8[0]];
    even.a(u8u4.high());
    odd.a(u8u4.low());
    *odd_p  = odd.value();
    *even_p = even.value();
}

// portabel
inline uint16_t packeven(uint32_t x)
{                       
    x &= 0x55555555;    
    x |= x>>1;          
    x &= 0x33333333;    
    x |= x>>2;          
    x &= 0x0f0f0f0f;    
    x |= x>>4;          
    x &= 0x00ff00ff;    
    x |= x>>8;          
    return x;
}

inline void deinterleave4(uint32_t x, uint16_t *odd, uint16_t *even)
{
    *odd = packeven(x);
    *even = packeven(x>>1);
}

// Tabelle mit Bit-Shifts
inline void deinterleave5( uint32_t in, volatile uint16_t* odd_p, volatile uint16_t* even_p)
{
    uint16_t odd;
    uint16_t even;
    uint8_t nibble;
    
    nibble = even_odd_bits[ (uint8_t)(in >> 24)];
    even  = (nibble & 0xf0) << 8;
    odd   = (nibble & 0x0f) << 12;
    
    nibble = even_odd_bits[ (uint8_t)(in >> 16)];
    even  |= (nibble & 0xf0) <<  4;
    odd   |= (nibble & 0x0f) <<  8;
    
    nibble = even_odd_bits[ (uint8_t)(in >>  8)];
    even  |= (nibble & 0xf0) << 0;
    odd   |= (nibble & 0x0f) << 4;
    
    nibble = even_odd_bits[ (uint8_t)(in)];
    even  |= (nibble & 0xf0) >> 4;
    odd   |= (nibble & 0x0f) << 0;
    
    *odd_p  = odd;
    *even_p = even;
}
#endif

inline void* operator new(size_t, void* __p) throw() { return __p; }
inline void* operator new[](size_t, void* __p) throw() { return __p; }

struct LittleEndian {};
struct BigEndian {};

typedef typename std::conditional<(std::endian::native == std::endian::little), LittleEndian, BigEndian>::type endian_type;

struct ByteToIntegral{};
struct IntegralToByte{};

template<typename Dir, typename T> struct ByteUnion;

template<typename T>
struct ByteUnion<IntegralToByte, T> {
    static_assert(sizeof(std::byte) == 1);
    static_assert(std::is_same<uint64_t, T>::value || std::is_same<uint32_t, T>::value || std::is_same<uint16_t, T>::value, "use a primitive type uint16|32|64_t");
    static_assert(sizeof(T) > 1, "use from-type bigger than 1 byte");
public:
    explicit ByteUnion(const T& v) : ByteUnion{std::make_index_sequence<sizeof(T)>{}, v} {}
    explicit ByteUnion(const volatile T& v) : ByteUnion{std::make_index_sequence<sizeof(T)>{}, v} {}
    
    std::byte operator[](uint8_t i) const {
        if constexpr(std::endian::native == std::endian::little) {
            return b[i];
        }
        else {
            return b[sizeof(T) - 1 - i];
        }
    }
private:
    template<size_t... II>
    explicit ByteUnion(std::index_sequence<II...>, const T& v) {
        const std::byte* pv = reinterpret_cast<const std::byte*>(&v);
        ((b[II] = std::byte{pv[II]}),...);
    }
    template<size_t... II>
    explicit ByteUnion(std::index_sequence<II...>, const volatile T& v) {
        T buffer{v};
        const std::byte* pv = reinterpret_cast<const std::byte*>(&buffer);
        ((b[II] = std::byte{pv[II]}),...);
    }

    std::byte b[sizeof(T)];
};

template<typename T>
struct ByteUnion<ByteToIntegral, T> {
    static_assert(sizeof(std::byte) == 1);
    static_assert(std::is_same<uint64_t, T>::value || std::is_same<uint32_t, T>::value || std::is_same<uint16_t, T>::value, "use a primitive type uint16|32|64_t");
    static_assert(sizeof(T) > 1, "use to-type bigger than 1 byte");
public:
    template<typename... B>
    requires (std::is_same<B, std::byte>::value || ...) && (sizeof...(B) == sizeof(T))
    explicit ByteUnion(B... vv) : ByteUnion{endian_type{}, std::index_sequence_for<B...>{}, vv...} {}
    
    const T& value() const {return a;}     
private:
    template<size_t... II, typename... B>
    explicit ByteUnion(BigEndian, std::index_sequence<II...>, B&&... vv) {
        uint8_t* p = reinterpret_cast<uint8_t*>(&a);
        ((p[II] = static_cast<uint8_t>(vv)),...);
    }
    template<size_t... II, typename... B>
    explicit ByteUnion(LittleEndian, std::index_sequence<II...>, B&&... vv) {
        uint8_t* p = reinterpret_cast<uint8_t*>(&a);
        ((p[sizeof...(II) - 1 - II] = static_cast<uint8_t>(vv)),...);    
    }
    T a;
};

using namespace std::literals;

volatile uint64_t vx{0x01020304};

volatile std::byte b1 = 0x01_byte;
volatile std::byte b2 = 0x02_byte;
volatile std::byte b3 = 0x03_byte;
volatile std::byte b4 = 0x04_byte;

int main(){
    ByteUnion<IntegralToByte, uint64_t> u1{vx};
//    ByteUnion<ByteToIntegral, uint32_t> u2{b1, b2, b3, b4};

    
    //    ByteUnion<IntegralToByte, uint64_t> u1{0x01020304};
    return std::to_integer<uint8_t>(u1[0]);    
//    u1.value();
    
//    ByteUnion<ByteToIntegral, uint32_t> u2{0x01_byte, 0x02_byte, 0x03_byte, 0x04_byte};
//    return u2.value(); 
    
//    u2[0];
}
    
