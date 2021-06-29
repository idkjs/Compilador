let program_text = {|
  int main(){ return 2;}
  |};

open Lexer;
let _ = lex(program_text)
|> Token.printTokenList
|> Parser.parse_program
|> Ast.printAST
|> Generator.generate_code;
