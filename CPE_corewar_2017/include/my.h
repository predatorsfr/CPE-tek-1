/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** raphael.dubois@epitech.eu
*/

#ifndef MY_H_
#define MY_H_
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
typedef struct clock_stct
{
	sfClock *clock;
	sfTime time;
	float seconds;
	sfClock *clock2;
	sfTime time2;
	float seconds2;
	sfClock *clock3;
	sfTime time3;
	float seconds3;
	sfClock *clock4;
	sfTime time4;
	float seconds4;
	sfClock *clock5;
	sfTime time5;
	float seconds5;
}clock_stct;

typedef struct window_stct
{
	sfVideoMode mode;
	sfRenderWindow* window;
}window_stct;

typedef struct fg_stct
{
	sfTexture* tfg;
	sfSprite* sfg;
	sfIntRect rectfg;
}fg_stct;

typedef struct bg_stct
{
	sfTexture* tbg;
	sfSprite* sbg;
	sfIntRect rectbg;
}bg_stct;

typedef struct mg_stct
{
	sfTexture* tmg;
	sfSprite* smg;
	sfIntRect rectmg;
}mg_stct;

typedef struct player_stct
{
	sfTexture* tpl;
	sfSprite* spl;
	sfIntRect rectpl;
	sfVector2f pos;
	sfVector2f pobs;
	sfVector2f vit;
	sfVector2f dep;
	sfTexture* tjp;
	sfSprite* sjp;
	sfIntRect rectjp;
}player_stct;

typedef struct event_stct
{
	sfEvent event;
	sfMusic *sound;
	sfMusic *jump;
}event_stct;

typedef struct text_stct
{
	sfText *text;
	sfFont *font;
	sfVector2f scale;
}text_stct;

void init(bg_stct *bg ,mg_stct *mg,fg_stct *fg,player_stct *pl,window_stct *wd);
void init2(event_stct *evt, text_stct *txt);
void drawtxt(window_stct *wd, text_stct *txt, char *end);
void farbuild(bg_stct *bg);
void backbuild(mg_stct *mg);
void firstbuild(fg_stct *fg);
void run(player_stct *pl);
void jump(player_stct *pl);
void createclock(clock_stct *time);
void initclock(clock_stct *time);
void timing(clock_stct *time, fg_stct *fg, mg_stct *mg, bg_stct *bg, player_stct *pl);
void keyboard(clock_stct *time, event_stct *evt, player_stct *pl);
void closewd(event_stct *evt, window_stct *wd);
int  my_printf(char *str, ...);
char *itoa(int i, char *b);
#endif /*MY_H_*/
