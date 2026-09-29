#include <cstdint>
#include <coroutine>
#include <memory>
#include <utility>
#include <iostream>
#include <array>

template<typename T>
struct async_generator {
    void process(std::byte b) {
    }
    struct promise_type {
        struct awaiter {
            awaiter(const T& v) : v{v}{
            } 
            bool await_ready() { 
                std::cout << __PRETTY_FUNCTION__ << '\n';
                return false; 
            }
            void await_suspend(std::coroutine_handle<>) {
                std::cout << __PRETTY_FUNCTION__ << '\n';
            }
            T await_resume() {
                std::cout << __PRETTY_FUNCTION__ << '\n';
                return v;
            }
            const T& v;
        };
        
        awaiter await_transform(T) {
            std::cout << __PRETTY_FUNCTION__ << '\n';
            return awaiter{val_};
        }
        
        async_generator get_return_object() {
            std::cout << __PRETTY_FUNCTION__ << '\n';
            return {std::coroutine_handle<promise_type>::from_promise(*this)}; 
        }
        
        std::suspend_never initial_suspend() {
            std::cout << __PRETTY_FUNCTION__ << '\n';
            return {}; 
        }
        std::suspend_never final_suspend() noexcept {         
            std::cout << __PRETTY_FUNCTION__ << '\n';
            return {}; 
        }
//        std::suspend_always yield_value(T value){
//            std::cout << __PRETTY_FUNCTION__ << '\n';
//            val_ = value;
//            return {};
//        }
        
        void unhandled_exception() {
            std::cout << __PRETTY_FUNCTION__ << '\n';
        }
        
        void return_void() {
            std::cout << __PRETTY_FUNCTION__ << '\n';
        }
    private:
        T val_;
    };
    auto& handle() const {
        std::cout << __PRETTY_FUNCTION__ << '\n';        
        return co_handle;
    }
    ~async_generator() {
        std::cout << __PRETTY_FUNCTION__ << '\n';
        co_handle.destroy();
    }
private:
    async_generator(std::coroutine_handle<promise_type> h) : co_handle{h}{
        std::cout << __PRETTY_FUNCTION__ << '\n';
    } 
    std::coroutine_handle<promise_type> co_handle; 
};


struct Analyzer {
    using FSM = async_generator<std::byte>;
    
    void process(std::byte b) {
        std::cout << __PRETTY_FUNCTION__ << '\n';
        fsm.process(b);
        fsm.handle().resume();
    }
    
    FSM analyze() {
        while(true) {
            std::cout << __PRETTY_FUNCTION__ << "A\n";
            auto b1 = co_await std::byte{};
            std::cout << __PRETTY_FUNCTION__ << "B\n";
            auto b2 = co_await std::byte{};
            std::cout << __PRETTY_FUNCTION__ << "C\n";
        }
    }
    
    FSM fsm = analyze();
};


int main() {
    std::array<std::byte, 10> data{std::byte{0x55}};

    Analyzer analyzer;
    
    for(const auto& b : data) {
        std::cout << __PRETTY_FUNCTION__ << '\n';
        analyzer.process(b);
    }    
}
