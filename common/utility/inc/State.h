#pragma once

namespace cbtek{
namespace common{
namespace utility{
class State
{
public:
    State();
    bool isEnter() const;
    bool isUpdate() const;
    bool isExit() const;
    void setEnter(const bool & mode);
    void setUpdate(const bool & mode);
    void setExit(const bool & mode);
    void setEnter();
    void setUpdate();
    void setExit();
    void setId(int id);
    int getId() const;
    void reset();
private:
    bool m_isEnter,m_isUpdate,m_isExit;
    int m_id;


};
}}}//namespace
