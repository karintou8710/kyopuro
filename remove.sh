#!/bin/sh

# デバック時のバグで生成されたa~zのファイルを一括削除
echo "名前がa~zのファイルを削除します。(^^)/"
find . -maxdepth 1  -type f | grep -E "^\./[a-z]$" | xargs rm -v