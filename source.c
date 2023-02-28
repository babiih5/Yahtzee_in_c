#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lab.h"

//Inicialização
void inicio(void) {
    setForeColor(MY_COLOR_LIGTH_GREEN);
    printf("\n");

    printf(" ||         ||       ||             ||         ||  ||||||||||||||||||  ||||||||||||  ||||||||||||  ||||||||||||    \n");
    printf("  ||       ||       ||||            ||         ||          ||                   ||   ||            ||              \n");
    printf("   ||     ||       ||  ||           ||         ||          ||                  ||    ||            ||              \n");
    printf("    ||   ||       ||    ||          ||         ||          ||                 ||     ||            ||              \n");
    printf("     || ||       ||      ||         ||         ||          ||                ||      ||            ||              \n");
    printf("      |||       ||        ||        |||||||||||||          ||               ||       ||||||||||    ||||||||||      \n");
    printf("      |||      ||||||||||||||       ||         ||          ||              ||        ||            ||              \n");
    printf("      |||     ||            ||      ||         ||          ||             ||         ||            ||              \n");
    printf("      |||    ||              ||     ||         ||          ||            ||          ||            ||              \n");
    printf("      |||   ||                ||    ||         ||          ||           ||           ||            ||              \n");
    printf("      |||  ||                  ||   ||         ||          ||          ||||||||||||  ||||||||||||  ||||||||||||    \n");

    
    


    setForeColor(MY_COLOR_WHITE);
    printf("\n\nPressiona qualquer tecla para prosseguir...");
    system("pause > nul");
    system("cls");

}

//dado
typedef struct {
    int valor;
}DADO;

//estrutura combo
typedef struct {
    int valor;
    int estado;
}COMBO;

//tabela
typedef struct {
    COMBO uns;
    COMBO dois;
    COMBO tres;
    COMBO quatros;
    COMBO cincos;
    COMBO seis;
    COMBO threeofakind;
    COMBO fourofakind;
    COMBO fullhouse;
    COMBO smallstraight;
    COMBO largestraight;
    COMBO chance;
    COMBO yahtzee;
}TABELA;


//iniciar dado

void initdado(DADO* dados) {
    dados->valor = dado(6);
}


//iniciar tabela

void inittab(TABELA* tab) {
    tab->uns.valor = 0;
    tab->uns.estado = 0;
    tab->dois.valor = 0;
    tab->dois.estado = 0;
    tab->tres.valor = 0;
    tab->tres.estado = 0;
    tab->quatros.valor = 0;
    tab->quatros.estado = 0;
    tab->cincos.valor = 0;
    tab->cincos.estado = 0;
    tab->seis.valor = 0;
    tab->seis.estado = 0;
    tab->threeofakind.valor = 0;
    tab->threeofakind.estado = 0;
    tab->fourofakind.valor = 0;
    tab->fourofakind.estado = 0;
    tab->fullhouse.valor = 0;
    tab->fullhouse.estado = 0;
    tab->smallstraight.valor = 0;
    tab->smallstraight.estado = 0;
    tab->largestraight.valor = 0;
    tab->largestraight.estado = 0;
    tab->chance.valor = 0;
    tab->chance.estado = 0;
    tab->yahtzee.valor = 0;
    tab->yahtzee.estado = 0;
}




//primeiro lançamento 

void firstdados(int x, int y, DADO v[]) {
    int i = 0;

    for (i = 0; i < 5; i++) {
        setForeColor(MY_COLOR_CYAN + i);
        showRectCenteredAt(x + i * 5, y, 4, 2);
        showCharAt(x + i * 5, y, v[i].valor + '0');
    }
}


//Lançar Todos os Dados

void lancardados(int x, int y, DADO v[]) {
    int i = 0;

    for (i = 0; i < 5; i++) {
        v[i].valor = dado(6);
        setForeColor(MY_COLOR_CYAN + i);
        showRectCenteredAt(x + i * 5, y, 4, 2);
        showCharAt(x + i * 5, y, v[i].valor + '0');
    }
}

//mostrar dados
void mostrardad(DADO* v) {
    int i = 0;

    for (i = 0; i < 5; i++) {
        setForeColor(MY_COLOR_CYAN + i);
        showRectCenteredAt(5 + i * 5, 5, 4, 2);
        showCharAt(5 + i * 5, 5, v[i].valor + '0');
    }
}


//Uns
int uns(DADO v[], TABELA* tab) {
    resetColor();

    int i = 0, um = 0;

    for (i = 0; i < 5; i++) {
        if (v[i].valor == 1) {
            um = um + 1;
        }
    }
    if (tab[0].uns.estado == 0) {
        tab[0].uns.valor = um;
    }
    

    return um;
}


