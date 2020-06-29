#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Define value to sort
#define bubbleSort 1
#define insertionSort 2
#define selectionSort 3
#define quickSort 4
#define mergeSort 5
#define heapSort 6
#define close 7
//Declaring functions that the program has
float functionBubbleSort(float *bubbleSortVector, int position, int maxPostion, int length);
float functionInsertionSort(float *insertionSortVector, int position, int key, int length);
float functionSelectionSort(float *selectionSortVector, int curPosition, int comparedPosition, int length, int temp);
int  functionCheckIfIsNumber(char size[]);
int  functionCheckSize();
float checkCurValue();
int checkExit();
float functionInsertionSortChildOne(float *insertionSortVector, int j, int key);
float functionQuickSortChildOne(float *quickSortVector, int initialPosition, int lastPosition);

//Declaring some variables in global scope

int typedSize= 0, sizeNotAllowed= 0, resultComparation, permission= 1, curPermission= 0;
int typedExit= 0, canExit= 1, continueProgram= 2;
int canStop= 1;
int ccvExit=5, ccvExitOne= 0, ccvExitTwo= 1;
char size[5], exitOption[5], curValue[5], especialValue[1] ={'0'};
float curValueFloat, atualValue;

int main(){

    int firstChoice= 0, position= 0, stop= 0;
    int finalSize= 0, finalCurValue= 0, ifIs0= 0, i= 0;
    float value= 0, curValue= 0;

    printf("Este programa contem 3 tipos deferentes de sort........");
    while(1){
            printf("\nEscolha um");
        printf("\nBubble Sort [ 1 ]\n");
        printf("Insertion Sort [ 2 ]\n");
        printf("Selection Sort [ 3 ]\n");
        printf("Digite sua escolha: ");
        scanf("%d", &firstChoice);

        if(firstChoice == bubbleSort){
             printf("\n\nFoi escolhido bubbleSort\n");
             finalSize = functionCheckSize();

             float bubbleSortVector[finalSize];
             for(i= 0; i < finalSize; i++){
                value= checkCurValue();
                bubbleSortVector[i] = value;
             }
             i=0;
             printf("\nOs valores digitados foram:\t");
             for(i= 0; i < finalSize; i++){
                printf("%f|", bubbleSortVector[i]);
             }
             //chamando a função
             functionBubbleSort(bubbleSortVector, position, finalSize-1, finalSize);
             printf("\n");
             i= 0;
             printf("\nO vetor ordenado fica:\t");
             for(i= 0; i< finalSize; i++){
                printf("%f|",bubbleSortVector[i]);
             }

             stop= checkExit();
             if(stop == canExit){
                break;
             }else if(stop == continueProgram){
                continue;
             }
        }else if(firstChoice == insertionSort){
             printf("\n\nFoi escolhido insertionSort\n");
             finalSize = functionCheckSize();

             float insertionSortVector[finalSize];
             for(i= 0; i < finalSize; i++){
                value= checkCurValue();
                insertionSortVector[i] = value;
             }
             i=0;
             printf("\nOs valores digitados foram:\t");
             for(i= 0; i < finalSize; i++){
                printf("%f|", insertionSortVector[i]);
             }
             //chamando a função
             functionInsertionSort(insertionSortVector, position, 1, finalSize);
             printf("\n");
             i= 0;
             printf("\nO vetor ordenado fica:\t");
             for(i= 0; i< finalSize; i++){
                printf("%f|",insertionSortVector[i]);
             }
             stop= checkExit();
             if(stop == canExit){
                break;
             }else if(stop == continueProgram){
                continue;
             }
        }else if(firstChoice == selectionSort){
             printf("\n\nFoi escolhido selectionSort\n");
             finalSize = functionCheckSize();

             float selectionSortVector[finalSize];
             for(i= 0; i < finalSize; i++){
                value= checkCurValue();
                selectionSortVector[i] = value;
             }
             i=0;
             printf("\nOs valores digitados foram:\t");
             for(i= 0; i < finalSize; i++){
                printf("%f|", selectionSortVector[i]);
             }
             //chamando a função
             functionSelectionSort(selectionSortVector,position,1,finalSize,0);
             printf("\n");
             i= 0;
             printf("\nO vetor ordenado fica:\t");
             for(i= 0; i< finalSize; i++){
                printf("%f|",selectionSortVector[i]);
             }
             stop= checkExit();
             if(stop == canExit){
                break;
             }else if(stop == continueProgram){
                continue;
             }

        }else if(firstChoice == close){
             printf("Foi escolhido fechar\n");
             break;

        }else{
            printf("Por favor digite uma das opções disponiveis\n");
            continue;
        }
    }


    return 0;
}
int checkExit(){
    printf("\nSe quiser fechar digite [ 1 ]\nCaso queira continuar digite [ 2 ]");
    scanf("%s", exitOption);
    typedExit= functionCheckIfIsNumber(exitOption);
    if(typedExit == canExit){
        printf("\n\nFoi decidido sair........");
        return typedExit;
    }else if(typedExit == continueProgram){
        printf("\nFoi decidido continuar........");
        return typedExit;
    }else{
        printf("\nOpt invalida, por favor digite [ 1 ] ou [ 2 ]");
        checkExit();
    }

}

