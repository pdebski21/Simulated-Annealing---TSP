#include "params.hpp"

/** Params */

Params::Params(double _t_max, double _t_min, double _step, double _alfa, int _max_iter) : t_max(_t_max), t_min(_t_min), step(_step), alfa(_alfa), max_iter(_max_iter)
{
}

void Params::setParams()
{
    std::cout << "enter simulated anneling parameters" << std::endl;
    std::cout << "t_max:" << std::endl;
    std::cin >> t_max;
    std::cout << "t_min:" << std::endl;
    std::cin >> t_min;
    std::cout << "step:" << std::endl;
    std::cin >> step;
    std::cout << "alfa:" << std::endl;
    std::cin >> alfa;
    std::cout << "max_iter:" << std::endl;
    std::cin >> max_iter;
}

void Params::showParams()
{
    std::cout << "simulated anneling parameters" << std::endl;
    std::cout << "t_max: " << t_max << std::endl;
    std::cout << "t_min :" << t_min << std::endl;
    std::cout << "step :" << step << std::endl;
    std::cout << "alfa :" << alfa << std::endl;
    std::cout << "max_iter :" << max_iter << std::endl;
}

/** State */

State::State() {}

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
