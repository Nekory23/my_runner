x/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** main
*/

#include "runner.h"

int main(int ac, char **av)
{
    int error = error_handling(ac, av);

    if (error != TRUE)
        return (error);
    if (compare_str(av[1], "-i"))
        runner();
    else {
        write(2, ERROR_ARG, my_strlen(ERROR_ARG));
        return (ERROR);
    }
    return (0);
}
