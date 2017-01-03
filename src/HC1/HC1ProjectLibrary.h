
#pragma once
#include "../Core/ProjectLibrary.h"

namespace ls {

/**  */
class HC1ProjectLibrary
	: public ProjectLibrary
{
public:
	HC1ProjectLibrary() = default;
	virtual ~HC1ProjectLibrary() = default;

	virtual void OnInitializeWorkspace() override;

private:
};

} // namespace ls