//Dois
int dois(DADO v[], TABELA* tab) {
    resetColor();

    int i = 0, twos = 0;

    for (i = 0; i < 5; i++) {
        if (v[i].valor == 2) {
            twos = twos + 2;
        }
    }
    if (tab[0].dois.estado == 0) {
        tab[0].dois.valor = twos;
    }

    return twos;
}


//Três
int tres(DADO v[], TABELA* tab) {
    resetColor();

    int i = 0, three = 0;

    for (i = 0; i < 5; i++) {
        if (v[i].valor == 3) {
            three = three + 3;
        }
    }

    if (tab[0].tres.estado == 0) {
        tab[0].tres.valor = three;
    }

    return three;
}


//Quatro
int quatros(DADO v[], TABELA* tab) {
    resetColor();

    int i = 0, quatro = 0;

    for (i = 0; i < 5; i++) {
        if (v[i].valor == 4) {
            quatro = quatro + 4;
        }
    }

    if (tab[0].quatros.estado == 0) {
        tab[0].quatros.valor = quatro;
    }

    return quatro;
}


//Cincos
int cincos(DADO v[], TABELA* tab) {
    resetColor();

    int i = 0, cinco = 0;

    for (i = 0; i < 5; i++) {
        if (v[i].valor == 5) {
            cinco = cinco + 5;
        }
    }

    if (tab[0].cincos.estado == 0) {
        tab[0].cincos.valor = cinco;
    }

    return cinco;
}


//Seis
int seis(DADO v[], TABELA* tab) {
    resetColor();

    int i = 0, six = 0;

    for (i = 0; i < 5; i++) {
        if (v[i].valor == 6) {
            six = six + 6;
        }
    }

    if (tab[0].seis.estado == 0) {
        tab[0].seis.valor = six;
    }

    return six;
}

// total numeros
int pontnum(TABELA* tab) {
    int soma = 0, total = 0;

    soma = tab[0].uns.valor + tab[0].dois.valor + tab[0].tres.valor + tab[0].quatros.valor + tab[0].cincos.valor + tab[0].seis.valor;

    if (soma >= 63) {
        printf("\n\n Bonus: 35");
        total = soma + 35;
        return total;
    }
    else {
        return soma;
    }
    

    
}



//3 of a kind
int ofakind3(DADO v[], TABELA* tab) {
    resetColor();
    int kind3 = 0;

    if (v[0].valor == v[1].valor && v[0].valor == v[2].valor) {
        kind3 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;

    }
    else if (v[0].valor == v[1].valor && v[0].valor == v[3].valor) {
        kind3 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }
    else if (v[0].valor == v[1].valor && v[0].valor == v[4].valor) {
        kind3 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }
    else if (v[0].valor == v[2].valor && v[0].valor == v[3].valor) {
        kind3 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }
    else if (v[0].valor == v[2].valor && v[0].valor == v[4].valor) {
        kind3 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }
    else if (v[0].valor == v[3].valor && v[0].valor == v[4].valor) {
        kind3 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }
    else if (v[1].valor == v[2].valor && v[1].valor == v[3].valor) {
        kind3 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }
    else if (v[1].valor == v[3].valor && v[1].valor == v[4].valor) {
        kind3 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }
    else if (v[1].valor == v[2].valor && v[1].valor == v[4].valor) {
        kind3 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }
    else if (v[2].valor == v[3].valor && v[2].valor == v[4].valor) {
        kind3 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }

    if (tab[0].threeofakind.estado == 0) {
        tab[0].threeofakind.valor = kind3;
    }

    return kind3;
}

//4 of a kind
int ofakind4(DADO v[], TABELA* tab) {
    resetColor();
    int kind4 = 0;

    if ((v[0].valor == v[1].valor) && (v[0].valor == v[2].valor) && (v[0].valor == v[3].valor)) {
        kind4 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }
    else if ((v[0].valor == v[1].valor) && (v[0].valor == v[2].valor) && (v[0].valor == v[4].valor)) {
        kind4 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }
    else if ((v[0].valor == v[1].valor) && (v[0].valor == v[3].valor) && (v[0].valor == v[4].valor)) {
        kind4 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }
    else if ((v[0].valor == v[2].valor) && (v[0].valor == v[3].valor) && (v[0].valor == v[4].valor)) {
        kind4 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }
    else if ((v[0].valor == v[2].valor) && (v[0].valor == v[3].valor) && (v[0].valor == v[4].valor)) {
        kind4 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }
    else if ((v[1].valor == v[2].valor) && (v[1].valor == v[3].valor) && (v[1].valor == v[4].valor)) {
        kind4 = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;
    }

    if (tab[0].fourofakind.estado == 0) {
        tab[0].fourofakind.valor = kind4;
    }

    return kind4;
}

