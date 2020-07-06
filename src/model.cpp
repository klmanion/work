/** model.cpp
 */

#include "model.h"

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

/* predicates {{{1 */
/* is_running() {{{2 */
bool
Model::is_running(void)
{
	return _running;
}

/* is_empty() {{{2 */
bool
Model::is_empty(void)
{
	return !_task_list;
}

/* actions {{{1 */
/* add_task() {{{2 */
Task&
Model::add_task(
    Task	&task)
{
	if (!_task_list)
	    return *(_task_list = &task);
	else
	    return _task_list->add_next(task);
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
