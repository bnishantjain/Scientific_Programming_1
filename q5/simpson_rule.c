#include<stdio.h>
#include<common_include.h>
#include<math.h>

/* 
* FUCNTION NAME   : simpson_rule
 * PARAMETER IN    : int number_of_interval
 * PARAMETER OUT   : float area
 * PURPOSE         : This function finds the area of sin(x) using
 *                   simpson_rule for the given number of interval
 */

float simpson_rule(int number_of_interval)
{
        float area = 0.0;
        int i = 0;
        float interval_value = 0.0;

        interval_value = (UPPER_BOUND - LOWER_BOUND)/number_of_interval;

        area = sin(LOWER_BOUND) + sin(UPPER_BOUND);

        for (i = 1; i <= (number_of_interval-1); i++)
        {
                if (i % 2 == 0)
                {
                        area += (2*sin(i*interval_value));
                }
                else
                {
                        area +=  (4*sin(i*interval_value));
                }
        }

        area = (area * interval_value)/3;

        return area;
}

