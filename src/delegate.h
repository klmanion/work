/** delegate.h
 * Delegates execution to the various modes.
 */

#ifndef _DELEGATE_H_
#define _DELEGATE_H_

#include "mode.h"

class Delegate
{
public:
	Delegate();
	~Delegate();

	int	engage (void);

private:
	Mode	*_mode;
};

#endif /* !_DELEGATE_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
