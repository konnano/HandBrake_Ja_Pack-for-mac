#!/bin/sh
cd `dirname $0`
cd ./en.lproj 2>/dev/null

path=`pwd|rev|cut -c 1-16|rev`
current='Ja_Pack/en.lproj'

if [ $path = $current ];then

 if [ -d /Applications/HandBrake.app/Contents/Resources/en.lproj ]
 then
  cp -R . /Applications/HandBrake.app/Contents/Resources/en.lproj/.
 elif [ -d /Applications/HandBrake.app/Contents/Resources/English.lproj ]
 then
  cp -R . /Applications/HandBrake.app/Contents/Resources/English.lproj/.
 else
  echo "\033[31m /ApplicationフォルダーにHandbreak.appがありません。\033[0m"
 fi

else
echo "\033[31m Ja_Pack内でクリックして下さい。\033[0m"
fi
