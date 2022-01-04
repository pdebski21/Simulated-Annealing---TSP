#ifndef PARAMS
#define PARAMS

#include <iostream>
#include <vector>

class Params
{
private:
    double t_max;
    double t_min;
    double step;
    double alfa;
    int max_iter;

public:
    Params(){};
    Params(double _t_max, double _t_min, double _step, double _alfa, int max_iter);
    void setParams();
    void showParams();
    double &get_t_max() { return t_max; }
    double &get_t_min() { return t_min; }
    double &get_step() { return step; }
    double &get_alfa() { return alfa; }
    int &get_max_iter() { return max_iter; }
};

class State
{
private:
    double t_curr;
    int iter;
    int tsp;
    std::vector<int> path;

public:
    State();
    State(double _t_curr, int _iter, int _tsp, std::vector<int> _path);
    void update(double _t_curr, int _iter, int _tsp, std::vector<int> _path);
    void show();
    void show_path();

    double &get_t_curr() { return t_curr; }
    int &get_iter() { return iter; }
    int &get_t_tsp() { return tsp; }
    std::vector<int> &get_path() { return path; }
    void set_path(std::vector<int> &_path) { path = _path; }
    void set_iter(int _iter) { iter = _iter; }
    void set_t_curr(double _t_curr) { t_curr = _t_curr; }
    void set_t_tsp(int _tsp) { tsp = _tsp; }
};

#endif