#include "eval.hpp"

void eval_visitor::visit( bool_expr& e )
{
	r = e.get_value();
}

void eval_visitor::visit( and_expr& e )
{
}

int eval( expr& e )
{
	eval_visitor v;
	e.accept( v );
	return v.r;
}
