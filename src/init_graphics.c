/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 22:08:38 by y0ja              #+#    #+#             */
/*   Updated: 2015/09/25 06:36:02 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

SDL_Surface		*init_sprite(char *filename)
{
	SDL_Surface *img;

	img = IMG_Load(filename);
	if (!img)
		ft_error(IMG_LOAD);
	return (img);
}

void	load_background(SDL_Surface *bg[8])
{
	bg[0] = init_sprite("./img/bg/gif/frame_0.gif");
	bg[1] = init_sprite("./img/bg/gif/frame_1.gif");
	bg[2] = init_sprite("./img/bg/gif/frame_2.gif");
	bg[3] = init_sprite("./img/bg/gif/frame_3.gif");
	bg[4] = init_sprite("./img/bg/gif/frame_4.gif");
	bg[5] = init_sprite("./img/bg/gif/frame_5.gif");
	bg[6] = init_sprite("./img/bg/gif/frame_6.gif");
}

static void		cut_sprite_sheet(SDL_Rect *clip, int x, int y, int w, int h)
{
	clip->x = x;
	clip->y = y;
	clip->h = h;
	clip->w = w;
}

void	load_sprite(t_sprite *sprite, char *filename, char *healthbar, int posx, int posy)
{
	// Sprite Sheet
	sprite->img = SDL_LoadBMP(filename);
	if (sprite->img == NULL)
		ft_error(IMG_LOAD);
	// HealthBar
	sprite->bar = SDL_LoadBMP(healthbar);
	if (sprite->bar == NULL)
		ft_error(IMG_LOAD);
	sprite->pos.x = posx;
	sprite->pos.y = posy;
}

static void		set_transparency(SDL_Surface *img, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, r, g, b));
}

void	cut_sheets(t_sprite *naruto, t_sprite *sasuke, t_sprite *sakura, t_sprite *neji, t_sprite *kakashi)
{
	int len;

	// Naruto
	len = naruto->img->h;
	cut_sprite_sheet(&naruto->clip[0], 0, 0, 45, len);
	cut_sprite_sheet(&naruto->clip[1], 50, 0, 45, len);
	cut_sprite_sheet(&naruto->clip[2], 100, 0, 45, len);
	cut_sprite_sheet(&naruto->clip[3], 147, 0, 50, len);
	cut_sprite_sheet(&naruto->clip[4], 195, 0, 50, len);
	cut_sprite_sheet(&naruto->clip[5], 240, 0, 50, len);
	// Sasuke
	len = sasuke->img->h;
	cut_sprite_sheet(&sasuke->clip[0], 0, 0, 45, len);
	cut_sprite_sheet(&sasuke->clip[1], 50, 0, 45, len);
	cut_sprite_sheet(&sasuke->clip[2], 100, 0, 45, len);
	cut_sprite_sheet(&sasuke->clip[3], 147, 0, 45, len);
	cut_sprite_sheet(&sasuke->clip[4], 195, 0, 45, len);
	cut_sprite_sheet(&sasuke->clip[5], 240, 0, 35, len);
	// Lee
	len = sakura->img->h;
	cut_sprite_sheet(&sakura->clip[0], 0, 0, 45, len);
	cut_sprite_sheet(&sakura->clip[1], 45, 0, 45, len);
	cut_sprite_sheet(&sakura->clip[2], 95, 0, 45, len);
	cut_sprite_sheet(&sakura->clip[3], 145, 0, 45, len);
	cut_sprite_sheet(&sakura->clip[4], 190, 0, 45, len);
	cut_sprite_sheet(&sakura->clip[5], 240, 0, 45, len);
	// Neji
	len = neji->img->h;
	cut_sprite_sheet(&neji->clip[0], 0, 0, 40, len);
	cut_sprite_sheet(&neji->clip[1], 45, 0, 40, len);
	cut_sprite_sheet(&neji->clip[2], 85, 0, 45, len);
	cut_sprite_sheet(&neji->clip[3], 132, 0, 45, len);
	cut_sprite_sheet(&neji->clip[4], 178, 0, 40, len);
	cut_sprite_sheet(&neji->clip[5], 220, 0, 45, len);
	// Kakashi
	len = kakashi->img->h;
	cut_sprite_sheet(&kakashi->clip[0], 0, 0, 50, len);
	cut_sprite_sheet(&kakashi->clip[1], 60, 0, 50, len);
	cut_sprite_sheet(&kakashi->clip[2], 120, 0, 50, len);
	cut_sprite_sheet(&kakashi->clip[3], 180, 0, 50, len);
}

void	cut_sheets2(t_sprite *lee)
{
	int len;

	len = lee->img->h;
	// Lee
	cut_sprite_sheet(&lee->clip[0], 0, 0, 40, len);
	cut_sprite_sheet(&lee->clip[1], 45, 0, 40, len);
	cut_sprite_sheet(&lee->clip[2], 90, 0, 40, len);
	cut_sprite_sheet(&lee->clip[3], 135, 0, 40, len);
}

static void		init_sdl_ttf(t_all *all)
{
	if (TTF_Init() == -1)
		ft_error(SYSCALL);
	all->text.font = TTF_OpenFont("font.ttf", 25);
	all->text.color.r = 0;
	all->text.color.g = 0;
	all->text.color.b = 0;
}

void	init_graphics(t_all *all)
{
	all->win = init_window();
	init_sdl_ttf(all);
	load_background(all->bg);
	load_sprite(&all->naruto, "./img/standingNaruto2.bmp", "./img/Hnaruto.bmp", 20, 205);
	load_sprite(&all->sasuke, "./img/standingSasuke2.bmp", "./img/Hsasuke.bmp", 70, 205);
	load_sprite(&all->sakura, "./img/standingSakura.bmp", "./img/Hsakura.bmp", 120, 210);
	load_sprite(&all->neji, "./img/standingNeji.bmp", "./img/Hneji.bmp", 375, 205);
	load_sprite(&all->kakashi, "./img/standingKakashi.bmp", "./img/Hkakashi.bmp", 310, 205);
	load_sprite(&all->lee, "./img/standingLee.bmp", "./img/Hlee.bmp", 430, 208);
	set_transparency(all->naruto.img, 144, 176, 216);
	set_transparency(all->naruto.bar, 144, 176, 216);
	set_transparency(all->sasuke.img, 144, 176, 216);
	set_transparency(all->sasuke.bar, 144, 176, 216);
	set_transparency(all->sakura.img, 144, 176, 216);
	set_transparency(all->sakura.bar, 144, 176, 216);
	set_transparency(all->neji.img, 144, 176, 216);
	set_transparency(all->neji.bar, 144, 176, 216);
	set_transparency(all->kakashi.img, 144, 176, 216);
	set_transparency(all->kakashi.bar, 144, 176, 216);
	set_transparency(all->lee.img, 144, 176, 216);
	set_transparency(all->lee.bar, 144, 176, 216);
	cut_sheets(&all->naruto, &all->sasuke, &all->sakura, &all->neji, &all->kakashi);
	cut_sheets2(&all->lee);
	all->rect_bar = SDL_CreateRGBSurface(SDL_HWSURFACE, 40, 4, 32, 0, 0, 0, 0);
	SDL_FillRect(all->rect_bar, NULL, SDL_MapRGB(all->win->format, 241, 6, 60));
}