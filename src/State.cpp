#include "State.h"
namespace cbtek{
namespace common{
namespace utility{


void State::next()
{
    switch(m_type)
    {
        case StateType::Enter: m_type = StateType::Update;break;
        case StateType::Update: m_type = StateType::Exit;break;
        case StateType::Exit: m_type = StateType::Enter;break;
    }
}

void State::reset()
{
    m_type = StateType::Enter;
}

}}}//namespace
