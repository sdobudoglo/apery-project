/*****************************
 Project    apery-project
 Autor      Sergey Dobudoglo
 copyright  2014
******************************/

#include "event.h"

IEvent::IEvent(EventType type, EventTypeSpec::EventPriority priority, AVariant data, bool has_return) : m_type(type)
  , m_data(data)
  , m_hasReturn(has_return)
  , m_priority(priority)
{}

IEvent::~IEvent()
{}

void IEvent::finishCbk()
{}
