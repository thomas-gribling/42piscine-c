/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgriblin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:26:52 by tgriblin          #+#    #+#             */
/*   Updated: 2023/09/03 13:55:00 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*place_val(char *sqr, char val, int row, int col)
{
	if (sqr[col + row * 4] != '0' && sqr[col + row * 4] != val)
		sqr[0] = 'E';
	else
		sqr[col + row * 4] = val;
	return (sqr);
}

char	*fill_empty(char *sqr)
{
	int	i;
	int	j;
	int	count;
	int	count_missing;
	int	missing;

	i = 0;
	j = 0;
	count_missing = 0;
	missing = 0;
	while (i <= 3)
	{
		j = 0;
		count = 0;
		count_missing = 0;
		while (j <= 3)
		{
			count += sqr[i + j * 4] - '0';
			if (sqr[i + j * 4] == '0')
			{
				count_missing++;
				missing = j;
			}
			j++;
		}
		if (count >= 6 && count_missing == 1)
			place_val(sqr, 10 - count + '0', missing, i);
		j = 0;
		count = 0;
		count_missing = 0;
		while (j <= 3)
		{
			count += sqr[j + i * 4] - '0';
			if (sqr[j + i * 4] == '0')
			{
				count_missing++;
				missing = j;
			}
			j++;
		}
		if (count >= 6 && count_missing == 1)
			place_val(sqr, 10 - count + '0', i, missing);
		i++;
	}
	return (sqr);
}

char	*fill_row(char *sqr, int row, int rule_l, int rule_r)
{
	if (rule_l == '1')
		place_val(sqr, '4', row, 0);
	if (rule_l == '4')
	{
		place_val(sqr, '1', row, 0);
		place_val(sqr, '2', row, 1);
		place_val(sqr, '3', row, 2);
		place_val(sqr, '4', row, 3);
	}
	if (rule_r == '1')
		place_val(sqr, '4', row, 3);
	if (rule_r == '4')
	{
		place_val(sqr, '1', row, 3);
		place_val(sqr, '2', row, 2);
		place_val(sqr, '3', row, 1);
		place_val(sqr, '4', row, 0);
	}
	if (rule_l == '3' && rule_r == '2')
		place_val(sqr, '4', row, 2);
	if (rule_l == '2' && rule_r == '3')
		place_val(sqr, '4', row, 1);
	if (rule_l == '2' && sqr[3 + row * 4] == '4')
		place_val(sqr, '3', row, 0);
	if (rule_r == '2' && sqr[0 + row * 4] == '4')
		place_val(sqr, '3', row, 3);
	return (sqr);
}

char	*fill_col(char *sqr, int col, int rule_t, int rule_b)
{
	if (rule_t == '1')
		place_val(sqr, '4', 0, col);
	if (rule_t == '4')
	{
		place_val(sqr, '1', 0, col);
		place_val(sqr, '2', 1, col);
		place_val(sqr, '3', 2, col);
		place_val(sqr, '4', 3, col);
	}
	if (rule_b == '1')
		place_val(sqr, '4', 3, col);
	if (rule_b == '4')
	{
		place_val(sqr, '1', 3, col);
		place_val(sqr, '2', 2, col);
		place_val(sqr, '3', 1, col);
		place_val(sqr, '4', 0, col);
	}
	if (rule_t == '3' && rule_b == '2')
		place_val(sqr, '4', 2, col);
	if (rule_t == '2' && rule_b == '3')
		place_val(sqr, '4', 1, col);
	if (rule_t == '2' && sqr[col + 12] == '4')
		place_val(sqr, '3', 0, col);
	if (rule_b == '2' && sqr[col] == '4')
		place_val(sqr, '3', 3, col);
	return (sqr);
}

char	*fill_sqr(char *sqr, char *rules)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (rules[i] != ' ')
		{
			if (i <= 14)
				fill_col(sqr, (i % 8) / 2, rules[i], rules[i + 8]);
			else
				fill_row(sqr, (i % 8) / 2, rules[i], rules[i + 8]);
		}
		if (i == 6 || i == 22)
			i += 9;
		else
			i++;
	}
	place_val(sqr, '3', 1, 1);
	fill_empty(sqr);
	fill_empty(sqr);
	return (sqr);
}
