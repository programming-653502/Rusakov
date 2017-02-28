#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

int bask[2];

void exit();
void Menu();
void mandarin();
void peach();
void grapes();
void basket();
void price();
void feedback();
void rep();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int kol=0,i,j,k,x=0;
	printf("Вас приветствует интернет-магазин \"eFruit\"\n");
	printf("Пожалуйста сделайте ваш заказ\n");
	Menu();
	getch();
}

void exit()
{
	return;
}

void rep()
{
	char c[20];
	printf("Желаете продолжить?(Да/Нет)\n");
	scanf("%s",&c);
	if (!strcmp(c,"Да"))
	{
		Menu();
		return;
	} else
	if (!strcmp(c,"Нет"))
	{
		exit();
		return;
	} else
	{
		printf("Ошибка ввода!\nПовторите ввод\n");
		rep();
		return;
	}
}

void mandarin()
{
	int i,k=0,weight;
	char s[20];

	printf("Введите количество(кг)\n");
	scanf("%s",&s);
	for (i = 0; i < strlen(s); i++)
	{
		if (!isdigit(s[i]))
		{
			printf("Ошибка ввода!\nПовторите ввод\n");
			mandarin();
			return;
		}
	}
	weight=atoi(s);
	bask[0]=bask[0]+weight;
	rep();
}

void peach()
{
	int i,k=0,weight;
	char s[20];

	printf("Введите количество(кг)\n");
	scanf("%s",&s);
	for (i = 0; i < strlen(s); i++)
	{
		if (!isdigit(s[i]))
		{
			printf("Ошибка ввода!\nПовторите ввод\n");
			peach();
			return;
		}
	}
	weight=atoi(s);
	bask[1]=bask[1]+weight;
	rep();
}

void grapes()
{
	int i,k=0,weight;
	char s[20];

	printf("Введите количество(кг)\n");
	scanf("%s",&s);
	for (i = 0; i < strlen(s); i++)
	{
		if (!isdigit(s[i]))
		{
			printf("Ошибка ввода!\nПовторите ввод\n");
			grapes();
			return;
		}
	}
	weight=atoi(s);
	bask[2]=bask[2]+weight;
	rep();
}

void basket()
{
	int weight=bask[0]+bask[1]+bask[2];

	if (!weight)
	{
		printf("Вы ничего не заказали\n");
		rep();
		return;
	}
	printf("\nВы заказали:\n");
	printf("Мандарины - %d(кг)\n",bask[0]);
	printf("Персики - %d(кг)\n",bask[1]);
	printf("Виноград - %d(кг)\n",bask[2]);
	rep();
}

void price()
{
	int weight=0,deliv=0;
	double sum=0;

	weight=bask[0]+bask[1]+bask[2];
	if (!weight)
	{
		printf("Вы ничего не заказали\n");
		rep();
		return;
	}

	printf("\nМандарины - 1,14$ за кг.\n");
	printf("Персики - 1,00$ за кг.\n");
	printf("Виноград - 1,28$ за кг.\n");
	sum=bask[0]*1.14+bask[1]+bask[2]*1.28;
	if (sum>=100)
	{
		printf("Вам предоставляется скидка в размере 10%\n");
		sum=sum*0.9;
	}
	else printf("Вам не предоставляется скидка\n");
	if (weight<5) deliv=1; else
	if ((weight>=5)&&(weight<=20)) deliv=3;
	else deliv=10+weight*2;
	printf("Затраты на доставку: %d\n",deliv);
	printf("Общая стоймость заказа: %.2f\n",deliv+sum);
	rep();
}

void feedback()
{
	printf("\nМагазин \"eFruit\"\n");
	printf("Номер лицензии 6484392302352\n");
	printf("Контактная информация:\n");
	printf("Телефон +375291168548\n");
	rep();
}

void Menu()
{
	int num;
	char c[20];

	printf("\n1.Заказ мандаринов(кг)\n");
	printf("2.Заказ персиков(кг)\n");
	printf("3.Заказ винограда(кг)\n");
	printf("4.Посмотреть корзину\n");
	printf("5.Расчетать стоимость заказа\n");
	printf("6.Обратная связь\n");
	printf("7.Завершить заказ\n\n");
	printf("Введите число от 1 до 7\n");
	scanf("%s",&c);
	if (!isdigit(c[0])||(strlen(c)>1))
	{
		printf("Ошибка ввода!\nПовторите ввод\n");
		Menu();
		return;
	}
	num=(int)c[0]-48;
	if ((num<1)||(num>7))
	{
		printf("Ошибка ввода!\nПовторите ввод\n");
		Menu();
		return;
	}
	switch (num){
	case 1:
	{
		mandarin();
		break;
	}
	case 2:
	{
		peach();
		break;
	}
	case 3:
	{
		grapes();
		break;
	}
	case 4:
	{
		basket();
		break;
	}
	case 5:
	{
		price();
		break;
	}
	case 6:
	{
		feedback();
		break;
	}
	case 7:
	{
		exit();
		break;
	}}
}

//---------------------------------------------------------------------------