//Full House
bool fullhouse(DADO v[], TABELA* tab) {
    int count[6] = { 0 };
    int i = 0;

    for (i = 0; i < 5; i++) {
        switch (v[i].valor) {
        case 1:
            count[0]++;
            break;
        case 2:
            count[1]++;
            break;
        case 3:
            count[2]++;
            break;
        case 4:
            count[3]++;
            break;
        case 5:
            count[4]++;
            break;
        case 6:
            count[5]++;
            break;
        default:
            break;
        }
    }


    bool three_of_a_kind = false;
    bool two_of_a_kind = false;
    for (int i = 0; i < 6; i++) {
        if (count[i] == 3) {
            three_of_a_kind = true;
        }
        else if (count[i] == 2) {
            two_of_a_kind = true;
        }
    }

    if ((three_of_a_kind == true) && (two_of_a_kind == true)) {
       
            tab[0].fullhouse.valor=25;
        
       
    }

    return three_of_a_kind && two_of_a_kind;
}

//Small Straight
int smalls(DADO* v, TABELA* tab) {
    int smallstraight = 0;

    if ((v[0].valor >= 1 && v[0].valor <= 4) && (v[1].valor >= 1 && v[1].valor <= 4) && (v[2].valor >= 1 && v[2].valor <= 4) && (v[3].valor >= 1 && v[3].valor <= 4) && (v[0].valor != v[1].valor) && (v[0].valor != v[2].valor) && (v[0].valor != v[3].valor) && (v[1].valor != v[2].valor) && (v[1].valor != v[3].valor) && (v[2].valor != v[3].valor)) {
        smallstraight = 30;
    }
    else if ((v[0].valor >= 1 && v[0].valor <= 4) && (v[1].valor >= 1 && v[1].valor <= 4) && (v[2].valor >= 1 && v[2].valor <= 4) && (v[4].valor >= 1 && v[4].valor <= 4) && (v[0].valor != v[1].valor) && (v[0].valor != v[2].valor) && (v[0].valor != v[4].valor) && (v[1].valor != v[2].valor) && (v[1].valor != v[4].valor) && (v[2].valor != v[4].valor)) {
        smallstraight = 30;
    }
    else if ((v[0].valor >= 1 && v[0].valor <= 4) && (v[1].valor >= 1 && v[1].valor <= 4) && (v[3].valor >= 1 && v[3].valor <= 4) && (v[4].valor >= 1 && v[4].valor <= 4) && (v[0].valor != v[1].valor) && (v[0].valor != v[3].valor) && (v[0].valor != v[4].valor) && (v[1].valor != v[3].valor) && (v[1].valor != v[4].valor) && (v[3].valor != v[4].valor)) {
        smallstraight = 30;
    }
    else if ((v[0].valor >= 1 && v[0].valor <= 4) && (v[2].valor >= 1 && v[2].valor <= 4) && (v[3].valor >= 1 && v[3].valor <= 4) && (v[4].valor >= 1 && v[4].valor <= 4) && (v[0].valor != v[2].valor) && (v[0].valor != v[3].valor) && (v[0].valor != v[4].valor) && (v[2].valor != v[3].valor) && (v[2].valor != v[4].valor) && (v[3].valor != v[4].valor)) {
        smallstraight = 30;
    }
    else if ((v[1].valor >= 1 && v[1].valor <= 4) && (v[2].valor >= 1 && v[2].valor == 4) && (v[3].valor >= 1 && v[3].valor <= 4) && (v[4].valor >= 1 && v[4].valor <= 4) && (v[1].valor != v[2].valor) && (v[1].valor != v[3].valor) && (v[1].valor != v[4].valor) && (v[2].valor != v[3].valor) && (v[2].valor != v[4].valor) && (v[3].valor != v[4].valor)) {
        smallstraight = 30;
    }
    else if ((v[0].valor >= 2 && v[0].valor <= 5) && (v[1].valor >= 2 && v[1].valor <= 5) && (v[2].valor >= 2 && v[2].valor <= 5) && (v[3].valor >= 2 && v[3].valor <= 5) && (v[0].valor != v[1].valor) && (v[0].valor != v[2].valor) && (v[0].valor != v[3].valor) && (v[1].valor != v[2].valor) && (v[1].valor != v[3].valor) && (v[2].valor != v[3].valor)) {
        smallstraight = 30;
    }
    else if ((v[0].valor >= 2 && v[0].valor <= 5) && (v[1].valor >= 2 && v[1].valor <= 5) && (v[2].valor >= 2 && v[2].valor <= 5) && (v[4].valor >= 2 && v[4].valor <= 5) && (v[0].valor != v[1].valor) && (v[0].valor != v[2].valor) && (v[0].valor != v[4].valor) && (v[1].valor != v[2].valor) && (v[1].valor != v[4].valor) && (v[2].valor != v[4].valor)) {
        smallstraight = 30;
    }
    else if ((v[0].valor >= 2 && v[0].valor <= 5) && (v[1].valor >= 2 && v[1].valor <= 5) && (v[3].valor >= 2 && v[3].valor <= 5) && (v[4].valor >= 2 && v[4].valor <= 5) && (v[0].valor != v[1].valor) && (v[0].valor != v[3].valor) && (v[0].valor != v[4].valor) && (v[1].valor != v[3].valor) && (v[1].valor != v[4].valor) && (v[3].valor != v[4].valor)) {
        smallstraight = 30;
    }
    else if ((v[0].valor >= 2 && v[0].valor <= 5) && (v[2].valor >= 2 && v[2].valor <= 5) && (v[3].valor >= 2 && v[3].valor <= 5) && (v[4].valor >= 2 && v[4].valor <= 5) && (v[0].valor != v[2].valor) && (v[0].valor != v[3].valor) && (v[0].valor != v[4].valor) && (v[2].valor != v[3].valor) && (v[2].valor != v[4].valor) && (v[3].valor != v[4].valor)) {
        smallstraight = 30;
    }
    else if ((v[1].valor >= 2 && v[1].valor <= 5) && (v[2].valor >= 2 && v[2].valor <= 5) && (v[3].valor >= 2 && v[3].valor <= 5) && (v[4].valor >= 2 && v[4].valor <= 5) && (v[1].valor != v[2].valor) && (v[1].valor != v[3].valor) && (v[1].valor != v[4].valor) && (v[2].valor != v[3].valor) && (v[2].valor != v[4].valor) && (v[3].valor != v[4].valor)) {
        smallstraight = 30;
    }
    else if ((v[0].valor >= 3 && v[0].valor <= 6) && (v[1].valor >= 3 && v[1].valor <= 6) && (v[2].valor >= 3 && v[2].valor <= 6) && (v[3].valor >= 3 && v[3].valor <= 6) && (v[0].valor != v[1].valor) && (v[0].valor != v[2].valor) && (v[0].valor != v[3].valor) && (v[1].valor != v[2].valor) && (v[1].valor != v[3].valor) && (v[2].valor != v[3].valor)) {
        smallstraight = 30;
    }
    else if ((v[0].valor >= 3 && v[0].valor <= 6) && (v[1].valor >= 3 && v[1].valor <= 6) && (v[2].valor >= 3 && v[2].valor <= 6) && (v[4].valor >= 3 && v[4].valor <= 6) && (v[0].valor != v[1].valor) && (v[0].valor != v[2].valor) && (v[0].valor != v[4].valor) && (v[1].valor != v[2].valor) && (v[1].valor != v[4].valor) && (v[2].valor != v[4].valor)) {
        smallstraight = 30;
    }
    else if ((v[0].valor >= 3 && v[0].valor <= 6) && (v[1].valor >= 3 && v[1].valor <= 6) && (v[3].valor >= 3 && v[3].valor <= 6) && (v[4].valor >= 3 && v[4].valor <= 6) && (v[0].valor != v[1].valor) && (v[0].valor != v[3].valor) && (v[0].valor != v[4].valor) && (v[1].valor != v[3].valor) && (v[1].valor != v[4].valor) && (v[3].valor != v[4].valor)) {
        smallstraight = 30;
    }
    else if ((v[0].valor >= 3 && v[0].valor <= 6) && (v[2].valor >= 3 && v[2].valor <= 6) && (v[3].valor >= 3 && v[3].valor <= 6) && (v[4].valor >= 3 && v[4].valor <= 6) && (v[0].valor != v[2].valor) && (v[0].valor != v[3].valor) && (v[0].valor != v[4].valor) && (v[2].valor != v[3].valor) && (v[2].valor != v[4].valor) && (v[3].valor != v[4].valor)) {
        smallstraight = 30;
    }
    else if ((v[1].valor >= 3 && v[1].valor <= 6) && (v[2].valor >= 3 && v[2].valor <= 6) && (v[3].valor >= 3 && v[3].valor <= 6) && (v[4].valor >= 3 && v[4].valor <= 6) && (v[1].valor != v[2].valor) && (v[1].valor != v[3].valor) && (v[1].valor != v[4].valor) && (v[2].valor != v[3].valor) && (v[2].valor != v[4].valor) && (v[3].valor != v[4].valor)) {
        smallstraight = 30;
    }

    if (tab[0].smallstraight.estado == 0) {
        tab[0].smallstraight.valor = smallstraight;
    }

    return smallstraight;
}