int functionCheckIfIsNumber(char size[]){
    int value;
    value = atoi(size);
    return value;
    //printf("oque foi digitado foi: %s ", size);
}

int functionCheckSize(){
    printf("Digite o tamanho do vetor: ");
    scanf("%s", size);
    typedSize= functionCheckIfIsNumber(size);
    if(typedSize > sizeNotAllowed){
        printf("Tamanho permitido\n");
        return typedSize;
    }else{
        printf("Tamanho invalido, por favor digite um tamanho válido[ maior que 0 e inteiro ]\n");
        functionCheckSize();
    }

}

float checkCurValue(){
    curPermission= 0;
    ccvExitOne= 0;
    ccvExitTwo= 1;
    printf("Digite um valor: ");
    scanf("%s", curValue);
    curValueFloat = atof(curValue);
    resultComparation = strcmp(curValue, especialValue);
    if(resultComparation == 0){
        curValueFloat = 0;
        curPermission = permission;
        ccvExitOne = ccvExit;
    }else if(curValueFloat > 0 || curValueFloat < 0){
        curPermission = permission;
        ccvExitTwo = ccvExit;
    }else{
        printf("Oq foi digitado foi: %s\n", curValue);
        printf("Por favor digite um numero...\n");
        checkCurValue();
    }

    if(ccvExitOne == ccvExit && curPermission == permission){
        return curValueFloat;
    }else if(ccvExitTwo == ccvExit && curPermission == permission){
        return curValueFloat;
    }
}


float functionBubbleSort(float *bubbleSortVector, int position, int maxPostion, int length){
    if(length == 1){
        return *bubbleSortVector;
    }
    else if(maxPostion <= 0){
        if(bubbleSortVector[position] > bubbleSortVector[position+1]){
            atualValue = bubbleSortVector[position];
            bubbleSortVector[position] = bubbleSortVector[position+1];
            bubbleSortVector[position+1] = atualValue;
        }
        return *bubbleSortVector;
    }else{
        if(position < maxPostion){
            if(bubbleSortVector[position] > bubbleSortVector[position+1]){
                atualValue = bubbleSortVector[position];
                bubbleSortVector[position] = bubbleSortVector[position+1];
                bubbleSortVector[position+1] = atualValue;
            }
            functionBubbleSort(bubbleSortVector, position+1, maxPostion, length);
        }else{
            functionBubbleSort(bubbleSortVector, 0, maxPostion-1, length);
        }
    }
}

float functionInsertionSort(float *insertionSortVector, int position, int key, int length){
    if(length == 1){
        return *insertionSortVector;
    }else if(position < length){
        int j = position - 1;
        key = insertionSortVector[position];
        functionInsertionSortChildOne(insertionSortVector,j, key);
        functionInsertionSort(insertionSortVector, position+1, key, length);
    }else{
        return *insertionSortVector;
    }
}
float functionInsertionSortChildOne(float *insertionSortVector, int j, int key){
    if(j >=0 && key < insertionSortVector[j]){
        insertionSortVector[j + 1] = insertionSortVector[j];
        j = j - 1;
        insertionSortVector[j + 1] = key;
        functionInsertionSortChildOne(insertionSortVector, j, key);
    }else{
        return *insertionSortVector;
    }
}

float functionSelectionSort(float *selectionSortVector, int curPosition, int comparedPosition, int length, int temp){
    if(length == 0){
        return *selectionSortVector;
    }if(curPosition < length){
        if(comparedPosition < length){
            if(selectionSortVector[curPosition] < selectionSortVector[comparedPosition]){
                temp = selectionSortVector[curPosition];
                selectionSortVector[curPosition] = selectionSortVector[comparedPosition];
                selectionSortVector[comparedPosition] = temp;
            }
            functionSelectionSort(selectionSortVector,curPosition,comparedPosition+1,length,temp);
        }else{
            functionSelectionSort(selectionSortVector,curPosition+1,0,length,temp);
        }
    }else{
        return *selectionSortVector;
    }
}









