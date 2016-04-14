#pragma once

/*********************************************************************************************************/
/************************************************ LOOPS  *************************************************/
/*********************************************************************************************************/
/*
FOREACH MACRO
*/

#define FOREACH(var, container)                     \
    auto __endpointer_##container##__ = (container)->end();       \
    container->GetEnumerator()->Reset();            \
    for(auto var = (container)->begin()++;          \
        var != __endpointer_##container##__;                      \
        ++var)