//Large Straight
int larges(DADO* v, TABELA* tab) {
    int largestraight = 0;
    if ((v[0].valor >= 1 && v[0].valor <= 5) && (v[1].valor >= 1 && v[1].valor <= 5) && (v[2].valor >= 1 && v[2].valor <= 5) && (v[3].valor >= 1 && v[3].valor <= 5) && (v[4].valor >= 1 && v[4].valor <= 5) && (v[0].valor != v[1].valor) && (v[0].valor != v[2].valor) && (v[0].valor != v[3].valor) && (v[0].valor != v[4].valor) && (v[1].valor != v[2].valor) && (v[1].valor != v[3].valor) && (v[1].valor != v[4].valor) && (v[2].valor != v[3].valor) && (v[2].valor != v[4].valor) && (v[3].valor != v[4].valor)) {
        largestraight = 40;
    }
    else if ((v[0].valor >= 2 && v[0].valor <= 6) && (v[1].valor >= 2 && v[1].valor <= 6) && (v[2].valor >= 2 && v[2].valor <= 6) && (v[3].valor >= 2 && v[3].valor <= 6) && (v[4].valor >= 2 && v[4].valor <= 6) && (v[0].valor != v[1].valor) && (v[0].valor != v[2].valor) && (v[0].valor != v[3].valor) && (v[0].valor != v[4].valor) && (v[1].valor != v[2].valor) && (v[1].valor != v[3].valor) && (v[1].valor != v[4].valor) && (v[2].valor != v[3].valor) && (v[2].valor != v[4].valor) && (v[3].valor != v[4].valor)) {
        largestraight = 40;
    }

    if (tab[0].largestraight.estado == 0) {
        tab[0].largestraight.valor = largestraight;
    }


    return largestraight;
}

