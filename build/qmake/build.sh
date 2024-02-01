SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
make $SCRIPT_DIR/out/
if [[ -z "${QT_PATH}" ]]; then
  qmake $SCRIPT_DIR/SmartSensors.pro -o $SCRIPT_DIR/out/Makefile
else
  $QT_PATH/6.6.1/gcc_64/bin/qmake $SCRIPT_DIR/SmartSensors.pro -o $SCRIPT_DIR/out/Makefile
fi
cd $SCRIPT_DIR/out/
make
#$SCRIPT_DIR/out/SmartSensors ##UNCOMMENT TO RUN