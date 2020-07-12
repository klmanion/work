/** task.cpp
 */

#include "task.h"

#include "system.h"
#include NCURSES_INCL
#include <cstdio>
#include "model.h"

/* genetic functs {{{1 */
/* ctors {{{2 */
/* default {{{3 */
Task::Task()
{
	_next = (Task *)NULL;
	_children = (Task *)NULL;
}

/* from file descriptor {{{3 */
Task::Task(
    int	fd)
    : Task()
{
	FILE * f;
	char *tag0, *tag = (char *)NULL;
	char *desc0, *desc = (char *)NULL;;
	char *pch;

	f = fdopen(fd, "rb");

	if (!f || feof(f))
	    goto bad;

	tag0 = tag = new char[80];

	fscanf(f, "%79s ", tag);

	for (; isspace(*tag); ++tag) { }
	if ((pch=strpbrk(tag, " \t\n"))) *pch = '\0';

	if (strlen(tag) == 0)
	    goto bad;

	if (feof(f))
	    goto done;

	desc0 = desc = new char[1024];

	fgets(desc, 1024, f);

	if (strlen(desc) == 0)
	    goto done;

	for (; isspace(*desc); ++desc) { }
	for (pch=strrchr(desc,'\0')-1; isspace(*pch); --pch) { *pch = '\0'; }

done:
	_tag = tag;
	if (desc)
	    _desc = desc;

bad:

	if (tag)
	    delete[] tag0;

	if (desc)
	    delete[] desc0;

	fclose(f);

	return;
}

/* dtor {{{2 */
Task::~Task()
{
	if (_next)
	    delete _next;

	if (_children)
	    delete _children;
}

/* predicates {{{1 */
/* is_folded() {{{2 */
bool
Task::is_folded(void)
{
	return _folded;
}

/* is_selected() {{{2 */
bool
Task::is_selected(void)
{
	return _selected;
}

/* is_cursed_over() {{{2 */
bool
Task::is_cursed_over(void)
{
	return Model::get_instance()->cursor_ptr() == this;
}

/* cdr actions {{{1 */
/* add_next() {{{2 */
Task&
Task::add_next(
    Task	&task)
{
	if (!_next)
	    return *(_next = &task);
	else
	    return _next->add_next(task);
}

/* add_child() {{{2 */
Task&
Task::add_child(
    Task	&task)
{
	if (!_children)
	    return *(_children = &task);
	else
	    return _children->add_next(task);
}

/* selection {{{1 */
/* select() {{{2 */
Task&
Task::select(void)
{
	_selected = true;

	return *this;
}

/* deselect() {{{2 */
Task&
Task::deselect(void)
{
	_selected = false;

	return *this;
}

/* select_toggle() {{{2 */
Task&
Task::select_toggle(void)
{
	return is_selected() ? deselect() : select();
}

/* printing {{{1 */
/* print() {{{2 */
void
Task::print(
    int	lvl)
{
	int y,x;

	if (!_tag.empty())
	    {
		getyx(stdscr, y,x);

		for (int i=lvl; i>0; --i)
		    printw("|");

		if (is_selected())
		    wattron(stdscr, A_BOLD);

		if (!_children)
		    addch(' ');
		else if (is_folded())
		    addch('+');
		else
		    addch('-');

		if (is_cursed_over())
		    wattron(stdscr, A_UNDERLINE);

		printw("%s", _tag.c_str());
		if (_desc.c_str())
		    printw(" - %s", _desc.c_str());


		if (is_cursed_over())
		    wattroff(stdscr, A_UNDERLINE);

		if (is_selected())
		    wattroff(stdscr, A_BOLD);

		move(++y,x);
	    }

	if (!is_folded() && _children)
	    _children->print(lvl+1);

	if (_next)
	    _next->print(lvl);
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
