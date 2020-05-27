/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** my_runner
*/

#include "runner.h"

window_t movement(window_t win)
{
    // set the position of the sprite
    sfSprite_setPosition(win.sprite, win.pos_sprite);
    sfSprite_setPosition(win.ground_s, win.pos_ground);
    sfSprite_setPosition(win.ground_s2, win.pos_ground2);
    sfSprite_setPosition(win.ground_s3, win.pos_ground3);
    sfSprite_setPosition(win.ground_s4, win.pos_ground4);
    sfSprite_setPosition(win.b_ground_s, win.pos_b_ground);
    sfSprite_setPosition(win.b_ground_s2, win.pos_b_ground2);
    
    // movement calculus
    win.pos_b_ground.x = (win.move * 0.5) + 5 - 1920;
    win.pos_b_ground2.x = (win.move * 0.5) + 5 + 1918;
    win.pos_ground.x = (win.move * 2) + 5 - 1920;
    win.pos_ground2.x = (win.move * 2) + (1*5);
    win.pos_ground3.x = (win.move * 2) + (1*5) + 1920;
    win.pos_ground4.x = (win.move * 2) + (1*5) + 3840;
    
    // change the value of the "move" var
    win.move -= 6;

    // replace the ground and background at 0
    // ground
    if (win.move < -1920) {
        win.pos_ground2.x = (win.move * 2) + (1*5) + 5760;
        win.pos_ground3.x = (win.move * 2) + (1*5) + 7680;
    }
    // background
    if (win.move < -3840)
        win.move = 0;
    return (win);
}

window_t set_positions(window_t win)
{
    // init of the gravity and the move value
    win.move = 0;
    win.gravity = 0;

    // init of the placement of the features (the background is by default in place here)
    //ground
    win.pos_ground.y = 950;
    win.pos_ground2.y = 950;
    win.pos_ground3.y = 950;
    win.pos_ground4.y = 950;

    // character
    win.pos_sprite.y = 900;
    win.pos_sprite.x = 150;
    return (win);
}

void draw_everything(window_t win)
{
    sfRenderWindow_drawSprite(win.window, win.b_ground_s, NULL);
    sfRenderWindow_drawSprite(win.window, win.b_ground_s2, NULL);
    sfRenderWindow_drawSprite(win.window, win.ground_s, NULL);
    sfRenderWindow_drawSprite(win.window, win.ground_s2, NULL);
    sfRenderWindow_drawSprite(win.window, win.ground_s3, NULL);
    sfRenderWindow_drawSprite(win.window, win.ground_s4, NULL);
    sfRenderWindow_drawSprite(win.window, win.sprite, NULL);
}

// close the window
void close_window(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
}

// more like a fill struct
window_t fill_sprites(window_t win)
{
    // coordinates for the origin of the character sprite (100x100 here)
    win.origin.x = 50;
    win.origin.y = 50;

    // create all of the sprites
    win.ground = sfTexture_createFromFile("./sprites/floor.png", NULL);
    win.ground_s = sfSprite_create();
    sfSprite_setTexture(win.ground_s, win.ground, sfTrue);
    win.ground2 = sfTexture_createFromFile("./sprites/floor.png", NULL);
    win.ground_s2 = sfSprite_create();
    sfSprite_setTexture(win.ground_s2, win.ground2, sfTrue);
    win.ground3 = sfTexture_createFromFile("./sprites/floor.png", NULL);
    win.ground_s3 = sfSprite_create();
    sfSprite_setTexture(win.ground_s3, win.ground3, sfTrue);
    win.ground4 = sfTexture_createFromFile("./sprites/floor.png", NULL);
    win.ground_s4 = sfSprite_create();
    sfSprite_setTexture(win.ground_s4, win.ground4, sfTrue);
    win.b_ground = sfTexture_createFromFile("./sprites/background.png", NULL);
    win.b_ground_s = sfSprite_create();
    sfSprite_setTexture(win.b_ground_s, win.b_ground, sfTrue);
    win.b_ground2 = sfTexture_createFromFile("./sprites/background.png", NULL);
    win.b_ground_s2 = sfSprite_create();
    sfSprite_setTexture(win.b_ground_s2, win.b_ground2, sfTrue);
    win.texture = sfTexture_createFromFile("./sprites/cube.png", NULL);
    win.sprite = sfSprite_create();
    sfSprite_setTexture(win.sprite, win.texture, sfTrue);

    // fill all the base positions
    win = set_positions(win);
    return (win);
}

window_t jump(window_t win)
{
    // detect tha space is pressed and changes the gravity
    if (sfKeyboard_isKeyPressed(sfKeySpace) && win.pos_sprite.y == 900)
        win.gravity = -20;
    
    // changes the location of the character
    win.pos_sprite.y = win.pos_sprite.y + win.gravity;

    // rotation around the origin
    if (win.pos_sprite.y < 900)
        sfSprite_rotate(win.sprite, 2.25);

    // if no key is pressed the sprite doesn't move
    if (win.pos_sprite.y > 900) {
        win.gravity = 0;
        win.pos_sprite.y = 900;
    }
    return (win);
}

void runner(void)
{
    window_t win;
    sfVideoMode mode = {1920, 1080, 32};

    // fill struct
    win = fill_sprites(win);

    // create the window, set the framerate and the origin
    win.window = sfRenderWindow_create(mode, "runner", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win.window, 60);
    sfSprite_setOrigin(win.sprite, win.origin);

    // loop for the game 
    while (sfRenderWindow_isOpen(win.window)) {
        // clear the window
        sfRenderWindow_clear(win.window, sfBlack);
        // handles the closing
        close_window(win.window);
        // changes the gravity
        win.gravity += 1;
        // move the ground and background
        win = movement(win);
        win = jump(win);
        // draw all of the sprites
        draw_everything(win);
        // displays
        sfRenderWindow_display(win.window);
    }
    sfRenderWindow_destroy(win.window);
}
