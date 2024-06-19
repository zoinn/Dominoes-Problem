#include "DominoesProblemHeader.h"

class Timer
{
public:
    Timer()
    {
        startTime = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        stop();
    }

    void stop()
    {
        auto endTime = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTime).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration / 1000;


        std::cout << duration << "us (" << ms << "ms)\n";

    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};

int main(int argc ,char* argv[]) {
    {
        Timer Timer;
        averageCaseFullRun(argv[1],argv[2]);
    }
    {
        Timer Timer;
        worstCaseFullRun(argv[1],argv[2]);
    }
    {
        Timer Timer;
        convolutedFullRun(argv[1],argv[2]);
    }
    return 0;
}