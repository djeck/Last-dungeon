 
#ifndef DATAREAD_H
#define DATAREAD_H

#include <iostream>
#include <irrlicht/irrlicht.h>

namespace LD
{
	namespace GO
	{

	  class dataread
	  {
		  public :
                         dataread(std::string& name);
			 static void read(void);
	          protected:
		    std::string* localisation;
			
	  };
	}
}

#endif
