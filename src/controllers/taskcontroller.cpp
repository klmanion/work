/** controllers taskcontroller.cpp
 */

#include "taskcontroller.h"

#include "../views/taskview.h"

/* genetic functs {{{1 */
/* constructor {{{2 */
TaskController::TaskController()
{
	static	keybind_t normalkm[] =
	    {
		    { 'h',	"hello_world",	[](int rep)
			    {
				printw("hello world");
				return 1;
			    }
		    },
		    { (const char)NULL, (const string)NULL, (bind_t)NULL }
	    };

	view = new TaskView();
	keymap = normalkm;
}

/* destructor {{{2 */
TaskController::~TaskController()
{

}

/* virtual functs {{{1 */
/* handle() {{{2 */
int
TaskController::handle(
    const char	ch)
{
	for (keybind_t *kb = keymap; kb->ch; ++kb)
	    {
		if (kb->ch == ch)
		    {
			kb->funct(1);
			break;
		    }
	    }

	return 1;
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
