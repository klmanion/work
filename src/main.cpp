/** main.cpp: work
 * created by: Kurt L. Manion
 * on: Sun., 14 June 2020
 *
 * a reprogramming of my 2018 work program
 */

#include "system.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include NCURSES_INCL

/* forward decls {{{1 */
static	void	ncurses_initialize (void);
static	void	ncurses_deinitialize (void);

static	int	main_loop (void);

/* main() {{{1 */
int
main(
    int argc,
    char *const argv[])
{
	int retv;

	setlocale(LC_ALL, "");
	setprogname(argv[0]);

	ncurses_initialize();

	printw("hello world");

	retv = main_loop();

	ncurses_deinitialize();

	return retv;
}

/* ncurses {{{1 */
/* _initialize() {{{2 */
static	void
ncurses_initialize(void)
{
	int row,col;

	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	nonl();
	noecho();
	curs_set(0);
	refresh();

	getmaxyx(stdscr, row,col);

	return;
}

/* _deinitialize() {{{2 */
static	void
ncurses_deinitialize(void)
{
	endwin();
}

/* main_loop() {{{1 */
static	int
main_loop()
{
	return EXIT_SUCCESS;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
