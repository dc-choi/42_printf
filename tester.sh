echo -e "\033[32;1m"ft_printf_tester"\033[m"
git clone https://github.com/paulo-santana/ft_printf_tester
make
cd ft_printf_tester
cp ../*.a .
sh test m
# sh test b1
# sh test b2
cd ..
make fclean
​
echo -e "\033[32;1m"printfTester"\033[m"
git clone https://github.com/Tripouille/printfTester
cd printfTester
make m
# make b
# make a
cd ..
make fclean
echo -e "\033[32;1m"FINISHED enter will remove testers and diff results, ctrl + c to check remain"\033[m"
read $a
# new version
rm -rf ft_printf_tester printfTester
