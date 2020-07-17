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
	_folded = false;
	_selected = false;
	_completed = false;

	_next = (Task *)NULL;
	_prev = (Task *)NULL;
	_children = (Task *)NULL;
	_parent = (Task *)NULL;
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

/* accessors/mutators/predicates {{{1 */
/* folding {{{2 */
/* is_folded() {{{3 */
bool
Task::is_folded(void)
{
	return _folded;
}

/* fold() {{{3 */
Task&
Task::fold(void)
{
	_folded = true;

	return *this;
}

/* unfold() {{{3 */
Task&
Task::unfold(void)
{
	_folded = false;

	return *this;
}

/* fold_toggle() {{{3 */
Task&
Task::fold_toggle(void)
{
	return is_folded() ? unfold() : fold();
}

/* selection {{{2 */
/* is_selected() {{{3 */
bool
Task::is_selected(void)
{
	return _selected;
}

/* select() {{{3 */
Task&
Task::select(void)
{
	_selected = true;

	return *this;
}

/* deselect() {{{3 */
Task&
Task::deselect(void)
{
	_selected = false;

	return *this;
}

/* select_toggle() {{{3 */
Task&
Task::select_toggle(void)
{
	return is_selected() ? deselect() : select();
}

/* completion {{{2 */
/* is_completed() {{{3 */
bool
Task::is_completed(void)
{
	return _completed;
}

/* complete() {{{3 */
Task&
Task::complete(void)
{
	_completed = true;

	return *this;
}

/* uncomplete() {{{3 */
Task&
Task::uncomplete(void)
{
	_completed = false;

	return *this;
}

/* complete_toggle() {{{3 */
Task&
Task::complete_toggle(void)
{
	return _completed ? uncomplete() : complete();
}

/* tag {{{2 */
/* has_tag() {{{3 */
bool
Task::has_tag(void)
{
	return !_tag.empty();
}

/* tag() {{{3 */
string&
Task::tag(void)
{
	return _tag;
}

/* tag_set() {{{3 */
string&
Task::tag_set(
    string	&tag)
{
	return (_tag = tag);
}

/* description {{{2 */
/* has_description() {{{3 */
bool
Task::has_description(void)
{
	return !_desc.empty();
}

/* description() {{{3 */
string&
Task::description(void)
{
	return _desc;
}

/* description_set() {{{3 */
string&
Task::description_set(
    string	&desc)
{
	return (_desc = desc);
}

/* next {{{2 */
/* has_next() {{{3 */
bool
Task::has_next(void)
{
	return !!_next;
}

/* next() {{{3 */
Task&
Task::next(void)
{
	return *_next;
}

Task&
Task::next_tail(void)
{
	if (has_next())
	    return next().next_tail();
	else
	    return *this;
}

/* next_set() {{{3 */
Task&
Task::next_set(
    Task	&next)
{
	next.prev_set(*this);
	next.parent_set(parent());
	return *(_next = &next);
}

/* next_add() {{{3 */
Task&
Task::next_add(
    Task	&task)
{
	if (!has_next())
	    {
		return next_set(task);
	    }
	else
	    {
		return next().next_add(task);
	    }
}

/* prev {{{2 */
/* has_prev() {{{3 */
bool
Task::has_prev(void)
{
	return !!_prev;
}

/* prev() {{{3 */
Task&
Task::prev(void)
{
	return *_prev;
}

/* prev_set() {{{3 */
Task&
Task::prev_set(
    Task	&prev)
{
	return *(_prev = &prev);
}

/* children {{{2 */
/* has_children() {{{3 */
bool
Task::has_children(void)
{
	return !!_children;
}

/* children() {{{3 */
Task&
Task::children(void)
{
	return *_children;
}

/* _tail() {{{3 */
Task&
Task::children_tail(void)
{
	return children().next_tail();
}

/* _set() {{{3 */
Task&
Task::children_set(
    Task	&children)
{
	return *(_children = &children);
}

