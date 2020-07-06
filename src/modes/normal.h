/** modes normal.h
 */

#ifndef _MODES_NORMAL_H_
#define _MODES_NORMAL_H_

#include "../mode.h"

class Normal : public virtual Mode
{
public:
	Normal();

	void	loop (void);
	int	handle (const char);
	void	print (void);

	Task&	add_task (void);
	Task&	add_task (Task &);

private:
	Task	*_tcur;
};

#endif /* !_MODES_NORMAL_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
