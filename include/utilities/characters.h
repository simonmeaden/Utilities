#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <QChar>
#include <QString>

/*!
  \ingroup utilities
  \file characters.h
  \brief A holding place for reusable unicode characters.
  \author Simon Meaden
  \date 2022-08-10

  A partial set of useful unicode characters.

  \note Some of the characters have multiple names for the same character. An
  example is the forward slash character which has two names FORWARDSLASH and
  SOLIDUS. This is because it is actually called a solidus character in unicode
  but in many internal programming uses the name FORWARDSLASH is more
  descriptive of it's actual use.
 */
namespace Characters {

//! A null QChar
constexpr static QChar NULLCHAR = QChar(0x0);
//! A null QChar
constexpr static QChar BELL = QChar(0x7);
//! A null QChar
constexpr static QChar BACKSPACE = QChar(0x8);
//! horizontal tab character .
constexpr static QChar TAB = QChar(0x9);
//! vertical tab character .
constexpr static QChar VTAB = QChar(0xB);
//! form feed character .
constexpr static QChar FF = QChar(0xC);
//! carriage return character .
constexpr static QChar CR = QChar(0x0D);
//! line feed character .
constexpr static QChar LF = QChar(0x0A);
//! escape character .
constexpr static QChar ESCAPE = QChar(0x1B);
constexpr static QChar NEXTLINE = QChar(0x85);
constexpr static QChar LINESEPERATOR = QChar(0x2028);
constexpr static QChar PARASEPERATOR = QChar(0x2029);
constexpr static QChar BYTEORDERMARK = QChar(0xFEFF);
constexpr static QChar NBSPACE = QChar(0xA0);


// various arrow or arrow type characters.
//! ⯅ North pointing triangle
constexpr static QChar N_TRIANGLE = QChar(0x2BC5);
//! ⯆ South pointing triangle
constexpr static QChar S_TRIANGLE = QChar(0x2BC6);
//! ⯇ West pointing triangle
constexpr static QChar W_TRIANGLE = QChar(0x2BC7);
//! ⯈ East pointing triangle
constexpr static QChar E_TRIANGLE = QChar(0x2BC8);

//! ⭠ West pointing arrow
constexpr static QChar W_ARROW = QChar(0x2B60);
//! ⭡ North pointing arrow
constexpr static QChar N_ARROW = QChar(0x2B61);
//! ⭢ East pointing arrow
constexpr static QChar E_ARROW = QChar(0x2B62);
//! ⭣ South pointing arrow
constexpr static QChar S_ARROW = QChar(0x2B63);
//! ⭤ Horizontal double headed arrow
constexpr static QChar EW_ARROW = QChar(0x2B64);
//! ⭥ Vertical double headed arrow
constexpr static QChar NS_ARROW = QChar(0x2B65);
//! ⭦ NorthWest pointing arrow
constexpr static QChar NW_ARROW = QChar(0x2B66);
//! ⭧ NorthEast pointing arrow
constexpr static QChar NE_ARROW = QChar(0x2B67);
//! ⭨ SouthEast pointing arrow
constexpr static QChar SE_ARROW = QChar(0x2B68);
//! ⭩ SouthWest pointing arrow
constexpr static QChar SW_ARROW = QChar(0x2B69);
//! ⭪ West pointing dashed arrow
constexpr static QChar W_DASH_ARROW = QChar(0x2B6A);
//! ⭫ North pointing dashed arrow
constexpr static QChar N_DASH_ARROW = QChar(0x2B6B);
//! ⭬ East pointing dashed arrow
constexpr static QChar E_DASH_ARROW = QChar(0x2B6C);
//! ⭭ South pointing dashed arrow
constexpr static QChar S_DASH_ARROW = QChar(0x2B6D);
//! ⭮ Clockwise open circle arrow
constexpr static QChar CW_ARROW = QChar(0x2B6E);
//! ⭯ Anticlockwise open circle arrow
constexpr static QChar ACW_ARROW = QChar(0x2B6F);
//! ⭰ West pointing arrow to bar
constexpr static QChar W_ARROW_BAR = QChar(0x2B70);
//! ⭱ North pointing arrowv
constexpr static QChar N_ARROW_BAR = QChar(0x2B71);
//! ⭲ East pointing arrow to bar
constexpr static QChar E_ARROW_BAR = QChar(0x2B72);
//! ⭳ South pointing arrow to bar
constexpr static QChar S_ARROW_BAR = QChar(0x2B73);
//! ⭶ NorthWest pointing arrow to bar
constexpr static QChar NW_ARROW_BAR = QChar(0x2B76);
//!	⭷ NorthEast pointing arrow to bar
constexpr static QChar NE_ARROW_BAR = QChar(0x2B77);
//! ⭸ SouthEast pointing arrow to bar
constexpr static QChar SE_ARROW_BAR = QChar(0x2B78);
//! ⭹ SouthWest pointing arrow to bar
constexpr static QChar SW_ARROW_BAR = QChar(0x2B79);

// Assorted common characters
//! ' ' space character
constexpr static QChar SPACE = QChar(0x20);
//! ␤ Newline character - used when requiring a newline in text.
constexpr static QChar NEWLINE = '\n';
constexpr static char cNEWLINE = '\n';
//! ␤ Newline character
constexpr static QChar NEWLINE_SYMBOL = QChar(0x2424);
//! ⮒ Left Newline character
constexpr static QChar NEWLINE_LEFT_SYMBOL = QChar(0x2B92);
//! ⮒ Right Newline character
constexpr static QChar NEWLINE_RIGHT_SYMBOL = QChar(0x2B93);
//! ⭿ Vertical Tab character
constexpr static QChar VERTICALTABSYMBOL = QChar(0x2B7F);
//! ⭾ Horizontal Tab character
constexpr static QChar HORIZONTALTABSYMBOL = QChar(0x2B7E);

// Greater and less than (also html tags)
//! < less than character
constexpr static QChar LT = QChar(0x3C);
//! > greater than character
constexpr static QChar GT = QChar(0x3E);
//! < HTML 5 open tag character
constexpr static QChar HTML_OPEN_TAG = QChar(0x3C);
//! > HTML 5 close tag character
constexpr static QChar HTML_CLOSE_TAG = QChar(0x3E);

// various brackets {} [] ()
//! { left curly bracket character
constexpr static QChar OPEN_CURLY_BRACKET = QChar(0x7B);
//! { left curly bracket character
constexpr static QChar LEFT_CURLY_BRACKET = QChar(0x7B);
//! } right curly bracket character
constexpr static QChar CLOSE_CURLY_BRACKET = QChar(0x7D);
//! } right curly bracket character
constexpr static QChar RIGHT_CURLY_BRACKET = QChar(0x7D);
//! [ left square bracket character
constexpr static QChar OPEN_SQUARE_BRACKET = QChar(0x5B);
//! [ left square bracket character
constexpr static QChar LEFT_SQUARE_BRACKET = QChar(0x5B);
//! ] right square bracket character
constexpr static QChar CLOSE_SQUARE_BRACKET = QChar(0x5D);
//! ] right square bracket character
constexpr static QChar RIGHT_SQUARE_BRACKET = QChar(0x5D);
//! ( left round bracket character
constexpr static QChar OPEN_ROUND_BRACKET = QChar(0x28);
//! ( left parenthesis character
constexpr static QChar LEFT_PARENTHESIS = QChar(0x28);
//! ) right round bracket character
constexpr static QChar CLOSE_ROUND_BRACKET = QChar(0x29);
//! ) right parenthesis character
constexpr static QChar RIGHT_PARENTHESIS = QChar(0x29);

//! ? question mark character
constexpr static QChar QUESTIONMARK = QChar(0x3F);
//! ! exclamation mark character
constexpr static QChar EXCLAMATIONMARK = QChar(0x21);
//! ' apostrophe/single quote character
constexpr static QChar APOSTROPHE = QChar(0x27);
//! ' apostrophe/single quote character
constexpr static QChar SINGLEQUOTE = APOSTROPHE;
//! " double quote character
constexpr static QChar QUOTATION = QChar(0x22);
//! " double quote character
constexpr static QChar DOUBLEQUOTE = QUOTATION;
//! / solidus/forward slash character
constexpr static QChar SOLIDUS = QChar(0x2F);
//! / solidus/forward slash character
constexpr static QChar FORWARDSLASH = SOLIDUS;
//! \ reverse solidus/ backslash character
constexpr static QChar R_SOLIDUS = QChar(0x5C);
//! \ reverse solidus/ backslash character
constexpr static QChar BACKSLASH = R_SOLIDUS;
//! _ low line character
constexpr static QChar LOWLINE = QChar(0x5F);
//! = equals/assignment character
constexpr static QChar EQUALS = QChar(0x3D);
//! = assignment character. Identical to EQUALS.
constexpr static QChar ASSIGNMENT = EQUALS;
//! + plus character (QChar)
constexpr static QChar PLUS = QChar(0x2B);
//! + plus character (char)
constexpr static QChar cPLUS = '+';
//! - minus/hyphen character
constexpr static QChar MINUS = QChar(0x2D);
//! - minus/hyphen character
constexpr static QChar HYPHEN = MINUS;
//! : colon character (QChar)
constexpr static QChar COLON = QChar(0x3A);
//! : colon character (char)
constexpr static char cCOLON = ':';
//! & ampersand character (QChar)
constexpr static QChar AMPERSAND = QChar(0x26);
//! & ampersand character (char)
constexpr static char cAMPERSAND = '&';
//! # hash character (QChar)
constexpr static QChar HASH = QChar(0x23);
//! # octothorpe character (QChar)
constexpr static QChar OCTOTHORPE = HASH;
//! # hash character (char)
constexpr static char cHASH = '#';
//! * asterisk character
constexpr static QChar ASTERISK = QChar(0x2A);
constexpr static char cASTERISK = '*';
//! % percent character
constexpr static QChar PERCENT = QChar(0x25);
constexpr static char cPERCENT = '%';
//! , comma character
constexpr static QChar COMMA = QChar(0x2C);
constexpr static char cCOMMA = ',';
//! . comma character
constexpr static QChar STOP = QChar(0x2E);
constexpr static QChar POINT = QChar(0x2E);
constexpr static QChar FULLSTOP = STOP;
constexpr static char cSTOP = '.';
//! @ commercial at character
constexpr static QChar COMMERCIAL_AT = QChar(0x40);
constexpr static QChar cCOMMERCIAL_AT = '@';
//! @ commercial at character
constexpr static QChar BACKTICK = QChar(0x60);
constexpr static QChar GRAVEACCENT = BACKTICK;
constexpr static QChar cBACKTICK = '`';
//! ; semicolon character
constexpr static QChar SEMICOLON = QChar(0x2C);
//! ` Grave Accent
constexpr static QChar GRAVE_ACCENT = QChar(0x60);
//! ´ Acute Accent
constexpr static QChar ACUTE_ACCENT = QChar(0xB4);
//! | Vertical line
constexpr static QChar VERTICAL_LINE = QChar(0x7C);
//! | Vertical line
constexpr static QChar VERTICAL_BAR = VERTICAL_LINE;

//// escaped character strings
////! " escaped double quote character
// constexpr static QString ESCAPED_QUOTATION = "\"";

}; // end of namespace characters.

#endif // CHARACTERS_H
