#include<iostream>
#include"hash.h"

int main(int argc, char **argv)
{

	hash Hashy;
	Hashy.PrintTable();
	std::cout<<Hashy.Hash("Vibhasnhu")<<std::endl;
	Hashy.AddItem("Vibhanshu", "Coke");
	Hashy.AddItem("Vibhanshu", "Pepsi");
	Hashy.PrintTable();
	Hashy.findDrink("Vibhanshu");
	Hashy.remove("Vibhanshu");
		Hashy.PrintTable();

	return 7;

}
