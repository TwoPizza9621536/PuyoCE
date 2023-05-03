# SPDX-FileCopyrightText: 2023 Samuel Wu
#
# SPDX-License-Identifier: CC0-1.0

## Makefile Options
NAME = PUYOCE
ICON = icon.png
DESCRIPTION = "A port of the Puyo Puyo puzzle game to the TI-84 Plus CE"
COMPRESSED = NO
ARCHIVED = NO

# C Compiler Flags
CFLAGS = -std=c99 -Oz
CFLAGS := -Wall -Wextra -Wpedantic -pedantic -pedantic-errors

# C++ Compiler Flags
CXXFLAGS = -Wall -Wextra -Weffc++ -Wpedantic -pedantic -pedantic-errors
CXXFLAGS := -Oz

## Include default Makefile options
include $(shell cedev-config --makefile)
