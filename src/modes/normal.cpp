/** modes normal.cpp
 */

#include "normal.h"

#include "../system.h"
#include NCURSES_INCL

/* genetic functs {{{1 */
/* contructor {{{2 */
Normal::Normal()
{
	static	keybind_t normalkm[] =
	    {
		    { 'a',	"add-task",	[this](int rep)
			    {
				_model->add_next();
				return 1;
			    }
		    },

		    { 'c',	"add-child",	[this](int rep)
			    {
				_model->add_child();
				return 1;
			    }
		    },

		    { 's',	"select",	[this](int rep)
			    {
				_model->cursor().select_toggle();
				return 1;
			    }
		    },

		    { (const char)NULL, "", [](int rep) { return 0;} }
	    };
	
	_keymap = normalkm;
	_tcur = (Task *)NULL;
}

/* virtual functs {{{1 */
/* loop() {{{2
 * 	Returning nullptr causes no change in mode.
 * 	Returning a mode object switches the active mode.
 * 	Upon mode switch, the mode is destroyed.
 */
void
Normal::loop(void)
{
	handle(getch());
}

/* handle() {{{2 */
int
Normal::handle(
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

/* print() {{{2 */
void
Normal::print(void)
{
	clear();
	move(0,0);
	if (!_model->no_tasks())
	    _model->task_list().print();
	refresh();
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
