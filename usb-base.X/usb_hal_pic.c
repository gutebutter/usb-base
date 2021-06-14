/*
 * File:   usb_hal_pic.c
 * Author: tf
 *
 * Created on 14 June 2021, 08:58
 */

#include <xc.h>

#include "usb_config.h"
#include "usb_hal_pic.h"

#define USB_EP0_OUT_BASE    (USB_BDT_BASE + 2 * sizeof(struct usb_bdt))
#define USB_EP0_IN_BASE     (USB_EP0_OUT_BASE + USB_EP0_SIZE)
uint8_t usb_ep0_buf_out[USB_EP0_SIZE] __at(USB_EP0_OUT_BASE);
uint8_t usb_ep0_buf_in[USB_EP0_SIZE] __at(USB_EP0_OUT_BASE + USB_EP0_SIZE);

// the usb BDTs.
// 1 for EP0, single buffered
// 2 for application EPs, single buffered
struct usb_bdt usb_bdt[2] __at(USB_BDT_BASE);

#if 0
// bdts have to be initialized at runtime, since xc8 tells me 'initialization of absolute variable in RAM is not supported'
{
    // ep0 entries, no ping-pong
    {
        .stat = 0,
        .cnt = USB_EP0_SIZE,
        .adrl = USB_EP0_OUT_BASE & 0xFF,
        .adrh = USB_EP0_OUT_BASE >> 8
    },
    {
        .stat = 0,
        .cnt = USB_EP0_SIZE,
        .adrl = USB_EP0_IN_BASE & 0xFF,
        .adrh = USB_EP0_IN_BASE >> 8      
    }
};
#endif

void inline usb_select_ep(uint8_t ep) {
    
}

// initialize usb macro to the point where usb resets can be received (?!)
void usb_init() {
    
    // the macro expects the BDT implicitly at USB_BDT_BASE
    
    // setup the BDT for EP0
    // EP0 out
    usb_bdt[0].cnt = USB_EP0_SIZE;
    usb_bdt[0].adrl = USB_EP0_OUT_BASE & 0xFF;
    usb_bdt[0].cnt = USB_EP0_OUT_BASE >> 8;
    // EP0 in
    usb_bdt[1].cnt = USB_EP0_SIZE;
    usb_bdt[1].adrl = USB_EP0_IN_BASE & 0xFF;
    usb_bdt[1].cnt = USB_EP0_IN_BASE >> 8;
    
    // endpoint 0 configuration, bidirectional, do not block SETUP transfers
    UEP0bits.EPINEN = 1;
    UEP0bits.EPOUTEN = 1;    
    
    UCFGbits.UPUEN = 1; // use device internal Dx pullups
    UCFGbits.FSEN = 1; // full-speed configuration
    // lets go, clock has to be setup prior to setting this bit
    UCONbits.USBEN = 1;
}
