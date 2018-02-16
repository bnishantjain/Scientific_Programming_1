#include<stdio.h>
#include<stdlib.h>

#define FIRST_NUM (4)
#define SECOND_NUM (2)
#define THIRD_NUM (1)
#define MAX_DISPLAY_STRING_LEN (40)

/*


**/
u_int collatz_conjecture(u_int num)
{
	u_int result = 0;

	if (num % 2 == 0)
	{
		result = num/2;
	}
	else
	{
		result = (3*num)+1;
	}

	return result;
}


/*
*counts the number of digits
 *                   in the given number
 ********************************************************************/

u_int count_digits(u_int num)
{
	u_int count = 0;

        if (num == 0)
        {
           return count;
        }


	while(num != 0)
	{
		num /= 10;
		count++;
	}

	return count;
}


/*
*display collatz conjecture
 *    
 ********************************************************************/

void print_in_order(u_int num, int *str_position, u_int is_third_num)
{
	u_int ndigits = 0;

	ndigits = count_digits(num);

	if (*str_position + 1 + ndigits  > MAX_DISPLAY_STRING_LEN)
	{
      
		printf("\n");
		*str_position = 0;
	}

	if (is_third_num == 1 && num == 1)
	{
		printf("%u\n",num);
	}
	else
	{
		printf("%u, ", num);
	}

	*str_position = *str_position + 2 + ndigits;

	return;
}

/****/

int main(int argc, char *argv[])
{

	u_int num = 0;
	int ndigits = 0;
	int str_position = 0;

	

	if (argc != 2)
	{
		printf(" check the Input\n");
		return 0;
	}

	/* convert string  to the integer*/
	num = atoi(argv[1]);
 
	
	while (num > 0)
	{
		if (num == FIRST_NUM)
		{
			print_in_order(FIRST_NUM, &str_position, 0);
			print_in_order(SECOND_NUM, &str_position, 0);
			print_in_order(THIRD_NUM, &str_position, 1);

			break;
		}

		print_in_order(num, &str_position, 0);

		num = collatz_conjecture(num);
	}
   
	return 0;
}
