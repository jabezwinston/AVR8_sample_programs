ifeq ($(OS),Windows_NT)
    ifeq ($(notdir $(MAKE)),mingw32-make)
        SHELL = cmd
        RM  = del /s /q
    else
        RM = rm -rf
    endif
else
    RM = rm -rf
endif

############ Tools #########################

CC = avr-gcc
AS = avr-as
LD = avr-ld
OBJCOPY = avr-objcopy

FLASH_TOOL = avrdude

#############################################

MCU = atmega328p

PORT ?= /dev/ttyACM0

CPU_FREQ = 16000000

########## Compiler/Linker Flags ############

CFLAGS += -O2 -mmcu=$(MCU) -D F_CPU=$(CPU_FREQ)

LDFLAGS +=

#############################################

OBJ_DIR = build

C_FILES = $(notdir $(C_SRCS))
C_OBJS = $(addprefix $(OBJ_DIR)/, $(C_FILES:.c=.o))
C_PATHS = $(sort $(dir $(C_SRCS)))

ELF = $(OUTPUT).elf
HEX = $(OUTPUT).hex

############## Make targets #################

all: $(ELF) $(HEX)

$(HEX): $(ELF)
	@echo [ HEX ] $(HEX)
	@$(OBJCOPY) -O ihex $< $@

$(OBJ_DIR):
	@echo [ MKDIR ] $@
	@mkdir "$@"

$(ELF): $(OBJ_DIR) $(C_OBJS)
	@echo [ LD ] $@
	@$(CC) $(LDFLAGS) -o $(ELF) $(C_OBJS) $(addprefix -L,$(LIBPATHS)) $(addprefix -l,$(LIBS))

$(OBJ_DIR)/%.o: %.c
	@echo [ CC ] $< 
	@$(CC) $(CFLAGS) $(addprefix -I,$(INCLUDEPATHS)) -o "$@" "$<"

flash : $(HEX)
	@echo [ AVRDUDE ] $(HEX)
	@$(FLASH_TOOL) -p$(MCU) -c arduino -b 115200 -P $(PORT) -D -Uflash:w:$(HEX):i
 
clean:
	$(RM) $(OBJ_DIR) $(EXE) $(HEX)
