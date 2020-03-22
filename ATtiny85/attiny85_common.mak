############ Tools #########################

CC = avr-gcc
AS = avr-as
LD = avr-ld
OBJCOPY = avr-objcopy

FLASH_TOOL = micronucleus

#############################################

MCU = attiny85

CPU_FREQ = 16500000

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
	@echo [ FLASH ] $(HEX)
	@$(FLASH_TOOL) --run --type intel-hex $(HEX)
 
clean:
	rm -rf $(OBJ_DIR) $(EXE) $(HEX)
