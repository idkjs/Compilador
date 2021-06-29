// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Ast$Nqcc = require("./Ast.bs.js");
var Token$Nqcc = require("./Token.bs.js");
var Words$Nqcc = require("./Words.bs.js");

function generate_factor(ast, reg) {
  switch (ast.TAG | 0) {
    case /* UnOp */0 :
        var factor = ast._1;
        var ope = ast._0;
        if (Token$Nqcc.identificador(ope) === "LogNeg") {
          var return_unop = "    cmpl   $0, " + (Words$Nqcc.registro(reg) + ("\n    movl   $0, " + (Words$Nqcc.registro(1) + "\n    sete   %al ")));
          generate_factor(factor, 0);
          console.log(return_unop);
          return ;
        }
        var return_unop$1 = "    " + (Words$Nqcc.tradu(Token$Nqcc.identificador(ope)) + ("    " + Words$Nqcc.registro(1)));
        generate_factor(factor, 0);
        console.log(return_unop$1);
        return ;
    case /* Err_fac */1 :
        throw {
              RE_EXN_ID: "Match_failure",
              _1: [
                "Generator.re",
                2,
                2
              ],
              Error: new Error()
            };
    case /* Const */2 :
        var decimal = String(ast._0);
        var return_statement = "    movl    " + (decimal + (", " + Words$Nqcc.registro(reg)));
        console.log(return_statement);
        return ;
    
  }
}

function generate_termino(ast) {
  switch (ast.TAG | 0) {
    case /* Ter */0 :
        return generate_factor(ast._0, 0);
    case /* Err_ter */1 :
        throw {
              RE_EXN_ID: "Match_failure",
              _1: [
                "Generator.re",
                20,
                2
              ],
              Error: new Error()
            };
    case /* BinOp */2 :
        generate_factor(ast._1, 0);
        generate_factor(ast._2, 1);
        var return_termino = "    " + (Words$Nqcc.tradu(Token$Nqcc.identificador(ast._0)) + ("    " + Words$Nqcc.registro(1)));
        console.log(return_termino);
        return ;
    
  }
}

function generate_exp(ast_exp) {
  switch (ast_exp.TAG | 0) {
    case /* Expr */0 :
        return generate_termino(ast_exp._0);
    case /* Err_exp */1 :
        throw {
              RE_EXN_ID: "Match_failure",
              _1: [
                "Generator.re",
                31,
                2
              ],
              Error: new Error()
            };
    case /* BinOp */2 :
        var ope = ast_exp._0;
        generate_termino(ast_exp._1);
        generate_termino(ast_exp._2);
        if (Token$Nqcc.identificador(ope) === "Negation") {
          var return_unop = "    " + (Words$Nqcc.tradu(Token$Nqcc.identificador(ope)) + ("    " + Words$Nqcc.registro(1)));
          console.log(return_unop);
        }
        var return_exp = "    add    " + (Words$Nqcc.registro(0) + (", " + Words$Nqcc.registro(1)));
        console.log(return_exp);
        return ;
    
  }
}

function visit_statement(name) {
  var return_statement = "    " + Words$Nqcc.tradu(name);
  console.log(return_statement);
  
}

function generate_statement(ast) {
  if (Ast$Nqcc.identi_statement(ast) !== true) {
    return ;
  }
  var name_state = Ast$Nqcc.ext_name_statement(ast);
  var node_exp = Ast$Nqcc.ext_statement(ast);
  generate_exp(node_exp);
  return visit_statement(name_state);
}

function gen_function_code(ast) {
  if (Ast$Nqcc.identi_fun_decl(ast) !== true) {
    return ;
  }
  var functionName = Ast$Nqcc.ext_name_fun_decl(ast);
  var node_statement = Ast$Nqcc.ext_fun_decl(ast);
  console.log("_" + (functionName + ":"));
  return generate_statement(node_statement);
}

function generate_code(ast) {
  if (Ast$Nqcc.identi_prog(ast) === true) {
    var node_prog = Ast$Nqcc.ext_prog(ast);
    console.log("    .globl _main");
    return gen_function_code(node_prog);
  }
  console.log(Ast$Nqcc.ext_prog_err(ast));
  
}

exports.generate_factor = generate_factor;
exports.generate_termino = generate_termino;
exports.generate_exp = generate_exp;
exports.visit_statement = visit_statement;
exports.generate_statement = generate_statement;
exports.gen_function_code = gen_function_code;
exports.generate_code = generate_code;
/* No side effect */
