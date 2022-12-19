#ifndef KEYMAP_H
#define KEYMAP_H

#include <QAction>
#include <QIcon>
#include <QKeySequence>
#include <QMap>

#include "qyamlcpp/qyamlcpp.h"

/*!
  \ingroup utilities
  \file keymap.h
  \brief stores a set of Key maps for storage in a configuration file.
  \author Simon Meaden
  \date 2022-08-10

  Not really intended for anyone else to use as you can see from to
  paucity of mapping keys.

  Data is stored in a QMap<KeyEventMapper, KeyMapper> and the main part
  of the code is to allow the data to be stored/recovered from a YAML file
  using yaml-cpp.
 */

/*!
 * \enum KeyEventMapper
 *
 * Defines the key for a map of key/modifier structures.
 */
enum KeyEvent
{
  NoKey, //!< No key was pressed.

  HelpContents,
  WhatsThis,
  Open,
  Close,
  Save,
  SaveAs,
  Quit,
  New,
  Delete,
  Cut,
  Copy,
  Paste,
  Undo,
  Redo,
  Back,
  Forward,
  Refresh,
  ZoomIn,
  ZoomOut,
  Fullscreen,
  Print,
  AddTab,
  NextChild,
  PreviousChild,
  Find,
  FindNext,
  FindPrevious,
  Replace, //! Replace the item under the cursor.
  SelectAll,
  Deselect,
  Bold,
  Italic,
  Underline,
  MoveToNextChar,
  MoveToPreviousChar,
  MoveToNextWord,
  MoveToPreviousWord,
  MoveToNextLine,
  MoveToPreviousLine,
  MoveToNextPage,
  MoveToPreviousPage,
  MoveToStartOfLine,
  MoveToEndOfLine,
  MoveToStartOfBlock,
  MoveToEndOfBlock,
  MoveToStartOfDocument,
  MoveToEndOfDocument,
  SelectNextChar,
  SelectPreviousChar,
  SelectNextWord,
  SelectPreviousWord,
  SelectNextLine,
  SelectPreviousLine,
  SelectNextPage,
  SelectPreviousPage,
  SelectStartOfLine,
  SelectEndOfLine,
  SelectStartOfBlock,
  SelectEndOfBlock,
  SelectStartOfDocument,
  SelectEndOfDocument,
  DeleteStartOfWord,
  DeleteEndOfWord,
  DeleteEndOfLine,
  DeleteCompleteLine,
  InsertParagraphSeparator,
  InsertLineSeparator,
  Backspace,
  Cancel,

  PreviousBookmark, //!< Go to the previous bookmark
  NextBookmark,     //!< Go to the next bookmark.
  GoToBookmark,     //!< Go to selected bookmark.
  AddBookmark,      //!< Add a new bookmark.
  ToggleBookmark,   //!< Toggle current bookmark.
  EditBookmark,     //!< Edit bookmark.
  RemoveBookmark,   //!< Remove current bookmark.
  ClearBookmarks,   //!< Clears all bookmarks.

  Search = Find,                 //! Call up the search dialog.
  SearchNext = FindNext,         //! Search for the next item.
  SearchPrevious = FindPrevious, //! Search for the previous item.
  ReplaceAndFind, //! Replace the item under the cursor and search for the next
                  //! item.
  ReplaceAll,     //! Replace all located items.

  NextTag = NextChild,         //!< Go to the previous tag.
  PreviousTag = PreviousChild, //!< Go to the next tag.

  Preferences, //!< Calls preferences dialog.

  CustomEvent = 100, // Starter for custom key events.

};

/*!
 * \struct KeyMapper
 * \brief Stores a key/modifier value for a key press.
 */
struct KeyMapper
{

  //! Default constructor
  KeyMapper();
  //! Constructor for KeyMapper specifying Key value and modifiers
  KeyMapper(Qt::Key key, Qt::KeyboardModifiers modifiers = Qt::NoModifier);

  //! Validity check for KeyMapper
  bool isValid();

  QKeySequence keySequence();

  //! QKey value
  Qt::Key key = Qt::Key_unknown;
  //! Key modifiers
  Qt::KeyboardModifiers modifiers = Qt::NoModifier;
};
Q_DECLARE_METATYPE(KeyMapper)

///*!
// * Set of standardish key mappings.
// *
// * By standardish I mean it will generally match most OS's but some
// * only match Gnome and others Ios and still others Windows.
// * At some point, when I have time, I will update for better values.
// */
//QMap<KeyEvent, KeyMapper> STANDARD_KEY_VALUES{
//  //#if defined(Q_OS_ANDROID)

