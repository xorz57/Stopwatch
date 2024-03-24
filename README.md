# Stopwatch

## Example

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

    std::printf("stopwatch.total() = %lf ms\n", stopwatch.total()); // Not measured

    stopwatch.start();
    f(2);
    stopwatch.stop();

    std::printf("stopwatch.total() = %lf ms\n", stopwatch.total()); // Not measured

    stopwatch.start();
    f(3);
    stopwatch.stop();

    std::printf("stopwatch.total() = %lf ms\n", stopwatch.total()); // Not measured

    stopwatch.restart();
    f(1);
    stopwatch.stop();

    std::printf("stopwatch.total() = %lf ms\n", stopwatch.total()); // Not measured
}
```

## Output

```console
void f(int)
stopwatch.total() = 1000.089782 ms
void f(int)
stopwatch.total() = 3000.150913 ms
void f(int)
stopwatch.total() = 6000.231520 ms
void f(int)
stopwatch.total() = 1000.075934 ms
```
