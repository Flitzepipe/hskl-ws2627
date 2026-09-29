#include <pthread.h>

// Mist
// nach: https://erdani.org/publications/cuj-02-2001.php.html

class Mutex final {
public:
    void lock() volatile {
        pthread_mutex_lock(const_cast<pthread_mutex_t*>(&m));
    }
private:
    pthread_mutex_t m;
};

class SHM final {
public:
    void set(const int v) volatile {
        mMutex.lock();
        mData = v;
    }
private:
    int mData{0}; // Ist damit auch `volatile`
    mutable Mutex mMutex;
};

static volatile SHM shm;
static SHM normal;

int main() {
    shm.set(42);   
    
    normal.set(42);
}
