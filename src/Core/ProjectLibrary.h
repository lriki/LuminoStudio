
#pragma once

namespace ls {
class IEditor;

/** プロジェクト拡張のベースクラス */
class ProjectLibrary
	: public Object
{
public:
	ProjectLibrary() = default;
	virtual ~ProjectLibrary() = default;

	void SetEditorInterface(IEditor* editorInterface) { m_editorInterface = editorInterface; }
	IEditor* GetEditorInterface() const { return m_editorInterface; }

	virtual void OnInitializeWorkspace() = 0;

private:
	IEditor*	m_editorInterface;
};

/**  */
class ProjectLibraryManager
{
public:
	ProjectLibraryManager() = default;
	
	RefPtr<ProjectLibrary> CreateProjectLibrary(const String& id);

private:
};

} // namespace ls
