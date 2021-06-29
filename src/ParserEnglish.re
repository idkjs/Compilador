let rec parse_factor = (tokenList): (Ast.factor, list(Token.token)) => {
  let [token, ...remainingTokens] = tokenList; /* We take the next token that must be the number or UnOp */
  /* We check that the token is a unary operator */
  if (token
      |> Token.identificador == "Negation"
      || token
      |> Token.identificador == "Bitwise"
      || token
      |> Token.identificador == "LogNeg") {
    let (fac, remainingTokens) = parse_factor(remainingTokens); /* As it is a unary operator, we send the following element to be parsed, which must be a factor */
    if (Ast.identi_factor(fac) == true) {
      (
        /* Check that the received node is correct */
        Ast.UnOp(token, fac),
        remainingTokens /* We return the node */
      );
    } else {
      (
        Ast.Err_fac("Error, falta una constante u operador unario"),
        remainingTokens,
      );
    };
  } else if
    /*In case the token is not a unary operation, it must be a constant */
    (token |> Token.identificador == "Constant") {
    /*We check that the token is a constant*/
    let number = int_of_string(token |> Token.extrac); /*We store the value of the constant */
    (Ast.Const(number), remainingTokens); /*We return the constant node*/
  } else {
    (
      Ast.Err_fac("Error, a constant or unary operator is missing"),
      tokenList /*On error, returns an error node*/
    );
  };
};

// let parse_termino = tokenList: (Ast.termino, list (Token.token)) => {
//     let (fac1, tokenList) = parse_factor (tokenList); /* We send to call the parse_factor */
//     if (Ast.identi_factor (fac1) == true) { /* Check that the received node is correct */
//         let [token, ... r] = tokenList; /* We pop the list */
//         if ((token |> Token.identifier) ​​== "Multiplication" || (token |> Token.identifier) ​​== "Division") { /* Check if it is any of the * or /*/ operators
//             let oper = token; /* Saves the operation token in a variable */
//             let (fac2, r) = parse_factor (r); /* As I enter the if because it is a binary operation, the second term has to be parsed */
//             if (Ast.identi_factor (fac2) == true) { /* Check that the received node is correct */
//                 (Ast.BinOp (oper, fac1, fac2), r); /* Returns the node of the binary operation type exp */
//             } else {
//                 (Ast.Err_ter (Ast.ext_fac_err (fac1)), r); /* In case the node that returned the parse_factor is wrong, it returns an error node */
//             };

//         } else {
//             (Ast.Ter (fac1), tokenList); /* In case the token that followed the first term is not an operator, it only returns the factor 1 */
//         };
//     } else {
//         (Ast.Err_ter (Ast.ext_fac_err (fac1)), tokenList); /* In case the node that returned the parse_factor is wrong, it returns an error node */
//     };
//     };

// let parse_exp = tokenList: (Ast.exp, list (Token.token)) => {
//     let (ter1, tokenList) = parse_term (tokenList); /* We send to call the parse_termino */
//     if (Ast.identi_termino (ter1) == true) { /* Check that the received node is correct */
//         let [token, ... r] = tokenList; /* We pop the list */
//         if ((token |> Token.identifier) ​​== "Addition" || (token |> Token.identifier) ​​== "Negation") { /* Check if it is any of the operators + or - */
//             let oper = token; /* Saves the operation token in a variable */
//             let (ter2, r) = parse_term (r); /* As I enter the if because it is a binary operation, the second term has to be parsed */
//             if (Ast.identi_termino (ter2) == true) { /* Check that the received node is correct */
//                 (Ast.BinOp (oper, ter1, ter2), r); /* Returns the node of the binary operation type exp */
//             } else {
//                 (Ast.Err_exp (Ast.ext_ter_err (ter2)), r); /* In case the node that returned the parse_termino is wrong, it returns an error node */
//             };
//         } else {
//             (Ast.Expr (ter1), tokenList); /* In case the token that followed the first term is not an operator, it only returns the term 1 */
//         };
//     } else {
//         (Ast.Err_exp (Ast.ext_ter_err (ter1)), tokenList); /* In case the node that returned the parse_termino is wrong, it returns an error node */
//     };
//     };

