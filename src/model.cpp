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
	_running = true;
}

/* dtor {{{2 */
Model::~Model()
{

}

/* predicates {{{1 */
/* is_running() {{{2 */
bool
Model::is_running(void)
{
	return _running;
}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
