
#include <Lumino/Base/Serialization.h>
#include <Lumino/Json/JsonDocument.h>
#include "Project.h"
#include "ProjectLibrary.h"
#include "EditorCore.h"

namespace ls {


Project::Project()
	: m_data(RefPtr<ProjectData>::MakeRef())
	, m_projectLibrary(nullptr)
{
}

PathName Project::GetProjectFileFullPath() const
{
	return PathName(m_data->GetProjectDirectoryPath(), m_data->GetProjectFileName());
}

void Project::CreateProjectLibrary(const String& id, IEditor* editorInterface)
{
	m_projectLibrary = EditorCore::instance.GetProjectLibraryManager()->CreateProjectLibrary(id);
	m_projectLibrary->SetEditorInterface(editorInterface);
}

void Project::InitializeWorkspace()
{
	m_data->GetProjectDirectoryPath().CreateDirectory();
	m_projectLibrary->OnInitializeWorkspace();
}

void Project::Save()
{
	tr::JsonDocument2 doc;
	tr::Archive ar(&doc, tr::ArchiveMode::Save);

	String s = m_data->GetTitle();
	ar & tr::MakeNVP(_T("Title"), s);

	doc.Save(GetProjectFileFullPath());
}

void Project::Load(const PathName& filePath)
{
	m_data = RefPtr<ProjectData>::MakeRef();
	m_data->SetProjectDirectoryPath(filePath.GetParent());
	m_data->SetProjectFileName(filePath.GetFileName());

	tr::JsonDocument2 doc;
	doc.Load(filePath);

	tr::Archive ar(&doc, tr::ArchiveMode::Load);

	String s;
	ar & tr::MakeNVP(_T("Title"), s);
}

} // namespace ls