//Chance
int chance(DADO v[], TABELA* tab) {
    resetColor();
    int chan = 0;

    chan = v[0].valor + v[1].valor + v[2].valor + v[3].valor + v[4].valor;

    if (tab[0].chance.estado == 0) {
        tab[0].chance.valor = chan;
    }


    return chan;

}

//Yahtzee
int yahtzee(DADO v[], TABELA* tab) {
    resetColor();
    int yat = 0;

    if ((v[0].valor == v[1].valor) && (v[0].valor == v[2].valor) && (v[0].valor == v[3].valor) && (v[0].valor == v[4].valor)) {
        yat = 50;
    }

    if (tab[0].yahtzee.estado == 0) {
        tab[0].yahtzee.valor = yat;
    }


    return yat;

}



//Guardar combo ou jogar

int comboujog(void) {
    int escolha = 0;
    do {
        printf("\n\nDeseja guardar um combo (1) ou lancar novamente os dados (2)?\nResposta: ");
        (void)scanf(" %d", &escolha);
    } while (escolha != 1 && escolha != 2);


    return escolha;
}

//lancar novamente

void relancar(DADO* v) {
    int qntsrel = 0, cont = 0, esco = 0;
    printf("\nDeseja relancar quantos dados?\nResposta: ");
    (void)scanf(" %d", &qntsrel);
    if (qntsrel > 5) {
        printf("\n\nErro!Numero de dados invalido!");
        relancar(v);
    }
    else if (qntsrel < 5) {
        do {
            printf("Qual dado quer relancar?\nResposta: ");
            (void)scanf(" %d", &esco);
            cont++;

            switch (esco) {
            case 1:
                v[0].valor = dado(6);
                break;
            case 2:
                v[1].valor = dado(6);
                break;
            case 3:
                v[2].valor = dado(6);
                break;
            case 4:
                v[3].valor = dado(6);
                break;
            case 5:
                v[4].valor = dado(6);
                break;
            default:
                printf("\nErro! Dado invalido!");
                break;
            }
        } while (cont != qntsrel);
    }
    
    else if (qntsrel = 5) {
        lancardados(5, 5, v);
    }
   

}



//print tabela

