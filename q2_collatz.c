#include<stdio.h>
#include<stdlib.h>

#define FIRST_NUM (4)
#define SECOND_NUM (2)
#define THIRD_NUM (1)
#define MAX_DISPLAY_STRING_LEN (40)

/********************************************************************
 * FUCNTION NAME   : collatz_conjecture
 * PARAMETER IN    : u_int num
 * PARAMETER OUT   : int result
 * PURPOSE         : This function find the collatz_conjecture
 *                   for the given number
 ********************************************************************/
u_int collatz_conjecture(u_int num)
{
	u_int result = 0;

	/* Check whether the num is odd or even*/
	if (num % 2 == 0)
	{
		result = num/2;
	}
	else
	{
		result = (3*num)+1;
	}

	/* Return the result as per the input num to this function*/
	return result;
}


/********************************************************************
 * FUCNTION NAME   : count_digits
 * PARAMETER IN    : u_int num
 * PARAMETER OUT   : int count
 * PURPOSE         : This function counts the number of digits
 *                   in the given number
 ********************************************************************/

u_int count_digits(u_int num)
{
	u_int count = 0;

        if (num == 0)
        {
           return count;
        }

	/* loop until the num becomes zero*/
	while(num != 0)
	{
		num /= 10;
		count++;
	}

	/*Return the number of digits given an interger*/
	return count;
}


/********************************************************************
 * FUCNTION NAME   : print_in_order
 * PARAMETER IN    : u_int num, int *str_position, int is_third_num
 * PARAMETER OUT   : void
 * PURPOSE         : This function used to display collatz conjecture
 *                   according to the specified format. It displays
 *                   40 characters at the maximum in a single line 
 *                   and if the length exceeds it displays the
 *                   remaining number in the next line
 ********************************************************************/

void print_in_order(u_int num, int *str_position, u_int is_third_num)
{
	u_int ndigits = 0;

	ndigits = count_digits(num);

	if (*str_position + 1 + ndigits  > MAX_DISPLAY_STRING_LEN)
	{
                /*Exceeds the 40 characeter in the single line*/
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

/********************************************************************
 * FUCNTION NAME   : main
 * PARAMETER IN    : int argc, char *argv[]
 * PARAMETER OUT   : int SUCCESS OR FAILURE
 * PURPOSE         : This is the main function for this program
 *                   it accepts the input number for which collatz
 *                   conjecture needs to obtained and displayed
 ********************************************************************/

int main(int argc, char *argv[])
{

	u_int num = 0;
	int ndigits = 0;
	int str_position = 0;

	/* Check that user specified valid number*/

	if (argc != 2)
	{
		printf("Please Provide the Proper Input\n");
		return 0;
	}

	/* The input is accepted in the string format and hence convert it to the integer*/
	num = atoi(argv[1]);
 
	/* Loop Througth until num = 4 resepctively*/
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
