
#include "Project.h"
#include "ProjectLibrary.h"
#include "EditorCore.h"

namespace ls {


Project::Project()
	: m_data(RefPtr<ProjectData>::MakeRef())
	, m_projectLibrary(nullptr)
{
}

void Project::CreateProjectLibrary(const String& id, IEditor* editorInterface)
{
	m_projectLibrary = EditorCore::instance.GetProjectLibraryManager()->CreateProjectLibrary(id);
	m_projectLibrary->SetEditorInterface(editorInterface);
}

void Project::InitializeWorkspace()
{
	m_data->GetProjectPath().CreateDirectory();
	m_projectLibrary->OnInitializeWorkspace();
}

} // namespace ls
