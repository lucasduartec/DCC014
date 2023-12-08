#ifndef PERF_H
#define PERF_H

#include <chrono>

namespace Perf
{
    // Classe para medir o tempo de execução de um algoritmo
    class PerformanceTimer
    {
    public:
        PerformanceTimer();
        void start();
        void stop();
        double elapsed_time();

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
        std::chrono::time_point<std::chrono::high_resolution_clock> end_time;
        bool running;
    };

    class PerformanceCounter
    {
    public:
        PerformanceCounter();
        void increment_comparisons();
        void increment_swaps();
        unsigned int get_comparisons();
        unsigned int get_swaps();

    private:
        unsigned long int n_comparisons;
        unsigned long int n_swaps;
    };

    class Performance
    {
    public:
        Performance();
        PerformanceCounter &get_counter();
        PerformanceTimer &get_timer();

    private:
        PerformanceTimer timer;
        PerformanceCounter counter;
    };

    PerformanceTimer::PerformanceTimer()
    {
        running = false;
    }

    void PerformanceTimer::start()
    {
        start_time = std::chrono::high_resolution_clock::now();
        running = true;
    }

    void PerformanceTimer::stop()
    {
        end_time = std::chrono::high_resolution_clock::now();
        running = false;
    }

    double PerformanceTimer::elapsed_time()
    {
        std::chrono::duration<double> elapsed_seconds;
        if(running)
        {
            elapsed_seconds = std::chrono::high_resolution_clock::now() - start_time;
        }
        else
        {
            elapsed_seconds = end_time - start_time;
        }
        return elapsed_seconds.count();
    }

    PerformanceCounter::PerformanceCounter():
        n_comparisons(0),
        n_swaps(0)
    {
    }

    void PerformanceCounter::increment_comparisons()
    {
        n_comparisons++;
    }

    void PerformanceCounter::increment_swaps()
    {
        n_swaps++;
    }

    unsigned int PerformanceCounter::get_comparisons()
    {
        return n_comparisons;
    }

    unsigned int PerformanceCounter::get_swaps()
    {
        return n_swaps;
    }

    Performance::Performance():
        timer(),
        counter()
    {
    }

    PerformanceCounter& Performance::get_counter()
    {
        return counter;
    }

    PerformanceTimer& Performance::get_timer()
    {
        return timer;
    }

} // namespace Perf

#endif /* PERF_H */