void tabelanum(DADO* v, TABELA* tab) {

    uns(v, tab);
    dois(v, tab);
    tres(v, tab);
    quatros(v, tab);
    cincos(v, tab);
    seis(v, tab);
    ofakind3(v, tab);
    ofakind4(v, tab);
    fullhouse(v, tab);
    smalls(v, tab);
    larges(v, tab);
    chance(v, tab);
    yahtzee(v, tab);


    setForeColor(MY_COLOR_LIGTH_YELLOW);
    gotoxy(57, 1);
    printf("Tabela de pontos");

    if (tab[0].uns.estado == 0) {
        setForeColor(MY_COLOR_CYAN + 2);
        gotoxy(50, 3);
        printf("Ones (1): %d", tab[0].uns.valor);
    }
    else if (tab[0].uns.estado == 1) {
        setForeColor(MY_COLOR_DARK_RED);
        gotoxy(50, 3);
        printf("Ones (1): %d", tab[0].uns.valor);
    }

    if (tab[0].dois.estado == 0) {
        setForeColor(MY_COLOR_CYAN + 2);
        gotoxy(50, 5);
        printf("Twos (2): %d", tab[0].dois.valor);
    }
    else if (tab[0].dois.estado == 1) {
        setForeColor(MY_COLOR_DARK_RED);
        gotoxy(50, 5);
        printf("Twos (2): %d", tab[0].dois.valor);
    }

    if (tab[0].tres.estado == 0) {
        setForeColor(MY_COLOR_CYAN + 2);
        gotoxy(50, 7);
        printf("Threes (3): %d", tab[0].tres.valor);
    }
    else if (tab[0].tres.estado == 1) {
        setForeColor(MY_COLOR_DARK_RED);
        gotoxy(50, 7);
        printf("Threes (3): %d", tab[0].tres.valor);
    }

    if (tab[0].quatros.estado == 0) {
        setForeColor(MY_COLOR_CYAN + 2);
        gotoxy(50, 9);
        printf("Fours (4): %d", tab[0].quatros.valor);
    }
    else if (tab[0].quatros.estado == 1) {
        setForeColor(MY_COLOR_DARK_RED);
        gotoxy(50, 9);
        printf("Fours (4): %d", tab[0].quatros.valor);
    }

    if (tab[0].cincos.estado == 0) {
        setForeColor(MY_COLOR_CYAN + 2);
        gotoxy(50, 11);
        printf("Fives (5): %d", tab[0].cincos.valor);
    }
    else if (tab[0].cincos.estado == 1) {
        setForeColor(MY_COLOR_DARK_RED);
        gotoxy(50, 11);
        printf("Fives (5): %d", tab[0].cincos.valor);
    }

    if (tab[0].seis.estado == 0) {
        setForeColor(MY_COLOR_CYAN + 2);
        gotoxy(50, 13);
        printf("Sixes (6): %d", tab[0].seis.valor);
    }
    else if (tab[0].seis.estado == 1) {
        setForeColor(MY_COLOR_DARK_RED);
        gotoxy(50, 13);
        printf("Sixes (6): %d", tab[0].seis.valor);
    }

    if (tab[0].threeofakind.estado == 0) {
        setForeColor(MY_COLOR_CYAN + 2);
        gotoxy(70, 3);
        printf("3 of a kind (7): %d", tab[0].threeofakind.valor);
    }
    else if (tab[0].threeofakind.estado == 1) {
        setForeColor(MY_COLOR_DARK_RED);
        gotoxy(70, 3);
        printf("3 of a kind (7): %d", tab[0].threeofakind.valor);
    }


    if (tab[0].fourofakind.estado == 0) {
        setForeColor(MY_COLOR_CYAN + 2);
        gotoxy(70, 5);
        printf("4 of a kind (8): %d", tab[0].fourofakind.valor);
    }
    else if (tab[0].fourofakind.estado == 1) {
        setForeColor(MY_COLOR_DARK_RED);
        gotoxy(70, 5);
        printf("4 of a kind (8): %d", tab[0].fourofakind.valor);
    }

    if (tab[0].fullhouse.estado == 0) {
        setForeColor(MY_COLOR_CYAN + 2);
        gotoxy(70, 7);
        printf("Full House (9): %d", tab[0].fullhouse.valor);
    }
    else if (tab[0].fullhouse.estado == 1) {
        setForeColor(MY_COLOR_DARK_RED);
        gotoxy(70, 7);
        printf("Full House (9): %d", tab[0].fullhouse.valor);
    }

    if (tab[0].smallstraight.estado == 0) {
        setForeColor(MY_COLOR_CYAN + 2);
        gotoxy(70, 9);
        printf("SM Straight (10): %d", tab[0].smallstraight.valor);
    }
    else if (tab[0].smallstraight.estado == 1) {
        setForeColor(MY_COLOR_DARK_RED);
        gotoxy(70, 9);
        printf("SM Straight (10): %d", tab[0].smallstraight.valor);
    }

    if (tab[0].largestraight.estado == 0) {
        setForeColor(MY_COLOR_CYAN + 2);
        gotoxy(70, 11);
        printf("LG Straight (11): %d", tab[0].largestraight.valor);
    }
    else if (tab[0].largestraight.estado == 1) {
        setForeColor(MY_COLOR_DARK_RED);
        gotoxy(70, 11);
        printf("LG Straight (11): %d", tab[0].largestraight.valor);
    }

    if (tab[0].chance.estado == 0) {
        setForeColor(MY_COLOR_CYAN + 2);
        gotoxy(70, 13);
        printf("Chance (12): %d", tab[0].chance.valor);
    }
    else if (tab[0].chance.estado == 1) {
        setForeColor(MY_COLOR_DARK_RED);
        gotoxy(70, 13);
        printf("Chance (12): %d", tab[0].chance.valor);
    }

    if (tab[0].yahtzee.estado == 0) {
        setForeColor(MY_COLOR_CYAN + 2);
        gotoxy(70, 15);
        printf("Yathzee (13): %d", tab[0].yahtzee.valor);
    }
    else if (tab[0].yahtzee.estado == 1) {
        setForeColor(MY_COLOR_DARK_RED);
        gotoxy(70, 15);
        printf("Yathzee (13): %d", tab[0].yahtzee.valor);
    }

}



//Escolha combo

