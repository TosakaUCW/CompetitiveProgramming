@echo off
cd G:\Solution_Source_Code
git add . && git commit -m %date:~0,10% && git push