
#pragma once

namespace ls {
class IEditor;
class ProjectLibrary;
	
class ProjectData
	: public Object
{
public:
	ProjectData() = default;
	 
	void SetProjectFileName(const String& value) { m_projectFileName = value; }

	const String& GetProjectFileName() const { return m_projectFileName; }

	void SetTitle(const String& value) { m_title = value; }

	const String& GetTitle() const { return m_title; }

	void SetProjectDirectoryPath(const PathName& value) { m_projectDirectoryPath = value; }

	const PathName& GetProjectDirectoryPath() const { return m_projectDirectoryPath; }

private:
	String		m_projectFileName;
	String		m_title;
	PathName	m_projectDirectoryPath;
};

class Project
	: public Object
{
public:
	Project();

	ProjectData* GetData() const { return m_data; }

	PathName GetProjectFileFullPath() const;

	void CreateProjectLibrary(const String& id, IEditor* editorInterface);

	void InitializeWorkspace();

	void Save();
	void Load(const PathName& filePath);

private:
	RefPtr<ProjectData>		m_data;
	RefPtr<ProjectLibrary>	m_projectLibrary;
};

} // namespace ls
