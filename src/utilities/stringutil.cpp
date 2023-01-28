#include "utilities/stringutil.h"

namespace StringUtil {

QString
removeWhitespace(const QString& text)
{
  QString t;
  // removes all whitespace except single interior spaces
  auto simplified = text.simplified();
  for (auto &c : simplified) {
    // ignore all single space characters.
    if (c == ' ')
      continue;
    t += c;
  }
  return t;
}

QString lTrim(const QString &text, int &dropped)
{
  int i = 0;
  for (; i < text.length(); i++) {
    if (text.at(i).isSpace())
      continue;
    break;
  }
  dropped = i;
  return text.mid(i);
}

QString rTrim(const QString &text, int &dropped)
{
  int i = text.length();
  for (; i >= 0; i--) {
    if (text.at(i).isSpace())
      continue;
    break;
  }
  dropped = i;
  return text.left(text.length() - i);
}

} // end of namespace Strings
