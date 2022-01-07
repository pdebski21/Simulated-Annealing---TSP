#include "test_sa.hpp"

bool test_sa(int test_iter, State &state, Params &params, Graph &graph)
{
    int res, sum = 0, avg = 0;
    std::vector<int> results(test_iter);
    for (int iter = 0; iter < test_iter; iter++)
    {
        auto start = std::chrono::steady_clock::now();
        res = simulated_anneling(state, params, graph);
        auto end = std::chrono::steady_clock::now();
             sum += res;
        results[iter] = res;
        std::cout << "DURATION: "
                  << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
                  << " µs" << std::endl;
    }
    avg = sum / test_iter;
    std::cout << "average TSP result: " << avg << std::endl;
    std::cout << "all TSP results: {" << std::endl;
    for (auto result : results)
    {
        std::cout << result << ", ";
    }
    std::cout << std::endl;
    std::cout << "}" << std::endl;
}