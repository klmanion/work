/** view.h
 */

#ifndef _VIEW_H_
#define _VIEW_H_

#include "system.h"
#include NCURSES_INCL
#include "model.h"

class View
{
public:
	View();
	virtual ~View();

	virtual	void	print (void) = 0;

private:
	Model	*model;
	/* TODO: ncurses window */
};

#endif /* !_VIEW_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
