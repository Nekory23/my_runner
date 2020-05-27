/*
** EPITECH PROJECT, 2019
** my_screensaver
** File description:
** help display
*/

#include "runner.h"

void help_display(void)
{
    my_putstr("infinite runner created with CSFML.\n\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_runner [option]\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("  -h\t\tprint the usage and quit.\n");
    my_putstr("  -i\t\tlaunch the game in infinity mode\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  SPACE_KEY\tjump.\n");
}
