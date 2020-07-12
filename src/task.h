/** task.h
 */

#ifndef _TASK_H_
#define _TASK_H_

#include <string>

using std::string;

class Task
{
public:
	Task();
	Task(int);	/* from file descriptor */
	~Task();

	bool	is_folded (void);
	bool	is_selected (void);
	bool	is_cursed_over (void);

	Task&	add_next (Task &);
	Task&	add_child (Task &);

	Task&	select (void);
	Task&	deselect (void);
	Task&	select_toggle (void);

	void	print (int = 0);

private:
	string	_tag;
	string	_desc;

	bool	_folded;
	bool	_selected;

	/* cdr */
	Task	*_next;
	Task	*_children;
};

#endif /* !_TASK_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
