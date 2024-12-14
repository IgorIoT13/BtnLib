#ifndef BTN_SETTING
#define BTN_SETTING

#include <Arduino.h>
#include "ErrorList.h"

typedef enum BTN_TYPE{
    PULL_UP_TYPE,
    PULL_DOWN_TYPE,
    PRESS_PULL_UP_TYPE,
    PRESS_PULL_DOWN_TYPE,
    NULL_TYPE
}BTN_TYPE;


#endif
