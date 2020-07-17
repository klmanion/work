/** viewopts.h
 */

#ifndef _VIEWOPTS_H_
#define _VIEWOPTS_H_

class Viewopts
{
public:
	Viewopts();

	bool	show_completed (void);
	Viewopts&	show_completed_set (const bool);
	Viewopts&	show_completed_toggle (void);

private:
	bool	_show_completed;
};

#endif /* !_VIEWOPTS_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
