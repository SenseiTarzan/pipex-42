/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:48:16 by gcaptari          #+#    #+#             */
/*   Updated: 2023/12/19 09:24:11 by gcaptari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

/*
* permet de bypass de varialbe la limit de la normes 42 XD
*/
struct s_bypass_trim
{
	size_t	len_start;
	size_t	len_end;
	size_t	real_len;
};

struct s_bypass_split
{
	size_t	spliter_count;
	size_t	len;
};

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef char *	t_string;

/* ft_isalnum verifie si le char est un chiffre ou une lettre */
int		ft_isalnum(int c);

/* ft_isalpha verifie si le char est une lettre */
int		ft_isalpha(int c);

/* ft_isascii verifie si le char est ascii */
int		ft_isascii(int c);

/* ft_isdigit verifie si le char est un chiffre */
int		ft_isdigit(int c);

/* ft_isprint verifie si le char est imprimable */
int		ft_isprint(int c);

/* ft_strlen donne la taille d'un (char *) */
size_t	ft_strlen(const char *str);

/* ft_toupper permet de mettre en minuscule */
int		ft_tolower(int c);

/* ft_toupper permet de mettre en majuscule */
int		ft_toupper(int c);

/* ft_calloc permet de faire un malloc en remplissant de valeur NULL */
void	*ft_calloc(size_t count, size_t size);

/* ft_strdup permet de faire un clone d'un text */
char	*ft_strdup(const char *src);

/*
* ft_substr permet de re faire un nouveau
* par rapport a une source avec un start et un end
*/
char	*ft_substr(const char *str, unsigned int start, size_t end);

/* 
* ft_memchr permet de regarde si dans un buffer avec une taille n,
* il y a le caracter chercher et 
* donne la suite a la position de l'occurance
*/
void	*ft_memchr(const void *v1, int c, size_t n);

/* 
* ft_strchr permet de regarde si dans un (char *),
* il y a le caracter et donne la suite a la position de l'occurance
*/
char	*ft_strchr(const char *str, int c);

/*
* ft_strrchr permet de regarde si dans un (char *),
* il y a le caracter le plus a droit et
* donne la suite a la position de l'occurance
*/
char	*ft_strrchr(const char *str, int c);

/* 
* ft_strstr permet de regarde si dans un char *,
* il y a un (char *) et donne la suite a la position de l'occurance
*/
char	*ft_strstr(const char *haystack, const char *neddle);

/*
* ft_strnstr permet de regarde si dans un (char *),
* il y a un (char *) dans une taille max et
* donne la suite a la position de l'occurance
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

/*
* ft_memcmp permet de comparer 2 buffer entre eux avec une taille n
*/
int		ft_memcmp(const void *v1, const void *v2, size_t n);

/*
* ft_strncmp permet de comparer 2 (char *) entre eux avec une taille n
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
* ft_strtrim permet de trim un (char *) par rapport un set
*/
char	*ft_strtrim(const char *str, const char *set);

/*
* ft_strjoin permet de joindre 2 (char *)
*/
char	*ft_strjoin(const char *s1, const char *s2);

/*
* ft_strlcpy permet de copy la src dans la dest avec la taille de la dest
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/*
* ft_strlcat permet d'ajouter la src dans la dest avec la taille de la dest
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size);

/*
* ft_memcpy permet de copy la src dans la dest avec la taille de la dest
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

/*
* ft_memmove permet de copy la src dans la dest avec la taille de la dest
* avec un protection pour par perde des donner dans la src
*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/*
* ft_memset permet de remplire dans le dest avec la taille precise
* des char dans 
*/
void	*ft_memset(void *dest, int c, size_t n);

/*
* ft_bzero permet de remplire dans le dest avec la taille precise
* des NULL dans dans 
*/
void	ft_bzero(void *dest, size_t n);

/*
* ft_atoi permet de transformer un (char *) en int
*/
int		ft_atoi(const char *str);
/*
* ft_atoi permet de transformer un int en (char *)
*/
char	*ft_itoa(int n);
/*
* ft_split split un (char *) par rapport un sepparator
*/
char	**ft_split(const char *str, char sepparator);
/*
* ft_strmapi permet de faire un (char *) avec un (char *) et une fonction
*/
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
/*
* ft_striteri permet de faire un (char *) avec une fonction
*/
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
/*
* ft_putchar_fd permet d'ecrire un char dans un file descriptor
*/
void	ft_putchar_fd(char c, int fd);
/*
* ft_putstr_fd permet d'ecrire un (char *) dans un file descriptor
*/
void	ft_putstr_fd(const char *s, int fd);
/*
* ft_putendl_fd permet d'ecrire un (char *) dans un file descriptor
* avec un \n a la fin
*/
void	ft_putendl_fd(const char *s, int fd);
/*
* ft_putnbr_fd permet d'ecrire un int dans un file descriptor
*/
void	ft_putnbr_fd(int n, int fd);
/*
* ft_lstnew permet de creer un nouveau maillon
*/
t_list	*ft_lstnew(void *content);
/*
* ft_lstadd_front permet d'ajouter un maillon au debut de la liste
*/
void	ft_lstadd_front(t_list **alst, t_list *new);
/*
* ft_lstsize permet de donner la taille de la liste
*/
int		ft_lstsize(t_list *lst);
/*
* ft_lstlast permet de donner le dernier maillon de la liste
*/
t_list	*ft_lstlast(t_list *lst);
/*
* ft_lstadd_back permet d'ajouter un maillon a la fin de la liste
*/

void	ft_lstadd_back(t_list **alst, t_list *new);
/*
* ft_lstdelone permet de supprimer un maillon de la liste
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/*
* ft_lstclear permet de supprimer tous les maillons de la liste
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));
/*
* ft_lstiter permet d'appliquer une fonction a tous les maillons de la liste
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));
/*
* ft_lstmap permet de creer une nouvelle liste avec une fonction
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif