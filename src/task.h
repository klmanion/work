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

	Task&	add_next (Task &);

	void	print (void);

private:
	string	_tag;
	string	_desc;

	/* cdr */
	Task	*_next;
	Task	*_children;
};

#endif /* !_TASK_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
