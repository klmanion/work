/** task.cpp
 */

#include "task.h"

#include "system.h"
#include NCURSES_INCL
#include <cstdio>

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

/* actions {{{1 */
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

/* printing {{{1 */
/* print {{{2 */
void
Task::print(void)
{
	if (_desc.empty())
	    printw("%s\n", _tag.c_str());
	else
	    printw("%s - %s\n", _tag.c_str(), _desc.c_str());

	if (_next)
	    _next->print();
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
