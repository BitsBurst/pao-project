SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
$QT_PATH/6.6.1/gcc_64/bin/qmake $SCRIPT_DIR/SmartSensors.pro -o $SCRIPT_DIR/out/Makefile
cd $SCRIPT_DIR/out/
make
#$SCRIPT_DIR/out/SmartSensors ##UNCOMMENT TO RUN
