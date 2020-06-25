/** views taskview.cpp
 */

#include "taskview.h"

/* genetic functs {{{1 */
/* constructor {{{2 */
TaskView::TaskView()
{
	tcur = (Task *)NULL;
}

/* destructor {{{2 */
TaskView::~TaskView()
{

}

/* virtual functs {{{1 */
/* print() {{{2 */
void
TaskView::print(void)
{
	move(100,100);
	printw("hello world");
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
