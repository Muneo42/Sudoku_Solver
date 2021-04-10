/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:02:06 by jopaning          #+#    #+#             */
/*   Updated: 2021/04/10 21:51:29 by jopaning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int grid[9][9] = {{5,0,0,0,0,0,4,2,7},
                {3,0,2,6,0,0,0,1,5},
                {1,0,0,2,0,0,6,8,0},
                {0,0,0,3,0,5,8,0,0},
                {0,5,1,7,2,6,0,4,0},
                {0,7,3,8,9,0,0,0,0},
                {6,0,0,4,0,9,0,3,2},
                {7,3,0,1,0,0,0,0,0},
                {2,1,9,0,0,0,7,0,0}};

int     ft_possible(int y, int x, int n)
{
    int i;
    int j;
    int x1;
    int y1;

    i = 0;
    j = 0;
    while (i < 9)
    {
        if (grid[y][i] == n)
            return (0);
        i++;
    }
    i = 0;
    while (i < 9)
    {
        if (grid[i][x] == n)
            return (0);
        i++;
    }
    i = 0;
    x1 = (x/3)*3;
    y1 = (y/3)*3;
    while (j < 3)
    {
        while (i < 3)
        {
            if (grid[y1 + i][x1 + j] == n)
                return (0);
            i++;
        }
        i = 0;
        j++;
    }
    return (1);
}

int     ft_solve()
{
    int i;
    int j;
    int n;
    int x;
    int y;

    x = 0;
    y = 0;
    n = 1;
    while (y < 9)
    {
        while (x < 9)
        {
            if (grid[y][x] == 0)
            {
                while (n < 10)
                {
                    if (ft_possible(y,x,n))
                    {
                        grid[y][x] = n;
                        ft_solve();
                        grid[y][x] = 0;
                    }
                    n++;
                }
                return (0);
            }
            x++;
        }
        x = 0;
        y++;
    }
    i = 0;
    j = 0;
    while (j < 9)
    {
        while (i < 9)
        {
            printf("%d", grid [j][i]);
            i++;
        }
        i = 0;
        printf("\n");
        j++;
    }
    return (1);
}

int     main()
{
    ft_solve();
    return 0;
}