<div align="center">

# HexaC - Compilateur langage C
#### Hexanome H4312

</div>

## Features

- [x] 5.1 Générer un squelette vide
- [x] 5.2 Enregistrement d’activation et ABI
- [x] 5.3 Compiler un programme qui fait un putchar()
- [x] 5.4 Compiler l’affectation vers une variable
- [x] 5.5 Compiler des expressions
- [x] 5.6 Compiler le if ... else
- [x] 5.7 Compiler les boucles while
- [x] 5.8 Compiler le retour de valeur
- [x] 5.9 Compiler l’affectation à une lvalue quelconque
- [ ] 5.10 Compiler des tableaux
- [x] 5.11 Compiler les appels de fonction ayant jusqu’à 6 arguments
- [ ] 5.12 Compiler les boucles for
- [ ] 5.13 Test sur des programmes complexes
- [ ] 5.14 Gestion correcte des types
- [ ] 5.15 Compiler les appels de fonction ayant plus de 6 arguments

### Points notables

Vis à vis des fonctionnalitées décrites ci-dessus, beaucoup de bugs ont été corrigés depuis la présentation, notamment :
- La vérification de la concordance de types en analyse statique fonctionne à nouveau (elle ne respecte pas le standard C : les types doivent correspondre exactement, sauf entre int32_t et int64_t)
- Les fonctions récursives fonctionnent
- Les paramètres fonctionnent

### Points manquants

- Pas de tests automatisés ni d'unit tests : nous avons uniquement utilisé les tests front-end et back-end fournis sur Moodle avec une commande du type :

```bash
for file in FrontEndTests/ValidPrograms/*
do
./HexaC "$file" test && ./test
done
```

- Très peu de commentaires. Cependant, le nommage a été choisi pour être assez explicite, et l'organisation des classes a été bien étudiée. Nous pensons donc que le code s'auto-documente assez bien dans sa globalité.

- Certains endroits du code de génération d'assembleur sont hardcodés de façon assez inflexible, mais fonctionnent très bien pour les fonctionnalitées présentées ici.

- Pas d'optimisation.

- La gestion des erreurs fonctionne bien pour le frontend (lexicale, syntaxique et sémantique), mais est incomplète pour le backend.

- La génération d'IR pour les opérations binaires suivantes n'est pas implémentée :

DIV '/', MOD '%', ASSIGN_MULT '*=', ASSIGN_DIV '/=', ASSIGN_MOD '%=', ASSIGN_ADD '+=', ASSIGN_SUB '-=', ASSIGN_OR '|=', ASSIGN_AND '&=', ASSIGN_XOR '^=', NEQ '!=', OR '||', AND '&&', BOR '|', BAND '&', LSH '<<', RSH '>>', XOR '^', GT '>', GE '>=', LE '<=', COMMA ','

- Les opérations binaires dont la génération d'IR est actuellement implémentée sont :

ADD '+', SUB '-', MULT '*', EQ '==', ASSIGN '='

- La génération d'IR pour les opérations unaires suivantes n'est pas implémentée :

POST_INC '++', POST_DEC '--', PRE_DEC '--', PLUS '+', MINUS '-', NOT '!'

- Les opérations unaires dont la génération d'IR est actuellement implémentée sont :

PRE_INC '++'

## Build
Le projet est compilé avec cmake

```bash
$ mkdir build
$ cd build
$ cmake ../ && make
```

## Usage

Compilation simple :

```bash
$ ./HexaC test.c test # Compiler test.c avec notre programme
$ ./test              # Lancer l'executable
```

**ATTENTION, les options utilisées ci-dessous sont hardcodées sur le 3ème paramètre (nous n'avons pas eu le temps de mettre en place un vrai parsing des arguments du programme via une bibliothèque externe).**

Pour activer l'analyse statique (pour l'instant uniquement vérification de la concordance des types) :

```bash
$ ./HexaC test.c test -a
```

Pour activer le pretty print de l'AST :

```bash
$ ./HexaC test.c test -p
```

