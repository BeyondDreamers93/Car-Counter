#include "carCounter.h"

bool carCounter::countCars(float ReferencePt, float lineReferencePtY)
{
	if ((ReferencePt <= lineReferencePtY+1) && (ReferencePt >= (lineReferencePtY - 1)))
	{
		return 1;
	}
	return 0;
}