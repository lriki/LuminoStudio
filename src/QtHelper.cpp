
#include "QtHelper.h"

ln::String QtHelper::toLNString(const QString& str)
{
	QByteArray utf8 = str.toLocal8Bit();
	return ln::String::FromNativeCharString(utf8.constData(), utf8.size());
}

QString QtHelper::toQString(ln::String& str)
{
#ifdef LN_UNICODE
	return QString::fromStdWString(str.c_str());
#else
	return QString(str.c_str());
#endif
	// http://d.hatena.ne.jp/morchin/touch/20130317/p1
}

ln::PathName QtHelper::toLNPath(const QString& str)
{
	return ln::PathName(toLNString(str));
}