void combo(DADO* v, TABELA* tab) {
    
    int escolha = 0;
    int pontos = 0;

    mostrardad(v);

    tabelanum(v, tab);

    resetColor();
    gotoxy(0, 20);
    printf("Qual o combo que quer guardar?: ");


    (void)scanf(" %d", &escolha);


    switch (escolha) {
    case 1:
        if (tab[0].uns.estado == 0) {
            tab[0].uns.estado = 1;
        }
        else if (tab[0].uns.estado == 1) {
            printf("\nJa escolheu este combo! \nPressione qualquer tecla para tentar novamente...");
            system("pause>nul");
            system("cls");
            combo(v, tab);
        }
        break;

    case 2:
        if (tab[0].dois.estado == 0) {
            tab[0].dois.estado = 1;
        }
        else if (tab[0].dois.estado == 1) {
            printf("\nJa escolheu este combo! \nPressione qualquer tecla para tentar novamente...");
            system("pause>nul");
            system("cls");
            combo(v, tab);
        }
        
        break;

    case 3:
        if (tab[0].tres.estado == 0) {
            tab[0].tres.estado = 1;
        }
        else if (tab[0].tres.estado == 1) {
            printf("\nJa escolheu este combo! \nPressione qualquer tecla para tentar novamente...");
            system("pause>nul");
            system("cls");
            combo(v, tab);
        }
        
        
        break;

    case 4:
        if (tab[0].quatros.estado == 0) {
            tab[0].quatros.estado = 1;
        }
        else if (tab[0].quatros.estado == 1) {
            printf("\nJa escolheu este combo! \nPressione qualquer tecla para tentar novamente...");
            system("pause>nul");
            system("cls");
            combo(v, tab);
        }
        
        
        break;

    case 5:
        if (tab[0].cincos.estado == 0) {
            tab[0].cincos.estado = 1;
        }
        else if (tab[0].cincos.estado == 1) {
            printf("\nJa escolheu este combo! \nPressione qualquer tecla para tentar novamente...");
            system("pause>nul");
            system("cls");
            combo(v, tab);
        }
        
        
        break;

    case 6:
        if (tab[0].seis.estado == 0) {
            tab[0].seis.estado = 1;
        }
        else if (tab[0].seis.estado == 1) {
            printf("\nJa escolheu este combo! \nPressione qualquer tecla para tentar novamente...");
            system("pause>nul");
            system("cls");
            combo(v, tab);
        }
        
       
        break;

    case 7:
        if (tab[0].threeofakind.estado == 0) {
            tab[0].threeofakind.estado = 1;
        }
        else if (tab[0].threeofakind.estado == 1) {
            printf("\nJa escolheu este combo! \nPressione qualquer tecla para tentar novamente...");
            system("pause>nul");
            system("cls");
            combo(v, tab);
        }
        
        
        break;

    case 8:
        if (tab[0].fourofakind.estado == 0) {
            tab[0].fourofakind.estado = 1;
        }
        else if (tab[0].fourofakind.estado == 1) {
            printf("\nJa escolheu este combo! \nPressione qualquer tecla para tentar novamente...");
            system("pause>nul");
            system("cls");
            combo(v, tab);
        }
        
        break;
    
    case 9:
        if (tab[0].fullhouse.estado == 0) {
            tab[0].fullhouse.estado = 1;
        }
        else if (tab[0].fullhouse.estado == 1) {
            printf("\nJa escolheu este combo! \nPressione qualquer tecla para tentar novamente...");
            system("pause>nul");
            system("cls");
            combo(v, tab);
      
        }

        break;

    case 10:
        if (tab[0].smallstraight.estado == 0) {
            tab[0].smallstraight.estado = 1;
        }
        else if (tab[0].smallstraight.estado == 1) {
            printf("\nJa escolheu este combo! \nPressione qualquer tecla para tentar novamente...");
            system("pause>nul");
            system("cls");
            combo(v, tab);
        }

        break;

    case 11:
        if (tab[0].largestraight.estado == 0) {
            tab[0].largestraight.estado = 1;
        }
        else if (tab[0].largestraight.estado == 1) {
            printf("\nJa escolheu este combo! \nPressione qualquer tecla para tentar novamente...");
            system("pause>nul");
            system("cls");
            combo(v, tab);
        }

        break;


    case 12:
        if (tab[0].chance.estado == 0) {
            tab[0].chance.estado = 1;
        }
        else if (tab[0].chance.estado == 1) {
            printf("\nJa escolheu este combo! \nPressione qualquer tecla para tentar novamente...");
            system("pause>nul");
            system("cls");
            combo(v, tab);
        }

        break;

    case 13:
        if (tab[0].yahtzee.estado == 0) {
            tab[0].yahtzee.estado = 1;
        }
        else if (tab[0].yahtzee.estado == 1) {
            printf("\nJa escolheu este combo! \nPressione qualquer tecla para tentar novamente...");
            system("pause>nul");
            system("cls");
            combo(v, tab);
        }

        break;

    default:
        printf("\nCombo invalido!! \nPressione qualquer tecla para tentar novamente...");
        system("pause>nul");
        system("cls");
        combo(v, tab);
        break;
    }



}



