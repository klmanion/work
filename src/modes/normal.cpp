/** modes normal.cpp
 */

#include "normal.h"

#include "../system.h"
#include NCURSES_INCL
#include <cstdio>
#include <unistd.h>

/* genetic functs {{{1 */
/* contructor {{{2 */
Normal::Normal()
{
	static	keybind_t normalkm[] =
	    {
		    { 'h',	"hello-world",	[](int rep)
			    {
				printw("hello world");
				return 1;
			    }
		    },

		    { 'a',	"add-task",	[this](int rep)
			    {
				add_task();
				return 1;
			    }
		    },

		    { (const char)NULL, "", [](int rep) { return 0;}}
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
	if (!_model->is_empty())
	    _model->task_list().print();
	refresh();
}

/* action functs {{{1 */
/* add_task {{{2 */
/* (void) {{{3 */
Task&
Normal::add_task(void)
{
	char f_name[80] = "/tmp/tl_task_inp-XXXXXX";
	int fd;
	char com[80];	/* make static ? */
	Task *task;

	fd = mkstemp(f_name);

	snprintf(com, 79, "${EDITOR:-${VISUAL:-nano}} %s", f_name);

	/* suspend ncurses */
	def_prog_mode();
	endwin();

	system(com);

	/* resume ncurses */
	reset_prog_mode();

	task = new Task(fd);

	remove(f_name);

	add_task(*task);

	return *task;
}

/* (Task &) {{{3 */
Task&
Normal::add_task(
    Task	&task)
{
	return _model->add_task(task);
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
