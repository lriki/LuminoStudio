
#include "Project.h"
#include "EditorCore.h"

namespace ls {

EditorCore EditorCore::instance;

void EditorCore::NewProject(const String& projectName, const String& title, const PathName& projectPath)
{
	m_project = RefPtr<Project>::MakeRef();
	m_project->GetData()->SetProjectFileName(projectName);
	m_project->GetData()->SetTitle(title);
	m_project->GetData()->SetProjectDirectoryPath(projectPath);
	m_project->Save();
}

void EditorCore::OpenProject(const PathName& projectFilePath)
{
	m_project = RefPtr<Project>::MakeRef();
	m_project->Load(projectFilePath);
}

} // namespace ls
