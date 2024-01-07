#!/usr/bin/python3
file = open('../../CMakeLists.txt', 'r')
lines = file.readlines()
fileTemplate = open('SmartSensors_Template.pro', 'r')
template = fileTemplate.read()
headers = filter(lambda x: ".h" in x , lines)
headers = ["../../"+ h.replace("\n","").replace(" ","") + " \ \n"  for h in headers]
source = filter(lambda x: ".cpp" in x , lines)
source = ["../../"+ h.replace("\n","").replace(" ","") + " \ \n"  for h in source]
template = template.replace("{HEADERS}", "".join(headers))
template = template.replace("{SOURCES}", "".join(source))
fileOut = open('SmartSensors.pro', 'w')
fileOut.write(template)