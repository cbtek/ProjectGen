#pragma once

#include <memory>

namespace cbtek{
namespace common{
namespace utility{
enum class StateType
{
    Enter,
    Update,
    Exit
};

class State
{
public:
    State() { m_type = StateType::Enter; }
    StateType type() const { return m_type; }
    void setType(StateType type) { m_type = type; }
    void next();
    void reset();
private:
    StateType m_type;
};
using StatePtr = std::shared_ptr<State>;
}}}//namespace
