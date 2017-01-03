
#pragma once

namespace ls {
class IEditorWindow;
class IEditorPane;

/** */
enum class DockingArea
{
	Left,
	Right,
};

/** */
class IEditor
{
public:
	virtual IEditorWindow* GetMainWindow() = 0;
};

/** */
class IEditorWindow
{
public:
	virtual IEditorPane* CreateDockablePane(const String& id, DockingArea area) = 0;
};

/** */
class IEditorPane
{
public:

};

} // namespace ls
