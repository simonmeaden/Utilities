#include "utilities/keymap.h"

////====================================================================
////=== KeyMap
////====================================================================
KeyMapper::KeyMapper() {}

KeyMapper::KeyMapper(Qt::Key key, Qt::KeyboardModifiers modifiers)
{
  this->key = key;
  this->modifiers = modifiers;
}

bool
KeyMapper::isValid()
{
  if (key != Qt::Key_unknown)
    return true;
  return false;
}

QKeySequence
KeyMapper::keySequence()
{
  return QKeySequence(key, modifiers);
}

void
KeyEventMap::insert(KeyEvent event,
                    Qt::Key key,
                    Qt::KeyboardModifiers modifiers)
{
  m_map.insert(event, KeyMapper(key, modifiers));
}

QAction*
KeyEventMap::action(KeyEvent event)
{
  if (m_actionMap.contains(event)) {
    return m_actionMap.value(event);
  }
  return nullptr;
}

QAction*
KeyEventMap::addAction(KeyEvent event,
                       QIcon icon,
                       const QString& text,
                       Qt::Key key,
                       Qt::KeyboardModifiers modifiers)
{
  m_map.insert(event, KeyMapper(key, modifiers));
//  m_stringMap.insert(event, text);
  auto action = new QAction(icon, text, this);
  m_actionMap.insert(event, action);
  return action;
}

QAction*
KeyEventMap::addAction(KeyEvent event,
                       const QString& text,
                       Qt::Key key,
                       Qt::KeyboardModifiers modifiers)
{
  m_map.insert(event, KeyMapper(key, modifiers));
//  m_stringMap.insert(event, text);
  auto action = new QAction(text, this);
  m_actionMap.insert(event, action);
  return action;
}

QAction*
KeyEventMap::addAction(KeyEvent event, QIcon icon, const QString& text)
{
  if (m_map.value(event).isValid()) {
//    m_stringMap.insert(event, text);
    auto action = new QAction(icon, text, this);
    m_actionMap.insert(event, action);
    return action;
  }
  return nullptr;
}

QAction*
KeyEventMap::addAction(KeyEvent event, const QString& text)
{
  if (m_map.value(event).isValid()) {
//    m_stringMap.insert(event, text);
    auto action = new QAction(text, this);
    m_actionMap.insert(event, action);
    return action;
  }
  return nullptr;
}

void
KeyEventMap::remove(KeyEvent event)
{
  m_map.remove(event);
//  m_stringMap.remove(event);
  auto action = m_actionMap.take(event);
  delete action;
}

void KeyEventMap::clear()
{
  m_map.clear();
  //    m_stringMap.clear();
  qDeleteAll(m_actionMap);
  m_actionMap.clear();
}
//====================================================================
//=== QYamlCpp extensions.
//====================================================================
// namespace YAML {

// Emitter&
// operator<<(Emitter& out, const KeyMapper v)
//{
//   out << Key << "key" << Value << v.key << Key << "modifier" << Value
//       << v.modifiers;
//   return out;
// }

// Emitter&
// operator<<(Emitter& out, const KeyEventMapper v)
//{
//   out << Value << int(v);
//   return out;
// }

// Emitter&
// operator<<(Emitter& out, const KeyEventMap* v)
//{
//   for (auto it = v.m_map.cbegin(); it != v->m_map.cend(); ++it) {
//     auto key = it.key();
//     auto value = it.value();
//     out << Key << int(key);
//     out << Value;
//     out << BeginMap;
//     out << Key << "key" << Value << value.key;
//     out << Key << "modifier" << Value << value.modifiers;
//     out << EndMap;
//   }
//    return out;
// }

// Node
// convert<KeyEventMapper>::encode(const KeyEventMapper rhs)
//{
//   Node node;
//   node = int(rhs);
//   return node;
// }

// bool
// convert<KeyEventMapper>::decode(const Node& node, KeyEventMapper& rhs)
//{
//   if (!node.IsScalar()) {
//     return false;
//   }

//  rhs = KeyEventMapper(node.as<int>());

//  return true;
//}

// Node
// convert<KeyMapper>::encode(const KeyMapper rhs)
//{
//   Node node;
//   node["key"] = int(rhs.key);
//   node["modifier"] = int(rhs.modifiers);
//   return node;
// }

// bool
// convert<KeyMapper>::decode(const Node& node, KeyMapper rhs)
//{
//   if (!node.IsMap()) {
//     return false;
//   }

//  auto key = node["key"].as<int>();
//  auto value = node["modifier"].as<int>();
//  rhs.key = Qt::Key(key);
//  rhs.modifiers = Qt::KeyboardModifiers(value);

//  return true;
//}

// Node YAML::convert<KeyEventMap *>::encode(const KeyEventMap *rhs)
//{

//}

// bool YAML::convert<KeyEventMap *>::decode(const Node &node, KeyEventMap *rhs)
//{

//}

//} // end of namespace YAML
