/*
** EPITECH PROJECT, 2017
** my_sokoban
** File description:
** Structures header file.
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct map {
	char *str;
	char *backup_str;
	int pos_p;
	int pos_init;
	int lines;
	int cols;
}map_t;

#endif
