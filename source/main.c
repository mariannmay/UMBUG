//////////////////////////////////////////////////////////////////
//                                                              //
//    main program	                                            //
//    last edited by: Kane Anderson                             //
//    date: January 22, 2012                                    //
//																//
//	  This is where the magic starts							//
//                                                              //
//////////////////////////////////////////////////////////////////

#include "system/System.h"
#include "test application/TestApplication.h"

//////////////////////////////////////////////////////////////////

void main(void)
{
	system_initialize();

	while(true)
	{
		system_main();
	}
}
