/** model.cpp
 */

#include "model.h"

#include "system.h"
#include NCURSES_INCL
#include <cstdio>
#include <unistd.h>

/* genetic functs {{{1 */
/* get_instance() {{{2 */
Model&
Model::get_instance(void)
{
	static Model model;
	return model;
}

/* ctor {{{2 */
Model::Model()
{
	_task_list = (Task *)NULL;

	_running = true;

}

/* dtor {{{2 */
Model::~Model()
{
	if (_task_list)
	    delete _task_list;
}

/* accessors/mutators {{{1 */
/* task_list accessor {{{2 */
Task&
Model::task_list(void)
{
	return *_task_list;
}

/* cursor accessor {{{2 */
Task&
Model::cursor(void)
{
	return *_cursor;
}

/* cursor pointer accessor {{{2 */
Task*
Model::cursor_ptr(void)
{
	return _cursor;
}

/* cursor mutator {{{2 */
Task&
Model::cursor_set(
    Task	&task)
{
	return *(_cursor = &task);
}

/* view_options accessor {{{2 */
Viewopts&
Model::view_options(void)
{
	return _viewopts;
}

/* predicates {{{1 */
/* is_running() {{{2 */
bool
Model::is_running(void)
{
	return _running;
}

/* no_tasks() {{{2 */
bool
Model::no_tasks(void)
{
	return !_task_list;
}

/* new_task() {{{1 */
Task&
Model::new_task(void)
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

	return *task;
}

/* cdr actions {{{1 */
/* add_next() {{{2 */
/* setter {{{3 */
Task&
Model::add_next(
    Task	&task)
{
	if (no_tasks())
	    return *(_cursor = _task_list = &task);
	else
	    return cursor().next_add(task);
}

/* creator {{{3 */
Task&
Model::add_next(void)
{
	return add_next(new_task());
}

/* add_child() {{{2 */
/* setter {{{3 */
Task&
Model::add_child(
    Task	&task)
{
	if (no_tasks())
	    return add_next(task);
	else
	    return cursor().child_add(task);
}

/* creator {{{3 */
Task&
Model::add_child(void)
{
	return add_child(new_task());
}

/* cursing {{{1 */
/* _above_coord() {{{2
 * 	Curses upward while staying within the same list of the hierarchy.
 * 	If the cursor is on the first element of the list, it will not curse
 * 	upwards to the task containing the current list.
 */
Task&
Model::curse_above_coord(void)
{
	return cursor_set(cursor().above_coord());
}

/* _above_supord() {{{2
 * 	Curses upward traversing the hierarchy.
 * 	If the cursor is on the first element of the list,
 * 	it will curse to the task containing the current list.
 */
Task&
Model::curse_above_supord(void)
{
	return cursor_set(cursor().above_supord());
}

/* _below_coord() {{{2
 * 	Curses downward while staying within the same list of the hierarchy.
 * 	If the cursor is on the last element of the list,
 * 	it will not jump out of that list.
 */
Task&
Model::curse_below_coord(void)
{
	return cursor_set(cursor().below_coord());
}

/* _below_supord() {{{2
 * 	Curses downward traversing the hierarchy.
 * 	If the cursor is on the last element of the list,
 * 	it will jump to the next list of the containing hierarchy
 * 	If the cursor is on a task with children,
 * 	it will curse to the first child.
 */
Task&
Model::curse_below_supord(void)
{
	return cursor_set(cursor().below_supord());
}

/* _out() {{{2
 * 	Curse to the containing list.
 */
Task&
Model::curse_out(void)
{
	if (cursor().has_parent())
	    return cursor_set(cursor().parent());
	else
	    return cursor();
}

/* _in() {{{2
 * 	Curse to the contained list.
 */
Task&
Model::curse_in(void)
{
	if (cursor().has_children())
	    return cursor_set(cursor().children());
	else
	    return cursor();
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
