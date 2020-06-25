/** controller.cpp
 */

#include "controller.h"

/* genetic functs {{{1 */
/* constructor {{{2 */
Controller::Controller()
{
	_model = Model::get_instance();
	_view = (View *)NULL;
	_keymap = (keybind_t *)NULL;
}

Controller::~Controller()
{

}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
