/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "include/my.h"
#include "include/bsq.h"



framebuffer_t   *framebuffer_create(int width, int height)
{
    int i = 0;
    int len_buf;
    framebuffer_t   *buff;
    sfUint8 *pixels;

    buff = malloc(sizeof(framebuffer_t));
    buff->width = width;
    buff->height = height;
    len_buf = width * height * 4;
    pixels = malloc(sizeof(sfUint8) * len_buf);
    buff->pixels = pixels;
    while (i < len_buf) {
        buff->pixels[i] = 0;
        buff->pixels[i + 1] = 0;
        buff->pixels[i + 2] = 0;
        buff->pixels[i + 3] = 255;
        i = i + 4;
    }
    return buff;
}

void    my_put_pixel(framebuffer_t *buff,  int x, int y, sfColor clr)
{
	int resizer = 4;
    if (x < 500 && y < 500 && x > 0 && y > 0) {
        x = x * resizer;
        y = y * resizer;
        buff->pixels[buff->width * y + x] = clr.r;
        buff->pixels[buff->width * y + x + 1] = clr.g;
        buff->pixels[buff->width * y + x + 2] = clr.b;
        buff->pixels[buff->width * y + x + 3] = clr.a;
    }
}


void init_csfml(){ 
    sfVideoMode mode = {500, 500, 64};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Poulpe pu du cul", sfClose, NULL);
    sfColor background = sfColor_fromRGB(20,20,20);
    framebuffer_t   *buff = framebuffer_create(500, 500);

    sfIntRect oscilo_tx_rect = {0, 0, 500, 500};
    sfTexture* oscilo_textr = sfTexture_createFromFile("adriensoscilo.png", &oscilo_tx_rect);
    
    sfSprite* plat1_sprite = sfSprite_create();
    sfSprite_setTexture(plat1_sprite, oscilo_textr, 1);
    sfIntRect plat1_texture_section = {0, 0, 500, 500};
    sfSprite_setTextureRect(plat1_sprite, plat1_texture_section);
    sfEvent evt;

    sfColor rgb;
    rgb.r = 200;
    rgb.g = 255;
    rgb.b = 255;
    rgb.a = 255;
    int i = 0;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &evt)) {
            if (evt.type == sfEvtClosed){
                sfRenderWindow_close(window);
            }
        }
        i = 0;
        sfRenderWindow_clear(window, background);
        sfRenderWindow_drawSprite(window, plat1_sprite, NULL);
        sfRenderWindow_display(window);
        while(i < 200){
            my_put_pixel(buff, i, i, rgb);
            i+=1;
        }
    }
    sfRenderWindow_destroy(window);
}

