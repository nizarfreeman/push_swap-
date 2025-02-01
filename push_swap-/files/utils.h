/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:35:39 by nfaska            #+#    #+#             */
/*   Updated: 2025/01/24 17:50:12 by nfaska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>

int		ll_check(unsigned long long res, int flag, int *flag_2);
int		ft_atoi(const char *s, int *flag_2);
int		count_words(const char *s, char c);
int		get_len(const char *s, char c);
int		ft_isdigit(int c);

char	**ft_split(const char *s, char c);

void	skip_spaces(const char **s);
void	sign_check(const char	**s, int *flag, int *double_sign);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	free_array(char **arr);
void	skip_delim(const char	**s, char c);

#endif
