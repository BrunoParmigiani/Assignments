:-include('./db1.pl').
:-include('./db2.pl').

redeinfo :-
    format('Olá! Eu sou RedeInfo, eu respondo perguntas sobre redes de computadores.\n'),
    format('- Quando desejar encerrar o programa digite \"fim\".\n- Se desejar utilizar o programa denovo digite \"redeinfo.\".\n'),
    format('Sobre o que deseja saber?\n'),
    repeat,
        processa.

:- initialization(redeinfo).

processa :-
    Chars = [233, 201, 234, 202, 231, 199, 227, 195, 244, 212, 243, 211, 245, 213],
    Subs = [101, 101, 101, 101, 99, 99, 97, 97, 111, 111, 111, 111, 111, 111],
    write('\n- '),
    read_line_to_codes(user_input, Entrada_Bruta),
    exclude(=(0'?), Entrada_Bruta, Entrada_ASCII),
    filtra(Entrada_ASCII, Chars, Subs, Entrada_Filtrada),
    atom_codes(Entrada_Caixa, Entrada_Filtrada),
    downcase_atom(Entrada_Caixa, Entrada),
    consulta_base(Entrada),
    termina(Entrada).

substitui(_, _, [], []).
substitui(Elem, Sub, [Elem | X], [Sub | Y]) :- substitui(Elem, Sub, X, Y).
substitui(Elem, Sub, [H | X], [H | Y]) :- dif(H, Elem), substitui(Elem, Sub, X, Y).

filtra(LsIn, [], [], LsIn).
filtra(LsIn, [A | B], [C | D], LsFinal) :-
    filtra(LsIn, B, D, LsOut),
    substitui(A, C, LsOut, LsFinal).

consulta_base(Entrada) :-
    qa(Entrada, Resposta)
    -> write(Resposta), nl;
    write('Desculpe, eu não entendi a pergunta.'), nl.

termina(Entrada) :-
    Entrada = 'fim'.
