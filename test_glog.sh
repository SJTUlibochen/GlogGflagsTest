echo "Test stderrthreshold"
./bin/GlogGflagsTest --nobool_var --int32_var=10 --double_var=10.5 --str_var="Hello World" --port=8080 --multi_vd1="joachim" --multi_vd2="joshua" --multi_vd3="ZHI" --log_dir="./logs/" --stderrthreshold=1
echo "-----------------------------------------------------"
