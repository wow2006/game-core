#ifndef GCORE_COMMON_H
#define GCORE_COMMON_H
#pragma once

/**********************************************
	Common defines for all GCore classes.
***********************************************/


//nullptr definition:
#ifndef nullptr
	#define nullptr (0)
#endif

//////////////////////////////////////////////////////////////////////////

//STL class dll interface warning disabled
#pragma warning(disable : 4251)	

//////////////////////////////////////////////////////////////////////////

//Cross-Platform definitions
#include "GC_CrossPlatform.h"

#if defined(DEBUG) || defined(_DEBUG)
	/// GCore Debug Mode
	#define GC_DEBUG
#endif

#ifndef GC_LIB_BUILD // DLL mode 
	#if defined ( GCORE_SOURCE ) 
	///Import / Export of dynamic lib functions/classes for Windows
		#define GCORE_API DllExport
	#else
	///Import / Export of dynamic lib functions/classes for Windows
		#define GCORE_API DllImport
	#endif
#else
	#define GCORE_API  // lib mode : don't export symbols
#endif


//Exception management
#include "GC_Exception.h" 


#endif