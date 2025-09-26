/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:16:51 by hgutterr          #+#    #+#             */
/*   Updated: 2025/09/24 13:16:51 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    quick_sort_array(int *arr, int low, int high)
{
    int i;
    int j;
    int pivot;
    int tmp;

    if (low >= high)
        return ;
    pivot = arr[high];
    i = low - 1;
    j = low;
    while (j < high)
    {
        if (arr[j] <= pivot)
        {
            i++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
        j++;
    }
    tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    quick_sort_array(arr, low, i);
    quick_sort_array(arr, i + 2, high);
}


