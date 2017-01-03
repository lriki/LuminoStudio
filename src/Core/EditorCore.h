
#pragma once

namespace ls {
using namespace ln;
class Project;

class EditorCore
{
public:
	static EditorCore instance;

	void NewProject(const String& projectName, const String& title, const PathName& projectPath);

private:
	RefPtr<Project>	m_project;
};

} // namespace ls
