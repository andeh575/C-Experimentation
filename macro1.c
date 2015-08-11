// Author:	Andrew Graham
// Date:		11 August 2015
// Purpose:	Looking at the effects of Macros, Expansion, and Evaluation Order
#include <stdio.h>
#define MULTIPLY(a, b) a * b

int main(void)
{
	int i = 0;
	
	/* Expected Output:	15
	 * Actual Output:		9
	 * Explanation:			Macro arguments are not being evaluated before Macro Expansion. The result is:
	 *									
	 *									1 + 2 * 3 + 2 = 9
	 *
	 *									As opposed to:
	 *									(1 + 2) * (3 + 2) = 15
	 */
	i = MULTIPLY(1 + 2, 3 + 2);
	printf("%d\n", i);

	// We can force order of operations with () to get what we initially expected
	i = MULTIPLY((1 + 2), (3 + 2));
	printf("%d\n", i);
	
	return 0;
}