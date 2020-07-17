/** viewopts.cpp
 */

#include "viewopts.h"

/* genetic functions {{{1 */
/* ctor {{{2 */
Viewopts::Viewopts()
{
	_show_completed = false;
}

/* show_completed {{{1 */
/* show_completed() {{{2 */
bool
Viewopts::show_completed(void)
{
	return _show_completed;
}

/* show_completed_set() {{{2 */
Viewopts&
Viewopts::show_completed_set(
    const bool	show_completed)
{
	_show_completed = show_completed;

	return *this;
}

/* show_completed_toggle() {{{2 */
Viewopts&
Viewopts::show_completed_toggle(void)
{
	show_completed_set(!show_completed());

	return *this;
}

/* }}}1 */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