void process_file(char *filepath)
{
    int file = 0;
    int size = 0;
    int i = 0;
    int *adresse;
    int canal1;
    int canal2;
    file = open(filepath, O_RDONLY);
    if (file <= 0){
        my_putstr("There's no file called :");
        my_putstr(filepath);
        my_putstr("\n");
        exit(1);
    }
    close(file);

    struct taille{
        //[Bloc de déclaration d'un fichier au format WAVE]
        char riff[4];
        int size;
        char wave[4];

        //[Bloc décrivant le format audio]
        char formatblockid[4];
        int blocksize;
        short audioformat;
        short nbcanaux;
        int frequence;
        int byte_per_sec;
        short byte_per_block;
        short bits_per_sample;

        //[Bloc des données]
        char DataBlocID[4];
        int DataSize;
        
    }test;

    file = open(filepath, O_RDONLY);

    if(read(file, &test, sizeof(test)) != sizeof(test)){ //Je verifie que les 8 premiers octets sont remplis et je les stock
        my_putstr("ya moins de 8 octets\n");
        exit(1);
    }

    my_putstr("Riff format : ");
    my_putstr(test.riff);
    my_putchar('\n');

    my_putstr("Size size : ");
    my_put_nbr(test.size);
    my_putchar('\n');

    my_putstr("Wave format : ");
    my_putstr(test.wave);
    my_putchar('\n');

    my_putstr("Format block id : ");
    my_putstr(test.formatblockid);
    my_putchar('\n');

    my_putstr("Block size : ");
    my_put_nbr(test.blocksize);
    my_putchar('\n');

    my_putstr("Audio format : ");
    my_put_nbr(test.audioformat);
    my_putchar('\n');

    my_putstr("Nb canaux : ");
    my_put_nbr(test.nbcanaux);
    my_putchar('\n');

    my_putstr("Frequence : ");
    my_put_nbr(test.frequence);
    my_putchar('\n');

    my_putstr("Byte per sec : ");
    my_put_nbr(test.byte_per_sec);
    my_putchar('\n');

    my_putstr("Byte per bloc : ");
    my_put_nbr(test.byte_per_block);
    my_putchar('\n');

    my_putstr("Bits per sample : ");
    my_put_nbr(test.bits_per_sample);
    my_putchar('\n');

    my_putstr("Data block id : ");
    my_putstr(test.DataBlocID);
    my_putchar('\n');

    my_putstr("Data size : ");
    my_put_nbr(test.DataSize);
    my_putchar('\n');
    if(test.riff[0] != 'R' || test.riff[1] != 'I' || test.riff[2] != 'F' || test.riff[3] != 'F'){
        my_putstr("ya pas RIFF au début de mon fichier\n");
        exit(1);
    }
    if(test.size == 0){
        my_putstr("la size est de 0\n");
        exit(1);
    }
    
    if(test.wave[0] != 'W' || test.wave[1] != 'A' || test.wave[2] != 'V' || test.wave[3] != 'E'){
        my_putstr("mon fichier n'est pas au format WAVE\n");
        exit(1);
    }

    if(test.DataBlocID[0] != 'd' || test.DataBlocID[1] != 'a' || test.DataBlocID[2] != 't' || test.DataBlocID[3] != 'a'){
        my_putstr("le databloc id n'est pas data");
        exit(1);
    }
    adresse = malloc(test.DataSize);

    if(adresse == NULL){
        exit(1);
    }

    if(read(file, adresse, test.DataSize) < test.DataSize){
        my_putstr("read n'as pas lu assez");
        exit(1);
    }
    if(test.nbcanaux !=2){
        my_putstr("le nombre de canaux est pas égale à 2\n");
        exit(1);
    }

    if(test.bits_per_sample == 8){
        my_putstr("le nombre bits par sample est egale à 8\n");
        //char
        exit(1);
    }
    else if (test.bits_per_sample == 16){
        my_putstr("le nombre bits par sample est egale à 16\n");
    }
    else if(test.bits_per_sample == 24){
        my_putstr("le nombre bits par sample est egale à 24\n");
        exit(1);
    }
    else{
        my_putstr("le nombre de bits par sample n'est pas reconnus\n");
    }
    while(i <= test.DataSize/2){
        canal1 = adresse[i];
        //my_put_nbr(canal1);
        canal2 = adresse[i+1];
        float jesuisnul = 1/test.frequence;
        //usleep(jesuisnul*1000000);
        i+=2;
    }

    //printf("pute %ld\n", test.size);
    //my_putstr("test\n");

    /*while (i < test.size) {
        my_putchar('*');
        i+=1;
    }
    init_csfml();

    

    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    map = (char *)malloc(sizeof(char) * size);
    seek(file, 0L, SEEK_SET);

*/
    free(adresse);
    close(file);
}

int option(int ac, char **av){
    int i = 1;
	if (av[i][0] == '-' && av[i][1] == 'h'){
        my_putstr("USAGE\n");
        my_putstr("   ./test [map_file]\n");
        my_putstr("\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("   wav test\n");
		return 0;
    }
	else 
	process_file(av[1]);

}

int main(int ac, char **av)
{
    if (ac < 2){
        my_putstr("Too few arguments.");
        return (84);
    }
    else if(ac > 2){
        my_putstr("Too much arguments.");
        return (84);
    }
    else
    option(ac, av);
    return (0);
}
