#include <cstdint>
#include <coroutine>
#include <memory>
#include <utility>
#include <iostream>

template<typename T>
struct Generator {
    // The class name 'Generator' is our choice and it is not required for coroutine magic.
    // Compiler recognizes coroutine by the presence of 'co_yield' keyword.
    // You can use name 'MyGenerator' (or any other name) instead as long as you include
    // nested struct promise_type with 'MyGenerator get_return_object()' method.
    // Note: You need to adjust class constructor/destructor names too when choosing to
    // rename class.
    
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;
    
    struct promise_type { // required
        T value_;
        std::exception_ptr exception_;
        
        Generator get_return_object() {
            return Generator(handle_type::from_promise(*this));
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void unhandled_exception() { 
            //        exception_ = std::current_exception(); 
        } // saving
        // exception
        
        template<std::convertible_to<T> From> // C++20 concept
        //    template<typename From> // C++20 concept
        std::suspend_always yield_value(From &&from) {
            value_ = std::forward<From>(from); // caching the result in promise
            return {};
        }
        void return_void() {}
    };
    
    handle_type h_;
    
    Generator(handle_type h) : h_(h) {}
    ~Generator() { h_.destroy(); }
    explicit operator bool() {
        fill(); // The only way to reliably find out whether or not we finished coroutine,
        // whether or not there is going to be a next value generated (co_yield) in
        // coroutine via C++ getter (operator () below) is to execute/resume coroutine
        // until the next co_yield point (or let it fall off end).
        // Then we store/cache result in promise to allow getter (operator() below to
        // grab it without executing coroutine).
        return !h_.done();
    }
    T operator()() {
        fill();
        full_ = false; // we are going to move out previously cached
        // result to make promise empty again
        return std::move(h_.promise().value_);
    }
    
private:
    bool full_ = false;
    
    
    void fill() {
        if (!full_) {
            h_();
            if (h_.promise().exception_)
                //        std::rethrow_exception(h_.promise().exception_);
                // propagate coroutine exception in called context
                
                full_ = true;
        }
    }
};

template<typename T>
struct ReturnObject {
    struct promise_type {
        T val_;
        ReturnObject get_return_object() {
            return {std::coroutine_handle<promise_type>::from_promise(*this)}; 
        }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        std::suspend_always yield_value(T value){
            val_ = value;
            return {};
        }
        void unhandled_exception() {}
//        void* operator new(size_t) {
        
//        }
    };
    
    std::coroutine_handle<promise_type> h_; 
    ReturnObject(std::coroutine_handle<promise_type> h) : h_{h}{ } 
    operator std::coroutine_handle<promise_type>() const { return h_; } 
    
    std::coroutine_handle<promise_type> handle() const {
        return h_;
    }
    
    T operator()() {
        h_();
        return std::move(h_.promise().val_);
    }
};


Generator<uint16_t> f() {
    uint16_t i{0};
    while (true) {
        co_yield i;
        ++i;
    }
}

ReturnObject<uint16_t> g() {
    uint16_t i{0};
    while (true) {
        co_yield i;
        ++i;
    }
}

int main() {
    auto h = f();
    for(uint8_t i{}; i < 10; ++i) {
        auto x = h();
        //    decltype(x)::_;
        std::cout << x << '\n';
    }
    
    auto h2 = g().handle();
    //    decltype(h2)::_;
    
    for(uint8_t i{}; i < 10; ++i) {
        auto x = h2.promise().val_;
        //    decltype(x)::_;
        std::cout << x << '\n';
        h2();
    }


    //    decltype(h2)::_;
    
    auto h3 = g();
    for(uint8_t i{}; i < 10; ++i) {
        auto x = h3();
        //    decltype(x)::_;
        std::cout << x << '\n';
        h2();
    }
}
