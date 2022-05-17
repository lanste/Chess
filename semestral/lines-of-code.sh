#!/usr/bin/env bash

echo $(date) >> progress.log
RESULT=$(find "./src/" -type f -name "*.cpp" -o -name "*.h" | xargs wc -l | head -n -1 | wc -l)
echo "$RESULT files of code" >> progress.log
find "./src/" -type f -name "*.cpp" -o -name "*.h" | xargs wc -l | tail -1 >> progress.log
echo "
" >> progress.log
