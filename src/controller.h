/** controller.h
 */

#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <string>
#include <functional>
#include "model.h"
#include "view.h"

using std::string;

typedef	std::function<int(int)>	bind_t;

struct keybind_t
{
	const char	ch;
	const string	name;
	bind_t		funct;
};

class Controller
{
public:
	Controller();
	~Controller();

	virtual	int	handle (const char) = 0;

protected:
	Model		*model;
	View		*view;
	keybind_t	*keymap;
};

#endif /* !_CONTROLLER_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