/* child_add() {{{3 */
Task&
Task::child_add(
    Task	&task)
{
	task.parent_set(*this);

	if (!has_children())
	    return children_set(task);
	else
	    return children().next_add(task);
}

/* parent {{{2 */
/* has_parent() {{{3 */
bool
Task::has_parent(void)
{
	return !!_parent;
}

/* parent() {{{3 */
Task&
Task::parent(void)
{
	return *_parent;
}

/* parent_set() {{{3 */
Task&
Task::parent_set(
    Task	&parent)
{
	return *(_parent = &parent);
}
/* misc. predicates {{{2 */
/* is_cursed_over() {{{3 */
bool
Task::is_cursed_over(void)
{
	return Model::get_instance().cursor_ptr() == this;
}

/* above/below {{{1 */
/* above_coord() {{{2
 * 	Returns task above this on the same ordinal.
 * 	If there is no previous task in the same ordinal,
 * 	this is returned.
 */
Task&
Task::above_coord(void)
{
	if (has_prev())
	    return prev();
	else
	    return *this;
}

/* above_supord() {{{2
 * 	Returns the task above this across the hierarchy.
 * 	If there is no previous task,
 * 	the parent is returned,
 * 	unless there is no parent,
 * 	in which case this is returned.
 * 	If there is a previous task,
 * 	either it or its last child will be returned,
 * 	conditional on the existence of its children.
 */
Task&
Task::above_supord(void)
{
	if (!has_prev())
	    {
		if (has_parent())
		    return parent();
		else
		    return *this;
	    }
	else
	    {
		if (prev().has_children())
		    return prev().children_tail();
		else
		    return prev();
	    }
}

/* below_coord() {{{2
 * 	Returns task below this on the same ordinal.
 * 	If there is no subsequent task in the same ordinal,
 * 	this is returned.
 */
Task&
Task::below_coord(void)
{
	if (has_next())
	    return next();
	else
	    return *this;
}

/* below_supord() {{{2
 * 	Returns the task below this across hierarchy.
 * 	If the current task has children,
 * 	the first child is returned;
 * 	otherwise, the next task is returned.
 * 	If there is no next task,
 * 	the parent's next task is returned.
 * 	If the parent has no next task,
 * 	this is returned.
 */
Task&
Task::below_supord(void)
{
	if (has_children())
	    {
		return children();
	    }
	else if (has_next())
	    {
		return next();
	    }
	else if (has_parent() && parent().has_next())
	    {
		return parent().next();
	    }
	else
	    {
		return *this;
	    }
}

/* printing {{{1 */
/* print() {{{2 */
void
Task::print(
    int	lvl)
{
	int y,x;
	bool show_completed;

	if (!_tag.empty())
	    {
		getyx(stdscr, y,x);

		show_completed = Model::get_instance()
			.view_options()
			.show_completed();

		if (!is_completed() || show_completed)
		    {
			for (int i=lvl; i>0; --i)
			    printw("|");

			if (!has_children())
			    addch(' ');
			else if (is_folded())
			    addch('+');
			else
			    addch('-');
		    }

		if (is_selected())
		    wattron(stdscr, A_STANDOUT);

		if (is_cursed_over())
		    wattron(stdscr, A_UNDERLINE);

		if (show_completed && !is_completed())
		    wattron(stdscr, A_BOLD);

		if (!is_completed() || show_completed)
		    {
			printw("%s", tag().c_str());
			if (has_description())
			    printw(" - %s", description().c_str());

			move(++y,x);
		    }
		    
		if (show_completed && !is_completed())
		    wattroff(stdscr, A_BOLD);

		if (is_cursed_over())
		    wattroff(stdscr, A_UNDERLINE);

		if (is_selected())
		    wattroff(stdscr, A_STANDOUT);
	    }

	if (!is_completed() && !is_folded() && has_children())
	    children().print(lvl+1);

	if (has_next())
	    next().print(lvl);
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
