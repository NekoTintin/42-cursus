# Libft

La **Libft** est une bibliothèque personnelle, elle contient des fonctions standards du C, ainsi que des fonctions supplémentaires.

## Partie 1 - Fonctions de la bibliothèque standard

## 1. **ft_strlen**
   - **Description :** Retourne la longueur de la chaîne de caractères `s`.
   - **Prototype :** `size_t ft_strlen(const char *s);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_strlen](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_strlen.c)

## 2. **ft_strchr**
   - **Description :** Recherche la première occurrence du caractère `c` dans la chaîne `s` et retourne un pointeur vers cette position.
   - **Prototype :** `char *ft_strchr(const char *s, int c);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_strchr](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_strchr.c)

## 3. **ft_strrchr**
   - **Description :** Recherche la dernière occurrence du caractère `c` dans la chaîne `s` et retourne un pointeur vers cette position.
   - **Prototype :** `char *ft_strrchr(const char *s, int c);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_strrchr](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_strrchr.c)

## 4. **ft_strncmp**
   - **Description :** Compare les `n` premiers caractères des chaînes `s1` et `s2`.
   - **Prototype :** `int ft_strncmp(const char *s1, const char *s2, size_t n);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_strncmp](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_strncmp.c)

## 5. **ft_memset**
   - **Description :** Remplit les `n` premiers octets de la zone mémoire pointée par `b` avec la valeur `c`.
   - **Prototype :** `void *ft_memset(void *b, int c, size_t len);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_memset](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_memset.c)

## 6. **ft_bzero**
   - **Description :** Remplace les `n` premiers octets de la zone mémoire pointée par `s` par des zéros.
   - **Prototype :** `void ft_bzero(void *s, size_t n);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_bzero](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_bzero.c)

## 7. **ft_memcpy**
   - **Description :** Copie `n` octets de la zone mémoire pointée par `src` vers la zone mémoire pointée par `dst`.
   - **Prototype :** `void *ft_memcpy(void *dst, const void *src, size_t n);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_memcpy](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_memcpy.c)

## 8. **ft_memmove**
   - **Description :** Déplace `n` octets de la zone mémoire pointée par `src` vers la zone mémoire pointée par `dst`, en gérant le chevauchement.
   - **Prototype :** `void *ft_memmove(void *dst, const void *src, size_t len);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_memmove](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_memmove.c)

## 9. **ft_memchr**
   - **Description :** Recherche la première occurrence de la valeur `c` dans la zone mémoire `s` de `n` octets.
   - **Prototype :** `void *ft_memchr(const void *s, int c, size_t n);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_memchr](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_memchr.c)

## 10. **ft_memcmp**
   - **Description :** Compare les `n` premiers octets des zones mémoire pointées par `s1` et `s2`.
   - **Prototype :** `int ft_memcmp(const void *s1, const void *s2, size_t n);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_memcmp](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_memcmp.c)

## 11. **ft_strlcpy**
   - **Description :** Copie jusqu'à `dstsize - 1` caractères de la chaîne `src` dans `dst`, en terminant par un caractère nul.
   - **Prototype :** `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_strlcpy](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_strlcpy.c)

## 12. **ft_strlcat**
   - **Description :** Concatène les `n` premiers caractères de `src` à `dst` jusqu'à `dstsize`, en terminant par un caractère nul.
   - **Prototype :** `size_t ft_strlcat(char *dst, const char *src, size_t dstsize);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_strlcat](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_strlcat.c)

