#include "menu.hpp"

void menu()
{

    std::unique_ptr<Graph> graph;
    Params params;
    State state;
    std::string fileName;


    int control = -1;
    std::cout << "1) read data from file" << std::endl;
    std::cout << "2) set stop criterion" << std::endl;
    std::cout << "3) run algorithm with loaded data and parameters" << std::endl;

    std::cin >> control;

    switch (control)
    {
    case 1:
        std::cin >> fileName;
        graph = read_graph_file(fileName);
        graph->show();
        break;
    case 2:
        std::cout << "2) set stop criterion" << std::endl;
        params.setParams();
        params.showParams();
        break;
    case 3:
        std::cout << "3) run algorithm with loaded data and parameters" << std::endl;
        break;
    default:
        std::cout << "Wrong menu option" << std::endl;
        break;
    }
}