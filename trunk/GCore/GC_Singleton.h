#ifndef GCORE_SINGLETON_H
#define GCORE_SINGLETON_H
#pragma once

#include "GC_Common.h"

namespace GCore
{
		
	/** Singleton : class with an unique occurency.
		
		A Singleton class MyClass should heritate from Singleton<T> 
		like the following example :
		\code
		class Myclass : public Singleton<MyClass>
		\endcode
		@par
		The class instance should be created using Myclass::create()
		and destroyed using Myclass::destroy() (but this one is optional).
		@par
		To access the class instance, use Myclass::getSingleton() or
		MyClass::getSingletonPtr(). 

	*/
	template<typename T>
	class Singleton
	{
		static T* ms_singleton;
		protected:

			Singleton()
			{
				GC_ASSERT( ms_singleton == nullptr , "Tried to create a singleton twice!" );
				ms_singleton = static_cast<T*>(this);
			}

			~Singleton()
			{
				GC_ASSERT( ms_singleton != nullptr , "Tried to destroy a singleton twice!" );
				ms_singleton = nullptr;
			}

		public:
			static inline void create()
			{
				if(ms_singleton)return;
				new T();
			}
			static inline T& getSingleton()
			{
				GC_ASSERT( ms_singleton , "Tried to get a singleton before creating it!" );
				return *ms_singleton;
			}
			static inline T* getSingletonPtr()
			{
				GC_ASSERT(ms_singleton , "Tried to get a singleton before creating it!" );
				return ms_singleton;
			}
			static inline void destroy()
			{
				if(ms_singleton)delete ms_singleton;
				ms_singleton = nullptr;
			}
			static inline bool isValid()
			{
				return ( ms_singleton != nullptr );
			}
	};

	template <typename T> T* Singleton <T>::ms_singleton = nullptr;
}
#endif