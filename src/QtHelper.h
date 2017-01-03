
#pragma once

class QtHelper
{
public:
	static ln::String toLNString(const QString& str);
	static QString toQString(ln::String& str);
	static ln::PathName toLNPath(const QString& str);
};

