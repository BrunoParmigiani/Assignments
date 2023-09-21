#include <stdio.h>

int repetir = 1;
int quantidadeLivros;
double criterioA, criterioB, criterioC;

int main()
{
	while (repetir)
	{	
		printf("\nQuantidade de livros: ");
		scanf("%i", &quantidadeLivros);
	
		while (quantidadeLivros < 1)
		{
			printf("\nInsira um valor v%clido.", 160);
			printf("\nQuantidade de livros: ");
			scanf("%i", &quantidadeLivros);
		}
	
		criterioA = 0.25 * quantidadeLivros + 7.5;
		criterioB = 0.5 * quantidadeLivros + 2.5;
		criterioC = 0.65 * quantidadeLivros + 1.5;
	
		if (criterioA == criterioB)
		{
			printf("\nO melhor crit%crio %c o crit%crio C, pois o valor foi R$%0.2f", 130, 130, 130, criterioC);
		}
		else if (criterioA == criterioC)
		{
			printf("\nO melhor crit%crio %c o crit%crio B, pois o valor foi R$%0.2f", 130, 130, 130, criterioB);
		}
		else if (criterioB == criterioC)
		{
			printf("\nO melhor crit%crio %c o crit%crio A, pois o valor foi R$%0.2f", 130, 130, 130, criterioA);
		}
		else
		{
			if (criterioA > criterioB && criterioA > criterioC)
			{
				printf("\nO melhor crit%crio %c o crit%crio A, pois o valor foi R$%0.2f", 130, 130, 130, criterioA);
			}
			else if (criterioB > criterioC && criterioB > criterioA)
			{
				printf("\nO melhor crit%crio %c o crit%crio B, pois o valor foi R$%0.2f", 130, 130, 130, criterioB);
			}
			else if (criterioC > criterioA && criterioC > criterioB)
			{
				printf("\nO melhor crit%crio %c o crit%crio C, pois o valor foi R$%0.2f", 130, 130, 130, criterioC);
			}
		}

		printf("\nRepetir o programa? 1 - Sim, 0 - N%co: ", 198);
		scanf("%i", &repetir);

		if (repetir < 1)
		{
			repetir = 0;
		}
	}

	return 0;
}