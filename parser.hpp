#ifndef PARSER_HPP
#define PARSER_HPP

#include <deque>
#include <memory>
#include <list>

#include "lexer.hpp"
#include "context.hpp"
#include "token.hpp"
#include "expr.hpp"
#include "type.hpp"
#include "translator.hpp"
#include "stmt.hpp"
#include "decl.hpp"

class parser
{
	lexer& m_lexer;
	context& m_cxt;
	std::list<scope>& m_stack;
	std::deque<token_ptr> tokens;
	translator sema;
	value_map& m_values;
public:	
	parser( lexer&, context&, std::list<scope>&, value_map& );

	token_kind lookahead();
	token_ptr consume();
	token_ptr match( token_kind tk );
	token_ptr match_if( token_kind tk );
	
	expr* expression();
	expr* assignment_expression();
	expr* additive_expression();
	expr* multiplicative_expression();
	expr* conditional_expression();
	expr* logical_or_expression();
	expr* logical_and_expression();
	expr* equality_expression();
	expr* ordering_expression();	
	expr* unary_expression();	
	expr* primary_expression();
	expr* id_expression();

	stmt* statement();
	stmt* print_statement();
	stmt* while_statement();
	stmt* if_statement();
	stmt* block_statement();
	stmt* declaration_statement();
	stmt* expression_statement();

	decl* declaration();
	decl* variable_declaration();
	decl* function_declaration();
	decl* parameter_declaration();

	const type* type_specifier();

	symbol* identifier();

	decl* program();
};


#endif
