/** modes normal.h
 */

#ifndef _MODES_NORMAL_H_
#define _MODES_NORMAL_H_

#include "../mode.h"
#include "../views/taskview.h"

class Normal : Mode
{
public:
	Normal();

	int	loop (void);

private:
	TaskView	tview;
};

#endif /* !_MODES_NORMAL_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
