#include <iostream>
#include <functional>
#include <type_traits>

struct BaseType_t {
    virtual ~BaseType_t () = default;
};
struct TypeA_t:BaseType_t {
    int value = 123;
};
struct TypeB_t:BaseType_t {
    double value = 123.321;
};

struct Test_t {
    void OnTypeA (const TypeA_t & type) {
        std::cout << "OnTypeA! value: " << type.value << std::endl;
    } 
    
    void OnTypeB (const TypeB_t & type) {
        std::cout << "OnTypeB! value: " << type.value << std::endl;
    } 
    template<typename BT>
    void OnType (const BT* base_type) {
        if constexpr(std::is_same_v<BT, TypeA_t>) {
            OnTypeA(*base_type);
        }       
        if constexpr(std::is_same_v<BT, TypeB_t>) {
            OnTypeB(*base_type);
        }       
    }
    
    void OnType2(const BaseType_t* p) {
//        p->value;   
    }
};

int main () 
{
    Test_t t;
    
    TypeA_t a;
    TypeB_t b;
    
    t.OnType(&a);
    t.OnType(&b);
    
    t.OnType2(&a);
    t.OnType2(&b);
} 
