<div align="center">

# HexaC - Compilateur langague c
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
- [ ] 5.9 Compiler l’affectation à une lvalue quelconque
- [ ] 5.10 Compiler des tableaux
- [ ] 5.11 Compiler les appels de fonction ayant jusqu’à 6 arguments
- [ ] 5.12 Compiler les boucles for
- [ ] 5.13 Test sur des programmes complexes
- [ ] 5.14 Gestion correcte des types
- [ ] 5.15 Compiler les appels de fonction ayant plus de 6 arguments

## Build
Le projet est complié avec cmake

```bash
$ cd cmake
$ cmake ../ && make
```

## Usage

```bash
$ ./HexaC test.c test # Compiler test.c avec notre programme
$ as -o test.o test.s # Assemblage
$ gcc -lc test.o      # Création de l'executable
$ ./a.out             # Lancer l'executable
```
