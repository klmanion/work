/** model.cpp
 */

#include "model.h"

#include "system.h"
#include NCURSES_INCL
#include <cstdio>
#include <unistd.h>

/* genetic functs {{{1 */
/* get_instance() {{{2 */
Model*
Model::get_instance(void)
{
	static Model model;
	return &model;
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
Task*
Model::cursor(void)
{
	return _cursor;
}

/* cursor mutator {{{2 */
void
Model::cursor_set(
    Task	&task)
{
	_cursor = &task;
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

/* actions {{{1 */
/* add_next {{{2 */
/* setter {{{3 */
Task&
Model::add_next(
    Task	&task)
{
	if (!_task_list)
	    return *(_task_list = &task);
	else
	    return _task_list->add_next(task);
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
	if (!_task_list)
	    return add_next(task);
	else
	    return _task_list->add_child(task);
}

/* creator {{{3 */
Task&
Model::add_child(void)
{
	return add_child(new_task());
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

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