## 13. **ft_strnstr**
   - **Description :** Recherche la première occurrence de la sous-chaîne `needle` dans la chaîne `haystack` jusqu'à `len` caractères.
   - **Prototype :** `char *ft_strnstr(const char *haystack, const char *needle, size_t len);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_strnstr](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_strnstr.c)

## 14. **ft_atoi**
   - **Description :** Convertit la chaîne de caractères `str` en un entier `int`.
   - **Prototype :** `int ft_atoi(const char *str);`
   - **Fonctions externes autorisées :** `Aucune`
   - **Dossier :** [Accéder à ft_atoi](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_atoi.c)

## 15. **ft_calloc**
   - **Description :** Alloue une zone mémoire de `count` éléments de `size` octets et l'initialise à zéro.
   - **Prototype :** `void *ft_calloc(size_t count, size_t size);`
   - **Fonctions externes autorisées :** `malloc`
   - **Dossier :** [Accéder à ft_calloc](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_calloc.c)

## 16. **ft_strdup**
   - **Description :** Duplique la chaîne de caractères `s1`.
   - **Prototype :** `char *ft_strdup(const char *s1);`
   - **Fonctions externes autorisées :** `malloc`
   - **Dossier :** [Accéder à ft_strdup](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_strdup.c)

# Partie 2 - Fonctions supplémentaires de `libft`

## 1. **ft_substr**
   - **Prototype :** `char *ft_substr(char const *s, unsigned int start, size_t len);`
   - **Paramètres :**
     - `s` : La chaîne de laquelle extraire la nouvelle chaîne.
     - `start` : L’index de début de la nouvelle chaîne dans la chaîne `s`.
     - `len` : La taille maximale de la nouvelle chaîne.
   - **Valeur de retour :** La nouvelle chaîne de caractères. `NULL` si l’allocation échoue.
   - **Description :** Alloue (avec `malloc`) et retourne une chaîne de caractères issue de la chaîne `s`. Cette nouvelle chaîne commence à l'index `start` et a pour taille maximale `len`.
   - **Fonctions externes autorisées :** `malloc`
   - **Dossier :** [Accéder à ft_substr](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_substr.c)

## 2. **ft_strjoin**
   - **Prototype :** `char *ft_strjoin(char const *s1, char const *s2);`
   - **Paramètres :**
     - `s1` : La chaîne de caractères préfixe.
     - `s2` : La chaîne de caractères suffixe.
   - **Valeur de retour :** La nouvelle chaîne de caractères. `NULL` si l’allocation échoue.
   - **Description :** Alloue (avec `malloc`) et retourne une nouvelle chaîne, résultat de la concaténation de `s1` et `s2`.
   - **Fonctions externes autorisées :** `malloc`
   - **Dossier :** [Accéder à ft_strjoin](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_strjoin.c)

## 3. **ft_strtrim**
   - **Prototype :** `char *ft_strtrim(char const *s1, char const *set);`
   - **Paramètres :**
     - `s1` : La chaîne de caractères à trimmer.
     - `set` : Le set de référence de caractères à trimmer.
   - **Valeur de retour :** La chaîne de caractères trimmée. `NULL` si l’allocation échoue.
   - **Description :** Alloue (avec `malloc`) et retourne une copie de la chaîne `s1`, sans les caractères spécifiés dans `set` au début et à la fin de la chaîne de caractères.
   - **Fonctions externes autorisées :** `malloc`
   - **Dossier :** [Accéder à ft_strtrim](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_strtrim.c)

## 4. **ft_split**
   - **Prototype :** `char **ft_split(char const *s, char c);`
   - **Paramètres :**
     - `s` : La chaîne de caractères à découper.
     - `c` : Le caractère délimiteur.
   - **Valeur de retour :** Le tableau de nouvelles chaînes de caractères résultant du découpage. `NULL` si l’allocation échoue.
   - **Description :** Alloue (avec `malloc`) et retourne un tableau de chaînes de caractères obtenu en séparant `s` à l’aide du caractère `c`, utilisé comme délimiteur. Le tableau doit être terminé par `NULL`.
   - **Fonctions externes autorisées :** `malloc`, `free`
   - **Dossier :** [Accéder à ft_split](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_split.c)

## 5. **ft_itoa**
   - **Prototype :** `char *ft_itoa(int n);`
   - **Paramètres :**
     - `n` : L’entier à convertir.
   - **Valeur de retour :** La chaîne de caractères représentant l’entier. `NULL` si l’allocation échoue.
   - **Description :** Alloue (avec `malloc`) et retourne une chaîne de caractères représentant l’entier `n` reçu en argument. Les nombres négatifs doivent être gérés.
   - **Fonctions externes autorisées :** `malloc`
   - **Dossier :** [Accéder à ft_itoa](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_itoa.c)

## 6. **ft_strmapi**
   - **Prototype :** `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));`
   - **Paramètres :**
     - `s` : La chaîne de caractères sur laquelle itérer.
     - `f` : La fonction à appliquer à chaque caractère.
   - **Valeur de retour :** La chaîne de caractères résultant des applications successives de `f`. Retourne `NULL` si l’allocation échoue.
   - **Description :** Applique la fonction `f` à chaque caractère de la chaîne de caractères `s`, passant son index comme premier argument et le caractère lui-même comme second argument. Une nouvelle chaîne de caractères est créée (avec `malloc`), résultant des applications successives de `f`.
   - **Fonctions externes autorisées :** `malloc`
   - **Dossier :** [Accéder à ft_strmapi](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_strmapi.c)

## 7. **ft_striteri**
   - **Prototype :** `void ft_striteri(char *s, void (*f)(unsigned int, char*));`
   - **Paramètres :**
     - `s` : La chaîne de caractères sur laquelle itérer.
     - `f` : La fonction à appliquer à chaque caractère.
   - **Valeur de retour :** Aucune
   - **Description :** Applique la fonction `f` à chaque caractère de la chaîne de caractères transmise comme argument, et en passant son index comme premier argument. Chaque caractère est transmis par adresse à `f` afin d’être modifié si nécessaire.
   - **Fonctions externes autorisées :** Aucune
   - **Dossier :** [Accéder à ft_striteri](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_striteri.c)

## 8. **ft_putchar_fd**
   - **Prototype :** `void ft_putchar_fd(char c, int fd);`
   - **Paramètres :**
     - `c` : Le caractère à écrire.
     - `fd` : Le descripteur de fichier sur lequel écrire.
   - **Valeur de retour :** Aucune
   - **Description :** Écrit le caractère `c` sur le descripteur de fichier donné.
   - **Fonctions externes autorisées :** `write`
   - **Dossier :** [Accéder à ft_putchar_fd](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_putchar_fd.c)

## 9. **ft_putstr_fd**
   - **Prototype :** `void ft_putstr_fd(char *s, int fd);`
   - **Paramètres :**
     - `s` : La chaîne de caractères à écrire.
     - `fd` : Le descripteur de fichier sur lequel écrire.
   - **Valeur de retour :** Aucune
   - **Description :** Écrit la chaîne de caractères `s` sur le descripteur de fichier donné.
   - **Fonctions externes autorisées :** `write`
   - **Dossier :** [Accéder à ft_putstr_fd](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_putstr_fd.c)

## 10. **ft_putendl_fd**
   - **Prototype :** `void ft_putendl_fd(char *s, int fd);`
   - **Paramètres :**
     - `s` : La chaîne de caractères à écrire.
     - `fd` : Le descripteur de fichier sur lequel écrire.
   - **Valeur de retour :** Aucune
   - **Description :** Écrit la chaîne de caractères `s` sur le descripteur de fichier donné suivie d’un retour à la ligne.
   - **Fonctions externes autorisées :** `write`
   - **Dossier :** [Accéder à ft_putendl_fd](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_putendl_fd.c)

## 11. **ft_putnbr_fd**
   - **Prototype :** `void ft_putnbr_fd(int n, int fd);`
   - **Paramètres :**
     - `n` : L’entier à écrire.
     - `fd` : Le descripteur de fichier sur lequel écrire.
   - **Valeur de retour :** Aucune
   - **Description :** Écrit l’entier `n` sur le descripteur de fichier donné.
   - **Fonctions externes autorisées :** `write`
   - **Dossier :** [Accéder à ft_putbnr_fd](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_putbnr_fd.c)

# Partie Bonus

## 1. **ft_lstnew**
- **Prototype**: `t_list *ft_lstnew(void *content);`
- **Description**: Alloue (avec `malloc(3)`) et retourne un nouvel élément de type `t_list`, initialisé avec le contenu passé en argument.
- **Paramètres**:
  - `content`: Pointeur vers le contenu à stocker dans le nouvel élément.
- **Fonctions externes autorisées**: malloc
- **Dossier :** [Accéder à ft_lstnew](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_lstnew.c)

## 2. **ft_lstadd_front**
- **Prototype**: `void ft_lstadd_front(t_list **lst, t_list *new);`
- **Description**: Ajoute l’élément `new` au début de la liste pointée par `lst`.
- **Paramètres**:
  - `lst`: Pointeur vers le pointeur de la première cellule de la liste.
  - `new`: Pointeur vers l'élément à ajouter.
- **Fonctions externes autorisées**: Aucune
- **Dossier :** [Accéder à ft_lstadd_front](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_lstadd_front.c)

## 3. **ft_lstsize**
- **Prototype**: `int ft_lstsize(t_list *lst);`
- **Description**: Retourne le nombre d’éléments dans la liste.
- **Paramètres**:
  - `lst`: Pointeur vers le premier élément de la liste.
- **Fonctions externes autorisées**: Aucune
- **Dossier :** [Accéder à ft_lstsize](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_lstsize.c)

## 4. **ft_lstlast**
- **Prototype**: `t_list *ft_lstlast(t_list *lst);`
- **Description**: Retourne le dernier élément de la liste.
- **Paramètres**:
  - `lst`: Pointeur vers le premier élément de la liste.
- **Fonctions externes autorisées**: Aucune
- **Dossier :** [Accéder à ft_lstlast](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_lstlast.c)

## 5. **ft_lstadd_back**
- **Prototype**: `void ft_lstadd_back(t_list **lst, t_list *new);`
- **Description**: Ajoute l’élément `new` à la fin de la liste pointée par `lst`.
- **Paramètres**:
  - `lst`: Pointeur vers le pointeur de la première cellule de la liste.
  - `new`: Pointeur vers l'élément à ajouter.
- **Fonctions externes autorisées**: Aucune
- **Dossier :** [Accéder à ft_lstadd_back](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_lstadd_back.c)

## 6. **ft_lstdelone**
- **Prototype**: `void ft_lstdelone(t_list *lst, void (*del)(void*));`
- **Description**: Supprime l’élément `lst` de la liste et libère la mémoire allouée pour son contenu en utilisant la fonction `del`.
- **Paramètres**:
  - `lst`: Pointeur vers l'élément à supprimer.
  - `del`: Fonction de suppression du contenu de l'élément. Elle prend en paramètre un pointeur vers le contenu à libérer.
- **Fonctions externes autorisées**: free
- **Dossier :** [Accéder à ft_lstdelone](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_lstdelone.c)

## 7. **ft_lstclear**
- **Prototype**: `void ft_lstclear(t_list **lst, void (*del)(void*));`
- **Description**: Supprime tous les éléments de la liste et libère la mémoire allouée pour chaque élément en utilisant la fonction `del`.
- **Paramètres**:
  - `lst`: Pointeur vers le pointeur de la première cellule de la liste.
  - `del`: Fonction de suppression du contenu de chaque élément. Elle prend en paramètre un pointeur vers le contenu à libérer.
- **Fonctions externes autorisées**: free
- **Dossier :** [Accéder à ft_lstclear](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_lstclear.c)

## 8. **ft_lstiter**
- **Prototype**: `void ft_lstiter(t_list *lst, void (*f)(void *));`
- **Description**: Applique la fonction `f` à chaque élément de la liste.
- **Paramètres**:
  - `lst`: Pointeur vers le premier élément de la liste.
  - `f`: Fonction à appliquer à chaque élément de la liste. Elle prend en paramètre un pointeur vers le contenu de l'élément.
- **Fonctions externes autorisées**: Aucune
- **Dossier :** [Accéder à ft_lstiter](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_lstiter.c)

## 9. **ft_lstmap**
- **Prototype**: `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));`
- **Description**: Applique la fonction `f` à chaque élément de la liste et crée une nouvelle liste résultante. Si une erreur survient, la fonction `del` est utilisée pour libérer la mémoire.
- **Paramètres**:
  - `lst`: Pointeur vers le premier élément de la liste.
  - `f`: Fonction de transformation appliquée à chaque élément de la liste. Elle prend en paramètre un pointeur vers le contenu de l'élément et retourne un pointeur vers le contenu transformé.
  - `del`: Fonction de suppression du contenu en cas d'erreur. Elle prend en paramètre un pointeur vers le contenu à libérer.
- **Fonctions externes autorisées**: malloc, free
- **Dossier :** [Accéder à ft_lstmap](https://github.com/NekoTintin/42-cursus/tree/main/2.Libft/ft_lstmap.c)

[Accéder au PDF](https://github.com/NekoTintin/42-cursus/blob/main/2.Libft/fr.subject.pdf)