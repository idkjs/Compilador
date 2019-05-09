// Generated by BUCKLESCRIPT VERSION 4.0.6, PLEASE EDIT WITH CARE
'use strict';

var Belt_List = require("bs-platform/lib/js/belt_List.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

function tokenToString(acummulator, t) {
  var result;
  if (typeof t === "number") {
    switch (t) {
      case 0 : 
          result = "OpenBrace";
          break;
      case 1 : 
          result = "CloseBrace";
          break;
      case 2 : 
          result = "OpenParen";
          break;
      case 3 : 
          result = "CloseParen";
          break;
      case 4 : 
          result = "Semicolon";
          break;
      case 5 : 
          result = "ReturnKeyword";
          break;
      case 6 : 
          result = "IntKeyword";
          break;
      case 7 : 
          result = "Negation";
          break;
      case 8 : 
          result = "Bitwise";
          break;
      case 9 : 
          result = "LogNeg";
          break;
      case 10 : 
          result = "Addition";
          break;
      case 11 : 
          result = "Multiplication";
          break;
      case 12 : 
          result = "Division";
          break;
      case 13 : 
          result = "Invalid Token";
          break;
      
    }
  } else {
    result = t.tag ? "(Constant: " + (String(t[0]) + ")") : "(Id: " + (t[0] + ")");
  }
  return acummulator + (" " + (result + ","));
}

function tokenListToString(tokensList) {
  var comma_regexp = (/,$/);
  var stringList = Belt_List.reduce(tokensList, "[", tokenToString);
  return stringList.replace(comma_regexp, " ]");
}

function printTokenList(tokenList) {
  console.log(tokenListToString(tokenList));
  return tokenList;
}

function identificador(t) {
  if (typeof t === "number") {
    switch (t) {
      case 0 : 
          return "OpenBrace";
      case 1 : 
          return "CloseBrace";
      case 2 : 
          return "OpenParen";
      case 3 : 
          return "CloseParen";
      case 4 : 
          return "Semicolon";
      case 5 : 
          return "ReturnKeyword";
      case 6 : 
          return "IntKeyword";
      case 7 : 
          return "Negation";
      case 8 : 
          return "Bitwise";
      case 9 : 
          return "LogNeg";
      case 10 : 
          return "Addition";
      case 11 : 
          return "Multiplication";
      case 12 : 
          return "Division";
      case 13 : 
          return "Invalid Token";
      
    }
  } else if (t.tag) {
    return "Constant";
  } else {
    return "Id";
  }
}

function extrac(t) {
  if (typeof t === "number") {
    if (t === 13) {
      return "Invalid Token";
    } else {
      throw [
            Caml_builtin_exceptions.match_failure,
            /* tuple */[
              "Token.re",
              78,
              4
            ]
          ];
    }
  } else if (t.tag) {
    return String(t[0]);
  } else {
    return t[0];
  }
}

exports.tokenToString = tokenToString;
exports.tokenListToString = tokenListToString;
exports.printTokenList = printTokenList;
exports.identificador = identificador;
exports.extrac = extrac;
/* No side effect */
