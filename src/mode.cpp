/** mode.cpp
 */

#include "mode.h"

/* genetic functs {{{1 */
/* constructor {{{2 */
Mode::Mode()
{
	_model = Model::get_instance();
}

/* destructor {{{2 */
Mode::~Mode()
{

}

/* predicates {{{1 */
/* is_running() {{{2 */
bool
Mode::is_running(void)
{
	return _model->is_running();
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
