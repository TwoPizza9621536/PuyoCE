# SPDX-FileCopyrightText: 2023 Samuel Wu
#
# SPDX-License-Identifier: CC0-1.0

## Makefile Options
NAME = PUYOCE
ICON = icon.png
DESCRIPTION = "A port of the Puyo Puyo puzzle game to the TI-84 Plus CE"
COMPRESSED = YES
ARCHIVED = NO

# C Compiler Flags
CFLAGS = -Oz -Wall -Wextra -Wpedantic -pedantic -pedantic-errors

# C++ Compiler Flags
CXXFLAGS = -Oz -Wall -Wextra -Weffc++ -Wpedantic -pedantic -pedantic-errors

## Include default Makefile options
include $(shell cedev-config --makefile)