// let parse_statement = tokenList: (Ast.statement, list (Token.token)) => { /* Get token list and return token and modified list */
//     let [token, ... remainingTokens] = tokenList; /* We remove the next token that should be the return */
//     if ((token |> Token.identifier) ​​== "ReturnKeyword") { /* We check that the token is return */
//         let var = token |> Token.identifier; /* We store the word return in a variable */
//         let (exp, remainingTokens) = parse_exp (remainingTokens); /* The element is an exp, so it is passed to the parse_exp */
//         if (Ast.identi_exp (exp) == true) { /* Check that the received node is correct */
//             let [token, ... remainingTokens] = remainingTokens; /* We remove the next token that must be ";" */
//             if ((token |> Token.identifier) ​​== "Semicolon") { /* Check that it is indeed the; come*/
//                 (Ast.Assign (var, exp), remainingTokens); /* Returns the node along with what is left of the list */
//             } else {
//                 (Ast.Err_state ("Error, missing;"), remainingTokens); /* In case the; return node error */
//             };
//         } else {
//             (Ast.Err_state (Ast.ext_exp_err (exp)), remainingTokens); /* In case the node that returned the parse_exp is wrong, it returns an error node */
//         };
//     } else {
//         (Ast.Err_state ("Error, return is missing"), remainingTokens); /* In case the token that comes is not the return, an error node is returned */
//     };
//   };

// let parse_function = tokenList: Ast.fun_decl => {
//     let [token, ... remainingTokens] = tokenList; /* We remove the first element of the token list, which in this case will be the identifier "Int" */
//       if (token |> Token.identificador == "IntKeyword") {
//       /*We check that the token is Intkeyword*/
//         let [token, ... remainingTokens] = remainingTokens; /* We remove the next element from the list that will be an id */
//         if (token |> Token.identifier ​​== "Id") { /* We check that the token is an Id */
//             let idName = token |> Token.extrac; /* We get the name of the id */
//             let [token, ... remainingTokens] = remainingTokens;
//             /* We remove the next element from the list that will be "(" */
//             if (token |> Token.identifier == "OpenParen") {
//               /* We check that the token is a "(" */
//                 let [token, ... remainingTokens] = remainingTokens;
//                 /* We remove the next element from the list that must be ")" */
//                 if (token |> Token.identifier == "CloseParen") {
//                   /* We check that the token is a) */
//                     let [token, ... remainingTokens] = remainingTokens;
//                      /* We remove the next element from the list that must be "{" */
//                     if (token |> Token.identifier == "OpenBrace") { /* We check that the token is a {*/
//                         let (return, remainingTokens) = parse_statement (remainingTokens); /* As the next thing in the list is the return is passed to the parse_statement */
//                         if (Ast.identi_statement (return) == true) { /* We check that the returned node has no error */
//                             let [token, ... remainingTokens] = remainingTokens; /* We remove the next element from the list, which should be} */
//                             if (token |> Token.identifier == "CloseBrace") { /* In theory you should check that what follows is the "}" */
//                                 Ast.Fun (idName, return); /* Returns the function node */
//                             } else {
//                                 Ast.Err_fun ("Error, missing}"); /* If} is missing, an error node is created and */ is returned
//                             };
//                         } else {
//                             Ast.Err_fun (Ast.ext_state_err (return)); /* In case the node returned by the parse_statement has an error, it creates another error node that will be returned */
//                         };
//                     } else { /* The rest of the error nodes in case one occurs */
//                         Ast.Err_fun ("Error, missing {");
//                     };
//                 } else {
//                     Ast.Err_fun ("Error, missing)");
//                 };
//             } else {
//                 Ast.Err_fun ("Error, missing (");
//             };
//           } else {
//             Ast.Err_fun ("Error, missing identifier");
//           };
//       } else {
//         Ast.Err_fun ("Error, missing int");
//       };
//     };

// let parse_program = tokenList: Ast.prog => {
//     let func_decl = parse_function (tokenList); /* We send to call the function that parses the functions */
//     if (Ast.identi_fun_decl (func_decl) == true) { /* We check that the returned node is not from an error */
//         Ast.Prog (func_decl); /* Returns the AST correctly */
//     } else {
//         Js.log (Ast.ext_fun_err (func_decl)); /* In case of error it tells us what the error was */
//         Ast.Err_prog ("Error in parser"); /* At the end it returns an error node that the generator will check if the Ast is valid or not */
//     };
//   };
