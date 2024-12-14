#ifndef BTN_HEADER
#define BTN_HEADER
#include "setting.h"

class btn{
private:
    BTN_TYPE type;
    uint8_t pin;    
    
public:
    /**
     * ----------------------------------------------------------------------------------------------------------------
     * ---------------------- Consturctors ----------------------------------------------------------------------------
     * ----------------------------------------------------------------------------------------------------------------
     */

    
    /**
     * @brief Default consturt
     * @note Use him to declarate button
     * @warning begin don`t work if you only don`t use manual set pin and type
     */
    btn();

    /**
     * @brief Set only pin 
     * @note Type was set automatic (PULL_UP_TYPE)
     */
    btn(uint8_t pin);

    /**
     * @brief Set all paramets for button
     */
    btn(uint8_t pin, BTN_TYPE type);

    /**
     * 
     * 
     * 
     */




};


#endif
