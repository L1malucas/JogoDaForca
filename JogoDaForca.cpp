#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>

#define pause getchar()
#define limpa system("clear")

void Menu();
void Jogo();
int Forca(int Vida);
void Regra();
void Sobre();

int main()
{

    std::cout << "\e]0;JOGO DA FORCA\a\n";
    while (true)
    {
        Menu();
        int Opcao = {0};
        std::cin >> Opcao;
        if (Opcao == 1)
        {
            limpa;
            Jogo();
            pause;
            limpa;
        }
        if (Opcao == 2)
        {
            limpa;
            Regra();
            pause;
            sleep(3);
            limpa;
        }
        if (Opcao == 3)
        {
            break;
        }
        if (Opcao == 4)
        {
            limpa;
            Sobre();
            pause;
            pause;
            break;

        }
        
        if (Opcao > 4)
        {
            std::cout << "Opção digitada invalida!";
            limpa;
        }
    }

    return 0;
}

void Menu()
{
    std::cout << "\033[1;32m \t\t\t\tJOGO\033[0m\n";
    std::cout << "\033[1;32m \t\t\t\t DA\033[0m\n";
    std::cout << "\033[1;32m \t\t\t\tFORCA\033[0m\n";

    sleep(1);
    std::cout << "\n";
    std::cout << "\t\t\t 1 - Iniciar\n";
    std::cout << "\t\t\t 2 - Regras\n";
    std::cout << "\t\t\t 3 - Sair\n";
    std::cout << "\t\t\t 4 - Sobre\n";
    std::cout << "\n\t\tDigite sua Opção: ";
}

void Jogo()
{
    char NomeCarrasco[10], NomeVitima[10], Carrasco[30], Mesa[30], Letra;
    int VidaVitima = {0}, AuxVida;
    std::string Digitado;

    for (int i = 0; i < 30; i++)
    {
        Carrasco[i] = 0;

        Mesa[i] = 0;
    }
    fflush(stdin);
    std::cin.ignore();
    std::cout << "Nome da Vitima: ";
    std::cin.getline(NomeVitima, 10);
    limpa;
    std::cout << "\nNome do Carrasco: ";
    std::cin.getline(NomeCarrasco, sizeof(NomeCarrasco));

    limpa;

    std::cout << "\n CARRASCO " << NomeCarrasco << ", escreva a palavra: ";
    std::cin.getline(Carrasco, sizeof(Carrasco));

    for (int i = 0; Carrasco[i] != '\0'; i++)
    {
        if (Carrasco[i] == ' ')
        {
            Mesa[i] = ' ';
        }
        else
        {
            Mesa[i] = '_';
        }
    }
    limpa;

    while (true)
    {
        AuxVida = {0};
        Forca(VidaVitima);
        std::cout << "\n\n\nLETRAS DIGITADAS: " << Digitado << " ";
        std::cout << "\nErros = " << VidaVitima;
        if (VidaVitima == 5)
        {
            std::cout << "\n\n\nVoce perdeu!\n A palavra era: " << Carrasco << "\n";
            break;
        }
        std::cout << "\t\t\t\t" << Mesa << "\n\n";
        std::cout << "Letra: ";
        std::cin >> Letra;
        
        Digitado = (Digitado + Letra);
        for (int i = 0; Carrasco[i] != '\0'; i++)
        {
            if (Letra == Carrasco[i])
            {
                Mesa[i] = Letra;
                AuxVida++;
            }
        }
        if (AuxVida == 0)
        {
            VidaVitima++;
        }

        limpa;
        //NAO EXIBE VITORIA
        if (!strcasecmp(Mesa, Carrasco))
        {
            std::cout << "P A R A B E N S " << NomeVitima << " V O C E  G A N H O U ! ! ! !\n\n\n";
            std::cout << " Palavra " << Carrasco;
            
        }
    }
}

