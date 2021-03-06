#pragma once

#ifndef TRIGGERTYPE_H
#define TRIGGERTYPE_H

#include "always.h"
#include "abstracttype.h"
#include "housetype.h"
#include "taction.h"
#include "tevent.h"

// This enum is just for casting the TriggerType heap indexes.
enum TriggerType
{
    TRIGGER_NONE = -1,
};

DEFINE_ENUMERATION_OPERATORS(TriggerType);

enum TriggerStateType
{
    STATE_NONE = -1,
    STATE_VOLATILE = 0, // Will only ever be activated once.
    STATE_SEMI_PERSISTANT, // Will only trigger once the trigger event has all conditions have been met.
    STATE_PERSISTANT, // Will continue to repeat itself whenever its trigger event is true.
};

enum TEventWhenType
{
    /*
    When 0, only the first trigger event (part 5) must be true for the trigger to be activated.
    When 1, the first (part 5) and second (part 8) must both be true for the trigger to be activated.
    When 2, either the first trigger event or the second trigger event must be true, whichever comes first.
    When 3, either the first trigger event or the second trigger event must be true. See the upcoming summary (next) for
            further details on how this operates.
    */
};

enum TActionWhenType
{
    /*
    When 0, only one trigger action is activated when the event is triggered. See the summary (next) for which trigger action
            is activated, and when.
    When 1, both trigger actions are activated when the event is triggered.
    */
};

class TriggerTypeClass : public AbstractTypeClass
{
public:
    TriggerTypeClass();
    // TriggerTypeClass(const TriggerTypeClass &noinit);
    TriggerTypeClass(const NoInitClass &noinit) : AbstractTypeClass(noinit) {}
    ~TriggerTypeClass() {}

    void Code_Pointers();
    void Decode_Pointers();

    TEventClass Get_Event_One() const { return m_EventOne; }
    TEventClass Get_Event_Two() const { return m_EventTwo; }
    TActionClass Get_Action_One() const { return m_ActionOne; }
    TActionClass Get_Action_Two() const { return m_ActionTwo; }

    HousesType Get_House() const { return m_House; }

    static TriggerTypeClass *From_Name(const char *name);
    static const char *Name_From(TriggerType trigger);
    static const char *Name_From(TriggerTypeClass *trigger);

    static TriggerTypeClass &As_Reference(TriggerType trigger);
    static TriggerTypeClass *As_Pointer(TriggerType trigger);

protected:
#ifndef CHRONOSHIFT_NO_BITFIELDS
    // Union/Struct required to get correct packing when compiler packing set to 1.
    union
    {
        struct
        {
            bool m_IsActive : 1; // 1
        };
        int m_Bitfield;
    };
#else
    bool m_IsActive;
#endif

    TriggerStateType m_State;
    HousesType m_House;
    TEventClass m_EventOne;
    TEventClass m_EventTwo;
    TEventWhenType m_TrigEventWhen;
    TActionClass m_ActionOne;
    TActionClass m_ActionTwo;
    TActionWhenType m_TrigActionWhen;
};

#ifndef CHRONOSHIFT_STANDALONE
#include "hooker.h"
extern TFixedIHeapClass<TriggerTypeClass> &g_TriggerTypes;
#else
extern TFixedIHeapClass<TriggerTypeClass> g_TriggerTypes;
#endif

#endif // TRIGGERTYPE_H