//  //#elif defined(Q_OS_LINUX)
//  { HelpContents, KeyMapper(Qt::Key_F1) },                 //!< comment
//  { WhatsThis, KeyMapper(Qt::Key_F1, Qt::ShiftModifier) }, //!< comment
//  { Open, KeyMapper(Qt::Key_O, Qt::ControlModifier) },     //!< comment
//  { Close, KeyMapper(Qt::Key_W, Qt::ControlModifier) },    //!< comment
//  { Save, KeyMapper(Qt::Key_S, Qt::ControlModifier) },     //!< comment
//  { SaveAs, KeyMapper(Qt::Key_Q, Qt::ControlModifier) },   //!< comment
//  { Quit,
//    KeyMapper(Qt::Key_S,
//              Qt::ControlModifier | Qt::ShiftModifier) }, //!< comment
//  { New, KeyMapper(Qt::Key_N, Qt::ControlModifier) },     //!< comment
//  { Delete, KeyMapper(Qt::Key_D, Qt::ControlModifier) },  //!< comment
//  { Cut, KeyMapper(Qt::Key_X, Qt::ControlModifier) },     //!< comment
//  { Copy, KeyMapper(Qt::Key_C, Qt::ControlModifier) },    //!< comment
//  { Paste, KeyMapper(Qt::Key_V, Qt::ControlModifier) },   //!< comment
//  { Undo, KeyMapper(Qt::Key_Z, Qt::ControlModifier) },    //!< comment
//  { Redo,
//    KeyMapper(Qt::Key_Z,
//              Qt::ControlModifier | Qt::ShiftModifier) },      //!< comment
//  { Back, KeyMapper(Qt::Key_Left, Qt::AltModifier) },          //!< comment
//  { Forward, KeyMapper(Qt::Key_Right, Qt::AltModifier) },      //!< comment
//  { Refresh, KeyMapper(Qt::Key_R, Qt::ControlModifier) },      //!< comment
//  { ZoomIn, KeyMapper(Qt::Key_Plus, Qt::ControlModifier) },    //!< comment
//  { ZoomOut, KeyMapper(Qt::Key_Minus, Qt::ControlModifier) },  //!< comment
//  { Fullscreen, KeyMapper(Qt::Key_F11, Qt::ControlModifier) }, //!< comment
//  { Print, KeyMapper(Qt::Key_P, Qt::ControlModifier) },        //!< comment
//  { AddTab, KeyMapper(Qt::Key_T, Qt::ControlModifier) },       //!< comment
//  { NextChild, KeyMapper(Qt::Key_Tab, Qt::ControlModifier) },  //!< comment
//  { PreviousChild,
//    KeyMapper(Qt::Key_Tab,
//              Qt::ControlModifier | Qt::ShiftModifier) },  //!< comment
//  { Find, KeyMapper(Qt::Key_F, Qt::ControlModifier) },     //!< comment
//  { FindNext, KeyMapper(Qt::Key_G, Qt::ControlModifier) }, //!< comment
//  { FindPrevious,
//    KeyMapper(Qt::Key_G,
//              Qt::ControlModifier | Qt::ShiftModifier) },   //!< comment
//  { Replace, KeyMapper(Qt::Key_H, Qt::ControlModifier) },   //!< comment
//  { SelectAll, KeyMapper(Qt::Key_A, Qt::ControlModifier) }, //!< comment
//  { Deselect,
//    KeyMapper(Qt::Key_A,
//              Qt::ControlModifier | Qt::ShiftModifier) },   //!< comment
//  { Bold, KeyMapper(Qt::Key_B, Qt::ControlModifier) },      //!< comment
//  { Italic, KeyMapper(Qt::Key_I, Qt::ControlModifier) },    //!< comment
//  { Underline, KeyMapper(Qt::Key_U, Qt::ControlModifier) }, //!< comment
//  { MoveToNextChar, KeyMapper(Qt::Key_Right) },             //!< comment
//  { MoveToPreviousChar, KeyMapper(Qt::Key_Left) },          //!< comment
//  { MoveToNextWord,
//    KeyMapper(Qt::Key_Right, Qt::ControlModifier) }, //!< comment
//  { MoveToPreviousWord,
//    KeyMapper(Qt::Key_Left, Qt::ControlModifier) },               //!< comment
//  { MoveToNextLine, KeyMapper(Qt::Key_Down) },                    //!< comment
//  { MoveToPreviousLine, KeyMapper(Qt::Key_Up) },                  //!< comment
//  { MoveToNextPage, KeyMapper(Qt::Key_PageUp) },                  //!< comment
//  { MoveToPreviousPage, KeyMapper(Qt::Key_PageDown) },            //!< comment
//  { MoveToStartOfLine, KeyMapper(Qt::Key_Home) },                 //!< comment
//  { MoveToEndOfLine, KeyMapper(Qt::Key_E, Qt::ControlModifier) }, //!< comment
//  { MoveToStartOfBlock, KeyMapper(Qt::Key_Up, Qt::AltModifier) }, //!< comment
//  { MoveToEndOfBlock, KeyMapper(Qt::Key_Down, Qt::AltModifier) }, //!< comment
//  { MoveToStartOfDocument,
//    KeyMapper(Qt::Key_Home, Qt::ControlModifier) }, //!< comment
//  { MoveToEndOfDocument,
//    KeyMapper(Qt::Key_End, Qt::ControlModifier) },                 //!< comment
//  { SelectNextChar, KeyMapper(Qt::Key_Right, Qt::ShiftModifier) }, //!< comment
//  { SelectPreviousChar,
//    KeyMapper(Qt::Key_Left, Qt::ShiftModifier) }, //!< comment
//  { SelectNextWord,
//    KeyMapper(Qt::Key_Right,
//              Qt::ControlModifier | Qt::ShiftModifier) }, //!< comment
//  { SelectPreviousWord,
//    KeyMapper(Qt::Key_Left,
//              Qt::ControlModifier | Qt::ShiftModifier) },           //!< comment
//  { SelectNextLine, KeyMapper(Qt::Key_Down, Qt::ShiftModifier) },   //!< comment
//  { SelectPreviousLine, KeyMapper(Qt::Key_Up, Qt::ShiftModifier) }, //!< comment
//  { SelectNextPage,
//    KeyMapper(Qt::Key_PageDown, Qt::ShiftModifier) }, //!< comment
//  { SelectPreviousPage,
//    KeyMapper(Qt::Key_PageUp, Qt::ShiftModifier) }, //!< comment
//  { SelectStartOfLine,
//    KeyMapper(Qt::Key_Home, Qt::ShiftModifier) },                 //!< comment
//  { SelectEndOfLine, KeyMapper(Qt::Key_End, Qt::ShiftModifier) }, //!< comment
//  { SelectStartOfBlock,
//    KeyMapper(Qt::Key_Up, Qt::ShiftModifier | Qt::AltModifier) }, //!< comment
//  { SelectEndOfBlock,
//    KeyMapper(Qt::Key_Down, Qt::ShiftModifier | Qt::AltModifier) }, //!< comment
//  { SelectStartOfDocument,
//    KeyMapper(Qt::Key_Home,
//              Qt::ControlModifier | Qt::ShiftModifier) }, //!< comment
//  { SelectEndOfDocument,
//    KeyMapper(Qt::Key_End,
//              Qt::ControlModifier | Qt::ShiftModifier) }, //!< comment
//  { DeleteStartOfWord,
//    KeyMapper(Qt::Key_Backspace, Qt::ControlModifier) }, //!< comment
//  { DeleteEndOfWord,
//    KeyMapper(Qt::Key_Delete, Qt::ControlModifier) },             //!< comment
//  { DeleteEndOfLine, KeyMapper(Qt::Key_K, Qt::ControlModifier) }, //!< comment
//  { DeleteCompleteLine,
//    KeyMapper(Qt::Key_U, Qt::ControlModifier) },          //!< comment
//  { InsertParagraphSeparator, KeyMapper(Qt::Key_Enter) }, //!< comment
//  { InsertLineSeparator,
//    KeyMapper(Qt::Key_Enter, Qt::ShiftModifier) }, //!< comment
//  //    { Backspace, KeyMapper(Qt::Key_F1) },                //!< comment
//  { Cancel, KeyMapper(Qt::Key_Escape) }, //!< comment
//  //#elif defined(Q_OS_DARWIN)

