# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug_x64
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug_x64)
  raylib_config = debug_x64
  game_premake_main_config = debug_x64

else ifeq ($(config),debug_x86)
  raylib_config = debug_x86
  game_premake_main_config = debug_x86

else ifeq ($(config),release_x64)
  raylib_config = release_x64
  game_premake_main_config = release_x64

else ifeq ($(config),release_x86)
  raylib_config = release_x86
  game_premake_main_config = release_x86

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := raylib game-premake-main

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

raylib:
ifneq (,$(raylib_config))
	@echo "==== Building raylib ($(raylib_config)) ===="
	@${MAKE} --no-print-directory -C _build -f raylib.make config=$(raylib_config)
endif

game-premake-main: raylib
ifneq (,$(game_premake_main_config))
	@echo "==== Building game-premake-main ($(game_premake_main_config)) ===="
	@${MAKE} --no-print-directory -C _build -f game-premake-main.make config=$(game_premake_main_config)
endif

clean:
	@${MAKE} --no-print-directory -C _build -f raylib.make clean
	@${MAKE} --no-print-directory -C _build -f game-premake-main.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug_x64"
	@echo "  debug_x86"
	@echo "  release_x64"
	@echo "  release_x86"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   raylib"
	@echo "   game-premake-main"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"