/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "message_event.h"

IMessageEvent::IMessageEvent(EventType gl_type, EventType type, EventPriority priority, AVariant data, bool has_return, EventFinishCbk event_cbk) : m_globalType(gl_type)
  , m_type(type)
  , m_data(data)
  , m_hasReturn(has_return)
  , m_eventCbk(event_cbk)
  , m_priority(priority)
{}

IMessageEvent::~IMessageEvent()
{}
