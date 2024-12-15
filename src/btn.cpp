#include "btn.h"
    /**
     * ----------------------------------------------------------------------------------------------------------------
     * --------------------------- Consturctors -----------------------------------------------------------------------
     * ----------------------------------------------------------------------------------------------------------------
     */

    
    Btn::Btn(){
        this->init(0, PULL_UP_TYPE);
    }


    Btn::Btn(uint8_t pin){
        this->init(pin, PULL_UP_TYPE);
    }


    Btn::Btn(uint8_t pin, BTN_TYPE type){
        this->init(pin, type);
    }


    Btn::Btn(uint8_t pin, BTN_TYPE type, uint32_t delayTime){
        this->init(pin, type);
        this->setDelayTime(delayTime);
    }


    /**
     * ----------------------------------------------------------------------------------------------------------------
     * --------------------------- Starts fuctions ----------------------------------------------------------------------
     * ----------------------------------------------------------------------------------------------------------------
     */


    ErrorList Btn::init (uint8_t pin, BTN_TYPE type){
        this->pin = pin;
        this->type = type;
        this->onPress = nullptr;
        return ALL_OK;
    }


    ErrorList Btn::begin(){
        if(this->pin != 0 && pin <= MAX_PIN){
            this->pin = pin;
            this->type = type;

            ErrorList err = this->configPinout();

            if(err != ALL_OK){
                return err;
            }

            beginComplete = true;
            return ALL_OK;
        }else if(pin > MAX_PIN){
            return ERR_VALUER_UNCORECT;
        }else{
            return ERR_NULL_VALUER;
        }
    }


/**
 * ____________________________________________________________________________________________________________________
 * _______________________________ Busines logic ______________________________________________________________________
 * ____________________________________________________________________________________________________________________
 */



    /**
     * ----------------------------------------------------------------------------------------------------------------
     * --------------------------- Tick fuction -----------------------------------------------------------------------
     * ----------------------------------------------------------------------------------------------------------------
     */

    ErrorList Btn::tick(){

        if(this->type == PRESS_PULL_DOWN_TYPE || this->type == PRESS_PULL_UP_TYPE){
            this->press_tick();
        }else if(this->type == NULL_TYPE){
            return ERR_NULL_VALUER;
        }else{
            this->btn_tick();
        }
        return ALL_OK;
    }

    
    /**
     * ----------------------------------------------------------------------------------------------------------------
     * --------------------------- Handler fuctions -------------------------------------------------------------------
     * ----------------------------------------------------------------------------------------------------------------
     */


    ErrorList Btn::addPressFunction(void (*function)(void)){
        if(function != nullptr){
            this->onPress = function;
            return ALL_OK;
        }else{
            return ERR_NULL_VALUER;
        }
    }


    ErrorList Btn::removePressFunction(){
        if(this->onPress != nullptr){
            this->onPress = nullptr;
        }
        return ALL_OK;
    }


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


    ErrorList Btn::setPin(uint8_t pin){
        if(pin != 0 && pin <= MAX_PIN){
            this->pin = pin;
            ErrorList err = this->configPinout();
            return err;
        }else if(pin > MAX_PIN){
            return ERR_VALUER_UNCORECT;
        }else{ 
            return ERR_NULL_VALUER;
        }
    }


    ErrorList Btn::setType(BTN_TYPE type){
        if(type != NULL_TYPE){
            this->type = type;
            ErrorList err = this->configPinout();
            return err;
        }else{
            return ERR_NULL_VALUER;
        }
    }

    ErrorList Btn::setDelayTime(uint32_t time){
        this->delayTime = time;
        return ALL_OK;
    }



/**
 * ____________________________________________________________________________________________________________________
 * _______________________________ Service logic ______________________________________________________________________
 * ____________________________________________________________________________________________________________________
 */

    /**
     * ----------------------------------------------------------------------------------------------------------------
     * ---------------------------Service handler fuctions and checkers -----------------------------------------------
     * ----------------------------------------------------------------------------------------------------------------
     */


    ErrorList Btn::doPressFunction(){
        if(this->onPress != nullptr){
            onPress();
            return ALL_OK;
        }else{
            return ERR_NULL_VALUER;
        }
    }


    /**
     * ----------------------------------------------------------------------------------------------------------------
     * --------------------------- Service Ticks fuctions -------------------------------------------------------------
     * ----------------------------------------------------------------------------------------------------------------
     */

    ErrorList Btn::btn_tick(){
        if(millis() - this->bufer >= this->delayTime){
            this->bufer = millis();
            switch(this->type){
                case PULL_UP_TYPE:
                    if(!digitalRead(this->pin)){
                        this->pressFlag = true;
                    }
                    break;

                case PULL_DOWN_TYPE:
                    if(digitalRead(this->pin)){
                        this->pressFlag = true;
                    }
                    break;
                default:
                    return ERR_VALUER_UNCORECT;
                    break;
            }
        }
        return ALL_OK;
    }


    ErrorList Btn::press_tick(){

        switch(this->type){
                case PRESS_PULL_UP_TYPE:
                    if(!digitalRead(this->pin)){
                        this->pressFlag = true;
                    }else{
                        this->pressFlag = false;
                    }
                    break;

                case PRESS_PULL_DOWN_TYPE:
                    if(digitalRead(this->pin)){
                        this->pressFlag = true;
                    }else{
                        this->pressFlag = false;
                    }
                    break;
                default:
                    return ERR_VALUER_UNCORECT;
                    break;
            }
        return ALL_OK;
    }


    ErrorList Btn::configPinout(){
        uint8_t pin_mode = 0;

        if(this->type == PULL_UP_TYPE || this->type == PRESS_PULL_UP_TYPE){
            pin_mode = PULLUP;
        }else if(this->type == PULL_DOWN_TYPE || this->type == PRESS_PULL_DOWN_TYPE){
            pin_mode = PULLDOWN;
        }else{ 
            return ERR_NULL_VALUER;
        }


        if(pin != 0 && pin <= MAX_PIN){
            this->pin = pin;
            pinMode(this->pin, pin_mode);
            return ALL_OK;
        }else if(pin > MAX_PIN){
            return ERR_VALUER_UNCORECT;
        }else{ 
            return ERR_NULL_VALUER;
        }
        return ALL_OK;
    }


