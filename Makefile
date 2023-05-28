# SPDX-FileCopyrightText: 2023 Samuel Wu
#
# SPDX-License-Identifier: CC0-1.0

## Makefile Options
NAME = PUYOCE
DESCRIPTION = "A port of the Puyo Puyo puzzle game to the TI-84 Plus CE"
ICON = icon.png
COMPRESSED = NO
COMPRESSED_MODE = zx0
ARCHIVED = NO

# C Compiler Flags
CFLAGS = -std=c99
CFLAGS += -Oz -Wall -Wextra -Wpedantic -pedantic -pedantic-errors

# C++ Compiler Flags
CXXFLAGS = -std=c++98
CXXFLAGS += -Oz -Wall -Wextra -Weffc++ -Wpedantic -pedantic -pedantic-errors

## Include default Makefile options
include $(shell cedev-config --makefile)
