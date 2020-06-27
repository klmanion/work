/** modes normal.cpp
 */

#include "normal.h"

#include "../system.h"
#include NCURSES_INCL
#include "controllers/taskcontroller.h"

/* genetic functs {{{1 */
/* contructor {{{2 */
Normal::Normal()
{
	_controller = new TaskController(&_tview);
}

/* virtual functs {{{1 */
/* loop() {{{2
 * 	Returning nullptr causes no change in mode.
 * 	Returning a mode object switches the active mode.
 * 	Upon mode switch, the mode is destroyed.
 */
Mode*
Normal::loop(void)
{
	char ch;

	ch = getch();

	clear();
	_controller->handle(ch);
	_tview.print();
	refresh();

	return nullptr;
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
