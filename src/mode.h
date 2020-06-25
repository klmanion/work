/** mode.h: controlls the event loop
 */

#ifndef _MODE_H_
#define _MODE_H_

#include "model.h"
#include "controller.h"

class Mode
{
public:
	Mode();
	~Mode();

	virtual	int	loop (void) = 0;

protected:
	Model		*_model;
	Controller	*_controller;
	/* view objects are in the derrived classes */
};

#endif /* !_MODE_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
