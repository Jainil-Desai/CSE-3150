#ifndef TIMED_SHARED_PTR_HPP
#define TIMED_SHARED_PTR_HPP

#include <chrono>
#include <climits>
#include <iostream>

using Clock = std::chrono::high_resolution_clock;
using clockTime = std::chrono::time_point<Clock>;
using milliSeconds = std::chrono::milliseconds;

struct ControlTimedSharedPtr {
    void* ptr;
    long myUseCount;
    clockTime startTime;
    milliSeconds expiry;

    ControlTimedSharedPtr(void* p, long expiryMs)
        : ptr(p), myUseCount(1),
          startTime(Clock::now()),
          expiry(milliSeconds{expiryMs}) {
        std::cout << "ControlTimedSharedPtr " << ptr << " start: 0 ms\n";
    }

    ~ControlTimedSharedPtr() {
        auto elapsed = std::chrono::duration_cast<milliSeconds>(Clock::now() - startTime).count();
        std::cout << "ControlTimedSharedPtr " << ptr << " end: " << elapsed << " ms\n";
    }
};

template<typename T>
class TimedSharedPtr {
private:
    ControlTimedSharedPtr* _ctrl;

    milliSeconds elapsedMs() const {
        if (!_ctrl) return milliSeconds{LONG_MAX};
        return std::chrono::duration_cast<milliSeconds>(Clock::now() - _ctrl->startTime);
    }

public:
    TimedSharedPtr() noexcept : _ctrl(nullptr) {}

    TimedSharedPtr(T* raw, long expiryMs)
        : _ctrl(new ControlTimedSharedPtr(raw, expiryMs)) {}

    TimedSharedPtr(const TimedSharedPtr& other) noexcept : _ctrl(other._ctrl) {
        if (_ctrl) ++_ctrl->myUseCount;
    }

    TimedSharedPtr& operator=(const TimedSharedPtr& other) {
        if (this != &other) {
            release();
            _ctrl = other._ctrl;
            if (_ctrl) ++_ctrl->myUseCount;
        }
        return *this;
    }

    ~TimedSharedPtr() {
        release();
    }

    void release() {
        if (_ctrl && --_ctrl->myUseCount == 0) {
            delete static_cast<T*>(_ctrl->ptr);
            delete _ctrl;
        }
    }

    T* get() const {
        if (!_ctrl || elapsedMs() > _ctrl->expiry)
            return nullptr;
        return static_cast<T*>(_ctrl->ptr);
    }

    long use_count() const {
        return _ctrl ? _ctrl->myUseCount : 0;
    }

    bool expired() const {
        return !_ctrl || elapsedMs() > _ctrl->expiry;
    }

    explicit operator bool() const {
        return get() != nullptr;
    }

    long elapsed() const {
        return elapsedMs().count();
    }
};

#endif
