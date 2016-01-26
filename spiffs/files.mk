ifndef niffs
$(warn defaulting path to generic spiffs module, spiffs variable not set)
spiffs = ../generic/spiffs
endif
FLAGS	+= -DCONFIG_BUILD_SPIFFS
INC	+= -I${spiffs}/src
CPATH	+= ${spiffs}/src
SPIFFS_FILES	+= spiffs_nucleus.c
SPIFFS_FILES	+= spiffs_gc.c
SPIFFS_FILES	+= spiffs_hydrogen.c
SPIFFS_FILES	+= spiffs_cache.c
SPIFFS_FILES	+= spiffs_check.c
