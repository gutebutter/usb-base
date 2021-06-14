/*
 * File:   main.c
 * Author: tf
 *
 * Created on 10 June 2021, 11:21
 */

#include <xc.h>
#include <stdint.h>
#include <stddef.h>

#include "config.h"
#include "usb.h"

void main(void) {   
    
    usb_init();
    
    while (1);
}
