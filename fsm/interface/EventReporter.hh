#pragma once


template <class T>
class EventReporter
{
public:
    static T& get()
    {
        static T eventReporter;
        return eventReporter;
    }
    
protected:
    EventReporter() = default;
    ~EventReporter() = default;

    EventReporter(const EventReporter& orig) = delete;
    EventReporter& operator=(const EventReporter& orig) = delete;
};
