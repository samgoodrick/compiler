#include <iostream>
#include <iterator>
#include <typeinfo>
#include <vector>
#include <list>

#include "expr.hpp"
#include "context.hpp"
#include "eval.hpp"
#include "check.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "stmt.hpp"
#include "scope.hpp"

using stack = std::list<scope>;
using value_map = std::unordered_map<decl*, expr*>;

int main()
{
	context context;
	keyword_table kw;
	symbol_table sym;
	stack stk;
	value_map vm;

	// push the global scope
	stk.emplace_front();

	bool quit = false;
	std::string input;

	while( !quit )
	{
		std::string line;
		getline(std::cin, line);

		if( line == "quit" )
			quit = true;
		else 
			input += line + '\n';
		// input = "var int x = 5; print 5;";
		// input = "5 + 7;";
		
		// if( dynamic_cast<expr_stmt*>(s) )
		// {
		// 	expr_stmt* exst = dynamic_cast<expr_stmt*>( s );			
		// 	std::cout << eval(*exst->expression) << '\n';
		// }
		// else if( dynamic_cast<decl_stmt*>(s) )
		// {
		// 	decl_stmt* d = dynamic_cast<decl_stmt*>( s );
		// 	var_decl* v = dynamic_cast<var_decl*>( d->entity );
		// 	ref_expr* h = new ref_expr( d->entity, v->m_init, context );
		// 	std::cout << eval( *h ) << '\n';
		// 	expr* n = new int_expr( 8, context );
		// 	h->set_value( n );
		// 	std::cout << eval( *h ) << '\n';
		// }
		// break;
	}
	lexer l ( input.begin(), input.end(), kw, sym );
	parser p( l, context, stk, vm );
	p.program();
	
	return 0;
}
