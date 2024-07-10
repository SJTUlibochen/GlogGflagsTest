echo "Without any command line arguments or flags"
./bin/GlogGflagsTest
echo "-----------------------------------------------------"

echo "Recommended format: ./executable --<other_flag>=<value> --(no)bool_flag"
./bin/GlogGflagsTest --nobool_var --int32_var=10 --double_var=10.5 --str_var="Hello World" --port=8080 --multi_vd1="joachim" --multi_vd2="joshua" --multi_vd3="ZHI"
echo "-----------------------------------------------------"

echo "Another supported format: ./executable -<flag> <value>"
./bin/GlogGflagsTest -bool_var false -int32_var 10 -double_var 10.5 -str_var "Hello World" -port 8080 -multi_vd1 "joachim" -multi_vd2 "joshua" -multi_vd3 "ZHI"
echo "-----------------------------------------------------"