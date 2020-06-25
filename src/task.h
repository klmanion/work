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
	~Task();

private:
	string	tag;
	string	descr;
};

#endif /* !_TASK_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
