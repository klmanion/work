/** modes normal.cpp
 */

#include "normal.h"

#include "../system.h"
#include NCURSES_INCL

/* genetic functs {{{1 */
/* contructor {{{2 */
Normal::Normal()
{

}

/* virtual functs {{{1 */
/* loop() {{{2 */
int
Normal::loop(void)
{
	controller->handle(getch());
	tview.print();
	refresh();

	return 1;
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
