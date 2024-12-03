# ft_printf

Le but de ce projet est de recoder une version simplifiée de `printf`.
Il ne faut pas implémenter la gestion de buffer du `printf` original.

## Conversions
- `%c`: Affiche un seul charactère.
- `%s`: Affiche une chaîne de charactères (comme définie par la convention du C).
- `%p`: Affiche un pointer `void *` dans un format hexadecimal.
- `%d`: Affiche un nombre décimal (en base 10).
- `%i`: Affiche un `int` en base 10 (c'est la même chose que `%d`).
- `%u`: Affiche un `unsigned int` en base 10 (voir man).
- `%x`: Affiche un nombre en hexadecimal minuscule (base 16).
- `%X`: Affiche un nombre en hexadecimal majuscule (base 16).
- `%%`: Affiche un charactère `%`.