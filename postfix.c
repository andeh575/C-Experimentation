// Author:		Andrew Graham
// Date:			11 August 2015
// Purpose:	Experiment looking at postfix operators with gcc 4.9.3 on Windows 10
#include <stdio.h>

int main (void)
{
	int i = 1;
	
	/*	Expected Output: 	1 2 3
	 *	Actual Output:		2 1 3
	 *	Explanation:			The gcc compiler has freedom to evaluate in any order it wants - unless 
	 *									  forced with (). This leads to an interesting result in which the unary 
	 *										increment operator (postfix), ++, is first evaluated at the middle term, 
	 *										then the left most term (1 + 1: from the first i++), and finally i is 
	 *										evaluated at the last position (2 + 1: from the left-most i++).  
	 */
	printf("%d %d %d\n", i++, i++, i);

	return 0;
}