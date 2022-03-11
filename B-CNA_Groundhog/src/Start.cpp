/*
** EPITECH PROJECT, 2021
** B-CNA_Groundhog
** File description:
** Start
*/

#include "Groundhog.hpp"
#include "Error.hpp"
#include <cstring>

static int display_help(const char *bin)
{
    std::cout << "SYNOPSIS" << std::endl;
    std::cout << "    " << bin << " period\n" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "    period\tthe number of days defining a period" << std::endl;
    return SUCCESS;
}

int start(const int ac, const char **av)
{
    int ret = SUCCESS;

    try {
        if (ac != 2)
            throw Error(std::cerr, "The number of arguments is invalid");
        if (strcmp(av[1], "-h") == 0)
            return display_help(av[0]);
        Groundhog g(av[1]);
        g.Loop();
    }
    catch (Error &e) {
        std::cerr << "Error: " << e.what() << " (retry with -h)" << std::endl;
        ret = ERROR;
    }
    catch (...) {}
    return ret;
}