/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** 
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct framebuffer_s
{
    int width;
    int height;
    sfUint8 *pixels;
}framebuffer_t;
framebuffer_t   *framebuffer_create(int width, int height);
void    my_put_pixel(framebuffer_t *buff, int x, int y, sfColor color);

#endif

