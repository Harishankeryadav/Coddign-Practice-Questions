// TimeClock

// -- essential_libraries_and_namespace
#include <iostream>
// using namespace std;

// -- additional_libraries -- Imported From Custom BoilerPlate -=- Azure
// #include <vector>
// #include <algorithm>
// #include <array>
// #include <unordered_map>
// #include <map>
// #include <set>

// -- Project Specific Dependencies
#include <chrono>

// Classes

class timer
{
public:
    timer()
    {
        m_startPoint = std::chrono::high_resolution_clock::now();
    }

    ~timer()
    {
        stop();
    }

    void stop()
    {
        auto endTimepoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startPoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.001;
        std::cout << "\n";
        std::cout << "\n";
        // std::cout << "\t-----------------------------------------------------------------\n";
        std::cout << "\t-----------------------------------------------\n";
        std::cout << "\tTime taken for Execution : " << duration << "us ( " << ms << "ms )\n";
        std::cout << "\t-----------------------------------------------\n";
        // std::cout << "\t--------------------------------------------------------\n";
        // std::cout << "\n";
        // std::cout << "\t-------------\n";
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startPoint;
};

// Functions