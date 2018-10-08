mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_CXXOBJS += \
Controller.o \
Machine.o \
OnOffController.o


ifeq ($(side),right)
    APPL_CXXOBJS += RightNormalCourse.o \
    RightCourse.o \

endif

ifeq ($(side),left)

    APPL_CXXOBJS += LeftNormalCourse.o \
    LeftCourse.o \


endif

SRCLANG := c++

APPL_DIR += $(mkfile_path)apps

INCLUDES += -I$(mkfile_path)apps

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif
