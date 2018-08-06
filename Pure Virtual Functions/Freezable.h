#pragma once

/* Pure virtual class, representing the "freezable" capability. You can freeze and unfreeze the object. 
   we will freeze the saving account so you can't make deposit to it and will unfreeze it so you can make deposit to it.
   In Java or C# you call this interface class
*/

class Freezable
{
public:
	virtual void freeze() = 0;
	virtual void unfreeze() = 0;
};