/** model.cpp
 */

#include "model.h"

Model*
Model::get_instance(void)
{
	static Model model;
	return &model;
}

Model::Model()
{

}

Model::~Model()
{

}

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
