#ifndef CHECK_HPP
#define CHECK_HPP

#include "expr.hpp"
#include "type.hpp"

struct check_visitor : expr::visitor
{
	const type* r;
	void visit( bool_expr* e );
	void visit( and_expr* e );
	void visit( or_expr* e );
	void visit( not_expr* e );
	void visit( cond_expr* e );
	void visit( equal_expr* e );
	void visit( inequal_expr* e );
	void visit( int_expr* e );
	void visit( neg_expr* e );
	void visit( add_expr* e );
	void visit( sub_expr* e );
	void visit( mul_expr* e );
	void visit( div_expr* e );
	void visit( rem_expr* e );
	void visit( less_expr* e );
	void visit( greater_expr* e );
	void visit( lesseq_expr* e );
	void visit( greatereq_expr* e );
	void visit( ref_expr* e );
	void visit( value_expr* e );
	void visit( assign_expr* e );
};

const type* check( expr* e );

#endif
