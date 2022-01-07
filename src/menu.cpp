#include "menu.hpp"

void menu()
{

    std::unique_ptr<Graph> graph;
    Params params;
    State state;
    std::string fileName;

    int control = -1;
    bool loop = true;
    int test_iter = 0;

    while (loop)
    {
        std::cout << "1) read data from file" << std::endl;
        std::cout << "2) set stop criterion" << std::endl;
        std::cout << "3) run algorithm with loaded data and parameters" << std::endl;
        std::cout << "4) run algorithm with loaded data and parameters and measure time" << std::endl;
        std::cout << "5) exit" << std::endl;

        std::cin >> control;
        switch (control)
        {
        case 1:
            std::cin >> fileName;
            graph = read_graph_file(fileName);
            graph->show();
            break;
        case 2:
            params.setParams();
            params.showParams();
            break;
        case 3:
            simulated_anneling(state, params, *graph);
            break;
        case 4:
            std::cout << "enter test iteration count:" << std::endl;
            std::cin >> test_iter;
            test_sa(test_iter, state, params, *graph);
            break;
        case 5:
            loop = false;
            break;
        default:
            std::cout << "Wrong menu option" << std::endl;
            break;
        }
    }
}