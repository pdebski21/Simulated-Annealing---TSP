#ifndef SIMULATED_ANNELING
#define SIMULATED_ANNELING

#include "params.hpp"
#include "Graph.hpp"
#include <algorithm>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>

bool continue_optimalization(State &state, Params &params, std::chrono::time_point<std::chrono::system_clock> starttime);
double move_propability(double t_curr, int optimal_solution, int alternative_solution);
bool try_move(State &state, double propability);
double decrease_temperature_const(double &t_curr, double alfa);
double decrease_temperature_dependent(double &t_curr, Params &params, State &state);
int tsp(std::vector<int> path, Graph &graph);
std::vector<int> new_path(std::vector<int> &path);
int simulated_anneling(State &state, Params &params, Graph &graph);

#endif