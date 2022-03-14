/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jchoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:20:39 by jchoi             #+#    #+#             */
/*   Updated: 2022/03/14 18:20:50 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define ALEN ('Z' - 'A' + 1)
int    main(void){
    char str[1000002];
    int  count[ALEN] = {0,};
    int  most = 0;
    int  i, index;
    
    scanf("%s",str);
    i = 0;
    while (str[i])
    {
        if ('A' <= str[i] && str[i] <= 'Z')
            (count[str[i] - 'A'])++;
        else
            (count[str[i] - 'a'])++;
        i++;
    }
    i = 0;
    while (i < ALEN)
    {
        if (most < count[i])
            most = count[i];
        i++;
    }
    index = -1;
    i = 0;
    while (i < ALEN)
    {
        if (most == count[i])
        {
            if (0 <= index)
                break;
            index = i;
        }
        i++;
    }
    printf("%c", (i == ALEN) * ('A' + index) + (i < ALEN)*'?');
    return (0);
}
