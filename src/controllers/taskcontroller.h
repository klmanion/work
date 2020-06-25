/** controllers taskcontroller.h
 */

#ifndef _CONTROLLERS_TASKCONTROLLER_H_
#define _CONTROLLERS_TASKCONTROLLER_H_

#include "../controller.h"

class TaskController : public virtual Controller
{
private:
	TaskController();
public:
	TaskController(View *);
	~TaskController();

	int	handle (const char);
};

#endif /* !_CONTROLLERS_TASKCONTROLLER_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
