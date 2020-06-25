/** controller.cpp
 */

#include "controller.h"

/* genetic functs {{{1 */
/* constructor {{{2 */
Controller::Controller()
{
	model = Model::get_instance();
}

Controller::~Controller()
{
	delete view;
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
