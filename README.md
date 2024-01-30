# Stopwatch

```cpp
#include "Stopwatch.hpp"

#include <cstdio>
#include <thread>

void f(int duration) {
    std::printf("%s\n", __PRETTY_FUNCTION__);
    std::this_thread::sleep_for(std::chrono::seconds(duration));
}

int main() {
    Stopwatch stopwatch;

    stopwatch.start();
    f(1);
    stopwatch.stop();
    std::printf("stopwatch.total() = %lf ms\n", stopwatch.total());

    stopwatch.start();
    f(2);
    stopwatch.stop();
    std::printf("stopwatch.total() = %lf ms\n", stopwatch.total());

    stopwatch.start();
    f(3);
    stopwatch.stop();
    std::printf("stopwatch.total() = %lf ms\n", stopwatch.total());

    std::printf("stopwatch.restart()\n");
    stopwatch.restart();
    f(1);
    stopwatch.stop();
    std::printf("stopwatch.total() = %lf ms\n", stopwatch.total());
}
```
