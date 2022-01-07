#include "simulated_anneling.hpp"

int objective()
{
}

bool continue_optimalization(State &state, Params &params)
{
    return state.get_t_curr() > params.get_t_min() && state.get_iter() < params.get_max_iter();
    //std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count() < 10000000;
}

double move_propability(double t_curr, int optimal_solution, int alternative_solution)
{
    return std::min<double>(1, exp(-(alternative_solution - optimal_solution) / t_curr));
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

std::vector<int> discover_neighborhood(int neighbor_cnt, std::vector<int> &path, Graph &graph)
{
    std::vector<int> shuffled_path(path);
    std::vector<int> best_neighbor_path(path);
    int best_tsp, next_tsp, swap_idx;
    best_tsp = tsp(best_neighbor_path, graph);

    for (int i = 0; i < neighbor_cnt; i++)
    {
        swap_idx = rand() % (path.size() - 1);
        std::iter_swap((shuffled_path.begin() + swap_idx), (shuffled_path.begin() + swap_idx + 1));
        next_tsp = tsp(shuffled_path, graph);
        if (best_tsp > next_tsp)
        {
            best_neighbor_path = shuffled_path;
            best_tsp = next_tsp;
        }
    }
    return best_neighbor_path;
}

int simulated_anneling(State &state, Params &params, Graph &graph)
{
    std::vector<int> init_path(graph.getVertexCount());
    std::iota(std::begin(init_path), std::end(init_path), 0);
    std::random_shuffle(init_path.begin(), init_path.end());
    state.update(params.get_t_max(), 0, INT_MAX, init_path);
    int global_tsp = INT_MAX;
    std::vector<int> globla_path;
    std::vector<int> next_path;
    int next_tsp;
    double random;
    srand(time(NULL));

    while (continue_optimalization(state, params))
    {
        next_path = new_path(state.get_path());
        next_tsp = tsp(next_path, graph);

        if (next_tsp < state.get_t_tsp())
        {
            state.set_path(next_path);
            state.set_t_tsp(next_tsp);
        }
        else
        {
            random = (rand() % 101) / 100;
            if (random < move_propability(state.get_t_curr(), state.get_t_tsp(), next_tsp))
            {
                state.set_path(next_path);
                state.set_t_tsp(next_tsp);
            }
        }
        state.set_t_curr(decrease_temperature_dependent(state.get_t_curr(), params));
        state.inc_iter();
        if (state.get_t_tsp() < global_tsp)
        {
            // epochs - upgrades of global minimum path
            global_tsp = state.get_t_tsp();
            globla_path = next_path;
            state.show_path();
            state.show();
        }
    }
    std::cout << "Simulated anneling solution: " << global_tsp << std::endl;
    return global_tsp;
}