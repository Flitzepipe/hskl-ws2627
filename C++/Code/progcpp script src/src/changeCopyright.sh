#!/bin/bash

SUB="s/2018 \+Wil/2018 - 2022 Wil/g"

find . -name "*.cc" -exec sed -i "$SUB" {} \;
find . -name "*.c" -exec sed -i "$SUB" {} \;
find . -name "*.h" -exec sed -i "$SUB" {} \;
find . -name "*.java" -exec sed -i "$SUB" {} \;
find . -name "Makefile" -exec sed -i "$SUB" {} \;
find . -name "Makefile.include" -exec sed -i "$SUB" {} \;
find . -name "nmake" -exec sed -i "$SUB" {} \;
find . -name "nmake.include" -exec sed -i "$SUB" {} \;

SUB="s/wilhelm.meier@fh-kl.de/wilhelm.meier@hs-kl.de/g"

find . -name "*.cc" -exec sed -i "$SUB" {} \;
find . -name "*.c" -exec sed -i "$SUB" {} \;
find . -name "*.h" -exec sed -i "$SUB" {} \;
find . -name "*.java" -exec sed -i "$SUB" {} \;
find . -name "Makefile" -exec sed -i "$SUB" {} \;
find . -name "Makefile.include" -exec sed -i "$SUB" {} \;
find . -name "nmake" -exec sed -i "$SUB" {} \;
find . -name "nmake.include" -exec sed -i "$SUB" {} \;
