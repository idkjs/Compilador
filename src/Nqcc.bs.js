// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Ast$Nqcc = require("./Ast.bs.js");
var Lexer$Nqcc = require("./Lexer.bs.js");
var Token$Nqcc = require("./Token.bs.js");
var Parser$Nqcc = require("./Parser.bs.js");
var Generator$Nqcc = require("./Generator.bs.js");

var program_text = "\n  int main(){ return 2;}\n  ";

Generator$Nqcc.generate_code(Ast$Nqcc.printAST(Parser$Nqcc.parse_program(Token$Nqcc.printTokenList(Lexer$Nqcc.lex(program_text)))));

exports.program_text = program_text;
/*  Not a pure module */
