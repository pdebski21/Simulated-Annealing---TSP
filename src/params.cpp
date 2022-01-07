#include "params.hpp"

/** Params */

Params::Params() : t_max(100000), t_min(1), max_iter(5000000)
{
}

Params::Params(double _t_max, double _t_min, double _step, double _alfa, int _max_iter) : t_max(_t_max), t_min(_t_min), step(_step), alfa(_alfa), max_iter(_max_iter)
{
}

void Params::setParams()
{
    std::cout << "enter simulated anneling parameters" << std::endl;
    std::cout << "t_max:" << std::endl;
    std::cin >> t_max;
    do
    {
        std::cout << "t_min: (t_min != 0)" << std::endl;
        std::cin >> t_min;
    } while (t_min == 0);
    std::cout << "max_iter:" << std::endl;
    std::cin >> max_iter;
    // std::cout << "epoch_count:" << std::endl;
    // std::cin >> epoch_count;
    // std::cout << "neighborhood_size:" << std::endl;
    // std::cin >> neighborhood_size;
}

void Params::showParams()
{
    std::cout << "simulated anneling parameters" << std::endl;
    std::cout << "t_max: " << t_max << std::endl;
    std::cout << "t_min :" << t_min << std::endl;
    // std::cout << "step :" << step << std::endl;
    // std::cout << "alfa :" << alfa << std::endl;
    std::cout << "max_iter :" << max_iter << std::endl;
}

/** State */

State::State()
{
}

State::State(double _t_curr, int _iter, int _tsp, std::vector<int> _path) : t_curr(_t_curr), iter(_iter), tsp(_tsp), path(_path)
{
}

void State::update(double _t_curr, int _iter, int _tsp, std::vector<int> _path)
{
    t_curr = _t_curr;
    iter = _iter;
    tsp = _tsp;
    path = _path;
}

void State::show()
{
    std::cout << "t_curr: " << t_curr << ", iter: " << iter << ", tsp: " << tsp << std::endl;
}

void State::show_path()
{
    std::cout << "path: { " << std::endl;
    for (auto p : path)
    {
        std::cout << p << ", ";
    }
    std::cout << "}" << std::endl;
}
