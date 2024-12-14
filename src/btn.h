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

    void (*onPress)(void);
    
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
     * ----------------------------------------------------------------------------------------------------------------
     * --------------------------- Starts fuctions ----------------------------------------------------------------------
     * ----------------------------------------------------------------------------------------------------------------
     */


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
     * ----------------------------------------------------------------------------------------------------------------
     * --------------------------- Tick fuctions ----------------------------------------------------------------------
     * ----------------------------------------------------------------------------------------------------------------
     */


    /**
     * @brief Monitor changes and if some changed set flag(pressFlag)
     * @warning If begin() isn`t used - don`t work
     * 
     * @return Error if something was wrong and ALL_OK if all good
     */
    ErrorList tick();

    
    /**
     * ----------------------------------------------------------------------------------------------------------------
     * --------------------------- Handler fuctions -------------------------------------------------------------------
     * ----------------------------------------------------------------------------------------------------------------
     */


    /**
     * @brief Add function what works when button is active
     * @warning Fuction type void and cannot return valuer
     * @warning Fuction cannon take parameters
     * 
     * @param function it`s a void type function what was set as a press function
     * 
     * @return Error if something was wrong and ALL_OK if all good
     */
    ErrorList addPressFunction(void (*function)(void));


    /**
     * @brief Remove press fuction
     * @note If press function isn`t was add, do nothing.
     * 
     * @return Error if something was wrong and ALL_OK if all good
     */
    ErrorList removePressFunction();


/**
 * ____________________________________________________________________________________________________________________
 * _______________________________ GETTERS and SETTERS ________________________________________________________________
 * ____________________________________________________________________________________________________________________
 */



    /**
     * ----------------------------------------------------------------------------------------------------------------
     * --------------------------- Setters ----------------------------------------------------------------------------
     * ----------------------------------------------------------------------------------------------------------------
     */


    /**
     * @brief Set button pin
     * 
     * @return Error if something was wrong and ALL_OK if all good
     */
    ErrorList setPin(uint8_t pin);

    /**
     * @brief Set work type button
     * 
     * @return Error if something was wrong and ALL_OK if all good
     */
    ErrorList setType(BTN_TYPE type);


private:

/**
 * ____________________________________________________________________________________________________________________
 * _______________________________ Service logic ______________________________________________________________________
 * ____________________________________________________________________________________________________________________
 */

/**
 * @brief Use to safe run press functions
 * 
 * @return Error if something was wrong and ALL_OK if all good
 */
ErrorList doPressFunction();


};


#endif
