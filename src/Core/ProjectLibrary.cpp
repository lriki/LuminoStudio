
#include "ProjectLibrary.h"
#include "../HC1/HC1ProjectLibrary.h"	// TODO:

namespace ls {

RefPtr<ProjectLibrary> ProjectLibraryManager::CreateProjectLibrary(const String& id)
{
	return RefPtr<HC1ProjectLibrary>::MakeRef();	// TODO
}

} // namespace ls