//  //#elif defined(Q_OS_WIN32)

//  //#endif
//};

/*!
 * \class KeyEventMap keymap.h "utilities/keymap.h"
 * \brief The KeyEventMap class allows a set of KeyEventMapper => QAction*
 *        to be created, stored to file and recovered and recreated.
 */
class KeyEventMap : public QObject
{
public:
  /*!
   * \brief KeyEventMap constructor.
   */
  KeyEventMap(QObject* parent = nullptr)
    : QObject(parent)
  {
  }

  /*!
   * \brief inserts a KeyEventMapper => QKeySequence to be created.
   */
  void insert(KeyEvent event,
              Qt::Key key,
              Qt::KeyboardModifiers modifiers = Qt::NoModifier);

  /*!
   * \brief Returns the QAction attached to the supplied event,
   *   or nullptr if none has previously been created using one
   *   of the addAction() methods.
   */
  QAction* action(KeyEvent event);

  /*!
   * \brief Creates and returns a new QAction which will be
   *   attached to the supplied event. The action will be set
   *   up using the supplied QIcon and QString.
   */
  QAction* addAction(KeyEvent event,
                     QIcon icon,
                     const QString& text,
                     Qt::Key key,
                     Qt::KeyboardModifiers modifiers = Qt::NoModifier);