//Pontuação Final

int finalscore(TABELA*  tab) {

    printf("\nPressione qualquer tecla para acabar o jogo...");
    system("pause>nul");
    system("cls");

    int finalscore = 0;
    int bonus = 0;

    bonus = pontnum(tab);

    finalscore = bonus + tab[0].threeofakind.valor + tab[0].fourofakind.valor + tab[0].fullhouse.valor + tab[0].smallstraight.valor + tab[0].largestraight.valor + tab[0].chance.valor + tab[0].yahtzee.valor;
    
    setForeColor(MY_COLOR_LIGTH_GREEN);
    printf("\n\n\tPontuacao FINAL: %d", finalscore);

    return finalscore;

}


//Funçao JOGO principal
void jogo(void) {
    DADO lista[5];
    TABELA tab[1];
    int i = 0;
    int fscore = 0;
    int escolha = 0, a = 0, jog = 0;

    inittab(tab);

    for (i = 0; i < 5; i++) {
        initdado(&lista[i]);

    }


    printf("\n\n");
    do {

        lancardados(5, 5, lista);

        mostrardad(lista);

        tabelanum(lista, tab);

        do {

            mostrardad(lista);
            tabelanum(lista, tab);


            resetColor();
            escolha = comboujog();
            if (escolha == 1) {
                printf("\nPressione qualquer tecla para escolher o combo...");
                system("pause>nul");
                system("cls");

                combo(lista, tab);

                a = 2;

                
            }
            else if (escolha == 2) {

                relancar(lista);
                
                resetColor();
                printf("\n\n\nPressione qualquer tecla para jogar novamente...");
                system("pause>nul");
                system("cls");
                mostrardad(lista);
                printf("\n\n");
                tabelanum(lista, tab);

                a++;
            }


        } while (a != 2);

        if (escolha != 1) {
            combo(lista, tab);
        }
        if (jog < 12) {
            resetColor();
            gotoxy(0, 20);
            printf("Pressione qualquer tecla para a proxima ronda...");
            system("pause>nul");
            system("cls");
            tabelanum(lista, tab);
        }
        else if (jog == 12) {
            finalscore(tab);
        }
        
        jog++;
        a = 0;
    } while (jog < 13);


    resetColor();

}


//MENU
void menu(void) {
    int esc = 0;
    char nomep[20];
    setForeColor(MY_COLOR_LIGTH_GREEN);
    printf("******************************************* YAHTZEE *******************************************");


    setForeColor(MY_COLOR_CYAN);
    showRectCenteredAt(10, 5, 20, 3);
    showRectCenteredAt(33, 5, 20, 3);
    showRectCenteredAt(56, 5, 20, 3);
    

    setForeColor(MY_COLOR_DARK_YELLOW);
    gotoxy(4, 5);
    printf("Regras do jogo");
    gotoxy(9, 6);
    printf("(1)");
    gotoxy(29, 5);
    printf("Novo Jogo");
    gotoxy(32, 6);
    printf("(2)");
    gotoxy(54, 5);
    printf("Sair");
    gotoxy(55, 6);
    printf("(0)");
    

    gotoxy(1, 10);
    do {
        setForeColor(MY_COLOR_WHITE);
        printf("O que quer realizar?: ");
        (void)scanf(" %d", &esc);
    } while (esc != 0 && esc != 1 && esc != 2 && esc != 3);

    if (esc == 0) {
        return;
    }
    else if (esc == 1) {
        system("cls");
        setForeColor(MY_COLOR_SOFT_GREEN);
        printf("\nGame rules:\n\n");
        setForeColor(MY_COLOR_LIGTH_BLUE);
        printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of\n");
        printf("thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists\n");
        printf("of boxes that are scored by summing the value of the dice matching the faces of the box. If a player\n");
        printf("rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has\n");
        printf("chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
        printf("If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are\n");
        printf("added to the players overall score as a bonus. The lower section contains a number of poker like combinations.\n\n");

        setForeColor(MY_COLOR_WHITE);
        printf("Pressiona qualquer tecla para retornar ao menu...");
        system("pause > nul");
        system("cls");
        menu();
    }
    else if (esc == 2) {
        system("cls");
        printf("\n\nNome do jogador: ");
        (void)scanf(" %[^\n]", &nomep);

        printf("\nPressiona qualquer tecla para começar o jogo...");
        system("pause > nul");
        system("cls");

        jogo();

    }
}


int main() {
    srand((int)time(NULL));
    int escolhamenu = 0;

    inicio();
    menu();



    resetColor();
    gotoxy(14, 20);
    return 0;
}
