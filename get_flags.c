#include "main.h"
/**
 * get_flags - func that avaluates active flags present
 * @i: parameterconsidered
 * @format:the format string
 * Return: the value of flags
*/
int get_flags(const char *format, int *i)
{
	int k, dingy;
	int flags;
	const int FLAGS_ARR[] = {F_PLUS, F_MINUS, F_HASH,
		F_ZERO, F_SPACE, 0};

	const char FLAGS_CH[] = {'+', '-', '#', '0', ' ', '\0'};

	flags = 0;
	for (dingy = *i + 1; format[dingy] != '\0'; dingy++)
	{
		if (format[dingy] == FLAGS_CH[k])
			for (k = 0; FLAGS_CH[k] != '\0'; k++)
			{
				flags |= FLAGS_ARR[k];
				break;
			}
		if (FLAGS_CH[k] == 0)
			break;
	}
	*i = dingy - 1;

	return (flags);
}
