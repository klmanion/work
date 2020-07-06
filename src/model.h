/** model.h
 */

#ifndef _MODEL_H_
#define _MODEL_H_

#include "task.h"

class Model
{
public:
	static	Model*	get_instance (void);
	~Model();

private:
	Model();

public:
	Task&	task_list (void);

	bool	is_running (void);
	bool	is_empty (void);

	Task&	add_task (Task &);

private:
	Task	*_task_list;

	bool	_running;
};

#endif /* !_MODEL_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