  /*!
   * \brief Creates and returns a new QAction which will be
   *   attached to the supplied event. The action will be set
   *   up using the supplied QString.
   */
  QAction* addAction(KeyEvent event,
                     const QString& text,
                     Qt::Key key,
                     Qt::KeyboardModifiers modifiers = Qt::NoModifier);

  /*!
   * \brief Creates and returns a new QAction which will be
   *   attached to the supplied event. The action will be set
   *   up using the supplied QIcon and QString.
   *
   *  The Key and modifiers must have previously added using
   *  the insert method, otherwise a nullptr will be returned.
   */
  QAction* addAction(KeyEvent event, QIcon icon, const QString& text);

  /*!
   * \brief Creates and returns a new QAction which will be
   *   attached to the supplied event. The action will be set
   *   up using the supplied QString.
   *
   *  The Key and modifiers must have previously added using
   *  the insert method, otherwise a nullptr will be returned.
   */
  QAction* addAction(KeyEvent event, const QString& text);

  //! Removes a key event from the map, deleting the items if required.
  void remove(KeyEvent event);

  //! Clears and removes all key events from the map, deleting the items
  //! if required.
  void clear();

  //  //! \brief A yaml-cpp emitter operator for KeyMapper.
  //  friend YAML::Emitter& operator<<(YAML::Emitter& out, const KeyMapper v);
  //  //! \brief A yaml-cpp emitter operator for KeyEventMapper.
  //  friend YAML::Emitter& operator<<(YAML::Emitter& out, const KeyEventMapper
  //  v);
  //  //! \brief A yaml-cpp emitter operator for  QMap<KeyEventMapper,
  //  KeyMapper>. friend YAML::Emitter& operator<<(YAML::Emitter& out, const
  //  KeyEventMap* v);

private:
  QMap<KeyEvent, KeyMapper> m_map;
  //  QMap<KeyEventMapper, QString> m_stringMap;
  QMap<KeyEvent, QAction*> m_actionMap;
};

// namespace YAML {

////! \brief A yaml-cpp emitter operator for KeyMapper.
// Emitter&
// operator<<(Emitter& out, const KeyMapper v);

////! \brief A yaml-cpp emitter operator for KeyEventMapper.
// Emitter&
// operator<<(Emitter& out, const KeyEventMapper v);

////! \brief A yaml-cpp emitter operator for  QMap<KeyEventMapper, KeyMapper>.
// Emitter&
// operator<<(Emitter& out, const KeyEventMap* v);

////! \brief A yaml-cpp convertion class for KeyEventMapper.
// template<>
// struct convert<KeyEventMapper>
//{
//   //! encode function for KeyEventMapper
//   static Node encode(const KeyEventMapper rhs);

//  //! decode function for KeyEventMapper
//  static bool decode(const Node& node, KeyEventMapper& rhs);
//};

////! \brief A yaml-cpp convertion class for KeyMapper.
// template<>
// struct convert<KeyMapper>
//{
//   //! encode function for KeyMapper
//   static Node encode(const KeyMapper rhs);

//  //! decode function for KeyMapper
//  static bool decode(const Node& node, KeyMapper rhs);
//};

////! \brief A yaml-cpp convertion class for KeyMapper.
// template<>
// struct convert<KeyEventMap*>
//{
//   //! encode function for KeyMapper
//   static Node encode(const KeyEventMap* rhs);

//  //! decode function for KeyMapper
//  static bool decode(const Node& node, KeyEventMap* rhs);
//};

//} // end of namespace YAML

#endif // KEYMAP_H
