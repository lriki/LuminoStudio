
#include "Project.h"

namespace ls {


Project::Project()
	: m_data(RefPtr<ProjectData>::MakeRef())
{
}

void Project::InitializeWorkspace()
{
	m_data->GetProjectPath().CreateDirectory();
}

} // namespace ls
