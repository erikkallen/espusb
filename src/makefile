#
#             LUFA Library
#     Copyright (C) Dean Camera, 2015.
#
#  dean [at] fourwalledcubicle [dot] com
#           www.lufa-lib.org
#
# --------------------------------------
#         LUFA Project Makefile.
# --------------------------------------

# Run "make help" for target help.

SPIFFS_PATH = ../spiffs/src

MCU          = atmega8u2
ARCH         = AVR8
BOARD        = SPARKFUN8U2
F_CPU        = 16000000
F_USB        = $(F_CPU)
OPTIMIZATION = s
TARGET       = espusb
SRC          = $(TARGET).c Descriptors.c $(LUFA_SRC_USB) $(LUFA_SRC_USBCLASS) \
               $(SPIFFS_PATH)/spiffs_nucleus.c \
               $(SPIFFS_PATH)/spiffs_gc.c \
			   $(SPIFFS_PATH)/spiffs_hydrogen.c \
			   $(SPIFFS_PATH)/spiffs_cache.c \
			   $(SPIFFS_PATH)/spiffs_check.c
LUFA_PATH    = ../LUFA
CC_FLAGS     = -DUSE_LUFA_CONFIG_HEADER -IConfig/ -I../spiffs/src
LD_FLAGS     =
AVRDUDE_PROGRAMMER = avrispmkii

# Default target
all:

# Include LUFA build script makefiles
include $(LUFA_PATH)/Build/lufa_core.mk
include $(LUFA_PATH)/Build/lufa_sources.mk
include $(LUFA_PATH)/Build/lufa_build.mk
include $(LUFA_PATH)/Build/lufa_cppcheck.mk
include $(LUFA_PATH)/Build/lufa_doxygen.mk
include $(LUFA_PATH)/Build/lufa_dfu.mk
include $(LUFA_PATH)/Build/lufa_hid.mk
include $(LUFA_PATH)/Build/lufa_avrdude.mk
include $(LUFA_PATH)/Build/lufa_atprogram.mk
