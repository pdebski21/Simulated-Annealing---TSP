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

double tsp(std::vector<int> path, Graph &graph)
{
    int res = 0;
    for (int i = 1; i < path.size(); i++)
    {
        res += graph.at(path[i - 1], path[i]);
    }
    return res;
}

std::vector<int> new_path(std::vector<int> &path)
{
    std::vector<int> shuffled_path(path);
    int swap_idx = rand() % (path.size() - 1);
    std::iter_swap((shuffled_path.begin() + swap_idx), (shuffled_path.begin() + swap_idx + 1));
    return shuffled_path;
}

int simulated_anneling(State &state, Params &params, Graph &graph)
{
    std::vector<int> init_path(graph.getVertexCount());
    std::iota(std::begin(init_path), std::end(init_path), 0);
    state.update(params.get_t_max(), 0, tsp(init_path, graph), init_path);

    std::vector<int> next_path;
    double random;
    srand(time(NULL));
    while (continue_optimalization(state, params))
    {
        next_path = new_path(state.get_path());
        random = (rand() % 101) / 100;

        if (random < move_propability(state.get_t_curr(), state.get_t_tsp(), tsp(next_path, graph)))
        {
            state.set_path(next_path);
            state.set_t_tsp(tsp(next_path, graph));
        }
        state.set_t_curr(decrease_temperature_dependent(state.get_t_curr(), params));
        state.set_iter(1 + state.get_iter());
        //state.show();
        //state.show_path();
    }
    std::cout << "Simulated anneling solution: " << std::endl;
    state.show_path();
    state.show();
}