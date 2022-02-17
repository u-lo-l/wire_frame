

git clone https://github.com/chronikum/printf42_mandatorytester
make
cd printf42_mandatorytester
mv main.c tmp
echo "#include <stdio.h>" >> main.c
cat tmp >> main.c
cp ../*.a .
cp ../ft_printf.h .
gcc -L./ -lftprintf main.c 2> /dev/null
./a.out
cd ..
make fclean
rm -rf printf42_mandatorytester


echo -e "\033[32;1m"ft_printf_tester"\033[m"
git clone https://github.com/paulo-santana/ft_printf_tester
make
cd ft_printf_tester
cp ../*.a .
sh test
cd ..
make fclean
rm -rf ft_printf_tester


echo -e "\033[32;1m"printfTester"\033[m"
git clone https://github.com/Tripouille/printfTester
cd printfTester
make a
cd ..
make fclean
rm -rf printfTester
