#include <string>
#include <vector>
#include <utility>
#include <memory>

struct File {
    File() : mId{mNextSerialNumber++} {}
private:
    size_t mId{0};
    inline static size_t mNextSerialNumber{1};
};

struct Directory : public File {
    
    Directory& operator+=(std::unique_ptr<File> f) {
    }
private:
    std::vector<std::pair<std::string, std::unique_ptr<File>>> mEntries;
};

int main() {
    auto f = std::make_unique<File>();
    
    Directory d;
    
    d += (std::move(f));
}
