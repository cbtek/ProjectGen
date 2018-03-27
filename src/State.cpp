#include "State.h"
namespace cbtek{
namespace common{
namespace utility{

State::State()
{
    m_isEnter=true;
    m_isUpdate=false;
    m_isExit=false;
    m_id=0;
}

void State::reset()
{
    m_isEnter=true;
    m_isUpdate=false;
    m_isExit=false;
}
void State::setId(int id)
{
    m_id=id;
}
int State::getId() const
{
    return m_id;
}

bool State::isEnter() const
{
    return m_isEnter;
}

bool State::isUpdate() const
{
    return m_isUpdate;
}

bool State::isExit() const
{
    return m_isExit;
}

void State::setEnter(const bool & mode)
{
    m_isEnter=mode;
}
void State::setUpdate(const bool & mode)
{
    m_isUpdate=mode;
}
void State::setExit(const bool & mode)
{
    m_isExit=mode;
}

void State::setEnter()
{
    m_isEnter=true;
    m_isUpdate=false;
    m_isExit=false;
}
void State::setUpdate()
{
    m_isEnter=false;
    m_isUpdate=true;
    m_isExit=false;
}
void State::setExit()
{
    m_isEnter=false;
    m_isUpdate=false;
    m_isExit=true;
}
}}}//namespace
