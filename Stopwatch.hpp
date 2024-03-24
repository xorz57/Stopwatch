#pragma once

#include <chrono>

class Stopwatch {
public:
    Stopwatch() : mTimePoint0(std::chrono::high_resolution_clock::now()),
                  mTimePoint1(std::chrono::high_resolution_clock::now()),
                  mTotal(std::chrono::duration<double, std::milli>::zero()) {}

    void start() {
        mTimePoint0 = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        mTimePoint1 = std::chrono::high_resolution_clock::now();
        mTotal += mTimePoint1 - mTimePoint0;
    }

    void restart() {
        mTimePoint0 = std::chrono::high_resolution_clock::now();
        mTimePoint1 = std::chrono::high_resolution_clock::now();
        mTotal = std::chrono::duration<double, std::milli>::zero();
    }

    double total() const {
        return mTotal.count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> mTimePoint0;
    std::chrono::time_point<std::chrono::high_resolution_clock> mTimePoint1;
    std::chrono::duration<double, std::milli> mTotal;
};
