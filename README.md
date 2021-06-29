# Compilador

This project was carried out for the subject of compilers of the Faculty of Engineering in the semester 2019-1 It was carried out in the language reasonml

# Running

```sh
yarn build
node src/Nqcc.bs.js
```

```sh
> node src/Nqcc.bs.js
[ IntKeyword, (Id: main), OpenParen, CloseParen, OpenBrace, ReturnKeyword, (Constant: 2), Semicolon, CloseBrace ]
AST del parser aqui
{
  TAG: 0,
  _0: {
    TAG: 1,
    _0: 'main',
    _1: { TAG: 0, _0: 'ReturnKeyword', _1: [Object] }
  }
}
    .globl _main
_main:
    movl    2, %eax
    ret
```
