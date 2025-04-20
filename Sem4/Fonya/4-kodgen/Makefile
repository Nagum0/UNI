BUILD_DIR := build

TAB_CC := $(BUILD_DIR)/while.tab.cc
TAB_HH := $(BUILD_DIR)/while.tab.hh
LEX_CC := $(BUILD_DIR)/lex.yy.cc
POSITION_HH := $(BUILD_DIR)/position.hh
LOCATION_HH := $(BUILD_DIR)/location.hh

SRC := while.cc semantics.cc
OUT := while

all: $(OUT)

$(OUT): $(LEX_CC) $(TAB_CC) $(TAB_HH) $(POSITION_HH) $(LOCATION_HH) $(SRC)
	g++ -I$(BUILD_DIR) $(LEX_CC) $(TAB_CC) $(SRC) -o $(OUT)

$(LEX_CC): while.l | $(BUILD_DIR)
	flex -o $(LEX_CC) while.l

$(TAB_CC) $(TAB_HH) $(LOCATION_HH) $(POSITION_HH): while.y | $(BUILD_DIR)
	bison -d while.y
	mv while.tab.cc $(TAB_CC)
	mv while.tab.hh $(TAB_HH)
	mv location.hh $(LOCATION_HH)
	mv position.hh $(POSITION_HH)
	mv stack.hh $(BUILD_DIR)/stack.hh

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(OUT)

