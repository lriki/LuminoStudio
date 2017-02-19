
#include "../Core/EditorInterface.h"
#include "HC1ProjectLibrary.h"

namespace ls {

void HC1ProjectLibrary::OnInitializeWorkspace()
{
}

void HC1ProjectLibrary::OnActivateWorkspace()
{
	GetEditorInterface()->GetMainWindow()->CreateDockablePane(_T("Game scene list"), DockingArea::Left);
}


} // namespace ls
