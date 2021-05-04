SRC += oxinai.c \
      process_records.c

ifeq ($(strip $(QMKRC_ENABLE)), yes)
	SRC += qmk_rc.c
	RAW_ENABLE = yes
endif

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
  SRC += secrets.c
endif

EXTRAFLAGS += -flto

ifeq ($(strip $(NO_SECRETS)), yes)
    OPT_DEFS += -DNO_SECRETS
endif

