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
	Task&	cursor (void);
	Task*	cursor_ptr (void);
	void	cursor_set (Task &);

	bool	is_running (void);
	bool	no_tasks (void);

	Task&	add_next (Task &);
	Task&	add_next (void);

	Task&	add_child (Task &);
	Task&	add_child (void);

	Task&	new_task (void);

private:
	Task	*_task_list;
	Task	*_cursor;

	bool	_running;
};

#endif /* !_MODEL_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
