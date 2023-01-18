SRC += features/achordion.c

OLED_ENABLE = no
CAPS_WORD_ENABLE = yes

VPATH +=  keyboards/gboards/

ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
