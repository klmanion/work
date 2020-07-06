/** mode.h: controlls the event loop
 */

#ifndef _MODE_H_
#define _MODE_H_

#include <string>
#include <functional>
#include "model.h"

using std::string;

typedef	std::function<int(int)>	bind_t;

struct keybind_t
{
	const char	ch;
	const string	name;
	bind_t		funct;
};

class Mode
{
public:
	Mode();
	virtual	~Mode();

	virtual	void	loop (void) = 0;
	virtual int	handle (const char) = 0;
	virtual	void	print (void) = 0;

	bool	is_running (void);

protected:
	Model		*_model;
	keybind_t	*_keymap;
};

#endif /* !_MODE_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
