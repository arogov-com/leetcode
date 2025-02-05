#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char *result = calloc(len1 + len2 + 1, sizeof(char));
    if(num1[0] == '0' || num2[0] == '0') {
        result[0] = '0';
        result[1] = '\x0';
        return result;
    }

    int prod_index = len1 + len2 - 1;
    int result_index = prod_index;
    int index2 = len2 - 1;
    int index1;
    while(index2 >= 0) {
        index1 = len1 - 1;
        prod_index = result_index;
        while(index1 >= 0) {
            int s = (num1[index1--] - '0') * (num2[index2] - '0') + result[prod_index];

            if(s > 9) {
                result[prod_index - 1] += s / 10;
                s -= s / 10 * 10;
            }
            result[prod_index] = s;

            if(result[prod_index - 1] > 9) {
                result[prod_index - 2] += result[prod_index - 1] / 10;
                result[prod_index - 1] -= result[prod_index - 1] / 10 * 10;
            }
            --prod_index;
        }
        --result_index;
        --index2;
    }

    prod_index = result[0] == 0 ? 1 : 0;
    for(result_index = 0; prod_index <= len1 + len2 - 1; ++result_index, ++prod_index) {
        result[result_index] = result[prod_index] + '0';
    }
    result[result_index] = '\x0';

    return result;
}


int main(int argc, char const *argv[]) {
    char *result;
    result = multiply("9133", "0"); printf("%s\n", result);  // 0
    result = multiply("123", "456"); printf("%s\n", result); // 56088
    result = multiply("999", "999"); printf("%s\n", result); // 998001
    result = multiply("25", "231"); printf("%s\n", result);  // 5775
    result = multiply("23874", "34865387465"); printf("%s\n", result);  // 832376260339410
    result = multiply("87126508273650182476108247614308576134857143805734650376587346501834756108475603485760384576103485768712650827365018247610824761430857613485714380573465037658734650183475610847560348576038457610348576",
                       "23894759273645938745783652834651871023849238746528467348763248075264351934865029386529734515204397462389475927364593874578365283465187102384923874652846734876324807526435193486502938652973451520439746");
    printf("%s\n", result);  // 2081866941552192306757920301253383990204712841797939953600252864799124016400014662227027760051153419253882302210214775687189244173779328417585409900202809740085497507766416233527705200267287596720853388320452195477185934700239797154345977375696726102363340009513557579562754705101173242624717809568108375089138997763143356051839231025303766428415406148190200349245479416129535247727548617355864901696

    free(result);
    return 0;
}
