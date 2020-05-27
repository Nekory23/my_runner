/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** error_handling
*/

#include "runner.h"

int error_handling(int ac, char **av)
{
    if (ac != 2) {
        write(2, ERROR_ARG, my_strlen(ERROR_ARG));
        return (ERROR);
    }
    if (compare_str(av[1], "-h")) {
        help_display();
        return (FALSE);
    }
    return (TRUE);
}
