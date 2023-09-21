#include <stdio.h>

int totalMoradores;
int votoObrigatorio;
int votoFacultativo;
int naoEleitor;

int resposta = 0;

int main()
{
	printf("Voc%c deseja cadastrar algum usu%crio? Digite 1 - Sim, 0 - N%co: ", 136, 160, 198);
	scanf("%i", &resposta);

	if (resposta == 0)
	{
		printf("\nNenhum usu%crio foi cadastrado.", 160);

		return 0;
	}

	while (resposta)
	{
		int idade;

		printf("\nDigite sua idade: ");
		scanf("%i", &idade);

		if (idade >= 18 && idade <= 69)
		{
			votoObrigatorio++;
		}
		else if (idade == 16 || idade == 17 || idade >= 70)
		{
			votoFacultativo++;
		}
		else
		{
			naoEleitor++;
		}

		printf("\nVoc%c deseja cadastrar algum usu%crio? Digite 1 - Sim, 0 - N%co: ", 136, 160, 198);
		scanf("%i", &resposta);
	}

	totalMoradores = votoObrigatorio + votoFacultativo + naoEleitor;

	printf("\nNo munic%cpio h%c %i cidad%cos.", 161, 160, totalMoradores, 198);
	printf("\nNo munic%cpio h%c %i cidad%cos no qual o voto %c obrigat%crio.", 161, 160, votoObrigatorio, 198, 130, 162);
	printf("\nNo munic%cpio h%c %i cidad%cos no qual o voto %c facultativo.", 161, 160, votoFacultativo, 198, 130);
	printf("\nNo munic%cpio h%c %i cidad%cos no qual n%co s%co eleitores.", 161, 160, naoEleitor, 198, 198, 198);

	return 0;
}