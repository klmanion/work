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

	/* accessors/mutators/predicates */
	bool	has_tag (void);
	string&	tag (void);
	string&	tag_set (string &);

	bool	has_description (void);
	string&	description (void);
	string&	description_set (string &);

	bool	is_folded (void);
	Task&	fold (void);
	Task&	unfold (void);
	Task&	fold_toggle (void);

	bool	is_selected (void);
	Task&	select (void);
	Task&	deselect (void);
	Task&	select_toggle (void);

	bool	has_next (void);
	Task&	next (void);
	Task&	next_tail (void);
	Task&	next_set (Task &);
	Task&	next_add (Task &);

	bool	has_prev (void);
	Task&	prev (void);
	Task&	prev_set (Task &);

	bool	has_children (void);
	Task&	children (void);
	Task&	children_tail (void);
	Task&	children_set (Task &);
	Task&	child_add (Task &);

	bool	has_parent (void);
	Task&	parent (void);
	Task&	parent_set (Task &);

	bool	is_cursed_over (void);

	/* cursing/positionality */
	Task&	above_coord (void);
	Task&	above_supord (void);
	Task&	below_coord (void);
	Task&	below_supord (void);

	/* printing */
	void	print (int = 0);

private:
	bool	_folded;
	bool	_selected;

	string	_tag;
	string	_desc;

	/* cdr */
	Task	*_next;
	Task	*_prev;
	Task	*_children;
	Task	*_parent;
};

#endif /* !_TASK_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
