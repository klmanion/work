/** views taskview.h
 */

#ifndef _VIEWS_TASKVIEW_H_
#define _VIEWS_TASKVIEW_H_

#include "../view.h"
#include "../task.h"

class TaskView : public virtual View
{
public:
	TaskView();
	~TaskView();

	void	print (void);

private:
	Task	*_tcur;
};

#endif /* !_VIEWS_TASKVIEW_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
