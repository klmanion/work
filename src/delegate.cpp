/** delegate.cpp
 */

#include "delegate.h"

/* genetic functs {{{1 */
/* ctor {{{2 */
Delegate::Delegate()
{
	_mode = new Normal();
}

/* dtor {{{2 */
Delegate::~Delegate()
{

}

/* engage() {{{1 */
int
Delegate::engage(void)
{
	Mode *retv;

	while (Model::get_instance()->is_running())
	    {
		if ((retv=_mode->loop()))
		    {
			delete _mode;
			_mode = retv;
		    }
	    }

	return EXIT_SUCCESS;
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
