#include "GC.h"

namespace System{
	void GC::Collect(){	
		//TODO
		//DO NOTHING

		GC_collect_a_little();
		//GC_gcollect();
		//GC_gcollect_and_unmap();
	}

	void GC::SuppressFinalize(Object* obj){	
		//TODO
		//DO NOTHING				
	}

	void GC::Init()
	{
		GC_init();
		GC_allow_register_threads();
	}
}