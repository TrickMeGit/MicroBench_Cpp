#include <iostream>
#include <chrono>

// add includes & namespaces for bench:


// add variables for bench:


// add functions for bench:

void func1() {}         // demo function

void func2() {}         // demo function


int main() {
    // set run repetitions:
    const int64_t RUNS = 65536;

    std::chrono::_V2::system_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::chrono::_V2::system_clock::time_point end = std::chrono::high_resolution_clock::now();
    float first;
    float second;

    // add local variables for bench:

    int64_t a = 0;


    start = std::chrono::high_resolution_clock::now();
    for (int64_t run = 0; run < RUNS; run++) {
        // 1st run

        a++;
        // a += 1;          // reverse test

        // bench functions
        func1();
        // func2();          // reverse test
    }
    end = std::chrono::high_resolution_clock::now();
    first = (float)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    // reset bench variables:

    a = 0;


    start = std::chrono::high_resolution_clock::now();
    for (int64_t run = 0; run < RUNS; run++) {
        // 2nd run

        a += 1;
        // a++;             // reverse test

        // bench functions
        func2();
        // func1();          // reverse test
    }
    end = std::chrono::high_resolution_clock::now();
    second = (float)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    // print result nanoseconds
    // std::cout << "1st run: " << first / (float)RUNS << " ns" << std::endl;
    // std::cout << "2nd run: " << second / (float)RUNS << " ns" << std::endl;

    // print result microseconds
    std::cout << "1st run: " << first / (float)RUNS / 1000.0f << " µs" << std::endl;
    std::cout << "2nd run: " << second / (float)RUNS / 1000.0f << " µs" << std::endl;

    // print result milliseconds
    // std::cout << "1st run: " << first / (float)RUNS / 1.0e6f << " ms" << std::endl;
    // std::cout << "2nd run: " << second / (float)RUNS / 1.0e6f << " ms" << std::endl;

    // print result seconds
    // std::cout << "1st run: " << first / (float)RUNS / 1.0e9f << " s" << std::endl;
    // std::cout << "2nd run: " << second / (float)RUNS / 1.0e9f << " s" << std::endl;
}
