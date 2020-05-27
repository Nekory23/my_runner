/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** my.h
*/

#ifndef __RUNNER_H__
#define __RUNNER_H__

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/Window/Keyboard.h>

typedef struct window_t {
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture;
    sfTexture *ground;
    sfTexture *ground2;
    sfTexture *ground3;
    sfTexture *ground4;
    sfTexture *b_ground;
    sfTexture *b_ground2;
    sfSprite *sprite;
    sfSprite *ground_s;
    sfSprite *ground_s2;
    sfSprite *ground_s3;
    sfSprite *ground_s4;
    sfSprite *b_ground_s;
    sfSprite *b_ground_s2;
    sfVector2f pos_ground;
    sfVector2f pos_ground2;
    sfVector2f pos_ground3;
    sfVector2f pos_ground4;
    sfVector2f pos_b_ground;
    sfVector2f pos_b_ground2;
    sfVector2f pos_sprite;
    sfVector2f origin;
    int move;
    int gravity;
} window_t;

void runner(void);
void help_display(void);
int error_handling(int ac, char **av);

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int compare_str(char *str1, char *str2);

#define ERROR_ARG "./my_runner: bad arguments: 0 given but 1 is required\nretry with -h\n"
#define TRUE 1
#define FALSE 0
#define ERROR 84

#endif