int Forca(int Vida)
{
    if (Vida == 0)
    {

        std::cout << "\n\t ------------    \n\t";
        std::cout << "\n\t |        __|__  \n\t";
        std::cout << "\n\t |               \n\t";
        std::cout << "\n\t |               \n\t";
        std::cout << "\n\t |               \n\t";
        std::cout << "\n\t |               \n\t";
        std::cout << "\n\t |               \n\t";
        std::cout << "\n\t_|___            \n\t";
        std::cout << "\n";
    }
    else
    {
        if (Vida == 1)
        {

            std::cout << "\n\t  ------------     \n\t";
            std::cout << "\n\t  |        __|__   \n\t";
            std::cout << "\n\t  |          0     \n\t";
            std::cout << "\n\t  |                \n\t";
            std::cout << "\n\t  |                \n\t";
            std::cout << "\n\t  |                \n\t";
            std::cout << "\n\t  |                \n\t";
            std::cout << "\n\t__|___             \n\t";
            std::cout << "\n";
        }
        else
        {
            if (Vida == 2)
            {

                std::cout << "\n\t   ------------     \n\t";
                std::cout << "\n\t   |        __|__   \n\t";
                std::cout << "\n\t   |          0     \n\t";
                std::cout << "\n\t   |         /|     \n\t";
                std::cout << "\n\t   |                \n\t";
                std::cout << "\n\t   |                \n\t";
                std::cout << "\n\t   |                \n\t";
                std::cout << "\n\t___|___             \n\t";
                std::cout << "\n\t";
            }
            else
            {
                if (Vida == 3)
                {
  
                    std::cout << "\n\t   ------------     \n\t";
                    std::cout << "\n\t   |        __|__   \n\t";
                    std::cout << "\n\t   |          0     \n\t";
                    std::cout << "\n\t   |         /|\\   \n\t";
                    std::cout << "\n\t   |                \n\t";
                    std::cout << "\n\t   |                \n\t";
                    std::cout << "\n\t   |                \n\t";
                    std::cout << "\n\t___|___             \n\t";
                    std::cout << "\n\t";
                }
                else
                {
                    if (Vida == 4)
                    {

                        std::cout << "\n\t   ------------     \n\t";
                        std::cout << "\n\t   |        __|__   \n\t";
                        std::cout << "\n\t   |          0     \n\t";
                        std::cout << "\n\t   |         /|\\   \n\t";
                        std::cout << "\n\t   |          |     \n\t";
                        std::cout << "\n\t   |         /      \n\t";
                        std::cout << "\n\t   |                \n\t";
                        std::cout << "\n\t___|___             \n\t";
                        std::cout << "\n\t";
                    }
                    else
                    {
                        if (Vida == 5)
                        {

                            std::cout << "\n\t   ------------     \n\t";
                            std::cout << "\n\t   |        __|__   \n\t";
                            std::cout << "\n\t   |          0     \n\t";
                            std::cout << "\n\t   |         /|\\   \n\t";
                            std::cout << "\n\t   |          |     \n\t";
                            std::cout << "\n\t   |         / \\   \n\t";
                            std::cout << "\n\t   |                \n\t";
                            std::cout << "\n\t___|___             \n\t";
                            std::cout << "\n\t";

                            
                            std::cout << "\n\n\n\n\nQUE PENA VC PERDEU O JOGO !!!"
                                      << "\n";
                        }
                    }
                }
            }
        }
    }
}

void Regra()
{
    std::cout << "\n\n\t\t\t\t\t INSTRUCOES DO JOGO DA FORCA\n\n";
    std::cout << "REGRA NUMERO 1 -> A PALAVRA DEVE CONTER SoMENTE LETRAS"
              << "\n";
    std::cout << "REGRA NUMERO 2 -> NUMERO DE VIDAS = 5"
              << "\n";
    std::cout << "REGRA NUMERO 3 -> LETRAS ERRADAS REPETIDAS SERÃO CONSIDERADAS COMO ERROS"
              << "\n";
}

void Sobre ()
{
    std::cout << "PROJETO BASEADO NO TUTORIAL, FEITO POR EDUARDO FERRAREZI EM DEZEMBRO, 2006\n";
    std::cout << "EDUARDO REPOSITÓRIO: /EduardoFRRZ/Jogos.git \n\n\n";
    std::cout << "ATUALIZADO POR LUCAS LIMA EM NOVEMBRO, 2020\n";
    std::cout << "LUCAS LIMA GITHUB: @LUCASLIMADEV\n";
}