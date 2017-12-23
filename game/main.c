#include <stdio.h>
#include <stdlib.h>

char addProximities(int row, int column, int i, int j,char ch[row+2][column+2]){
int num=0;
if(ch[i+1][j+1] == '*')
    num++;
if(ch[i][j+1] == '*')
    num++;
if(ch[i-1][j+1] == '*')
    num++;
if(ch[i+1][j] == '*')
    num++;
if(ch[i-1][j] == '*')
    num++;
if(ch[i+1][j-1] == '*')
    num++;
if(ch[i][j-1] == '*')
    num++;
if(ch[i-1][j-1] == '*')
    num++;

if(num == 0)
    return ch[i][j];
if(num == 1)
    return '1';
if(num == 2)
    return '2';
if(num == 3)
    return '3';
if(num == 4)
    return '4';
if(num == 5)
    return '5';
if(num == 6)
    return '6';
if(num == 7)
    return '7';
if(num == 8)
    return '8';
if(num == 9)
    return '9';
}

int main()
{
    setvbuf(stdout,NULL,_IONBF,0);
    int row, column, mines;
    printf("Enter the number of row:");
    scanf("%i", &row);
    printf("Enter the number of column:");
    scanf("%i", &column);
    printf("How many mines do you want?");
    scanf("%i", &mines);

    char plate[row+2][column+2];
    int tmp;
    int i, j;
    time_t t;
    srand((unsigned) time(&t));

    j = 0;
    do{
    plate[0][j] = NULL;
    j++;
    }while( j != (column+2));

    j = 0;
    do{
    plate[row+1][j] = NULL;
    j++;
    }while( j != (column+2));

    i = 0;
    do{
    plate[i][0] = NULL;
    i++;
    }while( i != (row+2));

    i = 0;
    do{
    plate[i][column+1] = NULL;
    i++;
    }while( i != (row+2));

    i = 1;
    j = 1;
    int tmp4  = 0;
    do{
        for(i=1;i<row+1;i++){
            for(j=1;j<column+1;j++){
            tmp = rand()%1000-100;
            if(tmp >= 0 && (plate[i][j] != '*')){
                plate[i][j] = '.';
            }
            else if( ((tmp < 0) && (plate[i][j] != '*')) && (tmp4 < mines)){
                plate[i][j] = '*';
                tmp4++;
            }
            else if(plate[i][j] != '*'){
                plate[i][j] = '.';
            }
            }
        }
    }while( tmp4 < mines);


    for(i=1;i<row+1;i++){
        for(j=1;j<column+1;j++){
            if(plate[i][j] == '.')
            plate[i][j] = addProximities(row, column, i, j, plate);
        }
    }

//    for(i=1;i<row+1;i++){
//        for(j=1;j<column+1;j++)
//            printf("%c", plate[i][j]);
//        printf("\n");
//    }
    printf("So lets play\n\n");
    char game[row+2][column+2];
    for(i=1;i<row+1;i++){
        for(j=1;j<column+1;j++){
            game[i][j] = 'o';
        }
    }

    for(i=1;i<row+1;i++){
        for(j=1;j<column+1;j++)
            printf("%c ", game[i][j]);
        printf("\n");
    }

    int row1 = 0;
    int column1 = 0;
    int count = 0;
    do{
        printf("Enter the row\n");
        scanf("%i", &row1);
        printf("Enter the column\n");
        scanf("%i", &column1);
        game[row1][column1] = plate[row1][column1];
            if( game[row1][column1] == '*'){
                for(i=1;i<row+1;i++){
                    for(j=1;j<column+1;j++)
                        printf("%c ", game[i][j]);
                    printf("\n");
                }
                printf("Boom!!Boom!!Boom!!\n\n");
                return 1;
            }
            else{
                for(i=1;i<row+1;i++){
                    for(j=1;j<column+1;j++)
                        printf("%c ", game[i][j]);
                    printf("\n");
            }
            printf("Continue\n\n");
            }
        count = 0;

        for(i=1;i<row+1;i++){
            for(j=1;j<column+1;j++){
            if( game[i][j]== 'o')
            count++;
            }
        }
        if(count == mines){
            printf("You are winner. Yahoooooo \)\)");
            return 1;
        }

    }while( game[row1][column1] != '*' );
    printf("Anyway you are winner \)\)");
    return 0;
}
