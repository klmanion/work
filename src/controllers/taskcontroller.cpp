/** controllers taskcontroller.cpp
 */

#include "taskcontroller.h"

#include "../views/taskview.h"

/* genetic functs {{{1 */
/* default ctor {{{2 */
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
		    { (const char)NULL, "", [](int rep) { return 0;}}
	    };

	_keymap = normalkm;
}

/* ctor {{{2
 * 	This constructer should always be used over the default
 */
TaskController::TaskController(
    View	*view)
    : TaskController()
{
	_view = view;
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
	if (!ch)
	    return 0;

	for (keybind_t *kb = _keymap; kb->ch; ++kb)
	    {
		if (kb->ch == ch)
		    {
			if (kb->funct)
			    kb->funct(1);
			break;
		    }
	    }

	return 1;
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
