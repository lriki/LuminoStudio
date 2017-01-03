
#pragma once

namespace ls {
	
class ProjectData
	: public Object
{
public:
	ProjectData() = default;
	 
	void SetProjectName(const String& value) { m_projectName = value; }

	const String& GetProjectName() const { return m_projectName; }

	void SetTitle(const String& value) { m_title = value; }

	const String& GetTitle() const { return m_title; }

	void SetProjectPath(const PathName& value) { m_projectPath = value; }

	const PathName& GetProjectPath() const { return m_projectPath; }

private:
	String		m_projectName;
	String		m_title;
	PathName	m_projectPath;
};

class Project
	: public Object
{
public:
	Project();

	ProjectData* GetData() const { return m_data; }

	void InitializeWorkspace();


private:
	RefPtr<ProjectData>	m_data;
};

} // namespace ls
