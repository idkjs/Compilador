type factor =
  | UnOp(Token.token, factor)
  | Err_fac(string)
  | Const(int);
type termino =
  | Ter(factor)
  | Err_ter(string)
  | BinOp(Token.token, factor, factor);

type exp =
  | Expr(termino)
  | Err_exp(string)
  | BinOp(Token.token, termino, termino);

type statement =
  | Assign(string, exp)
  | Return(exp)
  | Err_state(string);
type fun_decl =
  | Err_fun(string)
  | Fun(string, statement);
type prog =
  | Prog(fun_decl)
  | Err_prog(string);

let identi_prog = (t: prog) =>
  /** To identify that the node is of type prog */
  {
    switch (t) {
    | Prog(fun_decl) => true
    | Err_prog(string) => false
    };
  };

let identi_fun_decl = (t: fun_decl) =>
  /** To identify that the node is of type fun_decl * */
  {
    switch (t) {
    | Err_fun(string) => false
    | Fun(string, statement) => true
    };
  };

let identi_statement = (t: statement) =>
  /** To identify that the node is of type fun_decl statement */
  {
    switch (t) {
    | Assign(string, exp) => true
    | Return(exp) => true
    | Err_state(string) => false
    };
  };

let identi_exp = (t: exp) =>
  /** To identify that the node is of type fun_decl exp */
  {
    switch (t) {
    | Expr(termino) => true
    | Err_exp(string) => false
    | BinOp(token, ter1, ter2) => true
    };
  };
let identi_termino = (t: termino) => {
  switch (t) {
  | Ter(factor) => true
  | Err_ter(string) => false
  | BinOp(token, fac1, fac2) => true
  };
};
let identi_factor = (t: factor) => {
  switch (t) {
  | UnOp(token, factor) => true
  | Err_fac(string) => false
  | Const(int) => true
  };
};

let ext_prog = (t: prog) =>
  /** To extract the fun_decl node from prog */
  {
    switch (t) {
    | Prog(fun_decl) => fun_decl
    };
  };

let ext_name_fun_decl = (t: fun_decl) =>
  /** To extract the name of the fun */
  {
    switch (t) {
    | Fun(string, statement) => string
    };
  };

let ext_fun_decl = (t: fun_decl) =>
  /** To extract the node statement from fun_decl */
  {
    switch (t) {
    | Fun(string, statement) => statement
    };
  };

let ext_name_statement = (t: statement) => {
  switch (t) {
  | Assign(string, exp) => string
  | Return(exp) => "ReturnKeyword"
  };
};

let ext_statement = (t: statement) => {
  switch (t) {
  | Assign(string, exp) => exp
  | Return(exp) => exp
  };
};

let ext_prog_err = (t: prog) =>
  /** To extract the node fun_decl from prog*/
  {
    switch (t) {
    | Err_prog(string) => string
    };
  };

let ext_fun_err = (t: fun_decl) =>
  /** To extract the node fun_decl from prog*/
  {
    switch (t) {
    | Err_fun(string) => string
    };
  };

let ext_state_err = (t: statement) =>
  /** To extract the node fun_decl from prog*/
  {
    switch (t) {
    | Err_state(string) => string
    };
  };

let ext_exp_err = (t: exp) =>
  /** To extract the node fun_decl from prog*/
  {
    switch (t) {
    | Err_exp(string) => string
    };
  };
let ext_ter_err = (t: termino) => {
  switch (t) {
  | Err_ter(string) => string
  };
};
let ext_fac_err = (t: factor) => {
  switch (t) {
  | Err_fac(string) => string
  };
};

let printAST = ast => {
  Js.log("AST del parser aqui");
  Js.log(ast);
  ast;
};
