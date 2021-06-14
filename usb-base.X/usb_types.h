#ifndef USB_TYPES_H_
#define USB_TYPES_H_

#include <stdint.h>

// USB Descriptors
// Device Descriptor
struct usb_device_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdUSB;
    uint8_t bDeviceClass;
    uint8_t bDeviceSubClass;
    uint8_t bDeviceProtocol;
    uint8_t bMaxPacketSize;
    uint16_t idVendor;
    uint16_t idProduct;
    uint16_t bcdDevice;
    uint8_t iManifacturer;
    uint8_t iProduct;
    uint8_t iSerialNumber;
    uint8_t bNumConfigurations;
};

// Configuration Descriptor
struct usb_configuration_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t wTotalLength;
    uint8_t bNumInterfaces;
    uint8_t bConfigurationValue;
    uint8_t iConfiguration;
    uint8_t bmAttributes;
    uint8_t bMaxPower;
};

// Interface Descriptor
struct usb_interface_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bInterfaceNumber;
    uint8_t bAlternateSetting;
    uint8_t bNumEndpoints;
    uint8_t bInterfaceClass;
    uint8_t bInterfaceSubClass;
    uint8_t bInterfaceProtocol;
    uint8_t iInterface;
};

// Endpoint Descriptor
struct usb_endpoint_descriptor {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bEndpointAddress;
    uint8_t bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t bInterval;
};

// the setup packet
struct usb_setup_packet {
    uint8_t bmRequestType;
    uint8_t bRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;
};

// bits in 'bmRequestType'
#define USB_REQUEST_DIR_DEVICE_TO_HOST    0x80

#define USB_REQUEST_TYPE_MASK       0x60
#define USB_REQUEST_TYPE_STANDARD   0
#define USB_REQUEST_TYPE_CLASS      1
#define USB_REQUEST_TYPE_VENDOR     2
#define USB_REQUEST_TYPE_RSVD       3

#define USB_REQUEST_RECIPIENT_MASK      0x1F
#define USB_REQUEST_RECIPIENT_DEVICE    0
#define USB_REQUEST_RECIPIENT_INTERFACE 1
#define USB_REQUEST_RECIPIENT_ENDPOINT  2
#define USB_REQUEST_RECIPIENT_OTHER     3
#define USB_REQUEST_RECIPIENT_RSVD      4 // up to 31

// Standard Requests
// Standard Device Requests
#define USB_DEVICE_REQUEST_GET_STATUS           0x00
#define USB_DEVICE_REQUEST_CLEAR_FEATURE        0x01
#define USB_DEVICE_REQUEST_SET_FEATURE          0x03
#define USB_DEVICE_REQUEST_SET_ADDRESS          0x05
#define USB_DEVICE_REQUEST_GET_DESCRIPTOR       0x06
#define USB_DEVICE_REQUEST_SET_DESCRIPTOR       0x07
#define USB_DEVICE_REQUEST_GET_CONFIGURATION    0x08
#define USB_DEVICE_REQUEST_SET_CONFIGURATION    0x09

// Standard Interface Requests
#define USB_INTERFACE_REQUEST_GET_STATUS    0x00
#define USB_INTERFACE_REQUEST_CLEAR_FEATURE 0x01
#define USB_INTERFACE_REQUEST_SET_FEATURE   0x03
#define USB_INTERFACE_REQUEST_GET_INTERFACE 0x0A
#define USB_INTERFACE_REQUEST_SET_INTERFACE 0x11

// Standard Endpoint Requests
#define USB_ENDPOINT_REQUEST_GET_STATUS     0x00
#define USB_ENDPOINT_REQUEST_CLEAR_FEATURE  0x01
#define USB_ENDPOINT_REQUEST_SET_FEATURE    0x03
#define USB_ENDPOINT_REQUEST_SYNCH_FRAME    0x12

#endif // USB_TYPES_H_
