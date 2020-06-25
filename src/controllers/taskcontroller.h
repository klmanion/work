/** controllers taskcontroller.h
 */

#ifndef _CONTROLLERS_TASKCONTROLLER_H_
#define _CONTROLLERS_TASKCONTROLLER_H_

#include "../controller.h"

class TaskController : public virtual Controller
{
	TaskController();
	~TaskController();

	int	handle (const char);
};

#endif /* !_CONTROLLERS_TASKCONTROLLER_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
