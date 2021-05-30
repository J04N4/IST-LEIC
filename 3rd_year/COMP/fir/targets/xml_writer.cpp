#include <string>
#include "targets/xml_writer.h"
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

//---------------------------------------------------------------------------

void fir::xml_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void fir::xml_writer::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}
void fir::xml_writer::do_double_node(cdk::double_node * const node, int lvl) {
  // EMPTY
}
void fir::xml_writer::do_not_node(cdk::not_node * const node, int lvl) {
  // EMPTY
}
void fir::xml_writer::do_and_node(cdk::and_node * const node, int lvl) {
  // EMPTY
}
void fir::xml_writer::do_or_node(cdk::or_node * const node, int lvl) {
  // EMPTY
}

//---------------------------------------------------------------------------

void fir::xml_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<sequence_node size='" << node->size() << "'>" << std::endl;
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void fir::xml_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  process_literal(node, lvl);
}

void fir::xml_writer::do_string_node(cdk::string_node * const node, int lvl) {
  process_literal(node, lvl);
}

//---------------------------------------------------------------------------

void fir::xml_writer::do_unary_operation(cdk::unary_operation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void fir::xml_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  do_unary_operation(node, lvl);
}

//---------------------------------------------------------------------------

void fir::xml_writer::do_binary_operation(cdk::binary_operation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void fir::xml_writer::do_add_node(cdk::add_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void fir::xml_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void fir::xml_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void fir::xml_writer::do_div_node(cdk::div_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void fir::xml_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void fir::xml_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void fir::xml_writer::do_le_node(cdk::le_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void fir::xml_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void fir::xml_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void fir::xml_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}
void fir::xml_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  do_binary_operation(node, lvl);
}

//---------------------------------------------------------------------------

void fir::xml_writer::do_variable_node(cdk::variable_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->name() << "</" << node->label() << ">" << std::endl;
}

void fir::xml_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

void fir::xml_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

  node->lvalue()->accept(this, lvl);
  reset_new_symbol();

  node->rvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}


//---------------------------------------------------------------------------

void fir::xml_writer::do_evaluation_node(fir::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}


//---------------------------------------------------------------------------

void fir::xml_writer::do_read_node(fir::read_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void fir::xml_writer::do_while_node(fir::while_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("block", lvl + 2);
  node->doblock()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void fir::xml_writer::do_if_node(fir::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  closeTag(node, lvl);
}

void fir::xml_writer::do_if_else_node(fir::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->thenblock()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  openTag("else", lvl + 2);
  node->elseblock()->accept(this, lvl + 4);
  closeTag("else", lvl + 2);
  closeTag(node, lvl);
}

/********************************************************************************************
 * Added
 ********************************************************************************************/
void fir::xml_writer::do_variable_declaration_node(fir::variable_declaration_node *const node, int lvl) {
/*  openTag(node, lvl);
  if(node->name() != NULL)
  	os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->name() << "</" << node->label() << ">" << std::endl;

  openTag("is_public", lvl + 2);
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->is_public() << "</" << node->label() << ">" << std::endl;
  closeTag("is_public", lvl + 2);

  openTag("is_required", lvl + 2);
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->is_required() << "</" << node->label() << ">" << std::endl;
  closeTag("is_required", lvl + 2);

 openTag("type", lvl + 2);
  if(node->type() != NULL)
  	os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->type()->name() << "</" << node->label() << ">" << std::endl;
  closeTag("type", lvl + 2);


  openTag("value", lvl + 2);
  if(node->value() != NULL)
  	node->value()->accept(this, lvl + 4);
  closeTag("value", lvl + 2);
  closeTag(node, lvl);*/
}

void fir::xml_writer::do_block_node(fir::block_node *const node, int lvl) {
  openTag(node, lvl);
  openTag("declaration", lvl + 2);
  node->declaration()->accept(this, lvl + 4);
  closeTag("declaration", lvl + 2);
  openTag("instruction", lvl + 2);
  node->instruction()->accept(this, lvl + 4);
  closeTag("instruction", lvl + 2);
  closeTag(node, lvl);
}

void fir::xml_writer::do_function_definition_node(fir::function_definition_node *const node, int lvl) {
  /*openTag(node, lvl);
  openTag("qualifier", lvl + 2);
  node->qualifier()->accept(this, lvl + 4);
  closeTag("qualifier", lvl + 2);
  
  if(node->identifier() != NULL)
  	os() << std::string(lvl, ' ') << "<" << node->identifier() << ">" << node->identifier() << "</" << node->identifier() << ">" << std::endl;
  
  openTag("arguments", lvl + 2);
  node->arguments()->accept(this, lvl + 4);
  closeTag("arguments", lvl + 2);
  
  openTag("prologue", lvl + 2);
  node->prologue_block()->accept(this, lvl + 4);
  closeTag("prologue", lvl + 2);
  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
   openTag("epilogue", lvl + 2);
  node->epilogue_block()->accept(this, lvl + 4);
  closeTag("epilogue", lvl + 2);
  closeTag(node, lvl);*/
}

void fir::xml_writer::do_function_declaration_node(fir::function_declaration_node *const node, int lvl) {
/*  openTag(node, lvl);
  if(node->identifier() != NULL)
  	os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->identifier() << "</" << node->label() << ">" << std::endl;
  
  openTag("is_public", lvl + 2);
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->is_public() << "</" << node->label() << ">" << std::endl;
  closeTag("is_public", lvl + 2);

  openTag("is_required", lvl + 2);
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->is_required() << "</" << node->label() << ">" << std::endl;
  closeTag("is_required", lvl + 2);

  openTag("arguments", lvl + 2);
  node->arguments()->accept(this, lvl + 4);
  closeTag("arguments", lvl + 2);
  closeTag(node, lvl);*/
}

void fir::xml_writer::do_function_call_node(fir::function_call_node *const node, int lvl) {
/*  openTag(node, lvl);
  if(node->identifier() != NULL)
  	os() << std::string(lvl, ' ') << "<" << *(node->identifier()) << ">" << std::endl;
  
  openTag("arguments", lvl + 2);
  if(node->arguments() != NULL)
  	node->arguments()->accept(this, lvl + 4);
  closeTag("arguments", lvl + 2);
  closeTag(node, lvl);*/
}

//---------------------------------------------------------------------------
void fir::xml_writer::do_write_node(fir::write_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("expression", lvl + 2);
  node->expressions()->accept(this, lvl + 4);
  closeTag("expression", lvl + 2);
  closeTag(node, lvl);
}

void fir::xml_writer::do_writeln_node(fir::writeln_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("expression", lvl + 2);
  node->expressions()->accept(this, lvl + 4);
  closeTag("expression", lvl + 2);
  closeTag(node, lvl);
}
//---------------------------------------------------------------------------

void fir::xml_writer::do_leave_node(fir::leave_node *const node, int lvl) {
  openTag(node, lvl);
  openTag("literal", lvl);
  if (node->literal())
    node->literal()->accept(this, lvl + 2);
  closeTag("literal", lvl);
  closeTag(node, lvl);
}

void fir::xml_writer::do_restart_node(fir::restart_node *const node, int lvl) {
  openTag(node, lvl);
  openTag("literal", lvl);
  if (node->literal())
    node->literal()->accept(this, lvl + 2);
  closeTag("literal", lvl);
  closeTag(node, lvl);
}

void fir::xml_writer::do_return_node(fir::return_node *const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------
void fir::xml_writer::do_pointer_index_node(fir::pointer_index_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("pointer", lvl + 2);
  if(node->pointer() != NULL)
  	node->pointer()->accept(this, lvl + 4);
  closeTag("pointer", lvl + 2);
  openTag("index", lvl);
  if(node->index() != NULL)
  	node->index()->accept(this, lvl + 4);
  closeTag("index", lvl);
  closeTag(node, lvl);
}

void fir::xml_writer::do_stack_alloc_node(fir::stack_alloc_node *const node, int lvl) {
  openTag(node, lvl);
  openTag("index", lvl);
  if(node->index() != NULL)
  	node->index()->accept(this, lvl + 4);
  closeTag("index", lvl);
  closeTag(node, lvl);
}

void fir::xml_writer::do_address_of_node(fir::address_of_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("lvalue", lvl);
  node->lvalue()->accept(this, lvl + 4);
  openTag("lvalue", lvl);
  closeTag(node, lvl);
}

void fir::xml_writer::do_sizeof_node(fir::sizeof_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("expression", lvl + 2);
  node->expression()->accept(this, lvl + 4);
  closeTag("expression", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------
void fir::xml_writer::do_null_node(fir::null_node *const node, int lvl) {
  openTag(node, lvl);
  closeTag(node, lvl);
}

void fir::xml_writer::do_identity_node(fir::identity_node *const node, int lvl) {
  do_unary_operation(node, lvl);
}
