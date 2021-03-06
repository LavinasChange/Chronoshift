/**
 * @file
 *
 * @author CCHyper
 * @author OmniBlade
 *
 * @brief 
 *
 * @copyright Chronoshift is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#include "unit.h"

#ifndef CHRONOSHIFT_STANDALONE
TFixedIHeapClass<UnitClass> &g_Units = Make_Global<TFixedIHeapClass<UnitClass> >(0x0065DC40);
#else
TFixedIHeapClass<UnitClass> g_Units;
#endif

UnitClass::UnitClass(RTTIType type, int id, HousesType house) :
    FootClass(type, id, house)
{
}

UnitClass::UnitClass(const UnitClass &that) :
    FootClass(that)
{
}

UnitClass::UnitClass(const NoInitClass &noinit) :
    FootClass(noinit)
{
}

UnitClass::~UnitClass()
{
}
