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

private:
	/* TODO */
};

#endif /* !_MODEL_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
