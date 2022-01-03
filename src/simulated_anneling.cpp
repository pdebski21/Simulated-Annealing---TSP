#include "simulated_anneling.hpp"

int objective()
{
}

bool continue_optimalization(State &state, Params &params)
{
    return state.get_iter() < params.get_max_iter() && state.get_t_curr() > params.get_t_min();
}

double move_propability(double t_curr, int optimal_solution, int alternative_solution)
{
    return std::min<double>(1, exp(-(optimal_solution - alternative_solution) / t_curr));
}

bool try_move(State &state, double propability)
{

    srand(time(NULL));
}

double decrease_temperature_const(double &t_curr, double alfa)
{
    return alfa * t_curr;
}

double decrease_temperature_dependent(double &t_curr, Params params)
{
    double beta = (params.get_t_max() - params.get_t_min()) / (params.get_max_iter() * params.get_t_max() * params.get_t_min());
    return t_curr / (1 + beta * t_curr);
}

int simulated_anneling(State &state, Params &params)
{
    while (continue_optimalization(state, params))
    {

        //move_propability();
        //try_move();
    }
}