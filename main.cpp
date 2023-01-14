#include <iostream>
#include <chrono>

// set run repetitions
const int64_t RUNS = 65536;

void func1() {}     // demo function

void func2() {}     // demo function

int main() {
    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    float first = 0.0f;
    float second = 0.0f;

    // bench setup
    int64_t a = 0;
    // /bench setup

    start = std::chrono::high_resolution_clock::now();
    for (int64_t run = 0; run < RUNS; run++) {
        // 1st run

        a++;
        // a += 1;          // reverse test

        // bench function
        // func1();
        // func2();          // reverse test

    }   // /1st run
    end = std::chrono::high_resolution_clock::now();
    first = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / (float)RUNS;

    // reset bench setup
    a = 0;
    // /reset bench setup

    start = std::chrono::high_resolution_clock::now();
    for (int64_t run = 0; run < RUNS; run++) {
        // 2nd run

        a += 1;
        // a++;             // reverse test

        // bench function
        // func2();
        // func1();          // reverse test

    }   // /2nd run
    end = std::chrono::high_resolution_clock::now();
    second = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / (float)RUNS;

    // print result nanoseconds
    // std::cout << "1st run: " << first << " ns" << std::endl;
    // std::cout << "2nd run: " << second << " ns" << std::endl;

    // print result microseconds
    std::cout << "1st run: " << first / 1000.0f << " µs" << std::endl;
    std::cout << "2nd run: " << second / 1000.0f << " µs" << std::endl;

    // print result milliseconds
    // std::cout << "1st run: " << first / 1.0e6f << " ms" << std::endl;
    // std::cout << "2nd run: " << second / 1.0e6f << " ms" << std::endl;

    // print result seconds
    // std::cout << "1st run: " << first / 1.0e9f << " s" << std::endl;
    // std::cout << "2nd run: " << second / 1.0e9f << " s" << std::endl;
}
