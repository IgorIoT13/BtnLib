#ifndef BTN_HEADER
#define BTN_HEADER
#include "setting.h"

/**
 * Don`t have interupt now but in future version i add them (I promiss)
 */



/**
 * @brief Class to more easy and comfortable use button
 * 
 * @warning Important use begin() after declarate (used constrancts) because him setup all parameters
 * 
 * 
 * @version 1.0
 * @author Igor Co (or IgorIoT13)
 */
class btn{
private:
    BTN_TYPE type;
    uint8_t pin;
    bool pressFlag;

    void (*onPress)(void* parameters);
    
public:
    /**
     * ----------------------------------------------------------------------------------------------------------------
     * --------------------------- Consturctors -----------------------------------------------------------------------
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
     * @brief Set all parameters for button
     */
    btn(uint8_t pin, BTN_TYPE type);


    /**
     * @brief Use in construct to more easy change parameters if need
     * @warning Better use construct (it`s more correct)
     * 
     * @return Error if something was wrong and ALL_OK if all good
     */
    ErrorList init (uint8_t pin = NULL, BTN_TYPE type = PULL_UP_TYPE);

    /**
     * @brief Use begin to setup all parameters
     * @warning Important to use
     * 
     * @return Error if something was wrong and ALL_OK if all good
     */
    ErrorList begin();
/**
 * ____________________________________________________________________________________________________________________
 * _______________________________ Busines logic ______________________________________________________________________
 * ____________________________________________________________________________________________________________________
 */


    /**
     * @brief Monitor changes and if some changed set flag(pressFlag)
     * @warning If begin() isn`t used - don`t work
     * 
     * @return Error if something was wrong and ALL_OK if all good
     */
    ErrorList tick();

    



};


#endif
