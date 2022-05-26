#include <roapi.h>
#include <iostream>

struct WinRt {
public:
    WinRt()
    {
        winRt_ = LoadLibraryA("api-ms-win-core-winrt-l1-1-0.dll");
        if (winRt_ == nullptr) {
            return;
        }
        auto roInitialize = reinterpret_cast<decltype(&::RoInitialize)>(GetProcAddress(winRt_, "RoInitialize"));

        if (!SUCCEEDED(roInitialize(RO_INIT_MULTITHREADED))) {
            std::cout << "Initialize failed" << std::endl;
            FreeLibrary(winRt_);
            winRt_ = nullptr;
            return;
        }

        std::cout << "Initialized" << std::endl;
    }

private:
    HMODULE winRt_{ nullptr };
};

int main()
{
    WinRt winRt;
    // requires runtimeobject.lib link
//    RoInitialize(RO_INIT_TYPE::RO_INIT_MULTITHREADED);
}