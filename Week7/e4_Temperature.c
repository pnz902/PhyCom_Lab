#include <stdio.h>
#include <ctype.h>

double celsiusToFahrenheit(double celcius);
double fahrenheitToCelcius(double fahrenheit);
void printFarenheit(double fahrenheit);
void printCelcius(double celcius);

int main(){
    double temp;
    char degree;

    scanf("%lf %c", &temp, &degree);

    if(tolower(degree) == 'c'){
        temp = celsiusToFahrenheit(temp);
        printFarenheit(temp);
    } else{
        temp = fahrenheitToCelcius(temp);
        printCelcius(temp);
    }

    return 0;
}

double celsiusToFahrenheit(double celcius){
    double fahrenheit;
    fahrenheit = 32 + (celcius)*(180.0/100.0);
    return fahrenheit;
}

double fahrenheitToCelcius(double fahrenheit){
    double celcius;
    celcius = (fahrenheit-32)*(100.0/180.0);
    return celcius;
}

void printFarenheit(double fahrenheit){
    printf("%.2lf f", fahrenheit);
}

void printCelcius(double celcius){
    printf("%.2lf c", celcius);
}