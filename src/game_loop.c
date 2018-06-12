/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** Contains the game loop and its directly associated functions.
*/

#include <ncurses.h>
#include "my.h"
#include "my_sokoban.h"

static int check_success(char const *map)
{
	for (int i = 0 ; map[i] ; i++) {
		if (map[i] == 'O')
			return (0);
	}
	return (1);
}

static int analyse_event(map_t *map, int ch)
{
	switch (ch) {
	case KEY_LEFT :
		map->pos_p = move_p(map, map->pos_p, -1);
		break;
	case KEY_RIGHT :
		map->pos_p = move_p(map, map->pos_p, 1);
		break;
	case KEY_UP :
		map->pos_p = move_p(map, map->pos_p, -map->cols);
		break;
	case KEY_DOWN :
		map->pos_p = move_p(map, map->pos_p, map->cols);
		break;
	case 27 :
		return (-1);
		break;
	case 32 :
		my_strcpy(map->str, map->backup_str);
		map->pos_p = map->pos_init;
		break;
	}
	return (check_success(map->str));
}

static void last_message(int result)
{
	char str[12] = "";

	if (result == 1)
		my_strcpy(str, "WELL DONE!!");
	else if (result == -1)
		my_strcpy(str, "YOU LOSE!!");
	start_color();
	mvprintw(LINES / 2, COLS / 2 - 6, str);
	for (int i = 1, turn = 0 ; turn < 5 ; i++) {
		init_pair(1, i, COLOR_BLACK);
		attron(COLOR_PAIR(1));
		mvprintw(LINES / 2, COLS / 2 - 6, str);
		refresh();
		usleep(100000);
		if (i == 7) {
			i = 0;
			turn++;
		}
	}
	attroff(COLOR_PAIR(1));
}

int display_game(map_t *map)
{
	int ch = 0;
	int success = 0;

	if (LINES <= map->lines || COLS < map->cols) {
		clear();
		mvprintw(LINES / 2, COLS / 2 - 9, "Enlarge the window");
	} else {
		ch = getch();
		clear();
		success = analyse_event(map, ch);
		display_map(map);
	}
	refresh();
	return (success);
}

void game_loop(map_t *map)
{
	int success = 0;

	initscr();
	keypad(stdscr, TRUE);
	noecho();
	display_map(map);
	while (!success)
		success = display_game(map);
	last_message(success);
	endwin();
}
