
#pragma once
#include "ProjectLibrary.h"

namespace ls {
using namespace ln;
class Project;

class EditorCore
{
public:
	static EditorCore instance;

	ProjectLibraryManager* GetProjectLibraryManager() { return &m_projectLibraryManager; }

	void NewProject(const String& projectName, const String& title, const PathName& projectPath);
	void OpenProject(const PathName& projectFilePath);

	Project* GetProject() const { return m_project; }

private:
	ProjectLibraryManager	m_projectLibraryManager;
	RefPtr<Project>	m_project;
};

} // namespace ls
