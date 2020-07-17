/** model.h
 */

#ifndef _MODEL_H_
#define _MODEL_H_

#include "task.h"
#include "viewopts.h"

class Model
{
public:
	static	Model&	get_instance (void);
	~Model();

private:
	Model();

public:
	Task&	task_list (void);

	Task&	cursor (void);
	Task*	cursor_ptr (void);
	Task&	cursor_set (Task &);

	bool	is_running (void);
	bool	no_tasks (void);

	Viewopts&	view_options (void);

	Task&	new_task (void);

	Task&	add_next (Task &);
	Task&	add_next (void);

	Task&	add_child (Task &);
	Task&	add_child (void);

	Task&	curse_above_coord (void);	/* coordinate movement */
	Task&	curse_above_supord (void);	/* superordinate movement */
	Task&	curse_below_coord (void);
	Task&	curse_below_supord (void);
	Task&	curse_out (void);
	Task&	curse_in (void);

private:
	Task	*_task_list;
	Task	*_cursor;

	bool	_running;

	Viewopts	_viewopts;
};

#endif /* !_MODEL_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
