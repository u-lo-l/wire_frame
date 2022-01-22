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



echo -e "\033[32;1m"ft_printf_tester"\033[m"

git clone https://github.com/paulo-santana/ft_printf_tester

make

cd ft_printf_tester

cp ../*.a .

sh test m

sh test b1

sh test b2

cd ..

make fclean



echo -e "\033[32;1m"printfTester"\033[m"

git clone https://github.com/Tripouille/printfTester

cd printfTester

# make m

# make b

make a

cd ..

make fclean
