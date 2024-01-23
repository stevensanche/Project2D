/* Steven Sanchez Jimenez*/




#include <stdio.h>
#include <stdlib.h>

typedef enum
{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
   UNSUPPORTED
} MathOperation;
        
void IssueBadNumberError()
{
    printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}
void IssueBadOperationError()
{
    printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}

MathOperation GetOperation(char *op)
{
    if (op[1] != '\0') {
        IssueBadOperationError();
    }
    else if (*op == '+') {
        return ADD;
    }
    else if (*op == '-') {
        return SUBTRACT;
    }
    else if (*op == 'x') {
        return MULT;
    }
    else if (*op == '/') {
        return DIV;
    }
    else {
    return UNSUPPORTED;
    }
}


double StringToDouble(char *str)
{
    int counter = 0;
    int negative = 1;
    int decimal = 0;
    int tmp = 0;
    int place = 0.1;
    int s = 0;
    int dcounter = 0;

    if (str[0] == '-') {
        negative = -1;
    }

    if (negative == -1) {
        s = 1;
    }
    
    for (s; str[s]; ++s) {
        if (str[s] == '.') {
            if (dcounter) {
                IssueBadNumberError();
            }      
            dcounter++;
            
        for (int x = s; str[x] != '\0'; ++x) {
            decimal += 1;
            place *= 10;
            }
        continue;
        
    }
    if (str[s] > '9') {
        IssueBadNumberError();
    }
    if (str[s] < '0') {
        IssueBadOperationError();
    }
    counter = str[s] - 48;
    tmp *= 10;
    tmp += counter;
}
    tmp *= negative;
    return tmp / place;
}    


int main(int argc, char *argv[])
{
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
    double v2 = StringToDouble(argv[3]);
    double result = 0.;
    switch (op)
    {
       case ADD:
         result = v+v2;
         break;
       case SUBTRACT:
         result = v-v2;
         break;
       case MULT:
         result = v*v2;
         break;
       case DIV:
         result = v/v2;
         break;
       case UNSUPPORTED:
         IssueBadOperationError();
         break;
         

    }
    printf("%d\n", (int) result);
 
    return 0;
}
